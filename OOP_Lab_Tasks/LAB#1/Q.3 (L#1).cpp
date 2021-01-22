/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	float courses,obtained_marks_in_all_courses;
	cout<<"Enter obtained marks: ";
	cin>>obtained_marks_in_all_courses;
	cout<<"Enter no. of courses: ";
	cin>>courses;
	float avg_marks=(obtained_marks_in_all_courses/courses);
	cout<<"Average Marks: "<<fixed<<setprecision(4)<<avg_marks<<endl;
	return 0;
}

