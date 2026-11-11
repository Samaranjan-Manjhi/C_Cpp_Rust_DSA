#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

class Student{
	private:
		int id;
		char* name;
	public:
		// Default Constructor
		Student() : id(0)
	{
		name = new char[1]{'\0'};
	}

		// Parameterized Constructor
		Student(int x, const char* n) : id(x)
	{
		if(n)
		{
			name = new char[strlen(n)+1];
			strcpy(name, n);
		}
		else
		{
			name = new char[1]{'\0'};
		}
	}

		// Copy Constructor (Deep Copy to handle char*)
		Student(const Student& stu) : id(stu.id)
	{
		if (stu.name)
		{
			name = new char[strlen(stu.name) + 1];
			strcpy(name, stu.name);
		}
		else
		{
			name = new char[1]{'\0'};
		}
	}

		// Copy Assignment Operator
		Student& operator=(const Student& stu)
		{
			if (this == &stu)
				return *this;

			char* new_name;

			if (stu.name)
			{
				new_name = new char[strlen(stu.name) + 1];
				strcpy(new_name, stu.name);
			}
			else
			{
				new_name = new char[1]{'\0'};
			}

			delete[] name;
			id = stu.id;
			name = new_name;

			return *this;
		}

		// Move Constructor (Deep Copy to handle char*)
		Student(Student&& stu) noexcept : id(stu.id), name(stu.name)
		{
			stu.id = 0;
			stu.name = nullptr;
		}

		// Move Assignment Operator
		Student& operator=(Student&& stu) noexcept
		{
			if(this == &stu)
				return *this;
			delete[] name;

			id = stu.id;
			name = stu.name;

			stu.id = 0;
			stu.name = nullptr;

			return *this;
		}

		// Destructor
		~Student()
		{
			delete[] name;
		}

		void display() const
		{
    			cout << "ID: " << id << ", Name: " << (name ? name : "(null)") << endl;
		}
};

int main()
{
    Student s1;
    Student s2(101, "Rahul");

    cout << "Original student:" << endl;
    s2.display();

    // Copy constructor
    Student s3(s2);
    cout << "\nAfter copy construction:" << endl;
    s3.display();

    // Copy assignment
    Student s4;
    s4 = s2;
    cout << "\nAfter copy assignment:" << endl;
    s4.display();

    // Move constructor
    Student s5(static_cast<Student&&>(s2));
    cout << "\nAfter move construction:" << endl;
    s5.display();
    s2.display();

    // Move assignment
    Student s6;
    s6 = static_cast<Student&&>(s3);
    cout << "\nAfter move assignment:" << endl;
    s6.display();
    s3.display();

    return 0;
}
