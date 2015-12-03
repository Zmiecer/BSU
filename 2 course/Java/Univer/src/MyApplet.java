import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * Created by Zmiecer on 29.11.2015.
 */


public class MyApplet extends JApplet implements MouseMotionListener, MouseListener, KeyListener
{
    StringBuffer str = new StringBuffer("OK");
    JButton button = new JButton(str.toString());
    JPanel panel = new JPanel();



    @Override
    public void init() {
        button.setBounds(0, 0, 100, 30);
        panel.setLayout(null);
        panel.add(button);
        this.add(panel);


        addMouseMotionListener(this);
        addMouseListener(this);
        button.addKeyListener(this);
        button.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                showStatus("(" + (e.getX() + button.getX()) + "," + (e.getY() + button.getY()) + ")");
            }
        });

    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        showStatus("(" + e.getX() + "," + e.getY() + ")");
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        showStatus("(" + e.getX() + "," + e.getY() + ")");
        if(e.isControlDown())
        {
            button.setBounds(e.getX(), e.getY(), 100, 30);
        }
    }

    @Override
    public void mouseEntered(MouseEvent e) {
    }

    @Override
    public void mouseExited(MouseEvent e) {
        showStatus("Cursor left applet area");
    }

    @Override
    public void mousePressed(MouseEvent e) {
    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        button.setBounds(e.getX(), e.getY(), 100, 30);
    }

    @Override
    public void keyTyped(KeyEvent e) {
        if (e.getKeyChar() != 8) {
            str.append(e.getKeyChar());
            button.setText(str.toString());
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (button.getText().length() > 0 && e.getKeyChar() == 8)
        {
            str.deleteCharAt(str.length() - 1);
            button.setText(str.toString());
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
    }
}