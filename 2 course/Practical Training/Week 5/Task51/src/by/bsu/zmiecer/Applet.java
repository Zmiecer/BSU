package by.bsu.zmiecer;

import javax.swing.*;

/**
 * Created by Zmiecer on 27.03.2016.
 */
public class Applet extends JApplet {
    @Override
    public void init() {
        MyPanel panel = new MyPanel();

        Timer timer = new Timer(1000, e -> {
            int time = panel.getLineCoord();
            time+=1;
            time%=60;
            panel.setLineCoord(time);
            panel.repaint();
        });
        timer.start();
        this.add(panel);
    }
}
