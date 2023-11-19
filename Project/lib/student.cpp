#include "student.h"
#include <iostream>
#include <cstring>

using namespace stud;

// Constructor
Student::Student(const char* name, const char *specializare, int study_year){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->study_year = study_year;
    
}

// Destructor
Student::~Student() {
    delete[] this->name;
    delete[] this->specializare;
    std::cout << "Student information has been deleted." << std::endl;
}

//Copy Constructor
Student::Student(const Student& copy){
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
    this->specializare = new char[strlen(copy.specializare) + 1];
    strcpy(this->specializare, copy.specializare);
    this->study_year = copy.study_year;
    std::cout << "I am copy constructor." << std::endl;
}

//change year of study
void Student::SetStudyYear(int year) {
    this->study_year = year;
}

//change name
void Student::SetName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Move Constructor
Student::Student(Student&& move) {
	
    this->name = move.name;
    this->specializare = move.specializare;
    this->study_year = move.study_year;
    
    move.name = nullptr;
    move.specializare = nullptr;
    move.study_year = 0;
    std::cout << "I am move constructor." << std::endl;
}

// Copy Assignment Operator
Student& Student::operator=(const Student& other) {
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


    return *this;
}

// Move Assignment Operator
Student& Student::operator=(Student&& move) noexcept {
    if (this != &move) {
	    
	    delete[] this->name;
	    delete[] this->specializare;

	    this->name = move.name;
	    this->specializare = move.specializare;
	    this->study_year = move.study_year;

	    move.name = nullptr;
	    move.specializare = nullptr;
	    move.study_year = 0;
    }
	
    return *this;
}

void Student::PrintStudentInfo() const{
    
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", specializare: " << this->specializare << std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}








