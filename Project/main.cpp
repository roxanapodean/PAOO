#include <iostream>
#include<string>
#include "student_licenta.h"
#include "student_master.h"

using namespace University;

int main() {
    StudentLicenta student1("Podean Roxana-Andreea", "AC", 4);
    StudentLicenta student2("Popescu Andrei", "ETC", 2);
    StudentLicenta student3("Ionescu Ana", "AC", 1);
    
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    std::cout << "Student 2:" << std::endl;
    student2.PrintStudentInfo();
    std::cout << "Student 3:" << std::endl;
    student3.PrintStudentInfo();
    
    
    StudentLicenta student4 = student2;
    student4.SetName("Dumitrescu Maria");
    
    std::cout << "Student 4:" << std::endl;
    student4.PrintStudentInfo();
    
    student2.SetStudyYear(3);
    std::cout << "Student 2, study year changed:" << std::endl;
    student2.PrintStudentInfo();
    
    StudentLicenta student5 = StudentLicenta(std::move(student1));
    student5.PrintStudentInfo();
    
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    
    StudentLicenta student6("Maria", "AC", 1);
    student6 = student2;
    
    std::cout << "Student 6:" << std::endl;
    student6.PrintStudentInfo();
	
    // Atribuire prin mutare
    student3 = std::move(student5);
    std::cout << "Student 3:" << std::endl;
    student3.PrintStudentInfo();
    
    StudentMaster studentMaster("Iliescu Alina", "SS", 2, 10);
    std::cout << "student Master:" << std::endl;
    studentMaster.PrintStudentInfo();
    
    return 0;
}







