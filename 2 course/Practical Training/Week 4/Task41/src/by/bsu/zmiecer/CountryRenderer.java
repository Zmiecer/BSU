package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * Created by Zmiecer on 27.03.2016.
 */
public class CountryRenderer extends JLabel implements ListCellRenderer<Map.Entry<String, String>> {

    @Override
    public Component getListCellRendererComponent(JList<? extends Map.Entry<String, String>> list, Map.Entry<String, String> entry, int index, boolean isSelected, boolean cellHasFocus) {
        String key = entry.getKey();
        String value = entry.getValue();

        ImageIcon imageIcon = new ImageIcon(getClass().getResource("/images/flag_" + key + ".png"));
        setIcon(imageIcon);

        if (isSelected) {
            setText(key + " " + value);
        } else {
            setText(key);
        }

        return this;
    }

}
