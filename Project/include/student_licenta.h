#pragma once
#include "student.h"

namespace University{

	class StudentLicenta : public Student{
		public:
		    // Constructor
		    StudentLicenta(const char* name, const char *faculty, int study_year);
		    // Destructor
		    ~StudentLicenta();
		    //Copy Constructor
	 	    StudentLicenta(const StudentLicenta& copy); 	    
		    StudentLicenta(StudentLicenta&& move); 
		    StudentLicenta& operator=(const StudentLicenta& other);
		    StudentLicenta& operator=(StudentLicenta&& move) noexcept;
		    void SetStudyYear(int year) override; 	   
		    void PrintStudentInfo() const override;
		    void SetName(const char* name) override; 

		private:
		    char* name;
		    char* faculty;
		    int study_year;
	};

}
