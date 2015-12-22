package by.bsu.zmiecer;


import javax.swing.*;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public class Frame extends JFrame
{
    public Frame(String s)
    {
        super(s);
        Panel panel = new Panel();
        setBounds(100, 100, 600, 400);
        panel.setOpaque(true);
        setContentPane(panel);
        panel.setLayout(null);





        panel.init();
        panel.repaint();


        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }


}
