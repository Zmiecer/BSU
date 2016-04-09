package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Zmiecer on 29.03.2016.
 */
public class Frame extends JFrame {
    public Frame() throws HeadlessException {
        setBounds(100, 100, 600, 400);
        setTitle("Regular 2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextArea area = new JTextArea();
        area.setText("05.04.2016 я сделал почти все лабы по программмированию. 04.11.1996 я родился. Ура-ура!");

        DefaultListModel model = new DefaultListModel();


        JButton button = new JButton("GO!");

        JList list = new JList(model);

        button.addActionListener(e -> {
            String text;
            model.removeAllElements();
            text = area.getText();
            //Pattern p = Pattern.compile("(((([0][1-9])|([1-2][0-9])|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))" + "|" + "((([0][1-9])|([1-2][0-9])|([3][0]))" + "[.]" + "(([0][246])|([1][1]))))" + "[.]" + "([0-9]+)");
            //Pattern p = Pattern.compile("(" + "((([0][1-9])|([1-2][0-9])|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))" + "|" + "((([0][1-9])|([1-2][0-9])|([3][0]))" + "[.]" + "(([0][46])|([1][1])))" + "|" + "((([0][1-9])|([1-2][0-8]))" + "[.]" + "([0][2]))" + ")" + "[.]" + "([0-9]+)");
            Pattern p = Pattern.compile("("
                    + "((([0][1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))"
                    + "|" + "((([0][1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0][46])|([1][1])))" + "|"
                    + "((([0][1-9])|([1-2][0-8]))" + "[.]" + "([0][2]))"
                    + ")" + "[.]" + "(\\d+)");
            // 135781012
            Matcher m = p.matcher(text);
            if(text.isEmpty())
            {
                JOptionPane.showMessageDialog(null, "Enter the data!");
            }
            //System.out.println(text);
            while(m.find())
            {
                String string;
                string = m.group();
                model.addElement(string);
                //System.out.println(string);
            }
        });



        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(button, BorderLayout.NORTH);
        contentPane.add(area, BorderLayout.CENTER);
        contentPane.add(list, BorderLayout.SOUTH);
        setContentPane(contentPane);


        setVisible(true);
    }
}
