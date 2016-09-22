package by.bsu.zmiecer.audio;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

/**
 * Created by Zmiecer on 17.05.2016.
 */
public class AudioThread  implements Runnable{
    @Override
    public void run() {
        try {
            javazoom.jl.player.Player p = new Player(new FileInputStream("highway.mp3"));
            p.play();
        } catch (FileNotFoundException|JavaLayerException e) {
            e.printStackTrace();
        }
    }
}
