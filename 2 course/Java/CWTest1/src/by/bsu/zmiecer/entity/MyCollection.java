package by.bsu.zmiecer.entity;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

/**
 * Created by Zmiecer on 25.11.2015.
 */
public class MyCollection <T extends Comparable <T>> extends ArrayList <T>
{
    public T minimum()
    {
        T min = this.get(0);
        //for(T i: this)
        //{
        //    if (min.compareTo(i) < 0)
        //        min = i;
        //}

        for(Iterator<T> iter = this.iterator(); iter.hasNext();)
            if (iter.hasNext() && min.compareTo(iter.next()) < 0)
                min = iter.next();
        //return min;

        return (T)Collections.min(this);
    }

    public T maximum()
    {

        return (T)Collections.max(this);
    }

    public MyCollection<T> sort()
    {
        MyCollection<T> temp = (MyCollection<T>) (this.clone());
        Collections.sort(temp);
        return temp;
    }

    public static void main(String[] args) {
        MyCollection<Student> test = new MyCollection<>();

        test.add(new Student("Zvedosovich", 18, 7.0));
        test.add(new Student("Bylinovich", 19, 7.0));

        MyCollection<Student> test2 = new MyCollection<>();
        test.sort();
        System.out.println(test.minimum());
     }
}
