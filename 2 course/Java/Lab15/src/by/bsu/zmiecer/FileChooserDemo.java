package by.bsu.zmiecer;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.SwingUtilities;

/**
 * Created by Zmiecer on 20.12.2015.
 */

public class FileChooserDemo extends JPanel implements ActionListener
{
    JButton openButton, saveButton;
    JFileChooser fc;
    File file = null;
    JTable table = null;

    StudentCollection<Student> students = new StudentCollection<>();
    final String[] columnNames = {"Number",
            "Surname",
            "Course",
            "Group"};

    public FileChooserDemo() {
        super(new BorderLayout());

        fc = new JFileChooser();

        openButton = new JButton("Open a File...");
        openButton.addActionListener(this);

        saveButton = new JButton("Add an item");
        saveButton.addActionListener(e ->
        {
            
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(openButton);
        buttonPanel.add(saveButton);
        add(buttonPanel, BorderLayout.PAGE_START);

    }

    public void actionPerformed(ActionEvent e)
    {
        int returnVal = fc.showOpenDialog(FileChooserDemo.this);

        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            file = fc.getSelectedFile();
            try
            {
                students.clear();
                Scanner scanner = new Scanner(file);
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
                students = students.sort();

                Object [][] data = new Object[students.size()][5];
                for (int i = 0; i < students.size(); i++) {
                    data[i][0] = students.get(i).getNumber();
                    data[i][1] = students.get(i).getSurname();
                    data[i][2] = students.get(i).getCourse();
                    data[i][3] = students.get(i).getGroup();
                }


                table = new JTable(data, columnNames);
                this.removeAll();
                JScrollPane scrollpane = new JScrollPane(table);
                add(scrollpane, BorderLayout.CENTER);

                JPanel buttonPanel = new JPanel();
                buttonPanel.add(openButton);
                buttonPanel.add(saveButton);
                add(buttonPanel, BorderLayout.PAGE_START);
                revalidate();

            }
            catch (FileNotFoundException ex)
            {
                System.out.println("File not found!");
            }
            catch (InputMismatchException ex)
            {
                System.out.println("Please, enter correct data!");
            }
            catch (NoSuchElementException ex)
            {
                System.out.println("No such element exception!");
            }
            catch (NullPointerException ex)
            {
                System.out.println("Null pointer exception!");
            }
        }
    }

    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    private static void createAndShowGUI() {
        JFrame frame = new JFrame("File Chooser");
        frame.setBounds(100,100, 640, 480);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Add content to the window.
        frame.add(new FileChooserDemo());

        //Display the window.
        frame.setVisible(true);
    }

    public static void main(String[] args) throws ClassNotFoundException, UnsupportedLookAndFeelException, InstantiationException, IllegalAccessException {
        //Schedule a job for the event dispatch thread:
        //creating and showing this application's GUI.

        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        }
        finally
        {
            System.out.println("Interface exception!");
        }
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }
}