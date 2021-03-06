package by.bsu.zmiecer;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

/**
 * Created by Zmiecer on 27.03.2016.
 */
public class TourFrame extends JFrame {
    public TourFrame() throws HeadlessException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setBounds(100, 100, 800, 400);
        setTitle("Tours");

        String[] columnNames = {"Country", "Description", "Price", "Check"};
        Object[][] data =
                {
                        {"Australia", "Amazing tour to the other side of the Globe", 4800, false},
                        {"Brazil", "Enjoy the brazilian carnival", 3510, false},
                        {"Ukraine", "Look on beautiful views of Carpatas", 875, false},
                        {"Thailand", "Here ypu can easily find whatever tou want of don't want", 2940, false},
                        {"India", "Discover the hostory of thousands Indian gods", 2315, false},
                        {"Japan", "Take alook on unique island culture", 4175, false},
                        {"Norway", "Fjords, rotten fish, bork", 3310, false},
                        {"Sweden", "Bork, bork, bork", 3220, false},
                };
        DefaultTableModel model = new DefaultTableModel(data, columnNames);



        JTable table = new JTable( model )
        {
            //  Returning the Class of each column will allow different
            //  renderers to be used based on Class
            public Class getColumnClass(int column)
            {
                switch (column) {
                    case (0): {
                        return String.class;
                    }
                    case (1): {
                        return String.class;
                    }
                    case (2): {
                        return Integer.class;
                    }
                    case (3): {
                        return Boolean.class;
                    }
                    default:
                    {
                        return String.class;
                    }
                }
            }
        };
        for (int i = 0; i < table.getColumnCount(); i++) {
            table.getColumnModel().getColumn(i).setCellRenderer(new ImageRenderer());
        }
        table.setPreferredScrollableViewportSize(table.getPreferredSize());
        table.getColumnModel().getColumn(0).setCellRenderer(new ImageRenderer());
        table.setRowHeight(48);
        table.getColumnModel().getColumn(1).setPreferredWidth(200);

        JButton buttonAdd = new JButton("Add");
        buttonAdd.addActionListener(e -> model.addRow(new Object[]{"Earth", "Description", 0, false}));


        JLabel labelPrice = new JLabel("Total price: 0");

        table.addPropertyChangeListener(evt -> {
            int price = 0;
            for (int i = 0; i < model.getRowCount(); i++) {
                if((boolean)model.getValueAt(i,3) == true)
                {
                    price += (int)model.getValueAt(i,2);
                }
            }
            labelPrice.setText(new String("Total price: " + price));
        });



        JScrollPane scrollPane = new JScrollPane(table);
        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(scrollPane, BorderLayout.CENTER);
        contentPane.add(buttonAdd, BorderLayout.NORTH);
        contentPane.add(labelPrice, BorderLayout.SOUTH);
        setContentPane(contentPane);

        setVisible(true);
    }
}
