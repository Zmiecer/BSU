package by.bsu.zmiecer.graphics;

import java.awt.image.BufferedImage;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class SpriteSheet
{
    private BufferedImage   sheet;
    private int             spriteCount;
    private int             scale;          // Размер одного спрайта в пикселях
    private int             spritesInWidth;

    public SpriteSheet(BufferedImage sheet, int spriteCount, int scale)
    {
        this.sheet = sheet;
        this.spriteCount = spriteCount;
        this.scale = scale;

        this.spritesInWidth = sheet.getWidth() / scale;
    }

    public BufferedImage getSpite(int index)
    {
        index = index % spriteCount;

        int x = (index % spritesInWidth) * scale;
        int y = (index / spritesInWidth) * scale;


        return sheet.getSubimage(x, y, scale, scale);
    }
}
