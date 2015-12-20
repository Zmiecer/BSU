package by.bsu.zmiecer;

import javax.swing.*;
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


        this.add(blackButton);
        this.add(blueButton);
        this.add(redButton);
        this.add(saveButton);
        this.add(openButton);

        blackButton.setSelected(true);

        saveButton.addActionListener(e -> {
            try
            {
                FileWriter file = new FileWriter("out.txt");
                for (int i = 0; i < lines.size(); i++)
                {
                    file.write(lines.get(i).toString());
                    file.write("\n");
                }
                file.close();
            }
            catch (IOException ex)
            {
                System.out.println("Can't write into file!");
            }
        });

        openButton.addActionListener(e -> {
            try
            {
                Scanner sc = new Scanner(new File("out.txt"));
                lines.clear();
                while(sc.hasNextLine())
                {
                    startX = sc.nextInt();
                    startY = sc.nextInt();
                    endX = sc.nextInt();
                    endY = sc.nextInt();
                    color = new Color(sc.nextInt(), sc.nextInt(), sc.nextInt());
                    lines.add(new Line(startX, startY, endX, endY, color));
                }
                repaint();
                sc.close();
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
}
