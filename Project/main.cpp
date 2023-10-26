#include <iostream>
#include<string>
#include "student.h"

int main() {
    Student student1("Podean Roxana-Andreea", "AC", 4);
    Student student2("Popescu Andrei", "ETC", 2);
    Student student3("Ionescu Ana", "AC", 1);
    
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    std::cout << "Student 2:" << std::endl;
    student2.PrintStudentInfo();
    std::cout << "Student 3:" << std::endl;
    student3.PrintStudentInfo();
    
    
    Student student4 = student2;
    student4.SetName("Dumitrescu Maria");
    
    std::cout << "Student 4:" << std::endl;
    student4.PrintStudentInfo();
    
    student2.SetStudyYear(3);
    std::cout << "Student 2, study year changed:" << std::endl;
    student2.PrintStudentInfo();
    
    Student student5 = Student(std::move(student1));
    student5.PrintStudentInfo();
    
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();

    return 0;
}







