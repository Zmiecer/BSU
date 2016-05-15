package by.bsu.zmiecer;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;

/**
 * Created by Zmiecer on 27.03.2016.
 */

class ImageRenderer extends DefaultTableCellRenderer {
    JLabel lbl = new JLabel();

    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected,
                                                   boolean hasFocus, int row, int column) {
        ImageIcon imageIcon;
        try {
            imageIcon = new ImageIcon(getClass().getResource("/images/flag_" + (String) value + ".png"));
            lbl.setText((String) value);
        }
        catch (NullPointerException e)
        {
            imageIcon = new ImageIcon(getClass().getResource("/images/flag_earth.png"));
            lbl.setText("Earth");
        }
        lbl.setIcon(imageIcon);
        return lbl;
    }
}