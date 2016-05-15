package by.bsu.zmiecer.graphics;

import by.bsu.zmiecer.utils.ResourceLoader;

import java.awt.image.BufferedImage;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class TextureAtlas
{
    private BufferedImage image;

    public TextureAtlas(String imageName)
    {
        image = ResourceLoader.loadImage(imageName);
    }

    public BufferedImage cut(int x, int y, int width, int height)
    {
        return image.getSubimage(x, y, width, height);
    }
}
