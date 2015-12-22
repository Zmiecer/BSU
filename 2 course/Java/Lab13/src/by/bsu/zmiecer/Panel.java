package by.bsu.zmiecer;

import oracle.jrockit.jfr.JFR;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Created by Zmiecer on 16.12.2015.
 */
public class Panel extends JScrollPane implements MouseListener, MouseMotionListener {

    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;
    Color color = Color.BLACK;

    boolean lineStarted = false;
    boolean mouseExited = false;


    ArrayList<Line> lines = new ArrayList<>();

    JToggleButton blackButton = new JToggleButton("Black");
    JToggleButton blueButton = new JToggleButton("Blue");
    JToggleButton redButton = new JToggleButton("Red");


    JPanel downPanel = new JPanel();

    protected void init()
    {

        JButton saveButton = new JButton("Save");
        JButton openButton = new JButton("Open");

        ButtonGroup group = new ButtonGroup();
        group.add(blackButton);
        group.add(blueButton);
        group.add(redButton);


        blackButton.setBounds(0, 0, 100, 50);
        blueButton.setBounds(0, 50, 100, 50);
        redButton.setBounds(0, 100, 100, 50);
        saveButton.setBounds(0, 150, 100, 50);
        openButton.setBounds(0, 200, 100, 50);




        downPanel.add(blackButton);
        downPanel.add(blueButton);
        downPanel.add(redButton);
        downPanel.add(saveButton);
        downPanel.add(openButton);


        JFileChooser fc = new JFileChooser("C:\\Users\\Дмитрий\\Документы\\GitHub\\BSU\\2 course\\Java\\Lab13\\pictures");
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Paint Files", "paint");
        fc.setFileFilter(filter);




        blackButton.setSelected(true);

        saveButton.addActionListener(e -> {
            try
            {
                int returnVal = fc.showSaveDialog(Panel.this);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File fileSave = fc.getSelectedFile();

                    FileWriter file = new FileWriter(fileSave + ".paint");
                    for (int i = 0; i < lines.size(); i++) {
                        file.write(lines.get(i).toString());
                        file.write("\n");
                    }
                    file.close();
                }
            }
            catch (IOException ex)
            {
                System.out.println("Can't write into file!");
            }
        });

        openButton.addActionListener(e -> {
            try
            {
                int returnVal = fc.showOpenDialog(Panel.this);

                if (returnVal == JFileChooser.APPROVE_OPTION)
                {
                    File fileOpen = fc.getSelectedFile();


                Scanner sc = new Scanner(fileOpen);
                lines.clear();
                while(sc.hasNextLine())
                {
                    if(sc.hasNext()) {
                        startX = sc.nextInt();
                        startY = sc.nextInt();
                        endX = sc.nextInt();
                        endY = sc.nextInt();
                        color = new Color(sc.nextInt(), sc.nextInt(), sc.nextInt());
                        lines.add(new Line(startX, startY, endX, endY, color));
                    }
                    else break;
                }
                repaint();
                sc.close();
                }
            }
            catch (IOException ex)
            {
                System.out.println("Invalid object exception!");
            }
            catch (NoSuchElementException ex)
            {
                System.out.println("No such element exception!");
            }
        });

        this.addMouseListener(this);
        this.addMouseMotionListener(this);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        setAutoscrolls(true);



        if(lineStarted)
        {
            if(blackButton.isSelected())
                color = Color.BLACK;
            if(blueButton.isSelected())
                color = Color.BLUE;
            if(redButton.isSelected())
                color = Color.RED;
            lines.add(new Line(startX, startY, endX, endY, color));
        }
        for (int i = 0; i < lines.size(); i++)
        {
            g.setColor(lines.get(i).getColor());
            g.drawLine(lines.get(i).getStartX(), lines.get(i).getStartY(), lines.get(i).getEndX(), lines.get(i).getEndY());
        }
        startX = endX;
        startY = endY;
    }

    @Override
    public void mouseClicked(MouseEvent e)
    {

    }

    @Override
    public void mousePressed(MouseEvent e)
    {
        startX = e.getX();
        startY = e.getY();
        endX = e.getX();
        endY = e.getY();
        lineStarted = true;
        repaint();
    }

    @Override
    public void mouseReleased(MouseEvent e)
    {
        lineStarted = false;
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e)
    {

        /*startX = e.getX();
        startY = e.getY();
        mouseExited = false;
        repaint();*/
    }

    @Override
    public void mouseExited(MouseEvent e)
    {
        /*endX = e.getX();
        endY = e.getY();
        mouseExited = true;
        repaint();*/
    }

    @Override
    public void mouseDragged(MouseEvent e)
    {
        if(!mouseExited)
        {
            endX = e.getX();
            endY = e.getY();
            lineStarted = true;
            repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e)
    {

    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Рисование");
        frame.setBounds(100,100,640,480);
        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());

        Panel drawPanel = new Panel();
        drawPanel.init();
        drawPanel.repaint();
        drawPanel.setOpaque(true);
        drawPanel.setLayout(null);
        drawPanel.setPreferredSize(new Dimension(1000, 600));
        JScrollPane scrollPaintPanel = new JScrollPane(drawPanel);
        scrollPaintPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaintPanel.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        contentPane.add(scrollPaintPanel, BorderLayout.CENTER);



        contentPane.add(drawPanel.downPanel, BorderLayout.SOUTH);




        frame.setContentPane(contentPane);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
