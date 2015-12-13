package by.bsu.zmiecer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class TreeCollection<T extends Tree> extends ArrayList<T> {

    public T min()
    {
        return Collections.min(this);
    }

    public T max()
    {
        return Collections.max(this);
    }

    public TreeCollection sort()
    {
        TreeCollection temp = (TreeCollection) (this.clone());
        Collections.sort(temp);
        return temp;
    }

    public void printInf()
    {
        for(Iterator<T> iter = this.iterator(); iter.hasNext();)
           System.out.println(iter.next());
    }

    public int binarySearch(T t){
        return Collections.binarySearch(this, t);
    }

    public int frequency(T t)
    {
        return Collections.frequency(this, t);
    }
}
