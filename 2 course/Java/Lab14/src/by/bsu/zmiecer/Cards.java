package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 20.12.2015.
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Cards implements MouseListener {

    String tempButtonText = new String();


    public void addComponentToPane(Container pane)
    {
        JTabbedPane tabbedPane = new JTabbedPane();

        //Card 1
        JPanel card1 = new JPanel();
        card1.setLayout(new BorderLayout());
        JButton buttonRight = new JButton(">");
        JButton buttonLeft = new JButton("<");

        JPanel card1Inside = new JPanel();
        card1Inside.setLayout(new BorderLayout());
        card1Inside.add(buttonRight, BorderLayout.NORTH);
        card1Inside.add(buttonLeft, BorderLayout.SOUTH);
        card1.add(card1Inside, BorderLayout.CENTER);

        //Lists
        DefaultListModel modelLeft = new DefaultListModel();
        String[] dataLeft = {"one", "two", "three", "four"};
        for (int i = 0; i < dataLeft.length; i++)
        {
            modelLeft.add(i, dataLeft[i]);
        }
        JList<String> listLeft = new JList<>(modelLeft);
        card1.add(listLeft, BorderLayout.WEST);

        DefaultListModel modelRight = new DefaultListModel();
        String[] dataRight = {"five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < dataRight.length; i++)
        {
            modelRight.add(i, dataRight[i]);
        }
        JList<String> listRight = new JList<>(modelRight);
        card1.add(listRight, BorderLayout.EAST);

        buttonRight.addActionListener(e ->
        {
            if(!listLeft.isSelectionEmpty()) {
                modelRight.add(modelRight.size(), listLeft.getSelectedValue());
                modelLeft.remove(listLeft.getSelectedIndex());
                listLeft.clearSelection();
            }
        });

        buttonLeft.addActionListener(e ->
        {
            if (!listRight.isSelectionEmpty()) {
                modelLeft.add(modelLeft.size(), listRight.getSelectedValue());
                modelRight.remove(listRight.getSelectedIndex());
                listRight.clearSelection();
            }
        });

        //Card 2
        JPanel card2 = new JPanel();
        card2.setLayout(new GridLayout(4, 5));

        JButton [] buttons = new JButton[20];

        for (int i = 0; i < 20; i++) {
            StringBuilder str = new StringBuilder();
            str.append(i+1);
            buttons[i] = new JButton(str.toString());
            buttons[i].addMouseListener(this);
            card2.add(buttons[i]);
        }





        //Card 3
        JPanel card3 = new JPanel();
        card3.setLayout(new GridLayout(5, 1));
        JRadioButton radio1 = new JRadioButton("Apollo");
        JRadioButton radio2 = new JRadioButton("Aphrodite");
        JRadioButton radio3 = new JRadioButton("Ares");
        JRadioButton radio4 = new JRadioButton("Zeus");
        JRadioButton radio5 = new JRadioButton("Cronus");

        //Icons
        ImageIcon icon = new ImageIcon("images/MercuryGod.jpg");
        radio1.setIcon(icon);
        icon = new ImageIcon("images/MercurySurface.jpg");
        radio1.setPressedIcon(icon);
        icon = new ImageIcon("images/MercuryPlanet.jpg");
        radio1.setSelectedIcon(icon);
        icon = new ImageIcon("images/MercurySymbol.jpg");
        radio1.setRolloverIcon(icon);
        icon = new ImageIcon("images/MercuryAstrology.png");
        radio1.setRolloverSelectedIcon(icon);

        icon = new ImageIcon("images/VenusGoddess.jpg");
        radio2.setIcon(icon);
        icon = new ImageIcon("images/VenusSurface.jpg");
        radio2.setPressedIcon(icon);
        icon = new ImageIcon("images/VenusPlanet.jpg");
        radio2.setSelectedIcon(icon);
        icon = new ImageIcon("images/VenusSymbol.jpg");
        radio2.setRolloverIcon(icon);
        icon = new ImageIcon("images/VenusAstrology.png");
        radio2.setRolloverSelectedIcon(icon);

        icon = new ImageIcon("images/MarsGod.jpg");
        radio3.setIcon(icon);
        icon = new ImageIcon("images/MarsSurface.jpg");
        radio3.setPressedIcon(icon);
        icon = new ImageIcon("images/MarsPlanet.jpg");
        radio3.setSelectedIcon(icon);
        icon = new ImageIcon("images/MarsSymbol.jpg");
        radio3.setRolloverIcon(icon);
        icon = new ImageIcon("images/MarsAstrology.png");
        radio3.setRolloverSelectedIcon(icon);

        icon = new ImageIcon("images/JupiterGod.jpg");
        radio4.setIcon(icon);
        icon = new ImageIcon("images/JupiterEye.jpg");
        radio4.setPressedIcon(icon);
        icon = new ImageIcon("images/JupiterPlanet.jpg");
        radio4.setSelectedIcon(icon);
        icon = new ImageIcon("images/JupiterSymbol.jpg");
        radio4.setRolloverIcon(icon);
        icon = new ImageIcon("images/JupiterAstrology.png");
        radio4.setRolloverSelectedIcon(icon);

        icon = new ImageIcon("images/SaturnGod.jpg");
        radio5.setIcon(icon);
        icon = new ImageIcon("images/SaturnRing.jpg");
        radio5.setPressedIcon(icon);
        icon = new ImageIcon("images/SaturnPlanet.jpg");
        radio5.setSelectedIcon(icon);
        icon = new ImageIcon("images/SaturnSymbol.png");
        radio5.setRolloverIcon(icon);
        icon = new ImageIcon("images/SaturnAstrology.png");
        radio5.setRolloverSelectedIcon(icon);




        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(radio1);
        radioGroup.add(radio2);
        radioGroup.add(radio3);
        radioGroup.add(radio4);
        radioGroup.add(radio5);

        card3.add(radio1);
        card3.add(radio2);
        card3.add(radio3);
        card3.add(radio4);
        card3.add(radio5);


        tabbedPane.addTab("Card 1", card1);
        tabbedPane.addTab("Card 2", card2);
        tabbedPane.addTab("Card 3", card3);

        pane.add(tabbedPane, BorderLayout.CENTER);
    }

    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Cards");
        frame.setBounds(100, 100, 640, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Cards cards = new Cards();
        cards.addComponentToPane(frame.getContentPane());

        //frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        /* Use an appropriate Look and Feel */
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            //UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
        } catch (UnsupportedLookAndFeelException ex) {
            ex.printStackTrace();
        } catch (IllegalAccessException ex) {
            ex.printStackTrace();
        } catch (InstantiationException ex) {
            ex.printStackTrace();
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }
        /* Turn off metal's use of bold fonts */
        //UIManager.put("swing.boldMetal", Boolean.FALSE);

        //Schedule a job for the event dispatch thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }


    @Override
    public void mouseClicked(MouseEvent e) {
    }

    @Override
    public void mousePressed(MouseEvent e) {
        tempButtonText = ((JButton)e.getComponent()).getText();
        ((JButton)e.getComponent()).setText("Clicked!");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        ((JButton)e.getComponent()).setText(tempButtonText);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        e.getComponent().setBackground(Color.red);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        e.getComponent().setBackground(Color.white);
    }
}