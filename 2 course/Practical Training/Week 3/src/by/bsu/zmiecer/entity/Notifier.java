package by.bsu.zmiecer.entity;

import java.util.Set;

/**
 * Created by Zmiecer on 28.02.16.
 */

public class Notifier {

    Set<Object> notifiables;

    public Notifier(Set<Object> notifiables) {
        this.notifiables = notifiables;
    }

    public void doNotifyAll(String message)
    {
        for (Object object: notifiables)
        {
            Student student = (Student) object;
            student.notify(message);
        }
    }
}
