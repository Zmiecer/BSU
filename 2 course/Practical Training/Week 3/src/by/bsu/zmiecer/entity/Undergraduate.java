package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 28.02.16.
 */
public class Undergraduate extends Student {
    Academic tutor;

    public Undergraduate(String name, String login, String email, Academic tutor) {
        super(name, login, email);
        this.tutor = tutor;
    }

    public Academic getTutor() {
        return tutor;
    }

    public void setTutor(Academic tutor) {
        this.tutor = tutor;
    }

    @Override
    public String toString() {
        return super.toString() + " Tutor: " + tutor.getName();
    }
}
