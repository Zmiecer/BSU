package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * Created by Zmiecer on 27.03.2016.
 */

public class CountryRenderer extends JLabel implements ListCellRenderer<Map.Entry<String, String>> {

    private Color foreground;

    @Override
    public Component getListCellRendererComponent(JList<? extends Map.Entry<String, String>> list, Map.Entry<String, String> entry, int index, boolean isSelected, boolean cellHasFocus) {

        String key = entry.getKey();
        String value = entry.getValue();

        ImageIcon imageIcon = new ImageIcon(getClass().getResource("/images/flag_" + key + ".png"));
        setIcon(imageIcon);

        if (isSelected) {
            foreground = Color.BLUE;
            setText(key + " " + value);
        } else {
            foreground = Color.BLACK;
            setText(key);
        }

        setForeground(foreground);


        return this;
    }
}
