#include<iostream>
using namespace std;
class person
{
	public:
		string name;
		int age;
		int id;
		string designation;
		float maxMarks[5]={100,100,100,100,100};
        float obtMarks[5];
        string subject[5] = {"OOP ", "DS  ", "CPS ", "STAT", "CALS"};
        
};
class student: virtual public person
{
 	public:
 		void studentData(string n, int a, string d, int i)
 		{
 		name=n;
		age=a;
		designation=d;
		id=i;	
		}
		void display_student()
		{
		    cout << "name of student: " <<name << endl;
		    cout << "age of student: " <<age << endl;
		    cout << "id of student: " <<id << endl;
		    cout << "designation of student: " <<designation << endl;
		}
};

class admin: virtual public person
{
	public:
		float percentage;
		char grade;
		float total_obtMarks;
		float total_maxMarks;
		void adminData(string n, int a, string d, int i)
 		{
	 		name=n;
			age=a;
			designation=d;
			id=i;	
		}
		void display_admin()
		{
		    cout << "name of admin: " <<name << endl;
		    cout << "age of admin: " <<age << endl;
		    cout << "id of admin: " <<id << endl;
		    cout << "designation of admin: " <<designation << endl;
		}
		void obtainingMarks(float m[])
		{
			for (int i=0; i<5; i++)
			{
				obtMarks[i] = m[i];
			}
		}
		void percentage_marks()
		{
			for (int i=0; i<5; i++)
			{
				total_obtMarks = total_obtMarks + obtMarks[i];
				total_maxMarks = total_maxMarks + maxMarks[i];
		    }
			percentage = (total_obtMarks / total_maxMarks) * 100;
		}
		void student_grade()
		{
			if (percentage >= 90)
			{
				grade = 'A';
			}
			else if (percentage >= 80)
			{
				grade = 'B';
			}
			else if (percentage >= 70)
			{
				grade = 'C';
			}
			else if (percentage >= 60)
			{
				grade = 'D';
			}
			else if (percentage >= 50)
			{
				grade = 'E';
			}
			else if (percentage <= 50)
			{
				grade = 'F';
			}
		}
};
class result: public admin, public student
{
	public:
	void display_result()
	    {
	    	for (int i=0; i<80; i++)
	    	{
	    		cout <<"=";
			}
			cout << endl;
			cout << "subject\t\tmax.marks\t\tobt.marks" << endl;
			for (int i=0; i<80; i++)
	    	{
	    		cout <<"=";
			}
			cout << endl;
			for(int i=0; i<5; i++)
			{
				cout << subject[i] << "\t\t" << maxMarks[i] << "\t\t\t" << obtMarks[i] << endl;
			}
			for (int i=0; i<80; i++)
	    	{
	    		cout <<"=";
			}
			cout <<"\nmax.marks\t" << total_maxMarks <<"  obt.marks\t\t"<< total_obtMarks <<endl;
			cout <<"Percentage\t" <<percentage <<"  Grade\t\t" <<grade;
		    cout << endl;
			for (int i=0; i<80; i++)
	    	{
	    		cout <<"=";
			}
		}
};
int main()
{
student s;
admin a;
result r;
s.studentData("Eman Fatima", 20, "Student", 132);
a.adminData("asad naqvi", 45, "Principal", 12345);
cout <<"Student Data\n\n";
s.display_student();
cout <<"\nAdmin Data\n\n";
a.display_admin();
float mark[5];
cout <<"\n\n";
for (int i=0; i<5; i++)
{
	cout <<"Enter the subject marks: ";
	cin >> mark[i];
}
cout <<"\nDisplay Result\n\n";
r.obtainingMarks(mark);
r.percentage_marks();
r.student_grade();
r.display_result();

    return 0;
}
