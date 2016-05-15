package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 19.04.2016.
 */

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.*;
import java.io.IOException;

public class GamePanel extends JScrollPane
{
    private final int N = 2;
    private ImageIcon defaultImage;
    private ImageIcon [] image = new ImageIcon[N*N];
    private JLabel [] part = new JLabel[N*N];
    private int changeX, changeY;
    private boolean [] moved = new boolean[N*N];
    private  JPanel finalPanel = new JPanel();

    public GamePanel() throws IOException
    {
        setLayout(null);
        defaultImage = new ImageIcon(getClass().getResource("Ava.jpg"));
        int imageWidth = defaultImage.getImage().getWidth(null);
        int imageHeight = defaultImage.getImage().getHeight(null);

        ImageIcon exampleImage = new ImageIcon(getClass().getResource("small_milky_way.jpg"));
        JLabel exampleImageLabel = new JLabel();
        exampleImageLabel.setIcon(exampleImage);
        exampleImageLabel.setBounds(0,0,200,118);
        add(exampleImageLabel);

        int [][] pixels = new int[N*N][imageWidth * imageHeight];
        PixelGrabber [] grabber = new PixelGrabber[N*N];

        int widthChange = imageWidth/N;
        int heightChange = imageHeight/N;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                grabber[i*N + j] = new PixelGrabber(defaultImage.getImage(), widthChange*i, heightChange*j, widthChange, heightChange, pixels[i*N + j], 0, imageWidth);
            }
        }

        try
        {
            for (int i = 0; i < N*N; i++)
            {
                grabber[i].grabPixels();
            }



        for (int i = 0; i < N*N; i++)
        {
            part[i] = new JLabel();
            image[i] = new ImageIcon(createImage(new MemoryImageSource(widthChange, heightChange, pixels[i], 0, imageWidth)));
            part[i].setIcon(image[i]);
            add(part[i]);
            part[i].setBounds(100 + 10*i, 10*i, 100 + widthChange + 10*i, heightChange + 10*i);
        }

        MouseAdapter mouseAdapter = new MouseAdapter()
        {
            @Override
            public void mousePressed(MouseEvent e)
            {
                //changeX = ((JLabel)e.getSource()).getX();
                //changeY = ((JLabel)e.getSource()).getY();


                //System.out.println(changeX);
                //System.out.println(changeY);
//                for (int i = 0; i < N*N; i++)
//                {
//                    if(((e.getX()<(part[i].getX()+ image[i].getIconWidth())) &&
//                            (e.getX()> part[i].getX())) &&
//                            (e.getY()<(part[i].getY()+ image[i].getIconHeight())) &&
//                            (e.getY()> part[i].getY()))
//                    {
//                        changeX = e.getComponent().getParent().getX() - part[i].getX();
//                        changeY = e.getComponent().getParent().getY() - part[i].getY();
//                        moved[i] = true;
//                        return;
//                    }
//                }

            }

            @Override
            public void mouseDragged(MouseEvent e)
            {
                ((JLabel)e.getSource()).setBounds(e.getComponent().getParent().getX() - changeX,e.getComponent().getParent().getY() - changeY, image[0].getIconWidth(), image[0].getIconHeight());;

//                for (int i = 0; i < N*N; i++)
//                {
//                    if(moved[i])
//                    {
//                        //e.getComponent().setBounds(e.getX() - changeX,e.getY() - changeY, image[i].getIconWidth(), image[i].getIconHeight());
//                        ((JLabel)e.getSource()).setBounds(e.getX() - changeX,e.getY() - changeY, image[i].getIconWidth(), image[i].getIconHeight());;
//                        //part[i].setBounds(e.getX() - changeX,e.getY() - changeY, image[i].getIconWidth(), image[i].getIconHeight());
//                    }
//                }
            }

            @Override
            public void mouseReleased(MouseEvent e)
            {
                for (int i = 0; i < N*N; i++)
                {
                    moved[i] = false;
                }


                if(finished())
                {
                    finalPanel.setBounds(part[0].getX(), part[0].getY(), defaultImage.getIconWidth(), defaultImage.getIconHeight());
                    finalPanel.setVisible(true);
                    for (int i = 0; i < N*N; i++)
                    {
                        part[i].setVisible(false);
                        remove(part[i]);
                    }
                    JOptionPane.showMessageDialog(null,"GG WP");

                }
            }
        };


            for (int i = 0; i < N*N; i++) {
                part[i].addMouseListener(mouseAdapter);
                part[i].addMouseMotionListener(mouseAdapter);
            }

        //addMouseListener(mouseAdapter);
        //addMouseMotionListener(mouseAdapter);

        JLabel finalLabel = new JLabel();
        finalLabel.setIcon(defaultImage);
        finalPanel.add(finalLabel);
        add(finalPanel);
        finalPanel.setVisible(false);

        }
        catch(InterruptedException ie)
        {
            JOptionPane.showMessageDialog(null,"Something went wrong...");
        }
    }

    private boolean finished()
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(i > 0)
                    if(Math.abs(part[i*N + j].getX() - (part[i*N + j - N].getX() + image[0].getIconWidth())) < 5)
                        count++;
                if(j > 0)
                    if((Math.abs(part[i*N + j].getY() - (part[i*N + j - 1].getY() + image[0].getIconHeight())) < 5))
                        count++;
            }
        }
        return (count == 2*N*(N-1));
    }
}
