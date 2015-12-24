package by.bsu.zmiecer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Created by Zmiecer on 23.12.2015.
 */

public class StudentCollection extends ArrayList<Student> {
        public class StudentComparator implements Comparator<Student>
        {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.getNumber() - o2.getNumber();
            }
        }


    public void sort() {
        Collections.sort(this, new StudentComparator());
    }
}
