#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;


class Student {
public:
	string firstname;
	string lastname;
	string rollno;

	Student(string f, string l, string no)
	{
		firstname = f;
		lastname = l;
		rollno = no;
	}

//operator overloading
	bool operator==(const Student &s)const
	{
		return rollno == s.rollno ? true : false;
	}
};

class HashFn {
public:
	size_t operator()(const Student &s)const
	{
		return s.firstname.length() + s.lastname.length();
	}
};

int main()
{
	unordered_map<Student, int, HashFn> student_map;

	Student s1("Prateek", "Narang", "018");
	Student s1("Ajay", "Rajput", "018");
	Student s1("Prateek", "Gupta", "014");
	Student s1("Rajnish", "Sharma", "018");

//add student-marks to hashmap
	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 45;

//
	cout << student_map[s3] << endl;

//iterater over all students
	for (auto s : student_map)
	{
		cout << s.first.firstname << " " << s.first.rollno << endl;
		cout << "marks" << s.second << endl;
	}

	return 0;
}