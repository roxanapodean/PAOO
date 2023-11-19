#pragma once
#include "student.h"

using namespace stud;

namespace studM{

	class StudentMaster : public Student{
		public:
		    // Constructor
		    StudentMaster(const char* name, const char *specializare, int study_year, int nota_licenta);	 
		    StudentMaster(const StudentMaster& copy);
		    StudentMaster(StudentMaster&& move);
		    void PrintStudentInfo() const override;
		    void SetNotaLicenta(int nota_licenta);

		private:
		    int nota_licenta;
	};

}
