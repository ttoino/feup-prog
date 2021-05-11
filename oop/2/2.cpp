#include <string>
#include <cmath>
#include <iostream>
#include <vector>

class Student
{
public:
    Student();
    Student(const std::string &code, const std::string &name);
    void setGrades(double shortExam, double project, double exam);
    std::string getCode() const;
    std::string getName() const;
    int getFinalGrade() const;
    double getShortExamGrade() const;
    double getProjectGrade() const;
    double getExamGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    // weights in percentage
    static constexpr int weightShortExam = 20,
                         weightProject = 30,
                         weightExam = 50;

private:
    std::string code;                // student code
    std::string name;                // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

// a)
void Student::setGrades(double shortExam, double project, double exam)
{
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;

    finalGrade = round((shortExam * weightShortExam + project * weightProject + exam * weightExam) / 100);
}

// b)
Student::Student() {}

Student::Student(const std::string &code, const std::string &name)
{
    this->code = code;
    this->name = name;
}

std::string Student::getCode() const
{
    return code;
}

std::string Student::getName() const
{
    return name;
}

int Student::getFinalGrade() const
{
    return finalGrade;
}

double Student::getShortExamGrade() const
{
    return shortExam;
}

double Student::getProjectGrade() const
{
    return project;
}

double Student::getExamGrade() const
{
    return exam;
}

bool Student::isApproved() const
{
    return finalGrade >= 10;
}

// c)
Student readStudentData()
{
    std::string code, name;
    double shortExam, project, exam;

    std::cout << "Student code: ";
    std::getline(std::cin, code);

    std::cout << "Student name: ";
    std::getline(std::cin, name);

    std::cout << "Short exam grade: ";
    std::cin >> shortExam;

    std::cout << "Project grade: ";
    std::cin >> project;

    std::cout << "Exam grade: ";
    std::cin >> exam;

    Student student(code, name);
    student.setGrades(shortExam, project, exam);
    return student;
}

// d)
void showAboveAverageStudents(std::ostream &out, const std::vector<Student> &students)
{
    int sum;
    for (const Student student : students)
        sum += student.getFinalGrade();
    double average = (double)sum / students.size();

    for (const Student student : students)
        if (student.getFinalGrade() > average)
            out << student.getCode() << "\t"
                << student.getName() << "\t"
                << student.getShortExamGrade() << "\t"
                << student.getProjectGrade() << "\t"
                << student.getExamGrade() << "\n";
}

// e)
int main()
{
    std::vector<Student> students{};

    while (true)
    {
        Student student{readStudentData()};

        if (std::cin.fail())
            break;

        students.push_back(student);
    }

    showAboveAverageStudents(std::cout, students);
}
