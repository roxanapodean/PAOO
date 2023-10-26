#pragma once

class Student {
	public:
	    // Constructor
	    Student(const char* name, const char *faculty, int study_year);
	    // Destructor
	    ~Student();
	    //Copy Constructor
 	    Student(const Student& copy); 	    
	    void SetStudyYear(int year); 	   
	    void PrintStudentInfo();
	    void SetName(const char* name); 
	    Student(Student&& move); 

	private:
	    char* name;
	    char* faculty;
	    int study_year;
};


