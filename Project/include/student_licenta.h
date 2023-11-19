#pragma once
#include "student.h"

using namespace stud;

namespace studL{

	class StudentLicenta : public Student{
		public:
		    // Constructor
		    StudentLicenta(const char* name, const char *specializare, int study_year);	 	   
		    void PrintStudentInfo() const override;
		    
	};

}
