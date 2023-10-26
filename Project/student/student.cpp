#include "student.h"
#include <iostream>
#include <cstring>

// Constructor
Student::Student(const char* name, const char *faculty, int study_year){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->faculty = new char[strlen(faculty) + 1];
    strcpy(this->faculty, faculty);
    this->study_year = study_year;
    std::cout << "Student has been registered." << std::endl;
}

// Destructor
Student::~Student() {
    delete[] this->name;
    delete[] this->faculty;
    std::cout << "Student information has been deleted." << std::endl;
}

//Copy Constructor
Student::Student(const Student& copy){
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
    this->faculty = new char[strlen(copy.faculty) + 1];
    strcpy(this->faculty, copy.faculty);
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
    this->faculty = move.faculty;
    this->study_year = move.study_year;
    
    move.name = nullptr;
    move.faculty = nullptr;
    move.study_year = 0;
    std::cout << "I am move constructor." << std::endl;
}

void Student::PrintStudentInfo(){
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", Faculty: " << this->faculty << ", Study year: "<< this->study_year << std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}








