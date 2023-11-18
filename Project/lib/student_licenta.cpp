#include "student_licenta.h"
#include <iostream>
#include <cstring>

using namespace University;

// Constructor
StudentLicenta::StudentLicenta(const char* name, const char *faculty, int study_year){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->faculty = new char[strlen(faculty) + 1];
    strcpy(this->faculty, faculty);
    this->study_year = study_year;
    std::cout << "StudentLicenta has been registered." << std::endl;
}

// Destructor
StudentLicenta::~StudentLicenta() {
    delete[] this->name;
    delete[] this->faculty;
    std::cout << "StudentLicenta information has been deleted." << std::endl;
}

//Copy Constructor
StudentLicenta::StudentLicenta(const StudentLicenta& copy){
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
    this->faculty = new char[strlen(copy.faculty) + 1];
    strcpy(this->faculty, copy.faculty);
    this->study_year = copy.study_year;
    std::cout << "I am copy constructor." << std::endl;
}

//change year of study
void StudentLicenta::SetStudyYear(int year) {
    this->study_year = year;
}

//change name
void StudentLicenta::SetName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Move Constructor
StudentLicenta::StudentLicenta(StudentLicenta&& move) {
	
    this->name = move.name;
    this->faculty = move.faculty;
    this->study_year = move.study_year;
    
    move.name = nullptr;
    move.faculty = nullptr;
    move.study_year = 0;
    std::cout << "I am move constructor." << std::endl;
}

// Copy Assignment Operator
StudentLicenta& StudentLicenta::operator=(const StudentLicenta& other) {
    if (this == &other) 
	return *this;
    

    // Deallocate the current buffer
    delete[] this->name;
    delete[] this->faculty;


    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->faculty = new char[strlen(other.faculty) + 1];
    strcpy(this->faculty, other.faculty);
    this->study_year = other.study_year;


    return *this;
}

// Move Assignment Operator
StudentLicenta& StudentLicenta::operator=(StudentLicenta&& move) noexcept {
    if (this != &move) {
	    
	    delete[] this->name;
	    delete[] this->faculty;

	    this->name = move.name;
	    this->faculty = move.faculty;
	    this->study_year = move.study_year;

	    move.name = nullptr;
	    move.faculty = nullptr;
	    move.study_year = 0;
    }
	
    return *this;
}

void StudentLicenta::PrintStudentInfo() const{
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", Faculty: " << this->faculty << ", Study year: "<< this->study_year << std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}








