#include "student.h"
#include <iostream>
#include <cstring>
#include <pthread.h>
#include <mutex>
#include <unistd.h>
#include <semaphore.h>

using namespace stud;
std::mutex laboratorMutex;
int Student::locuri_libere=5;
char Student::studenti[15][100];
sem_t Student::semafor;   
bool Student::initialized = false;
int Student::instanceCount = 0; 

// Constructor
Student::Student(const char* name, const char *specializare, int study_year){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->study_year = study_year;
    if (!initialized) {
        if (sem_init(&semafor, 0, 5) == -1) {
            perror("sem_init");
            exit(EXIT_FAILURE);
        }
        initialized = true;
    }
    ++instanceCount;
       
}

// Destructor
Student::~Student() {
    delete[] this->name;
    delete[] this->specializare;
    //std::cout << "Student information has been deleted." << std::endl;
    --instanceCount;

    if (instanceCount == 0) {
        if (sem_destroy(&semafor) == -1) {
            perror("sem_destroy");
            exit(EXIT_FAILURE);
        }
        initialized = false; 
    }
}

//Copy Constructor
Student::Student(const Student& copy){
    this->name = new char[strlen(copy.name) + 1];
    strcpy(this->name, copy.name);
    this->specializare = new char[strlen(copy.specializare) + 1];
    strcpy(this->specializare, copy.specializare);
    this->study_year = copy.study_year;
    //std::cout << "I am copy constructor." << std::endl;
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
    //std::cout << "I am move constructor." << std::endl;
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

void Student::LocuriLaborator(){
	pthread_t t;
	pthread_create(&t, NULL, SeteazaLocuriLaborator, this);
}

void* Student::SeteazaLocuriLaborator(void* arg){
    Student* student = (Student*) arg;
    
    if (sem_wait(&semafor) == -1) {
            perror("sem_wait");
            exit(EXIT_FAILURE);
    }
    
    laboratorMutex.lock();
    
    if (locuri_libere > 0) {   	
	strcpy((char*)studenti[5-(int)locuri_libere], student->name);
	locuri_libere--;
	printf("%s a ocupat un loc in laborator. Locuri libere: %d\n", student->name, locuri_libere);
    }
    
    std::cout<<"Studentii existenti:"<<std::endl;
    for(int i = 0; i < 5-locuri_libere; i ++)
    	std::cout<<studenti[i]<<std::endl; 
      
    laboratorMutex.unlock();
    
    int random = std::rand() % 5000000;
    int index = -1;
    
    usleep(random);
    
    laboratorMutex.lock();
    
    for(int i = 0; i < 5-locuri_libere; i ++){	
    	if(strcmp(studenti[i], student->name)==0){
    		index = i;
    		break;
    	}
    } 
    
    if(index != -1){
    	for(int i = index; i < 5-locuri_libere; i++){
    		strcpy(studenti[i], studenti[i + 1]);
    	}
    	printf("Studentul '%s' a fost sters.\n", student->name);
    }
        
    locuri_libere++;
    
    laboratorMutex.unlock();
    if (sem_post(&semafor) == -1) {
            perror("sem_post");
            exit(EXIT_FAILURE);
    }
    
    return NULL;

}

void Student::PrintStudentInfo() const{
    
    if(this->name != NULL) 
    	std::cout << "Name: " << this->name << ", specializare: " << this->specializare << std::endl;
    else
    	std::cout << "NULL" <<std::endl;
}








