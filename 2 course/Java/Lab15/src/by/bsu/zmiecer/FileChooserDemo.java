package by.bsu.zmiecer;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.SwingUtilities;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 * Created by Zmiecer on 20.12.2015.
 */

public class FileChooserDemo extends JPanel implements ActionListener
{
    JButton openButton, addButton, groupButton, clearButton;
    JFileChooser fc;
    File file = null;
    JTable table = null;
    int tempGroup = -1;

    StudentCollection students = new StudentCollection();
    //ArrayList<Student> students = new ArrayList<>();
    final String[] columnNames = {"Number",
            "Surname",
            "Course",
            "Group"};

    public FileChooserDemo() {
        super(new BorderLayout());

        fc = new JFileChooser("students");
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Text Files", "txt");
        fc.setFileFilter(filter);

        openButton = new JButton("Open a File...");
        openButton.addActionListener(this);

        addButton = new JButton("Add an item");
        addButton.addActionListener(e ->
        {
            JDialog dialog = new JDialog();

            dialog.setModal(true);

            JLabel labelNumber = new JLabel(" Number");
            JTextField fieldNumber = new JTextField(10);
            JLabel labelSurname = new JLabel(" Surname");
            JTextField fieldSurname = new JTextField(20);
            JLabel labelCourse = new JLabel(" Course");
            JTextField fieldCourse = new JTextField(1);
            JLabel labelGroup = new JLabel(" Group");
            JTextField fieldGroup = new JTextField(2);

            JPanel dialogPanel = new JPanel();
            dialogPanel.setLayout(new GridLayout(10, 1));

            JButton buttonOk = new JButton("OK");
            buttonOk.addActionListener(ee ->
            {
                try {
                    if(fieldSurname.getText().equals(""))
                        throw new NumberFormatException();
                    students.add(new Student(
                            Integer.parseInt(fieldNumber.getText()),
                            fieldSurname.getText(),
                            Integer.parseInt(fieldCourse.getText()),
                            Integer.parseInt(fieldGroup.getText())));
                    update(false);
                    dialog.setVisible(false);
                }
                catch (NumberFormatException ex)
                {
                    JOptionPane.showMessageDialog(null, "Please, enter correct data!");
                    //System.out.println("Please, enter correct data!");
                }
            });
            JButton buttonCancel = new JButton("Cancel");
            buttonCancel.addActionListener(ee -> dialog.setVisible(false));

            JPanel buttonDialogPanel = new JPanel();
            buttonDialogPanel.add(buttonOk);
            buttonDialogPanel.add(buttonCancel);

            dialogPanel.add(labelNumber);
            dialogPanel.add(fieldNumber);
            dialogPanel.add(labelSurname);
            dialogPanel.add(fieldSurname);
            dialogPanel.add(labelCourse);
            dialogPanel.add(fieldCourse);
            dialogPanel.add(labelGroup);
            dialogPanel.add(fieldGroup);
            dialogPanel.add(buttonDialogPanel);

            dialog.setBounds(150, 150, 200, 350);

            dialog.setContentPane(dialogPanel);
            dialog.setVisible(true);

            dialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        });

        groupButton = new JButton("Group");
        groupButton.addActionListener(e->
        {
            JDialog dialog = new JDialog();

            dialog.setModal(true);

            JLabel labelGroup = new JLabel(" Group");
            JTextField fieldGroup = new JTextField(2);

            JPanel dialogPanel = new JPanel();
            dialogPanel.setLayout(new GridLayout(10, 1));

            JButton buttonOk = new JButton("OK");
            buttonOk.addActionListener(ee ->
            {
                try {
                    tempGroup = Integer.parseInt(fieldGroup.getText());
                    if (tempGroup <= 0)
                        throw new NumberFormatException();
                    update(false);
                    dialog.setVisible(false);
                }
                catch (NumberFormatException ex)
                {
                    JOptionPane.showMessageDialog(null, "Please, enter correct data!");
                    //System.out.println("Please, enter correct data!");
                }
            });



            JButton buttonCancel = new JButton("Cancel");
            buttonCancel.addActionListener(ee -> dialog.setVisible(false));

            JPanel buttonDialogPanel = new JPanel();
            buttonDialogPanel.add(buttonOk);
            buttonDialogPanel.add(buttonCancel);

            dialogPanel.add(labelGroup);
            dialogPanel.add(fieldGroup);
            dialogPanel.add(buttonDialogPanel);

            dialog.setBounds(150, 150, 200, 350);

            dialog.setContentPane(dialogPanel);
            dialog.setVisible(true);

            dialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        });

        clearButton = new JButton("Clear");
        clearButton.addActionListener(e->{
            tempGroup = 0;
            update(false);
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(openButton);
        buttonPanel.add(addButton);
        buttonPanel.add(groupButton);
        buttonPanel.add(clearButton);
        add(buttonPanel, BorderLayout.PAGE_START);

    }

    public void update(boolean toScan)
    {
        try {
            if(toScan) {
                Scanner scanner = new Scanner(file);
                while (scanner.hasNextLine()) {
                    if (scanner.hasNext()) {
                        int number = scanner.nextInt();
                        String surname = scanner.next();
                        int course = scanner.nextInt();
                        int group = scanner.nextInt();
                        Student student = new Student(number, surname, course, group);
                        students.add(student);
                    } else
                        break;
                }
            }

            //Collections.sort(students);
            students.sort();
            StudentCollection tempStudents = new StudentCollection();
            if (tempGroup > 0)
                for (Student student:students) {
                    if(tempGroup == student.getGroup())
                     tempStudents.add(student);
                }
            else
                tempStudents = students;

            Object [][] data = new Object[tempStudents.size()][5];


            int i = 0;
            for (Student student : tempStudents) {
                data[i][0] = student.getNumber();
                data[i][1] = student.getSurname();
                data[i][2] = student.getCourse();
                data[i][3] = student.getGroup();
                i++;
            }

            table = new JTable(data, columnNames);
            table.setEnabled(false);
            this.removeAll();
            JScrollPane scrollpane = new JScrollPane(table);
            add(scrollpane, BorderLayout.CENTER);

            JPanel buttonPanel = new JPanel();
            buttonPanel.add(openButton);
            buttonPanel.add(addButton);
            buttonPanel.add(groupButton);
            buttonPanel.add(clearButton);
            add(buttonPanel, BorderLayout.PAGE_START);
            revalidate();

        }
        catch (FileNotFoundException ex)
        {
            JOptionPane.showMessageDialog(null, "File not found!");
            //System.out.println("File not found!");
        }
        catch (InputMismatchException ex)
        {
            JOptionPane.showMessageDialog(null, "Please, enter correct data!");
            //System.out.println("Please, enter correct data!");
        }
        catch (NoSuchElementException ex)
        {
            JOptionPane.showMessageDialog(null, "No such element exception!");
            //System.out.println("No such element exception!");
        }
        catch (NullPointerException ex)
        {
            JOptionPane.showMessageDialog(null, "Null pointer exception!");
            //System.out.println("Null pointer exception!");
        }
    }


    public void actionPerformed(ActionEvent e)
    {
        int returnVal = fc.showOpenDialog(FileChooserDemo.this);

        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            file = fc.getSelectedFile();
            students.clear();
            update(true);
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

        }
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }
}