package by.bsu.zmiecer;

import java.awt.*;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by Zmiecer on 16.12.2015.
 */
public class Line {
    int startX;
    int startY;
    int endX;
    int endY;
    Color color;

    public Line(int startX, int startY, int endX, int endY, Color color) {
        this.startX = startX;
        this.startY = startY;
        this.endX = endX;
        this.endY = endY;
        this.color = color;
    }

    public int getStartX() {
        return startX;
    }

    public int getStartY() {
        return startY;
    }

    public int getEndX() {
        return endX;
    }

    public int getEndY() {
        return endY;
    }

    public Color getColor() {
        return color;
    }

    @Override
    public String toString()
    {
        StringBuffer str = new StringBuffer();
        str.append(startX + " " + startY + " " + endX + " " + endY + " " + color.getRed() + " " + color.getGreen() + " " + color.getBlue());
        return str.toString();
    }

    public void write (String fileName) throws IOException
    {
        FileWriter file = new FileWriter(fileName);
        file.write(toString());
        file.close();
    }


}
