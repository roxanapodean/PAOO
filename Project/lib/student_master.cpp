#include "student_master.h"
#include <iostream>
#include <cstring>

using namespace University;

// Constructor
StudentMaster::StudentMaster(const char* name, const char *specializare, int study_year, int nota_licenta){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->study_year = study_year;
    this->nota_licenta = nota_licenta;
    std::cout << "StudentMaster has been registered." << std::endl;
}

// Destructor
StudentMaster::~StudentMaster() {
    delete[] this->name;
    delete[] this->specializare;
    std::cout << "StudentMaster information has been deleted." << std::endl;
}

//Copy Constructor
StudentMaster::StudentMaster(const StudentMaster& copy){
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
    this->specializare = new char[strlen(copy.specializare) + 1];
    strcpy(this->specializare, copy.specializare);
    this->study_year = copy.study_year;
    this->nota_licenta = copy.nota_licenta;
    std::cout << "I am copy constructor." << std::endl;
}

//change year of study
void StudentMaster::SetStudyYear(int year) {
    this->study_year = year;
}

//change name
void StudentMaster::SetName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Move Constructor
StudentMaster::StudentMaster(StudentMaster&& move) {
	
    this->name = move.name;
    this->specializare = move.specializare;
    this->study_year = move.study_year;
    this->nota_licenta = move.nota_licenta;
    
    move.name = nullptr;
    move.specializare = nullptr;
    move.study_year = 0;
    move.nota_licenta = 0;
    std::cout << "I am move constructor." << std::endl;
}

// Copy Assignment Operator
StudentMaster& StudentMaster::operator=(const StudentMaster& other) {
    if (this == &other) 
	return *this;
    

    // Deallocate the current buffer
    delete[] this->name;
    delete[] this->specializare;


    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->specializare = new char[strlen(other.specializare) + 1];
    strcpy(this->specializare, other.specializare);
    this->study_year = other.study_year;
    this->nota_licenta = other.nota_licenta;

    return *this;
}

// Move Assignment Operator
StudentMaster& StudentMaster::operator=(StudentMaster&& move) noexcept {
    if (this != &move) {
	    
	    delete[] this->name;
	    delete[] this->specializare;

	    this->name = move.name;
	    this->specializare = move.specializare;
	    this->study_year = move.study_year;
	    this->nota_licenta = move.nota_licenta;

	    move.name = nullptr;
	    move.specializare = nullptr;
	    move.study_year = 0;
	    move.nota_licenta = 0;
    }
	
    return *this;
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








