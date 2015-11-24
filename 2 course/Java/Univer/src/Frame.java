import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public class Frame extends JFrame
{
    public Frame (String s)
    {
        super(s);
        JPanel p = new JPanel();
        setBounds(100, 100, 600, 400);
        setContentPane(p);
        p.setLayout(new BorderLayout());

        JPanel pan1 = new JPanel();
        pan1.setBounds(0, 0, 100, 50);
        p.add(pan1, BorderLayout.SOUTH);


        JPanel pan2 = new JPanel(new GridLayout(0, 1));
        pan2.setBounds(0, 0, 100, 50);
        p.add(pan2, BorderLayout.WEST);

        JLabel label1 = new JLabel("Выберите прогрессию:      ");

        JRadioButton linButton = new JRadioButton("Арифметическая");
        linButton.setSelected(true);

        JRadioButton expButton = new JRadioButton("Геометрическая");

        ButtonGroup group = new ButtonGroup();
        group.add(linButton);
        group.add(expButton);

        pan2.add(label1);
        pan2.add(linButton);
        pan2.add(expButton);

        JTextField editFile = new JTextField();
        editFile.setBounds(100, 100, 100, 100);


        JLabel label2 = new JLabel("Введите имя файла для сохранения вашей прогрессии: ");

        JPanel pan3 = new JPanel(new GridLayout(0, 1));
        pan3.add(label2);
        pan3.add(editFile);
        p.add(pan3, BorderLayout.NORTH);

        JPanel pan4 = new JPanel(new GridLayout(0, 1));
        JLabel labelElem = new JLabel("  Введите основание прогрессии:      ");
        JLabel labelDelta = new JLabel("  Введите знаменатель прогрессии: ");
        JLabel labelLength = new JLabel("  Введите длину прогрессии: ");
        JTextField editElem = new JTextField();
        JTextField editDelta = new JTextField();
        JTextField editLength = new JTextField();
        pan4.add(labelElem);
        pan4.add(editElem);
        pan4.add(labelDelta);
        pan4.add(editDelta);
        pan4.add(labelLength);
        pan4.add(editLength);
        p.add(pan4, BorderLayout.CENTER);


        JButton buttonOk = new JButton("OK");
        JButton buttonClear = new JButton("Clear");
        JButton buttonSave = new JButton("Save");
        JPanel pan5 = new JPanel();
        pan5.setBounds(0, 0, 100, 0);
        pan5.setLayout(new GridLayout(0, 1));
        pan1.add(buttonOk);
        pan1.add(buttonClear);
        pan1.add(buttonSave);


        JLabel labelOut = new JLabel("Результат: ");
        pan4.add(labelOut);
        p.add(pan5, BorderLayout.EAST);


        buttonOk.addActionListener(e -> {
            try {
                if (editElem.getText().length() < 1) {
                    throw new IllegalArgumentException("Введите основание!");
                }
                if (editDelta.getText().length() < 1) {
                    throw new IllegalArgumentException("Введите знаменатель!");
                }
                if (editLength.getText().length() < 1) {
                    throw new IllegalArgumentException("Введите длину!");
                }
                double el = new Double(editElem.getText());
                double del = new Double(editDelta.getText());
                int len = new Integer(editLength.getText());
                if (linButton.isSelected())
                {
                    Linear line = new Linear(el, del, len);
                    labelOut.setText("Результат:   " + line.toString() + "  ");
                }
                else
                    if (expButton.isSelected())
                    {
                        Exponential exp = new Exponential(el, del, len);
                        labelOut.setText("Результат:   " + exp.toString() + "  ");
                    }


            } catch (IllegalArgumentException ee) {
                labelOut.setText("  " + ee.getMessage() + "  ");
            }
        });

        buttonClear.addActionListener(e ->
        {
            labelOut.setText("");
        });

        buttonSave.addActionListener(e -> {
            try {
                if (editFile.getText().length() < 1) {
                    throw new IllegalArgumentException("Введите имя файла!");
                }
                double el = new Double(editElem.getText());
                double del = new Double(editDelta.getText());
                if (linButton.isSelected())
                {
                    Linear line = new Linear(el, del, 10);
                    line.write(editFile.getText() + ".txt");
                }
                else if (expButton.isSelected())
                {
                    Exponential exp = new Exponential(el, del, 10);
                    exp.write(editFile.getText() + ".txt");
                }
            }
            catch (IllegalArgumentException ee) {
                labelOut.setText("  " + ee.getMessage() + "  ");
            }
            catch (IOException ee)
            {
                labelOut.setText("  " + "Invalid file name!" + "  ");
            }
        });


        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);


    }

    public static void main(String[] args)
    {
        Frame frame = new Frame("Прогрессии");
    }
}
