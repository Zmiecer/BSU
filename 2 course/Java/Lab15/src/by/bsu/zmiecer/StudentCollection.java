package by.bsu.zmiecer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class StudentCollection<T extends Student> extends ArrayList<T> {

    public StudentCollection sort() throws NoSuchElementException
    {
        if(this.size() <= 0)
        {
            NoSuchElementException e = new NoSuchElementException("There are no elements in your collection!");
            throw e;
        }

        StudentCollection temp = (StudentCollection) (this.clone());
        Collections.sort(temp);
        return temp;
    }
}
