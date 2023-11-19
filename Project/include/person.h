#pragma once

namespace pers{
	class Person {
		public:
		    // Funcție pur virtuală pentru afișarea informațiilor
		    //virtual void PrintStudentInfo() const = 0;

		    // Funcție pur virtuală 
		    virtual void SetStudyYear(int year) = 0; 
		    
		    //Functie pur virtuala
		    virtual void SetName(const char* name) = 0; 
		
	};
}
