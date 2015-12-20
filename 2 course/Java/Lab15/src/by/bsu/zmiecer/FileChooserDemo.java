package by.bsu.zmiecer;


import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.SwingUtilities;
import javax.swing.filechooser.*;

/**
 * Created by Zmiecer on 20.12.2015.
 */

public class FileChooserDemo extends JPanel
        implements ActionListener {
    JButton openButton, saveButton;
    JFileChooser fc;
    File file = null;


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

        saveButton = new JButton("Save a File...");
        saveButton.addActionListener(this);

        //For layout purposes, put the buttons in a separate panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(openButton);
        buttonPanel.add(saveButton);

        //Add the buttons and the log to this panel.
        add(buttonPanel, BorderLayout.PAGE_START);

        updateUI();

    }


    @Override
    public void updateUI() {
        super.updateUI();
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


            JTable table = new JTable(data, columnNames);

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
        catch (NullPointerException e)
        {
            System.out.println();
        }


    }

    public void actionPerformed(ActionEvent e) {

        //Handle open button action.
        if (e.getSource() == openButton) {
            int returnVal = fc.showOpenDialog(FileChooserDemo.this);

            if (returnVal == JFileChooser.APPROVE_OPTION) {
                file = fc.getSelectedFile();
                updateUI();
            }
        }
        //Handle save button action.
        else if (e.getSource() == saveButton) {
            int returnVal = fc.showSaveDialog(FileChooserDemo.this);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                file = fc.getSelectedFile();
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

        UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }
}