package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Zmiecer on 15.03.16.
 */
public class CountryFrame extends JFrame {
    public CountryFrame() throws HeadlessException {
        setBounds(100, 100, 600, 400);
        setTitle("Countries");


        Map<String, String> countries = new HashMap<>();

        countries.put("Albania", "Tirana");
        countries.put("Australia", "Canberra");
        countries.put("Azerbaijan", "Baku");
        countries.put("Belarus", "Minsk");
        countries.put("Brazil", "Brazilia");
        countries.put("Bulgaria", "Sofia");
        countries.put("Canada", "Toronto");
        countries.put("China", "Beijing");
        countries.put("Cuba", "Havana");
        countries.put("Cyprus", "Nicosia");
        countries.put("Denmark", "Copenhagen");
        countries.put("Egypt", "Cairo");
        countries.put("France", "Paris");
        countries.put("Germany", "Berlin");
        countries.put("Israel", "Jerusalem");
        countries.put("Ireland", "Dublin");
        countries.put("Spain", "Madrid");
        countries.put("Ukraine", "Kyiv");
        countries.put("USA", "Washington");


        DefaultListModel<Map.Entry<String, String>> listModel = new DefaultListModel<>();
        for (Map.Entry<String, String> entry : countries.entrySet())
        {
            listModel.addElement(entry);
        }
        JList countryList = new JList(listModel);
        countryList.setFixedCellWidth(400);
        countryList.setCellRenderer(new CountryRenderer());


        JScrollPane panel = new JScrollPane(countryList);
        setContentPane(panel);
        //panel.add(countryList);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
