/*
 * Copyright (c) 1995, 2008, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Oracle or the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */ 

package by.bsu.zmiecer;

/*
 * This code is based on an example provided by Richard Stanford, 
 * a tutorial reader.
 */

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.tree.DefaultMutableTreeNode;

public class DynamicTreeDemo extends JPanel 
                             implements ActionListener {
    private int newNodeSuffix = 1;
    private static String ADD_COMMAND = "add";
    private static String REMOVE_COMMAND = "remove";
    private static String CLEAR_COMMAND = "clear";
    
    private DynamicTree treePanel;

    private Map<String, Map<String, Set<String>>> map = new HashMap();

    File file;

    public DynamicTreeDemo() {
        super(new BorderLayout());
        
        //Create the components.
        treePanel = new DynamicTree();


        JButton addButton = new JButton("Add");
        addButton.setActionCommand(ADD_COMMAND);
        addButton.addActionListener(this);
        
        JButton removeButton = new JButton("Remove");
        removeButton.setActionCommand(REMOVE_COMMAND);
        removeButton.addActionListener(this);
        
        JButton clearButton = new JButton("Clear");
        clearButton.setActionCommand(CLEAR_COMMAND);
        clearButton.addActionListener(this);

        JButton openFileButton = new JButton("Open");
        openFileButton.addActionListener(e -> {
            JFileChooser chooser = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter(
                    "Text files", "txt");
            chooser.setFileFilter(filter);
            chooser.setCurrentDirectory(new File("C:\\Users\\Дмитрий\\Документы\\GitHub\\BSU\\2 course\\Practical Training\\Week 4\\Task43"));
            int returnVal = chooser.showOpenDialog(getParent());
            if(returnVal == JFileChooser.APPROVE_OPTION) {
                file = new File(chooser.getSelectedFile().getPath());
                treePanel.clear();
                map.clear();
                populateTree("");
            }
        });

        JButton editButton = new JButton("Edit");
        editButton.addActionListener(e1 -> {
            try {
                JDialog editDialog = new JDialog();
                editDialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                editDialog.setBounds(150, 150, 300, 200);
                JPanel panel = new JPanel();
                panel.setLayout(new GridLayout(8, 1));

                JTextField fieldCourse = new JTextField();
                JLabel labelCourse = new JLabel("Course:");
                JTextField fieldGroup = new JTextField();
                JLabel labelGroup = new JLabel("Group:");
                JTextField fieldName = new JTextField();
                JLabel labelName = new JLabel("Name:");
                fieldCourse.setText(treePanel.getSelectionPath().toString().substring(18, 19));
                fieldGroup.setText(treePanel.getSelectionPath().toString().substring(27, 28));
                fieldName.setText(treePanel.getSelectionPath().toString().substring(30, treePanel.getSelectionPath().toString().length() - 1));
                int course = Integer.parseInt(treePanel.getSelectionPath().toString().substring(18, 19));
                int group = Integer.parseInt(treePanel.getSelectionPath().toString().substring(27, 28));
                map.get("Course " + course).get("Group " + group).remove(treePanel.getSelectionPath().toString().substring(30, treePanel.getSelectionPath().toString().length() - 1));

                JButton okButton = new JButton("OK");
                okButton.addActionListener(e2 -> {
                    StringBuffer str = new StringBuffer();
                    str.append(fieldCourse.getText());
                    str.append(' ');
                    str.append(fieldGroup.getText());
                    str.append(' ');
                    str.append(fieldName.getText());
                    populateTree(str.toString());
                    editDialog.setVisible(false);
                });
                JButton cancelButton = new JButton("Cancel");
                cancelButton.addActionListener(e3 -> {
                    editDialog.setVisible(false);
                });

                panel.add(labelCourse);
                panel.add(fieldCourse);
                panel.add(labelGroup);
                panel.add(fieldGroup);
                panel.add(labelName);
                panel.add(fieldName);
                panel.add(okButton);
                panel.add(cancelButton);
                editDialog.setContentPane(panel);
                editDialog.setVisible(true);
            }
            catch (NullPointerException e)
            {
                JOptionPane.showMessageDialog(this, "Choose element to edit!");
            }
            catch (StringIndexOutOfBoundsException e)
            {
                JOptionPane.showMessageDialog(this, "Choose the student!");
            }

        });




        //Lay everything out.
        treePanel.setPreferredSize(new Dimension(600, 400));
        add(treePanel, BorderLayout.CENTER);

        JPanel panel = new JPanel(new GridLayout(0,4));
        panel.add(addButton);
        panel.add(removeButton);
        panel.add(editButton);
        //panel.add(clearButton);
        panel.add(openFileButton);
	    add(panel, BorderLayout.SOUTH);
    }

    public void populateTree(String str) {



        try {
            //file = new File("input1.txt");
            treePanel.clear();

            Scanner sc;
            if (str.equals(""))
                sc = new Scanner(file);
            else
            {
                sc = new Scanner(str);
            }

            while (sc.hasNext()) {
                int i;
                if (sc.hasNextInt())
                    i = sc.nextInt();
                else throw new InputMismatchException();
                int j;
                if (sc.hasNextInt())
                    j = sc.nextInt();
                else throw new InputMismatchException();
                String tmpSurname;
                if (sc.hasNext())
                    tmpSurname = sc.next();
                else throw new InputMismatchException();
                String name;
                if (sc.hasNext())
                    name = sc.next();
                else throw new InputMismatchException();
                String patronymic;
                if (sc.hasNext())
                    patronymic = sc.next();
                else throw new InputMismatchException();

                String surname = new String(tmpSurname + ' ' + name + ' ' + patronymic);
                try {
                    map.get("Course " + i).get("Group " + j).add(surname);
                } catch (NullPointerException e) {
                    try {
                        Set<String> names = new HashSet<>();
                        names.add(surname);
                        map.get("Course " + i).put("Group " + j, names);
                    } catch (NullPointerException ee) {
                        Map<String, Set<String>> course = new HashMap();
                        Set<String> names = new HashSet<>();
                        names.add(surname);
                        course.put(new String("Group " + j), names);
                        map.put(new String("Course " + i), course);
                    }

                }
            }
        }
        catch (FileNotFoundException e)
        {
            JOptionPane.showMessageDialog(this, "File not found!");
        }
        catch (InputMismatchException e)
        {
            JOptionPane.showMessageDialog(this, "Enter correct data!");
        }

        for (Map.Entry<String, Map<String, Set<String>>> entry: map.entrySet())
        {
            DefaultMutableTreeNode node = treePanel.addObject(null, entry.getKey());
            for (Map.Entry<String, Set<String>> entryIn : entry.getValue().entrySet())
            {
                DefaultMutableTreeNode leaf = treePanel.addObject(node, entryIn.getKey());
                for (String fio : entryIn.getValue())
                {
                    treePanel.addObject(leaf, fio);
                }
            }
        }



    }
    
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        
        if (ADD_COMMAND.equals(command)) {
            //Add button clicked
            treePanel.addObject("New Node " + newNodeSuffix++);
        } else if (REMOVE_COMMAND.equals(command)) {
            //Remove button clicked
            treePanel.removeCurrentNode();
        } else if (CLEAR_COMMAND.equals(command)) {
            //Clear button clicked.
            treePanel.clear();
        }
    }

    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("Students");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(100,100,600,400);
        //Create and set up the content pane.
        DynamicTreeDemo newContentPane = new DynamicTreeDemo();
        newContentPane.setOpaque(true); //content panes must be opaque
        frame.setContentPane(newContentPane);

        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}
