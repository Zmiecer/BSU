package by.bsu.zmiecer.entity;

import java.util.Set;

/**
 * Created by Zmiecer on 28.02.16.
 */

public class Notifier<T extends Notifiable> {

    Set<T> notifiables;

    public Notifier(Set<T> notifiables) {
        this.notifiables = notifiables;
    }

    public void doNotifyAll(String message)
    {
        for (T object: notifiables)
        {
            //Student student = (Student) object;
            object.notify(message);
        }
    }
}
