#include "student_master.h"
#include "student.h"
#include <iostream>
#include <cstring>

using namespace studM;
using namespace stud;

// Constructor
StudentMaster::StudentMaster(const char* name, const char *specializare, int study_year, int nota_licenta):Student(name, specializare, study_year){
    this->nota_licenta = nota_licenta;
    std::cout << "StudentMaster has been registered." << std::endl;
}


//Copy Constructor
StudentMaster::StudentMaster(const StudentMaster& copy):Student(copy){
    this->nota_licenta = copy.nota_licenta;
}

// Move Constructor
StudentMaster::StudentMaster(StudentMaster&& move):Student(move) {
    move.nota_licenta = 0;
}



void StudentMaster::PrintStudentInfo() const{
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", specializare: " << this->specializare << ", Study year: "<< this->study_year << ", Nota licenta:"<< this->nota_licenta<< std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}

void StudentMaster::SetNotaLicenta(int nota_licenta) {
    this->nota_licenta = nota_licenta;
}








