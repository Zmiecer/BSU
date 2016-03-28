package by.bsu.zmiecer;

import javax.swing.*;
import java.awt.*;

/**
 * Created by Zmiecer on 27.03.2016.
 */
class MyPanel extends JPanel {
    MyPanel() { setPreferredSize(new Dimension(200, 200)); }

    private int lineCoord = 0;

    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        g.drawOval(0, 0, 100, 100);
        double cos = Math.cos(6*lineCoord*2*Math.PI/360 - Math.PI/2);
        double sin = Math.sin(6*lineCoord*2*Math.PI/360 - Math.PI/2);
        int x1 = 50 + (int) (50 * cos);
        int y1 = 50 + (int) (50 * sin);
        g.drawLine(50,50,x1,y1);
    }

    public void setLineCoord(int lineCoord) {
        this.lineCoord = lineCoord;
    }

    public int getLineCoord() {
        return lineCoord;
    }
}
