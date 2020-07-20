#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//class for the exception handling:
class Exception_handling{
	static int tot_exceptions;
	
	public:
		Exception_handling(){}
		
		static bool check(const float inp, const float req){											//function to check the entered marks.
			try{
				if(inp >= (req+1)){
					throw inp;
				}
				return true;
			}
			catch(...){
				tot_exceptions+= 1;
				cout<< endl<< "EXCEPTION OCCURRED!"<< endl;
				cout<< "RE-ENTER MARKS (max."<< req<< " marks): "<< endl;
				fflush(stdin);
				return false;
			}	
		}
		
		int gettot_exceptions()	const{
			return tot_exceptions;
		}
		
		static float formnum(char markings[10]){
			float num = 0;
			int cnt = 0;
			float val = 0;
			int dig = 0, mult = 1;
			
			while(markings[cnt]!= '\0'){
				dig+= 1;
				cnt++;	
			}
			
			cnt = (dig-1);
			while(cnt != -1){
				val = markings[cnt] - 48;
				num = num + (val * mult);
				mult*= 10;
				cnt--;
			}
			
			return num;
		}
		
		static bool checkid(const char id){															//function to check the entered id for exception handling.
			try{
				if( (id>47) && (id<58) )
					return true;
				else
					throw id;
			}
			catch(...){
				cout<< endl<< "EXCEPTION OCCURRED!"<< endl;
				tot_exceptions+= 1;
				cout<< "RE-ENTER ID: ";
				fflush(stdin);
				return false;
			}	
		}
		
		static bool checkmarks(const char array[10]){												//function to check the entered marks for exception handling.
			int flag = 0, cnt = 0;
			
			try{
				while(cnt != 10){
					if( array[cnt]!= '\0' ){
						if( (array[cnt]>47) && (array[cnt]<58) ){}
						else
							throw array[cnt];
					}
					cnt++;
				}
				return true;
			}
			catch(const char exception){
				tot_exceptions+= 1;
				cout<< endl<< "EXCEPTION OCCURRED!"<< endl<< "You're not supposed to Enter data consist of character(s), like: "<< exception<< endl;
				cout<< "RE-ENTER MARKS: "<< endl;
				return false;
			}	
		}
		
		static bool checkn(const char name[21]){													//function to check the entered name for exception handling.
			int cnt = 0, cnt2 = 0;
			int fg = 0;
			int len = strlen(name);
			char arr[21] = {'\0'};
			
			try{
				while(cnt != len){
					if( (name[cnt] != ' ') && (name[cnt] != '\0') ){
						if( ((name[cnt]<65) || (name[cnt]>129)) ){
							fg = 1;
							arr[cnt2] = name[cnt];
							cnt2+= 1;
						}	
					}
					cnt++;
				}
				if(fg == 1)
					throw arr;
					
				return true;
			}
			catch(char chars[21]){
				tot_exceptions+= 1;
				cout<< endl<< "EXCEPTION OCCURRED!"<< endl<< "You've entered invalid character(s), like: ";
				for(int cnt = 0; cnt<21; cnt++){
					cout<< chars[cnt];
					if(chars[cnt+1] != '\0')
						cout<< ", ";
				}
					
				cout<< endl<< "RE-ENTER NAME: ";
				return false;
			}	
		}
		
};

int Exception_handling::tot_exceptions = 0;

//class for the student:
class Student{
	
	char name[21];
	int id;
	char sex;
	float quiz1, quiz2, mids, finals;
	
	public:
		Student(char nme[21], char sex, float *quiz, float mids, float finals){
			strcpy(name, nme);
			this->sex = sex;
			quiz1 = *(quiz);
			quiz2 = *(quiz+1);
			this->mids = mids;
			this->finals = finals;
		}
		
		Student(){	
			for(int cnt = 0; cnt<21; cnt++)
				name[cnt] = '\0';
			id = 0;
			quiz1 = 0;
			quiz2 = 0;
			mids = 0;
			finals = 0;	
		}
		
