/** 
 * 
 * Static function: can access only static members/ static properties. It does not have access to this pointer.
 * 
 **/

class Student {
	static int totalStudents;		// total number of students present

	public :

	int rollNumber;
	int age;


	Student() {
		totalStudents++;
	}

	int getRollNumber() {
		return rollNumber;
	}

	static int getTotalStudent() {
		return totalStudents;
	}
	
};

int Student :: totalStudents = 0;	// initialze static data members


