package by.bsu.zmiecer.graphics;

import java.awt.*;
import java.awt.image.BufferedImage;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class Sprite
{
    private SpriteSheet sheet;
    private float scale;        // Масштаб

    public Sprite(SpriteSheet sheet, float scale)
    {
        this.sheet = sheet;
        this.scale = scale;

    }
    int t = 0;

    public void render(Graphics2D g, float x, float y, boolean moving)
    {
        BufferedImage image;
        if (moving)
            image = sheet.getSpite(t/10);
        else
            image = sheet.getSpite(0);
        g.drawImage(image, (int)x, (int)y, (int)(image.getWidth()*scale), (int)(image.getHeight()*scale), null);
        t++;
    }
}
