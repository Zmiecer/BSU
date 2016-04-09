package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;

/**
 * Created by Zmiecer on 29.03.2016.
 */
public class Frame extends JFrame {

    private JTextField text = new JTextField("info");
    private JComboBox list = new JComboBox();
    private final String INT = "Натуральное";


    public Frame() throws HeadlessException {
        setBounds(100, 100, 600, 400);
        setTitle("Regular 1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        

        setVisible(true);
    }
}