		static int totalrecords(const char fpath[50]){								//function to get the total number of records
			ifstream Records;
			int roll = 0;
			Student Temp;
			
			Records.open(fpath);	
			if(Records.is_open()){
				while(!Records.eof()){
					if( Records.read((char*)&Temp, sizeof(Temp)) ){
						roll+= 1;
					}
				}
				Records.close();
				return roll;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
				return 0;
		}
		
		//setters:
		void setname(const char nme[21]){
			strcpy(name, nme);
		}
		
		bool setid(const char fpath[50]){
			ifstream file;
			Student Temp;
			
			file.open(fpath);
			if(file.is_open()){
				while(!file.eof()){
					if( file.read((char*)&Temp, sizeof(Temp)) );
				}
				if(Student::totalrecords(fpath) == 20){
					return false;
				}
				else{
					id = (Temp.id + 1);
					file.close();
					return true;
				}
			}	
			else{
				id = 0;
				cout<< endl<< "New File Will Be Created After This First Data Entry..."<< endl;
				return true;
			}
		}
		
		void setsex(const char gen){
			sex = gen;
		}
		
		void setquizs(const float *marks){
			quiz1 = *(marks+0);
			quiz2 = *(marks+1);
		}
		
		void setmids(const float midm){
			mids = midm;
		}
		
		void setfinals(const float finalm){
			finals = finalm;
		}
		
		//getter:
		int getid() const{
			return id;
		}
		
		//file-handling functions:
		void updatefile(const Student &Temp, const char fpath[50]){						//function to write(append) in the file.
			ofstream out;
			out.open(fpath, ios::app);
			if(out.is_open()){
				out.write((char*)&Temp, sizeof(Temp));
				out.close();
			}
			else
				cout<< endl<< "FAILED TO UPDATE THE RECORD!"<< endl;
		}
		
		void display(Student &Data) const{												//function to print the attributes of a particular object
			cout<< endl<< endl<< "NAME: "<< Data.name<< endl<< "SEX: "<< Data.sex<< endl
				<< "ID: "<< Data.id<< endl<< "QUIZ-1 MARKS: "<< Data.quiz1 << endl 
				<< "QUIZ-2 MARKS: "<< Data.quiz2 << endl<< "MID-MARKS: "<< Data.mids <<endl
				<< "FINAL-MARKS: "<< Data.finals<< endl; 
		}
		
		static void displayrecord(const char fpath[50]){								//function to get each object from file and call display()
			ifstream Data;
			Student Temp;
			int flag = 0;
			
			Data.open(fpath);
				if(Data.is_open()){
					cout<< endl<< "DISPLAYING THE RECORDS OF THE FILE: "<< endl;
					while(!Data.eof()){
						if( Data.read((char*)&Temp, sizeof(Temp)) ){
							Temp.display(Temp);
							flag = 1;
						}
					}
					Data.close();
					if(flag!= 1){
						cout<< endl<< "NO RECORDS FOUND!"<< endl;
					}
				}
			
				else
					cout<< endl<< "FAILED TO GET ANY RECORD!"<< endl;
		}
		
		static void displayvianame(const char name[21], const char fpath[50]){
			int flag = 0;
			Student Temp;
			ifstream in;
			
			in.open(fpath);
			if( (in.is_open()) ){
				while(!in.eof()){
					if( in.read((char*)&Temp, sizeof(Temp)) ){
						if(strcmp(Temp.name, name) == 0){
							flag = 1;
							Temp.display(Temp);
						}
					}
					else
						break;
				}
				in.close();
				
				if(flag != 1){
					cout<< endl<< "NO SUCH RECORD FOUND!"<< endl;
				}
			}
			
			else
				cout<< endl<< "FAILED TO GET ANY RECORD!"<< endl;
		}
		
		static bool deleterecord(const int identity, const char fpath[50]){					//function to remove the data.
			char fpath2[50] = "student2.txt";
			Student Temp;
			ifstream in;
			ofstream out;
			int flag = 0;
			
			in.open(fpath);
			out.open(fpath2);
			if( (in.is_open()) && (out.is_open()) ){
				while(!in.eof()){
					if( in.read((char*)&Temp, sizeof(Temp)) ){
						if(Temp.id == identity){
							flag = 1;
							continue;
						}
						else{
							out.write((char*)&Temp, sizeof(Temp));	
						}
					}
					else{
						break;
					}
				}
				
				in.close();
				out.close();
				remove(fpath);
				rename(fpath2, fpath);
				if(flag == 1){
					return true;
				}
				else{
					cout<< "NO SUCH RECORD FOUND!"<< endl;
					return false;
				}
			}
			
			else{
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
				return false;
			}
		}
		
		static void modifyrecord(const int identity, const char fpath[50]){					//function to modify the data.
			char fpath2[50] = "student2.txt";
			int chk;
			Student Temp;
			ifstream in;
			ofstream out;
			fstream file;
			int flag = 0;
			char markings[10] = {'\0'};
			bool chec = false;
			
			in.open(fpath);
			out.open(fpath2, ios::app);
			if( (in.is_open()) && out.is_open() ){
				while(!in.eof()){
					if( in.read((char*)&Temp, sizeof(Temp)) ){
						if(Temp.id == identity){
							int opt;
							char nme[21] = {'\0'};
							flag = 1;
							cout<< endl<< endl<< "Enter the following Number to modify a particular information of the student: "
								<< endl << "1 = NAME"<< endl<< "2 = GENDER(m/f)"<< endl
								<< "3 = QUIZ-1 MARKS"<< endl<< "4 = QUIZ-2 MARKS"<< endl
								<< "5 = MID-MARKS"<< endl<< "6 = FINAL-MARKS"<< endl;
							cin>> opt;
							fflush(stdin);
							if(opt == 1){
								do{
									cout<< "Student-Name(max. 20 characters): ";
									cin.getline(nme, 21);
									chk = Exception_handling::checkn(nme);
									if(chk == true)
									Temp.setname(nme);
									fflush(stdin);
								}while(chk != true);
							}
							else if(opt == 2){
								cout<< "Student-Gender: ";
								do{
									try{
										cin>>Temp.sex;
										if( (Temp.sex == 'm') || (Temp.sex == 'f') )
											break;
										else
											throw Temp.sex;
									}
									catch(char v){
										cout<< endl<< "EXCEPTION OCCURRED!"<< endl<< "RE-ENTER GENDER: ";
									}
								}while(1);
							}
							else if(opt == 3){
								do{		
									fflush(stdin);
									cin.getline(markings, 10);
									chec = Exception_handling::checkmarks(markings);
									if(chec == true){
										Temp.quiz1 = Exception_handling::formnum(markings);
										chk = Exception_handling::check(Temp.quiz1, 30);
									}
								}while(chk != true);
							}
							else if(opt == 4){
								do{		
									fflush(stdin);
									cin.getline(markings, 10);
									chec = Exception_handling::checkmarks(markings);
									if(chec == true){
										Temp.quiz2 = Exception_handling::formnum(markings);
										chk = Exception_handling::check(Temp.quiz2, 30);
									}
								}while(chk != true);
							}
							else if(opt == 5){
								cout<< "MID-MARKS: ";
								do{
									fflush(stdin);
									cin.getline(markings, 10);
									chec = Exception_handling::checkmarks(markings);
									if(chec == true){
										Temp.mids = Exception_handling::formnum(markings);
										chk = Exception_handling::check(Temp.mids, 100);
									}
								}while(chk != true);
							}
							else if(opt == 6){
								cout<< "FINAL-MARKS: ";
								do{
									fflush(stdin);
									cin.getline(markings, 10);
									chec = Exception_handling::checkmarks(markings);
									if(chec == true){
										Temp.finals = Exception_handling::formnum(markings);
										chk = Exception_handling::check(Temp.finals, 100);
									}
								}while(chk != true);
							}
							out.write((char*)&Temp, sizeof(Temp));
						}
						else{
							out.write((char*)&Temp, sizeof(Temp));	
						}
					}
					else{
						break;
					}
				}
				if(flag == 1)
					cout<< "RECORD UPDATED SUCCESSFULLY!"<< endl;
				else
					cout<< "NO SUCH RECORD FOUND!"<< endl;
					
				in.close();
				out.close();
				remove(fpath);
				rename(fpath2, fpath);
				for(int ct = 0; ct<10; ct++)
					markings[ct] = '\0';
				chec = false;
				chk = false;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
	
		static void sort_display(const char fpath[50]){										//function to sort in the descending order
			ifstream Data, temp;
			Student stud, n;
			float max = -1;
			char fpath2[50] = "temp.txt";
			ofstream out;
			int cnt = 0, num, flag = 0;
			
			Data.open(fpath);
			out.open(fpath2);
			if(Data.is_open() && out.is_open()){											//copying the main file to a temporary file
				while(!Data.eof()){
					if( Data.read((char*)&stud, sizeof(stud)) ){
						flag = 1;
						out.write((char*)&stud, sizeof(stud));
					}
				}
			}
			num = stud.id+1;
			Data.close();
			out.close();																	//main file copied to the temporary file
			
			while(cnt != num) {
				temp.open(fpath2);
				if(temp.is_open()){
					while(!temp.eof()){
						if( temp.read((char*)&stud, sizeof(stud)) ){
							if(stud.finals > max){
								max = stud.finals;
							}
						}
						else
							break;
					}
					temp.close();
					temp.open(fpath2);
					while(!temp.eof()){
						if( temp.read((char*)&stud, sizeof(stud)) ){
							if( max == stud.finals){
								stud.display(stud);
								temp.close();
								Student::deleterecord(stud.id, fpath2);
								max=-1;
								break;
							}
						}
						else
							break;
					}
				}
				cnt+= 1;
			}
			
			remove(fpath2);
			if(flag == 0)
				cout<< endl<< "NO RECORD FOUND!"<< endl;
		}
		
		//functions to get the lowest score of each evaluation:
		static float lowestmidscore(const char fpath[50]){
			ifstream data;
			Student Stud;
			float min;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				min = Stud.mids;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.mids < min){
							min = Stud.mids;
						}
					}
					else
						break;
				}
				data.close();
				return min;	
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!";	
		}
		
