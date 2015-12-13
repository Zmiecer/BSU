package by.bsu.zmiecer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class PupilCollection<T extends Pupil> extends ArrayList<T> {

    public T min()
    {
        return Collections.min(this);
    }

    public PupilCollection sort() throws NoSuchElementException
    {
        if(this.size() <= 0)
        {
            NoSuchElementException e = new NoSuchElementException("There are no elements in your collection!");
            throw e;
        }

        PupilCollection temp = (PupilCollection) (this.clone());
        Collections.sort(temp);
        return temp;
    }

    public void printInf() throws NoSuchElementException
    {
        if(this.size() <= 0)
        {
            NoSuchElementException e = new NoSuchElementException("There are no elements in your collection!");
            throw e;
        }

        for(Iterator<T> iter = this.iterator(); iter.hasNext();)
           System.out.println(iter.next());
    }

    public int binarySearch(T t) throws NoSuchElementException
    {
        if(this.size() <= 0)
        {
            NoSuchElementException e = new NoSuchElementException("There are no elements in your collection!");
            throw e;
        }
        return Collections.binarySearch(this, t);
    }

    public int frequency(T t) throws NoSuchElementException
    {
        if(this.size() <= 0)
        {
            NoSuchElementException e = new NoSuchElementException("There are no elements in your collection!");
            throw e;
        }

        return Collections.frequency(this, t);
    }
}
