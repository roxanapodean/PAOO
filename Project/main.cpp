#include <iostream>
#include<string>
#include "student_licenta.h"
//#include "student_master.h"
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <mutex>
#include<memory>
#include<semaphore.h>

using namespace studL;
//using namespace studM;
using namespace stud;
//codul comentat face perte din tema1+tema2

int main() {
    
    StudentLicenta student1("Podean Roxana-Andreea", "AC", 4);
    StudentLicenta student2("Popescu Andrei", "ETC", 2);
    StudentLicenta student3("Ionescu Ana", "AC", 1);
    /*
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    std::cout << "Student 2:" << std::endl;
    student2.PrintStudentInfo();
    std::cout << "Student 3:" << std::endl;
    student3.PrintStudentInfo();
    */
    
    StudentLicenta student4 = student2;
    student4.SetName("Dumitrescu Maria");
    /*
    std::cout << "Student 4:" << std::endl;
    student4.PrintStudentInfo();
    */
    student2.SetStudyYear(3);
    /*
    std::cout << "Student 2, study year changed:" << std::endl;
    student2.PrintStudentInfo();
    */
    StudentLicenta student5 = StudentLicenta(std::move(student1));
    //student5.PrintStudentInfo();
    /*
    std::cout << "Student 1:" << std::endl;
    student1.PrintStudentInfo();
    */
    StudentLicenta student6("Maria", "AC", 1);
    student6 = student2;
    /*
    std::cout << "Student 6:" << std::endl;
    student6.PrintStudentInfo();
    */	
    // Atribuire prin mutare
    student3 = std::move(student5);
    /*
    std::cout << "Student 3:" << std::endl;
    student3.PrintStudentInfo();
    */
    //StudentMaster studentMaster("Iliescu Alina", "SS", 2, 10);
    /*
    std::cout << "student Master:" << std::endl;
    studentMaster.PrintStudentInfo();
    */
    StudentLicenta studentA("studentA", "AC", 3);
    StudentLicenta studentB("studentB", "AC", 3);
    StudentLicenta studentC("studentC", "AC", 3);
    StudentLicenta studentD("studentD", "AC", 3);
    
    student3.LocuriLaborator();
    student4.LocuriLaborator();
    student2.LocuriLaborator();
    studentA.LocuriLaborator();
    studentB.LocuriLaborator();
    studentC.LocuriLaborator();
    studentD.LocuriLaborator();
    
    sleep(10);
    
    std::shared_ptr <Student> sp1;
    std::weak_ptr <Student> wp1;
    std::weak_ptr <Student> wp2;
    
    {
        std::shared_ptr <Student> sp2;

        sp1 = std::make_shared <Student> ("Matei Ana", "ETC", 2);

        wp1 = sp1;
        sp2 =sp1;

        sp1->PrintStudentInfo();
        sp1.reset();

        sp2->PrintStudentInfo();


        if(std::shared_ptr <Student> tempSharedPtr = wp1.lock()) {
            std::cout<<"Weak pointer"<<std::endl;
            tempSharedPtr->PrintStudentInfo();
        }
        else {
            std::cout<<"Weak pointer not valid"<<std::endl;
        }
    }
    
    if(std::shared_ptr <Student> tempSharedPtr = wp1.lock()) {
            std::cout<<"Weak pointer"<<std::endl;
            tempSharedPtr->PrintStudentInfo();
    }
    else {
            std::cout<<"Weak pointer not valid"<<std::endl;
    }
    
    
    return 0;
}







