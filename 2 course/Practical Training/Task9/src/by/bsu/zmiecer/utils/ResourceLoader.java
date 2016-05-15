package by.bsu.zmiecer.utils;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class ResourceLoader
{
    public static final String PATH = "res/";

    public static BufferedImage loadImage(String fileName)
    {
        BufferedImage image = null;

        try
        {
            image = ImageIO.read(new File(PATH + fileName));
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        return image;
    }
}