		static float lowestquiz1score(const char fpath[50]){
			ifstream data;
			Student Stud;
			float min;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				min = Stud.quiz1;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.quiz1 < min){
							min = Stud.quiz1;
						}
					}
					else
						break;
				}
				data.close();
				return min;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;	
		}
		
		static float lowestquiz2score(const char fpath[50]){
			ifstream data;
			Student Stud;
			float min;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				min = Stud.quiz2;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.quiz2 < min){
							min = Stud.quiz2;
						}
					}
					else
						break;
				}
				data.close();
				return min;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;	
		}
		
		static float lowestfinalscore(const char fpath[50]){
			ifstream data;
			Student Stud;
			float min;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				min = Stud.finals;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.finals < min){
							min = Stud.finals;
						}
					}
					else
						break;
				}
				data.close();
				return min;	
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
		
		//functions to get the highest score of each evaluation:
		static float highestmidscore(const char fpath[50]){
			ifstream data;
			Student Stud;
			float max;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				max = Stud.mids;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.mids > max){
							max = Stud.mids;
						}
					}
					else
						break;
				}
				data.close();
				return max;	
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!";	
		}
		
		static float highestquiz1score(const char fpath[50]){
			ifstream data;
			Student Stud;
			float max;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				max = Stud.quiz1;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.quiz1 > max){
							max = Stud.quiz1;
						}
					}
					else
						break;
				}
				data.close();
				return max;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;	
		}
		
		static float highestquiz2score(const char fpath[50]){
			ifstream data;
			Student Stud;
			float max;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				max = Stud.quiz2;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.quiz2 > max){
							max = Stud.quiz2;
						}
					}
					else
						break;
				}
				data.close();
				return max;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;	
		}
		
		static float highestfinalscore(const char fpath[50]){
			ifstream data;
			Student Stud;
			float max;
			
			data.open(fpath);
			if(data.is_open()){
				data.read((char*)&Stud, sizeof(Stud));
				max = Stud.finals;
				
				while(!data.eof()){
					if(data.read((char*)&Stud, sizeof(Stud))){
						if(Stud.finals > max){
							max = Stud.finals;
						}
					}
					else
						break;
				}
				data.close();
				return max;	
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
		
		static void highestscores(const char fpath[50]){
			cout<< endl << "THE HIGHEST MID SCORE IS: "<< highestmidscore(fpath) << endl;
			cout<< "THE HIGHEST QUIZ-1 SCORE IS: "<< highestquiz1score(fpath) << endl;
			cout<< "THE HIGHEST QUIZ-2 SCORE IS: "<< highestquiz2score(fpath) << endl;
			cout<< "THE HIGHEST FINAL SCORE IS: "<< highestfinalscore(fpath)<< endl << endl;
		}
		
		static void lowestscores(const char fpath[50]){
			cout<< endl << "THE LOWEST MID SCORE IS: "<< lowestmidscore(fpath) << endl;
			cout<< "THE LOWEST QUIZ-1 SCORE IS: "<< lowestquiz1score(fpath) << endl;
			cout<< "THE LOWEST QUIZ-2 SCORE IS: "<< lowestquiz2score(fpath) << endl;
			cout<< "THE LOWEST FINAL SCORE IS: "<< lowestfinalscore(fpath) << endl<< endl;
		}
		
		static void averagemids(const char fpath[50]){
			ifstream Data;
			Student Temp;
			double val = 0;
			int num;
			
			Data.open(fpath);	
			if(Data.is_open()){
				while(!Data.eof()){
					if( Data.read((char*)&Temp, sizeof(Temp)) ){
						val+= Temp.mids;
						num = Temp.id;
					}
					else
						break;
				}
				Data.close();
				val/= (num+1);
				cout << endl<< "THE AVERAGE-SCORE OF MIDS IS: "<< val ;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
		
		static void averagefinals(const char fpath[50]){
			ifstream Data;
			Student Temp;
			double val = 0;
			int num;
			
			Data.open(fpath);	
			if(Data.is_open()){
				while(!Data.eof()){
					if( Data.read((char*)&Temp, sizeof(Temp)) ){
						val+= Temp.finals;
						num = Temp.id;
					}
					else
						break;
				}
				Data.close();
				val/= (num+1);
				cout << endl<< "THE AVERAGE-SCORE OF FINALS IS: "<< val ;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
		
		static void averagequiz1(const char fpath[50]){
			ifstream Data;
			Student Temp;
			double val = 0;
			int num;
			
			Data.open(fpath);	
			if(Data.is_open()){
				while(!Data.eof()){
					if( Data.read((char*)&Temp, sizeof(Temp)) ){
						val+= Temp.quiz1;
						num = Temp.id;
					}
					else
						break;
				}
				Data.close();
				val/= (num+1);
				cout << endl<< "THE AVERAGE-SCORE OF QUIZ-1 IS: "<< val ;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}
		
		static void averagequiz2(const char fpath[50]){
			ifstream Data;
			Student Temp;
			double val = 0;
			int num;
			
			Data.open(fpath);	
			if(Data.is_open()){
				while(!Data.eof()){
					if( Data.read((char*)&Temp, sizeof(Temp)) ){
						val+= Temp.quiz2;
						num = Temp.id;
					}
					else
						break;
				}
				Data.close();
				val/= (num+1);
				cout << endl<< "THE AVERAGE-SCORE OF QUIZ-2 IS: "<< val ;
			}
			else
				cout<< endl<< "NO SUCH FILE FOUND!"<< endl;
		}		

		static void printmenu(){
			cout<< "Enter the digits for each particular task respectively: "<< endl<< endl
			<< "1.  Add student record"<< endl << "2.  Delete a particular student record"<< endl
			<< "3.  Update a particular student record"<< endl << "4.  Search a particular student by its name"<< endl
			<< "5.  View all students' records"<< endl << "6.  Calculate an average of students' scores in each evaluation"<< endl
			<< "7.  Display the highest score of each evaluation"<< endl<< "8.  Display the lowest score of each evaluation"<< endl
			<< "9.  Display total number of student's records"<< endl<< "10. Sort the students based on final score in descending order and display them"<< endl
			<< "11. Exit"<< endl;
		}
};

//scope of main:
int main(){
	
	char opt[16] = {'\0'};
	bool chk = false;
	Student S;
	char fpath[50] = "student.txt";
	Exception_handling E;
	
	do{
		system("cls");
		Student::printmenu();
		for(int iterate = 0; iterate< 16; iterate++)
			opt[iterate] = '\0';
			
		cout<< endl<< "CHOICE: ";
		while(1){
			fflush(stdin);
			try{
				cin.getline(opt, 16);
				for(int iterate = 0; iterate< 16; iterate++){
					if(opt[iterate] != '\0'){
						if( (opt[iterate] > 47) && (opt[iterate] < 58) ){
							break;
						}
						else
							throw opt[iterate];
					}
				}
				break;	
			}
			catch(char const except){
				cout<< endl<< "EXCEPTION OCCURRED!"<< endl<< "You're entering invalid character(s) like: "<< except<< endl<<  "RE-ENTER YOUR OPTION: ";
			}
		}
		if( strcmp(opt, "11") == 0 )
			break;
			
		else if( strcmp(opt, "1") == 0 ){
			char name[21] = {'\0'}, gen, markings[10] = {'\0'};
			float quiz[2], marks;
			const int numrec = Student::totalrecords(fpath);
			bool chec = false; 
			
			if(numrec == 0){
				cout<< "New File Will Be Created After This Data-Entry..."<< endl;
			}
			if(numrec<20){
				cout<< endl<< endl<< "Enter the following information of the student: "<< endl
					<< "Student-Name(max. 20 characters): ";
				do{
					cin.getline(name, 21);
					chk = Exception_handling::checkn(name);
					if(chk == true)
						S.setname(name);
					fflush(stdin);
				}while(chk != true);
				cout<< "Student-Gender(m/f): ";
				do{
					try{
						cin>>gen;
						if( (gen == 'm') || (gen == 'f') )
							break;
						else
							throw gen;
					}
					catch(char v){
						cout<< endl<< "EXCEPTION OCCURRED!"<< endl<< "RE-ENTER GENDER: ";
					}
				}while(1);
				S.setsex(gen);
				
				chec = false;
				chk = false;
				
				cout<< "Student-Marks: "<< endl;
				do{
					cout<< "QUIZ-1 Marks: ";
					fflush(stdin);
					cin.getline(markings, 10);
					chec = Exception_handling::checkmarks(markings);
					if(chec == true){
						quiz[0] = Exception_handling::formnum(markings);
						chk = Exception_handling::check(quiz[0], 30);
					}
				}while(chk!=true);
				
				for(int ct = 0; ct<10; ct++)
					markings[ct] = '\0';
				chec = false;
				chk = false;
				
				do{
					cout<< "QUIZ-2 Marks: ";
					fflush(stdin);
					cin.getline(markings, 10);
					chec = Exception_handling::checkmarks(markings);
					if(chec == true){
						quiz[1] = Exception_handling::formnum(markings);
						chk = Exception_handling::check(quiz[1], 30);
					}
				}while(chk!=true);
				S.setquizs(&quiz[0]);
				
				for(int ct = 0; ct<10; ct++)
					markings[ct] = '\0';
				chec = false;
				chk = false;
			
				do{
					cout<< "MID-MARKS: ";	
					fflush(stdin);
					cin.getline(markings, 10);
					chec = Exception_handling::checkmarks(markings);
					if(chec == true){
						marks = Exception_handling::formnum(markings);
						chk = Exception_handling::check(marks, 100);
					}
				}while(chk != true);
				S.setmids(marks);
				
				for(int ct = 0; ct<10; ct++)
					markings[ct] = '\0';
				chec = false;
				chk = false;
				
				do{
					cout<< "FINAL-MARKS: ";
					fflush(stdin);
					cin.getline(markings, 10);
					chec = Exception_handling::checkmarks(markings);
					if(chec == true){
						marks = Exception_handling::formnum(markings);
						chk = Exception_handling::check(marks, 100);
					}
				}while(chk != true);
				S.setfinals(marks);
				S.setid(fpath);
				S.updatefile(S, fpath);
				
				for(int ct = 0; ct<10; ct++)
					markings[ct] = '\0';
				chec = false;
				chk = false;
				
				cout<< "Assigned-ID: "<< S.getid()<< endl;
			}
			else{
				cout<< endl<< "YOU ARE EXCEEDING THE STUDENTS LIMIT i.e: "<< numrec<< endl;
			}
		}
	
		else if( strcmp(opt, "2") == 0 ){
			char ide;
			bool chec;
			int id;
			bool flag;
			
			cout<< endl<< endl<< "REMOVING DATA:"<< endl<< "Enter Student-ID: ";
			do{
				cin>> ide;
				chec = Exception_handling::checkid(ide);
				if(chec == true)
					id = ide - 48;
			}while(chec != true);
			flag = Student::deleterecord(id, fpath);
			if(flag == true){
				cout<< "RECORD REMOVED SUCCESSFULLY!"<< endl;
			}
		}
		
		else if( strcmp(opt, "3") == 0 ){
			int id;
			char ide;
			bool chec;
			
			cout<< endl<< endl<< "MODIFYING DATA: "<< endl<< "Enter Student-ID: ";
			do{
				cin>> ide;
				chec = Exception_handling::checkid(ide);
				if(chec == true)
					id = ide-48;
			}while(chec != true);
			Student::modifyrecord(id, fpath);
			fflush(stdin);
		}
		
		else if( strcmp(opt, "4") == 0 ){
			char nme[21] = {'\0'};
			bool chec;
			
			cout<< endl<< "DISPLAYING THE DATA OF A PARTICULAR STUDENT: "<< endl;
			cout<< endl<< "NAME OF THE STUDENT(max. 20 characters): ";
			do{
				cin.getline(nme, 21);
				chk = Exception_handling::checkn(nme);
				if(chk == true)
					Student::displayvianame(nme, fpath);
				fflush(stdin);
			}while(chk != true);
		}
		
		else if( strcmp(opt, "5") == 0 )
			Student::displayrecord(fpath);
		
		else if( strcmp(opt, "6") == 0 ){
			Student::averagemids(fpath);
			Student::averagequiz1(fpath);
			Student::averagequiz2(fpath);
			Student::averagefinals(fpath);		
			cout<< endl;
		}
		
		else if( strcmp(opt, "7") == 0 )
			Student::highestscores(fpath);	
		
		else if( strcmp(opt, "8") == 0 )
			Student::lowestscores(fpath);
		
		else if( strcmp(opt, "9") == 0 ){
			const int numrec = Student::totalrecords(fpath);
			cout<< endl<< "THE TOTAL NUMBER OF STUDENTS' RECORDS ARE: "<< numrec<< endl;
		}
		
		else if( strcmp(opt, "10") == 0 )
			Student::sort_display(fpath);
		
		else
			cout<< endl<< "You are making an Incorrect Choice!"<< endl;
			
		cout<< endl<< endl;
		system("PAUSE");
		cout<< endl<< endl<< endl;
	}while(1);
	
	cout<< endl<< endl<< "Process exited with the exception(s) value "<< E.gettot_exceptions()<< endl;
	
	return 0;
}
