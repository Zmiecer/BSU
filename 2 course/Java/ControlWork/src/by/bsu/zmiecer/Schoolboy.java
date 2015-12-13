package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class Schoolboy extends Pupil {
    int classGroup;
    String behavior;

    public Schoolboy(String surname, String institution, double gpa, int classGroup, String behavior) {
        super(surname, institution, gpa);
        this.classGroup = classGroup;
        this.behavior = behavior;
    }

    @Override
    public String toString() {
        return super.toString() + ", class: " + classGroup + ", behavior: " + behavior;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;

        Schoolboy schoolboy = (Schoolboy) o;

        if (classGroup != schoolboy.classGroup) return false;
        return behavior.equals(schoolboy.behavior);

    }

    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + classGroup;
        result = 31 * result + behavior.hashCode();
        return result;
    }
}
