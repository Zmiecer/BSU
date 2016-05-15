package by.bsu.zmiecer;

import javax.swing.*;
import java.io.IOException;

/**
 * Created by Zmiecer on 19.04.2016.
 */
public class Runner
{
    public static void main(String[] args) throws IOException
    {
        JFrame frame = new JFrame();
        frame.add(new GamePanel());
        frame.setBounds(100, 100, 1280, 720);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
