package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 28.02.16.
 */
public class Student extends Person implements Notifiable {
    String login;
    String email;

    public Student(String name, String login, String email) {
        super(name);
        this.login = login;
        this.email = email;
    }

    public String getLogin() {
        return login;
    }

    public String getEmail() {
        return email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public void notify(String message) {
        System.out.println(email + " got the message '" + message + "'!");
    }

    @Override
    public String toString() {
        return super.toString() + " Login: " + login + " Email: " + email;
    }
}
