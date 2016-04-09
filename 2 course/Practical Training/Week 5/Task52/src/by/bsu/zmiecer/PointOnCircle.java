package by.bsu.zmiecer;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.image.BufferedImage;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;

/**
 * Created by Zmiecer on 27.03.2016.
 */


public class PointOnCircle extends JComponent {
    private double angle;
    private int speed;
    private boolean right = true;


    BufferedImage image;

    public PointOnCircle() {
        URL imageURL = getClass().getResource("/star.png");
        try {
            image = ImageIO.read(imageURL);
        } catch (IOException e) {
            e.printStackTrace();
        }

        angle = 0;
        speed = 15;
        Timer timer = new Timer(30, e -> {
            if (right) {
                angle += speed / 100.0;
            }
            else
            {
                angle -= speed / 100.0;
            }
            repaint();
        });
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        int width = getWidth();
        int height = getHeight();
        g.setColor(Color.white);
        g.fillRect(0, 0, width, height);
        g.setColor(Color.blue);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(3f));
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        double x = 0.5 * width;
        double y = 0.5 * height;
        double r = 0.75 * Math.min(x, y);
        g2d.draw(circle(x, y, r));
        g2d.setColor(Color.red);
        x += r * Math.cos(angle);
        y += r * Math.sin(angle);


        /*Red moving blob
        r = Math.max(0.1 * r, 5);
        g2d.fill(circle(x, y, r));
        */





        g2d.drawImage(image, (int)x - 25, (int)y - 25, this);

    }


    private Shape circle(double x, double y, double r) {
        return new Ellipse2D.Double(x - r, y - r, 2 * r, 2 * r);
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setRight(boolean right) {
        this.right = right;
    }
}
