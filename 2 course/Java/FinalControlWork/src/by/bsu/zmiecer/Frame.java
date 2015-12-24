package by.bsu.zmiecer;

import javafx.stage.FileChooser;

import javax.swing.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Created by Zmiecer on 23.12.2015.
 */
public class Frame extends JFrame {

    FileChooser fc = new FileChooser();

    Frame(String s)
    {
        super(s);
        JPanel contentPane = new JPanel();

        ArrayList<Newspaper> newspapers = new ArrayList<>();
        ArrayList<Magazine> magazines = new ArrayList<>();

        /*class Panel extends JPanel {
            protected void init() {
                JButton openButton = new JButton("Open");
                openButton.addActionListener(e -> {
                    try {
                        int returnVal = fc.showOpenDialog(Panel.this);

                        if (returnVal == JFileChooser.APPROVE_OPTION) {
                            File fileOpen = fc.getSelectedFile();


                            Scanner sc = new Scanner(fileOpen);
                            newspapers.clear();
                            while (sc.hasNextLine()) {
                                if (sc.hasNext()) {

                                } else break;
                            }
                            repaint();
                            sc.close();
                        }
                    } catch (IOException ex) {
                        System.out.println("Invalid object exception!");
                    } catch (NoSuchElementException ex) {
                        System.out.println("No such element exception!");
                    }
                });
            }
        }*/

        setContentPane(contentPane);

    }
}
