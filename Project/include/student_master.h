#pragma once
#include "student.h"

namespace University{

	class StudentMaster : public Student{
		public:
		    // Constructor
		    StudentMaster(const char* name, const char *specializare, int study_year, int nota_licenta);
		    // Destructor
		    ~StudentMaster();
		    //Copy Constructor
	 	    StudentMaster(const StudentMaster& copy); 	    
		    StudentMaster(StudentMaster&& move); 
		    StudentMaster& operator=(const StudentMaster& other);
		    StudentMaster& operator=(StudentMaster&& move) noexcept;
		    void SetStudyYear(int year) override; 	   
		    void PrintStudentInfo() const override;
		    void SetName(const char* name) override; 
		    void SetNotaLicenta(int nota_licenta);

		private:
		    char* name;
		    char* specializare;
		    int study_year;
		    int nota_licenta;
	};

}
