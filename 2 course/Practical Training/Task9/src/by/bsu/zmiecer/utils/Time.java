package by.bsu.zmiecer.utils;

/**
 * Created by Zmiecer on 06.05.2016.
 */
public class Time {
    public static final long SECOND = 1000000000L;


    public static long get()
    {
        return System.nanoTime();
    }
}
