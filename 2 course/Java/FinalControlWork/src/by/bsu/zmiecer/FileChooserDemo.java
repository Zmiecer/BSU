package by.bsu.zmiecer;

import com.sun.org.apache.bcel.internal.generic.NEW;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Created by Zmiecer on 20.12.2015.
 */

public class FileChooserDemo extends JPanel implements ActionListener
{
    JButton openButton, addButton, buttonClear, buttonEditors;
    JFileChooser fc;
    File file = null;
    JTable table = null;

    ArrayList<Newspaper> newspapers = new ArrayList<>();
    ArrayList<Magazine> magazines = new ArrayList<>();

    final String[] columnNames = {"Name",
            "Editor",
            "Number of pages",
            "Type"};

    public FileChooserDemo() {
        super(new BorderLayout());

        fc = new JFileChooser("papers");
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Text Files", "txt");
        fc.setFileFilter(filter);

        openButton = new JButton("Open a File...");
        openButton.addActionListener(this);

        addButton = new JButton("Enter an editor");
        addButton.addActionListener(e ->
        {
            JDialog dialog = new JDialog();

            dialog.setModal(true);

            JLabel labelEditor = new JLabel(" Editor");
            JTextField fieldEditor = new JTextField(20);

            JPanel dialogPanel = new JPanel();
            dialogPanel.setLayout(new GridLayout(10, 1));

            JButton buttonOk = new JButton("OK");
            buttonOk.addActionListener(ee ->
            {
                try {
                    String enteredEditor = fieldEditor.getText();
                    update(false, enteredEditor);
                    dialog.setVisible(false);
                }
                catch (NumberFormatException ex)
                {
                    System.out.println("Please, enter correct data!");
                }
            });
            JButton buttonCancel = new JButton("Cancel");
            buttonCancel.addActionListener(ee -> dialog.setVisible(false));

            JPanel buttonDialogPanel = new JPanel();
            buttonDialogPanel.add(buttonOk);
            buttonDialogPanel.add(buttonCancel);

            dialogPanel.add(labelEditor);
            dialogPanel.add(fieldEditor);
            dialogPanel.add(buttonDialogPanel);

            dialog.setBounds(150, 150, 200, 350);

            dialog.setContentPane(dialogPanel);
            dialog.setVisible(true);

            dialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        });

        buttonClear = new JButton("Clear");

        buttonClear.addActionListener(e->update(false, null));

        buttonEditors = new JButton("Editors");
        buttonEditors.addActionListener(e->
        {
            JDialog dialog = new JDialog();

            dialog.setModal(true);

            DefaultListModel model = new DefaultListModel();
            for (int i = 0; i < newspapers.size(); i++)
            {
                model.add(i, newspapers.get(i).getEditor());
            }
            JList editorList = new JList(model);

            JPanel dialogPanel = new JPanel();
            dialogPanel.setLayout(new GridLayout(10, 1));


            dialog.setBounds(150, 150, 200, 350);

            dialogPanel.setLayout(new BorderLayout());

            JButton buttonOk = new JButton("OK");
            buttonOk.addActionListener(ee -> dialog.setVisible(false));

            dialogPanel.add(editorList, BorderLayout.CENTER);
            dialogPanel.add(buttonOk, BorderLayout.SOUTH);

            dialog.setContentPane(dialogPanel);
            dialog.setVisible(true);

            dialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(openButton);
        buttonPanel.add(addButton);
        buttonPanel.add(buttonClear);
        buttonPanel.add(buttonEditors);
        add(buttonPanel, BorderLayout.PAGE_START);

    }

    public void update(boolean toScan, String enteredEditor)
    {
        try {
            if(toScan) {
                Scanner preScan = new Scanner(file);
                String temp = null;
                String preName;
                if (preScan.hasNext())
                    preName = preScan.next();
                String preEditor;
                if (preScan.hasNext())
                        preEditor = preScan.next();
                int preNumberOfPages;
                if (preScan.hasNextInt())
                    preNumberOfPages = preScan.nextInt();
                if (preScan.hasNext())
                        temp = preScan.next();
                preScan.close();
                boolean paper;
                if (temp.equals("black/white") || temp.equals("colored"))
                    paper = true;
                else
                if (temp.equals("glyanz") || temp.equals("simple"))
                    paper = false;
                else
                    throw new InputMismatchException();


                Scanner scanner = new Scanner(file);
                if (paper)
                    while (scanner.hasNextLine()) {
                        if (scanner.hasNext()) {
                        String name = scanner.next();
                        String editor = scanner.next();
                        int numberOfPages = scanner.nextInt();
                        String coloring = scanner.next();
                        if (!coloring.equals("black/white") && !coloring.equals("colored"))
                            throw new InputMismatchException();
                        Newspaper newspaper = new Newspaper(name, editor, numberOfPages, coloring);
                        newspapers.add(newspaper);
                    } else
                        break;
                }
                else
                    if (!paper)
                        while (scanner.hasNextLine()) {
                            if (scanner.hasNext()) {
                                String name = scanner.next();
                                String editor = scanner.next();
                                int numberOfPages = scanner.nextInt();
                                String coloring = scanner.next();
                                if (!coloring.equals("glyanz") && !coloring.equals("simple"))
                                    throw new InputMismatchException();
                                Newspaper newspaper = new Newspaper(name, editor, numberOfPages, coloring);
                                newspapers.add(newspaper);
                            } else
                                break;
                        }
                else
                        throw new InputMismatchException();
            }


            ArrayList<Newspaper> tempNewspapers = new ArrayList<>();

            for (Newspaper newspaper : newspapers) {
                if(enteredEditor == null)
                    tempNewspapers.add(newspaper);
                else
                if(newspaper.getEditor().equals(enteredEditor))
                    tempNewspapers.add(newspaper);
            }


            Collections.sort(newspapers);
            Collections.sort(tempNewspapers);
            //newspapers.sort();

            Object [][] data = new Object[tempNewspapers.size()][5];


            int i = 0;
            for (Newspaper newspaper : tempNewspapers) {
                data[i][0] = newspaper.getName();
                data[i][1] = newspaper.getEditor();
                data[i][2] = newspaper.getNumberOfPages();
                data[i][3] = newspaper.getColoring();
                i++;
            }

            table = new JTable(data, columnNames);
            this.removeAll();
            JScrollPane scrollpane = new JScrollPane(table);
            add(scrollpane, BorderLayout.CENTER);

            JPanel buttonPanel = new JPanel();
            buttonPanel.add(openButton);
            buttonPanel.add(addButton);
            buttonPanel.add(buttonClear);
            buttonPanel.add(buttonEditors);
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


    public void actionPerformed(ActionEvent e)
    {
        int returnVal = fc.showOpenDialog(FileChooserDemo.this);

        if (returnVal == JFileChooser.APPROVE_OPTION)
        {
            file = fc.getSelectedFile();
            newspapers.clear();
            update(true, null);
        }
    }

    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Papers");
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