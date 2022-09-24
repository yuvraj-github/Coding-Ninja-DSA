/** 
 * 
 * Shallow copy: copy address of first index of array.
 * 
 * Deep copy: copy entire array rather address of first index of array.
 * 
 **/

class Student {
	int age;
	char *name;

	public :

	Student(int age, char *name) {
		this -> age = age;
		// Shallow copy
		// this -> name = name;
	
		// Deep copy
		this -> name = new char[strlen(name) + 1];
		strcpy(this -> name, name);
	
	}

	void display() {
		cout << name << " " << age << endl;
	}
};
