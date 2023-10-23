#pragma once

class Student {
	public:
	    // Constructor
	    Student(const char* name, const char *faculty, int study_year);

	    // Destructor
	    ~Student();
	    
 	    Student(const Student& copy);
	    void SetStudyYear(int year); 	
	   
	    void PrintStudentInfo();

	private:
	    char* name;
	    char* faculty;
	    int study_year;
};


