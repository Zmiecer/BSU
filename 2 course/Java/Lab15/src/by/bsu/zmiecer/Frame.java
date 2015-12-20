package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Created by Zmiecer on 20.12.2015.
 */

public class Frame extends JFrame
{
    JFileChooser fc;

    public Frame(String s) {
        super(s);
        setBounds(100, 100, 640, 480);

        String[] columnNames = {"Number",
                "Surname",
                "Course",
                "Group"};

        StudentCollection<Student> students = new StudentCollection<>();
        try
        {
            Scanner scanner = new Scanner(new File("students1.txt"));
            while (scanner.hasNextLine())
            {
                if(scanner.hasNext()) {
                    int number = scanner.nextInt();
                    String surname = scanner.next();
                    int course = scanner.nextInt();
                    int group = scanner.nextInt();
                    Student student = new Student(number, surname, course, group);
                    students.add(student);
                }
                else
                    break;
            }

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }
        catch (InputMismatchException e)
        {
            System.out.println("Please, enter correct data!");
        }
        catch (NoSuchElementException e)
        {
            System.out.println("No such element exception!");
        }

        students = students.sort();

        Object [][] data = new Object[students.size()][5];
        for (int i = 0; i < students.size(); i++) {
            data[i][0] = students.get(i).getNumber();
            data[i][1] = students.get(i).getSurname();
            data[i][2] = students.get(i).getCourse();
            data[i][3] = students.get(i).getGroup();
        }




        JButton openButton = new JButton("Open file...");


        JTable table = new JTable(data, columnNames);
        JScrollPane scrollpane = new JScrollPane(table);
        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(scrollpane, BorderLayout.CENTER);
        contentPane.add(openButton, BorderLayout.SOUTH);
        setContentPane(contentPane);

        openButton.addActionListener(e ->
        {
            //int returnVal = fc.showOpenDialog();
        });


        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
