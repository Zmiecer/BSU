package by.bsu.zmiecer;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;
import java.util.Hashtable;

/**
 * Created by Zmiecer on 27.03.2016.
 */
public class Applet extends JApplet {

    @Override
    public void init() {



        JPanel pane = new JPanel();
        PointOnCircle point =  new PointOnCircle();

        JSlider slider = new JSlider(JSlider.HORIZONTAL,0,50,15);
        Hashtable labelTable = new Hashtable();
        labelTable.put( new Integer( 0 ), new JLabel("Stop") );
        labelTable.put( new Integer( 15 ), new JLabel("Slow") );
        labelTable.put( new Integer( 50 ), new JLabel("Fast") );
        slider.setLabelTable( labelTable );
        slider.setPaintLabels(true);
        slider.addChangeListener(e -> {
            int speed;
            JSlider source = (JSlider)e.getSource();
            speed = source.getValue();
            point.setSpeed(speed);
        });

        DefaultListModel<String> model = new DefaultListModel<>();
        model.addElement("Right");
        model.addElement("Left");
        JList list = new JList(model);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.setSelectedIndex(0);
        list.addListSelectionListener(e -> {
            if(list.getSelectedIndex() == 0)
            {
                point.setRight(true);
            }
            else
            {
                point.setRight(false);
            }
        });

        pane.add(slider);
        pane.add(list);

        add(point, BorderLayout.CENTER);
        add(pane, BorderLayout.NORTH);
    }
}
