#include <iostream>
#include<string>
#include "student.h"

int main() {
    Student student1("Podean Roxana-Andreea", "AC", 4);
    Student student2("Popescu Andrei", "ETC", 2);
    Student student3("Ionescu Ana", "AC", 1);
    
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    
    
    Student student4 = student2;
    student4.SetStudyYear(3);
    
    std::cout << "Student 4:" << std::endl;
    student4.PrintStudentInfo();
    std::cout << "Student 2:" << std::endl;
    student2.PrintStudentInfo();
    

    return 0;
}







