import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public class Frame extends JFrame
{
    public Frame (String s)
    {
        super(s);
        Panel p = new Panel();
        p.add(new JTextField());
        setBounds(100, 100, 600, 400);
        setContentPane(p);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        Frame frame = new Frame("Main frame");
        Linear line = new Linear (1.0, 2.0, 12);
        System.out.println(line.getElem(12));
        System.out.println(line.sum());
        Exponential exp = new Exponential(1.0, 2.0, 12);
        System.out.println(exp.getElem(12));
        System.out.println(exp.sum());
    }
}
