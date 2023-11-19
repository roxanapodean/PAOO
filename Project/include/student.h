#pragma once
#include "person.h"

using namespace pers;

namespace stud{

	class Student : public Person{
		public:
		    // Constructor
		    Student(const char* name, const char *specializare, int study_year);
		    // Destructor
		    ~Student();
		    //Copy Constructor
	 	    Student(const Student& copy); 	    
		    Student(Student&& move); 
		    Student& operator=(const Student& other);
		    Student& operator=(Student&& move) noexcept;
		    void SetStudyYear(int year) override; 	   
		    virtual void PrintStudentInfo() const;
		    void SetName(const char* name) override; 

		
		    char* name;
		    char* specializare;
		    int study_year;
	};

}
