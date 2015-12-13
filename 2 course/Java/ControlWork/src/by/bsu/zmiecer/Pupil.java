package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public abstract class Pupil implements Comparable<Pupil> {
    String surname;
    String institution;
    double gpa;

    public Pupil(String surname, String institution, double gpa) {
        this.surname = surname;
        this.institution = institution;
        this.gpa = gpa;
    }

    @Override
    public String toString()
    {
        StringBuffer str = new StringBuffer("Surname: " + surname + ", institution: " + institution + ", GPA: " + gpa);
        return str.toString();
    }

    @Override
    public int compareTo(Pupil otherPupil) {
        if(!institution.equals(otherPupil.institution))
            return institution.compareTo(otherPupil.institution);
        else
            return surname.compareTo(otherPupil.surname);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pupil pupil = (Pupil) o;

        if (Double.compare(pupil.gpa, gpa) != 0) return false;
        if (!surname.equals(pupil.surname)) return false;
        return institution.equals(pupil.institution);

    }

    @Override
    public int hashCode() {
        int result;
        long temp;
        result = surname.hashCode();
        result = 31 * result + institution.hashCode();
        temp = Double.doubleToLongBits(gpa);
        result = 31 * result + (int) (temp ^ (temp >>> 32));
        return result;
    }
}
