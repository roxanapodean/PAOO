#include "student_licenta.h"
#include "student.h"
#include <iostream>
#include <cstring>

using namespace studL;
using namespace stud;

// Constructor
StudentLicenta::StudentLicenta(const char* name, const char *specializare, int study_year):Student(name, specializare, study_year){
    //std::cout << "StudentLicenta has been registered." << std::endl;
}



void StudentLicenta::PrintStudentInfo() const{
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", specializare: " << this->specializare << ", Study year: "<< this->study_year << std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}








