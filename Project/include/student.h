#pragma once
#include "person.h"
#include<pthread.h>
#include<mutex>
#include<semaphore.h>


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
		    void LocuriLaborator();
		    
		    
		     

		protected:
		    
		    char* name;
		    char* specializare;
		    int study_year;
		private:
		    static int locuri_libere;
		    static char studenti[15][100];
		    static std::mutex lock;
		    static sem_t semafor;
		    static bool initialized;
		    static int instanceCount;
		    static void *SeteazaLocuriLaborator(void* arg);
	};

}
