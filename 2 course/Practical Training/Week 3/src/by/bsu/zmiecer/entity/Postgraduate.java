package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 28.02.16.
 */
public class Postgraduate extends Student {
    Academic supervisor;

    public Postgraduate(String name, String login, String email, Academic supervisor) {
        super(name, login, email);
        this.supervisor = supervisor;
    }

    public Academic getSupervisor() {
        return supervisor;
    }

    public void setSupervisor(Academic supervisor) {
        this.supervisor = supervisor;
    }

    @Override
    public String toString() {
        return super.toString() + " Supervisor: " + supervisor.getName();
    }
}
