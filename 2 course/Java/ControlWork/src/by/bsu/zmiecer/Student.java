package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class Student extends Pupil {
    int course;

    public Student(String surname, String institution, double gpa, int course) {
        super(surname, institution, gpa);
        this.course = course;
    }

    @Override
    public String toString() {
        return super.toString() + ", course: " + course;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;

        Student student = (Student) o;

        return course == student.course;

    }

    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + course;
        return result;
    }
}
