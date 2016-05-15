package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Zmiecer on 29.03.2016.
 */
public class Frame extends JFrame {

    private JTextField textField = new JTextField();
    private JComboBox list = new JComboBox();
    private final String NAT = "Натуральное";
    private final String INT = "Целое";
    private final String DBL = "С плавающей запятой";
    private final String DAT = "Дата";
    private final String TIM = "Время";
    private final String EML = "Email";
    private String lol = new String(NAT);
    private Pattern p;
    private JCheckBox checkBox = new JCheckBox();
    private Boolean matches = false;
    private Matcher m;


    public Frame() throws HeadlessException {
        setBounds(100, 100, 600, 400);
        setTitle("Regular 1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());
        setContentPane(contentPane);
        list.addItem(NAT);
        list.addItem(INT);
        list.addItem(DBL);
        list.addItem(DAT);
        list.addItem(TIM);
        list.addItem(EML);

        list.addActionListener(e -> {
            StringBuffer str = new StringBuffer(e.getSource().toString());
            str.indexOf("selectedItemReminder=");
            lol = new String(str.substring(str.indexOf("selectedItemReminder=") + 21, str.length() - 1));
        });

        JPanel northPanel = new JPanel();
        northPanel.setLayout(new GridLayout(1,2));
        northPanel.add(checkBox);
        northPanel.add(list);

        checkBox.setIcon(new ImageIcon(getClass().getResource("no.png")));

        textField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                String text = textField.getText();
                switch(lol)
                {
                    case(NAT):
                    {
                        p = Pattern.compile("^([1-9]\\d*)");
                        break;
                    }
                    case(INT):
                    {
                        p = Pattern.compile("^[-+]?([1-9]\\d*)|[0]$");
                        break;
                    }
                    case(DBL):
                    {
                        p = Pattern.compile("^[-+]?([1-9]\\d*)|[0]" +
                                "|([-+]?((\\d*[.]?\\d+)|(\\d+[.]\\d*)))" +
                                "(([eE][-+]?)\\d+)?$");
                        break;
                    }
                    case(DAT):
                    {
                        p = Pattern.compile("^("
                                + "((([0][1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))"
                                + "|" + "((([0][1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0][46])|([1][1])))" + "|"
                                + "((([0-1][1-9])|([1][0])|([2][0-8]))" + "[.]" + "([0][2]))"
                                + ")" + "[.]" + "(\\d+)$");
                        break;
                    }
                    case(TIM):
                    {
                        p = Pattern.compile("^((([0][1-9])|([1][0-2]))[:][0-5][0-9](([A]|[P])[M])?)" +
                                "|((([1][3-9])|([2][0-3]))[:][0-5][0-9])$");
                        break;
                    }
                    case(EML):
                    {
                        p = Pattern.compile("^([a-zA-Z0-9_.+-]+)[@]([a-zA-Z0-9_.+-]+)[.]([a-zA-Z]{2,5})$");
                        break;
                    }
                }
                m = p.matcher(text);
                matches = m.matches();
                if(matches)
                    checkBox.setIcon(new ImageIcon(getClass().getResource("ok.jpg")));
                else
                    checkBox.setIcon(new ImageIcon(getClass().getResource("no.png")));
            }

        });

        contentPane.add(northPanel, BorderLayout.NORTH);
        contentPane.add(textField, BorderLayout.CENTER);

        setVisible(true);
    }
}
