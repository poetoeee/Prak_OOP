import java.util.HashMap;
import java.util.HashSet;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        this.students = new HashMap<String, Student>();
        this.courses = new HashMap<String, Course>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student student = new Student(studentID, name);
        this.students.put(studentID, student);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course course = new Course(courseID, courseName);
        this.courses.put(courseID, course);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        Student student = this.students.get(studentID);
        Course course = this.courses.get(courseID);

        if (student == null || course == null) {
            System.out.println("Student atau course tidak ditemukan!");
            return;
        }
        student.enrollCourse(courseID);
        course.addStudent(studentID);
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        Student student = this.students.get(studentID);
        if (student == null) {
            System.out.println("Student tidak ditemukan!");
            return;
        }

        HashSet<String> enrolledCourses = student.getEnrolledCourses();
        System.out.println("Student " + student.getName() + " terdaftar di " + enrolledCourses.size() + " course:");
        for (String courseID : enrolledCourses) {
            Course course = this.courses.get(courseID);
            System.out.println(course.getCourseID() + " " + course.getCourseName());
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
       Course course = this.courses.get(courseID);
        if (course == null) {
            System.out.println("Course tidak ditemukan!");
            return;
        }

        HashSet<String> enrolledStudents = course.getEnrolledStudents();
        System.out.println("Course " + course.getCourseName() + " memiliki " + enrolledStudents.size() + " student:");
        for (String studentID : enrolledStudents) {
            Student student = this.students.get(studentID);
            System.out.println(student.getStudentID() + " " + student.getName());
        }
    }
}
