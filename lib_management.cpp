#include<iostream>
#include <fstream>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class Date {
	private:
		int d;
		int m;
		int y;
		void toModifyDate() {
			if(d>30) {
				d+=30;
				m++;

			}
			if(m>12) {
				m+=12;
				y++;
			}
		}
	public:
		
		void setDate() {
			cout<<"\t \t \t \t Enter Date:";
			cin>>d;
			cout<<"\t \t \t \t Enter Month:";
			cin>>m;
			cout<<"\t \t \t \t Enter Year:";
			cin>>y;
		}
		void setDate(Date temp) {
			d = temp.d +15;
			m= temp.m;
			y=temp.y;
			toModifyDate();
		}
		void showDate() {
			cout<<d<<"/"<<m<<"/"<<y;
		}

};
class Menu {
	public:
		void mainMenu();
		void studentMenu();
		void bookMenu();
		void issueBook();
		void returnBook();
		void IssuedBookList();
};
void Menu :: mainMenu() {
	system("cls");
	cout<<endl<<endl<<endl<<endl<<"\t \t \t \t /////////////////////////////////////////////////"<<endl<<endl<<endl;
	cout<<"\t \t \t \t ******************  MAIN MENU  ******************"<<endl<<endl<<endl;
	cout<<"\t \t \t \t 1.Student Menu\n"<<endl<<endl<<"\t \t \t \t 2.Book Menu\n"<<endl<<endl<<"\t \t \t \t 3.Issue Book\n"<<endl<<endl<<"\t \t \t \t 4.Return Book\n"<<endl<<endl<<"\t \t \t \t 5.IssuedBookList\n"<<endl<<endl;
	cout<<"\t \t \t \t 6.Exit"<<endl<<endl;
	cout<<"\t \t \t \t /////////////////////////////////////////////////"<<endl<<endl;
}
void Menu :: studentMenu() {
	system("cls");
	cout<<endl<<endl<<endl<<endl<<"\t \t \t \t/////////////////////////////////////////////////////"<<endl<<endl<<endl;
	cout<<"\t \t \t \t ******************  STUDENT MENU  ******************"<<endl<<endl<<endl;
	cout<<"\t \t \t \t 1.New Entry"<<endl<<endl<<"\t \t \t \t 2.Modify Entry"<<endl<<endl<<"\t \t \t \t 3.Search Entry"<<endl<<endl<<"\t \t \t \t 4.Delete Entry"<<endl<<endl<<"\t \t \t \t 5.View all Student"<<endl<<endl<<"\t \t \t \t 6.Go back to previous Menu"<<endl<<endl<<endl;
	cout<<"\t \t \t \t ////////////////////////////////////////////////////"<<endl<<endl;
}
void Menu :: bookMenu() {
	system("cls");
	cout<<endl<<endl<<endl<<endl<<"\t \t \t \t ////////////////////////////////////////////////"<<endl<<endl;
	cout<<"\t \t \t \t ******************BOOK MENU******************"<<endl<<endl;
	cout<<"\t \t \t \t 1.New Entry"<<endl<<endl<<"\t \t \t \t 2.Modify Entry"<<endl<<endl<<"\t \t \t \t 3.Search Entry"<<endl<<endl<<"\t \t \t \t 4.Delete Entry"<<endl<<endl<<"\t \t \t \t 5.View all books details"<<endl<<endl<<"\t \t \t \t 6.go back to previous menu"<<endl<<endl<<endl;
	cout<<"\t \t \t \t ////////////////////////////////////////////////"<<endl<<endl;
}

/*////////////////////////////////////////STUDENT DATA//////////////////////////////////////////*/
class StudentData {
	public:
		int rollNo;
		char name[30];
		char branch[15];
		int status;
		char bookTitle[30];
		StudentData() {
			status=0;

		}
		void showallstudents()
		{
			cout<<"\t\t"<<rollNo<<"\t\t"<<name<<"\t\t"<<branch<<"\t\t";
		}
};
class Student {
	public:
		void inputDetails();
		void modifyDetails();
		void searchDetails();
		void deleteDetails();
		void viewAllStudentDetails();
};
/*///////////////////////////////STUDENT INPUT DETAILS/////////////////////////////////////////*/
void Student::inputDetails() {
	system("cls");
	fstream fp;
	fp.open("studentDetails1.dat",ios::out|ios::app|ios::binary);
	if(!fp) {
		cout<<"Unable to open file"<<endl;
		return;
	}
	StudentData student;
	cout<<endl<<endl<<endl;
	//cout<<"\t \t \t \t---------------------------------------------------"<<endl<<endl;
	cout<<"\t \t \t \t Enter Student Roll no. : ";
	cin>>student.rollNo;
	cout<<endl<<endl;
	cout<<"\t \t \t \t Enter Student Name : ";
	cin.ignore();
	cin.getline(student.name,30);
	cout<<endl<<endl;
	cout<<"\t \t \t \t Enter Student Branch : ";
	cin.getline(student.branch,15);
	cout<<endl<<endl;
	cout<<"\t \t \t \t Record added to database!"<<endl;
	//cout<<"\t \t \t \t---------------------------------------------------"<<endl<<endl;
	fp.write((char*)&student,sizeof(StudentData));

	fp.close();
}
/*///////////////////////////////VIEW ALL STUDENTS ////////////////////////////////////////*/
void Student :: viewAllStudentDetails() {
	system("cls");
	fstream ifp;
	ifp.open("studentDetails1.dat",ios::in|ios::binary);
	if(!ifp) {
		cout<<"Unable to open file!"<<endl;
		return;

	}
	StudentData student;
	int choice = 1;
	cout<<endl<<endl;
	cout<<"\t \t \t Student List\n\n";
	cout<<"=======================================================================================================================\n";
	cout<<"\t\tRoll.no."<<"\t\t"<<"Name \t\t Branch \t\t Book Issued\n";
	cout<<"=======================================================================================================================\n";
	while(ifp.read((char*)&student,sizeof(StudentData))) {
		cout<<endl<<endl;
		student.showallstudents();
		if(student.status == 1) {
			cout<<student.bookTitle<<endl;
		} else {
			cout<<" "<<endl;

		}
		
	}
	Sleep(5000);
	return;
}
void Student::modifyDetails() {
	system("cls");
	fstream fp;
	fp.open("studentDetails1.dat",ios::in|ios::binary|ios::out|ios::ate);
	if(!fp) {
		cout<<"\t \t \t \t Unable to open file!"<<endl;
		return;
	}
	fp.seekg(0,ios::beg);
	int target;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;
	cout<<"\t \t \t Enter students roll no. to modify: ";
	cin>>target;

	StudentData student;
	while(fp.read((char*)&student,sizeof(student))) {
		if(target==student.rollNo) {
			int pos=(-1)*sizeof(StudentData);
			fp.seekp(pos,ios::cur);
			cout<<endl<<endl;
			cout<<"\t \t \t Enter student's new roll No: ";
			cin>>student.rollNo;
			cout<<endl<<endl;
			cout<<"\t \t \t Enter Student's new Name : ";
			cin.ignore();
			cin.getline(student.name,30);
			cout<<endl<<endl;
			cout<<"\t \t \t Enter Student's new Branch : ";
			cin.getline(student.branch,15);
			cout<<endl<<endl;
			fp.write((char*)&student,sizeof(StudentData));
			fp.close();
			cout<<"\t \t \t Record Updated"<<endl;
			return;
		}
	}
	cout<<"\t \t \t Roll No. not found"<<endl;
	return;
}
void Student::searchDetails() {
	system("cls");
	fstream fp;
	fp.open("studentDetails1.dat",ios::in|ios::binary);
	if(!fp) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	int target;
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;
	cout<<"\t \t \t \t Enter the Roll No. of the student to search: ";
	cin>>target;
	cout<<endl<<endl;
	StudentData student;
	while(fp.read((char*)&student,sizeof(StudentData))) {
		if(target==student.rollNo) {
			cout<<"\t \t \t \t RECORD FOUND!"<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Student's name: "<<student.name<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Student's roll No.: "<<student.rollNo<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Student's branch: "<<student.branch<<endl;
			cout<<endl<<endl;
			if(student.status==1) {
				cout<<"\t \t \t \t Issued book name is : "<<student.bookTitle<<endl;
				cout<<endl<<endl;
				
			} else {
				cout<<"\t \t \t \t No book is issued"<<endl;
				cout<<endl<<endl;
			}
			Sleep(1000);
			return;

		}
	}
}
void Student::deleteDetails() {
	system("cls");
	fstream fp;
	fp.open("studentDetails1.dat",ios::in|ios::binary);
	if(!fp) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	fstream file;
	file.open("temporary.dat",ios::out|ios::binary);
	if(!file) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	int target;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;
	cout<<"\t \t \t \t Enter the Roll No. of the student to delete: ";
	cin>>target;
	int flag=0;
	StudentData student;
	while(fp.read((char*)&student,sizeof(StudentData))) {
		if(target==student.rollNo) {
			flag=1;
			continue;
		}
		file.write((char*)&student,sizeof(StudentData));
	}
	fp.close();
	file.close();
	remove("studentDetails1.dat");
	rename("temporary.dat","studentDetails1.dat");
	if(flag==1) {
		cout<<"\t \t \t \t Record Deleted!"<<endl;
	} else {
		cout<<"\t \t \t \t  Roll no. not found!"<<endl;
	}
	Sleep(50);
	return;
}
class BookData {
	public :
		char title[30];
		char author[30];
		char bookid[6];
		int status;
		float price;
		int issuedRollNo;
		Date issueDate;
		Date returnDate;
		BookData() {
			status=0;
			issuedRollNo=-9999;
		}
        void showallbooks()
		{
			cout<<"\t\t\t\t"<<bookid<<setw(35)<<title<<setw(25)<<author<<setw(20);
		}
};
class Book {
	public:
		void inputDetails();
		void modifyDetails();
		void searchDetails();
		void deleteDetails();
		void viewAllBookDetails();

};
/*//////////////////////////////ADD BOOK DETAILS///////////////////////////*/
void Book::inputDetails() {
	system("cls");
	fstream fp;
	fp.open("bookDetails1.dat",ios::out|ios::app|ios::binary);
	if(!fp)

	{
		cout<<"Unable to open file"<<endl;
		return;
	}
	BookData book;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	cout<<"\t \t \t \t Enter Book Id: ";
	cin>>book.bookid;
	cout<<endl<<endl;
	cout<<"\t \t \t \t Enter Book Name: ";
	cin.get();
	cin.getline(book.title,30);
	cout<<endl<<endl;
	cout<<"\t \t \t \t Enter author's Name: ";
	cin.getline(book.author,30);
	cout<<endl<<endl;
	fp.write((char*)&book,sizeof(BookData));
	cout<<"\t \t \t \t Record added to database!"<<endl;
	cout<<endl<<endl;
	Sleep(100);
	fp.close();
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////VIEW ALL BOOK DETAILSS////////////////////////////*/
void Book::modifyDetails() {
	system("cls");
	fstream fp;
	fp.open("bookDetails1.dat",ios::in|ios::binary|ios::out|ios::ate);
	if(!fp) {
		cout<<"\t \t \t \t Unable to open file!"<<endl;
		return;
	}
	fp.seekg(0,ios::beg);
	BookData book;
	char target[30];
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	cout<<"\t \t \t \t Enter book title to modify: ";
	cin.ignore();
	cin.getline(target,30);


	while(fp.read((char*)&book,sizeof(BookData))) {
		if(strcmp(book.title,target)==0) {
			int pos=(-1)*sizeof(BookData);
			fp.seekp(pos,ios::cur);
			cout<<"\t \t \t \t Enter Book ID: ";
			cin>>book.bookid;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Enter Book Name : ";
			cin.ignore();
			cin.getline(book.title,30);
            cout<<endl<<endl;
			cout<<"\t \t \t \t Enter author of the book : ";
			cin.getline(book.author,30);
			fp.write((char*)&book,sizeof(BookData));
			cout<<endl<<endl;
			fp.close();
			cout<<"\t \t \t \t Record Updated"<<endl;
			cout<<endl<<endl;
			return;
		}
	}
	cout<<"\t \t \t \t Book ID not found"<<endl;
	return;
}
void Book :: viewAllBookDetails() {
	system("cls");
	fstream ifp;
	ifp.open("bookDetails1.dat",ios::in|ios::binary);
	if(!ifp) {
		cout<<"\t \t \t \t Unable to open file!"<<endl;
		return;

	}
	BookData book;
	int choice = 1;
	cout<<endl<<endl<<endl;
    cout<<"\t \t \t                                                        BOOK LIST\n\n";
	cout<<"\t \t \t========================================================================================================================================================\n";
	cout<<"\t\t\t\tBOOK ID."<<setw(25)<<"TITLE"<<setw(25)<<"AUTHOR"<<setw(25)<<"ISSUED STATUS"<<setw(25)<<"ISSUED DATE"<<setw(25)<<"RETURN DATE "<<endl;
	cout<<"\t \t \t========================================================================================================================================================\n";
	
	while(ifp.read((char*)&book,sizeof(BookData))) 
	{
		//system("clr");
		book.showallbooks();
		if(book.status == 1) {
			cout<<book.issuedRollNo;
			cout<<setw(20);
			book.issueDate.showDate();
			cout<<setw(20);
			book.returnDate.showDate();
			
		} else {
			cout<<" "<<endl;

		}
		cout<<endl<<endl;
	}
	
	Sleep(5000);
	return;
}

/*///////////////////SEARCH FOR BOOK DETAILS////////////////////*/
void Book::searchDetails() {
	system("cls");
	fstream file;
	file.open("bookDetails1.dat",ios::in|ios::binary);
	if(!file) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	char title[30];
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	cout<<"\t \t \t \t Enter the title of the Book: ";
	cin.ignore();
	cin.getline(title,30);

	BookData book;
	while(file.read((char*)&book,sizeof(BookData))) {
		if(strcmp(book.title,title)==0) {
			cout<<"\t \t \t \t RECORD FOUND!"<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Book Title: "<<book.title<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Book ID: "<<book.bookid<<endl;
			cout<<endl<<endl;
			cout<<"\t \t \t \t Author of the book: "<<book.author<<endl;
			cout<<endl<<endl;
			if(book.status == 1) {
				cout<<"\t \t \t \t Issued status: "<<book.issuedRollNo<<endl;
				cout<<endl<<endl;
				cout<<"\t \t \t \t Issued date:";
				book.issueDate.showDate();
				cout<<endl<<endl;
				cout<<endl<<"\t \t \t \t Return Date:";
				book.returnDate.showDate();
				cout<<endl<<endl;
			} else {
				cout<<"\t \t \t \t Issued Status: None"<<endl;
				cout<<endl<<endl;

			}
			Sleep(2000);
			return;

		}
	}
	cout<<"\t \t \t \t Book not found!"<<endl;

}
void Book::deleteDetails() {
	system("cls");
	fstream fp;
	fp.open("bookDetails1.dat",ios::in|ios::binary);
	if(!fp) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	fstream file;
	file.open("temporary2.dat",ios::out|ios::binary);
	if(!file) {
		cout<<"\t \t \t \t Unable to open the file"<<endl;
		return;
	}
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	char target[6];
	cout<<"\t \t \t \t Enter the Book ID. of the student to delete: ";
	cin>>target;
	int flag=0;
	BookData book;
	while(fp.read((char*)&book,sizeof(BookData))) {
		if(strcmp(target,book.bookid)==0) {
			flag=1;
			continue;
		}
		file.write((char*)&book,sizeof(BookData));
	}
	fp.close();
	file.close();
	remove("bookDetails1.dat");
	rename("temporary2.dat","bookDetails1.dat");
	if(flag==1) {
		cout<<"\t \t \t \t Record Deleted!"<<endl;
		cout<<endl<<endl;
	} else {
		cout<<"\t \t \t \t Roll no. not found!"<<endl;
		cout<<endl<<endl;
	}
	return;
}

void Menu::issueBook() {
	system("cls");
	fstream st,bk;
	int rollNo,flag_st=0,flag_bk=0,pos;
	st.open("studentDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.open("bookDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.seekg(0,ios::beg);
	st.seekg(0,ios::beg);


	char title[30];
	StudentData student;
	BookData book;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	cout<<"\t \t \t \t Enter Students roll.no to issue book:";
	cin>>rollNo;
	while(st.read((char*)&student,sizeof(StudentData))) {
		if(student.rollNo==rollNo) {
			pos=(-1)*sizeof(StudentData);
			st.seekp(pos,ios::cur);
			flag_st++;
			break;
		}
	}
	if(flag_st!=1) {
		cout<<"\t \t \t \t Record not found!"<<endl;
		st.close();
		bk.close();
		return;
	}
    cout<<endl<<endl;
	cout<<"\t \t \t \t Enter the book title you want to issue:"<<endl;
	cin.ignore();
	cin.getline(title,30);
	while(bk.read((char*)&book,sizeof(BookData))) {
		if(strcmp(book.title,title)==0) {
			pos=(-1)*sizeof(BookData);
			bk.seekp(pos,ios::cur);
			flag_bk++;
			break;
		}

	}
	if(flag_bk!=1) {
		cout<<"\t \t \t \t Record not found!"<<endl;
		bk.close();
		st.close();
		return;
	}

	if(student.status!=1 && book.status!=1) {
		strcpy(student.bookTitle,title);
		student.status=1;
		book.status=1;
		book.issuedRollNo=student.rollNo;
		book.issueDate.setDate();
		book.returnDate.setDate(book.issueDate);
		st.write((char*)&student,sizeof(StudentData));
		bk.write((char*)&book,sizeof(BookData));
		st.close();
		bk.close();
	} else {
		if(student.status==1) {
			cout<<"\t \t \t \t Students account is already full"<<endl;
			st.close();
			bk.close();
			return;
		}
	}
}

void Menu::returnBook() 
{
	system("cls");
	fstream st,bk;
	int rollNo,flag_st=0,flag_bk=0,pos;
	char title[30];
	st.open("studentDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.open("bookDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.seekg(0,ios::beg);
	st.seekg(0,ios::beg);
	StudentData student;
	BookData book;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;

	cout<<"\t \t \t \t Enter Students roll.no to return book:";
	cin>>rollNo;

	while(st.read((char*)&student,sizeof(StudentData))) {
		if(student.rollNo==rollNo) {
			pos=(-1)*sizeof(StudentData);
			st.seekp(pos,ios::cur);
			flag_st++;
			break;
		}
	}

	if(flag_st!=1) {
		cout<<"\t \t \t \t Record not found!"<<endl;
		st.close();
		bk.close();
		return;
	}

	while(bk.read((char*)&book,sizeof(BookData))) {
		if(strcmp(book.title,student.bookTitle)==0) {
			pos=(-1)*sizeof(BookData);
			bk.seekp(pos,ios::cur);
			flag_bk++;
			break;
		}

	}
	if(flag_bk!=1) {
		cout<<"\t \t \t \t Record not found!"<<endl;
		bk.close();
		st.close();
		return;
	}
	cout<<"\t \t \t \t Enter the book title you want to issue:";
	cin.ignore();
	cin.getline(title,30);
	cout<<endl<<endl;
	if(student.status==1 && book.status==1) {
		strcpy(student.bookTitle,title);
		student.status=0;
		book.status=0;
		book.issuedRollNo=-9999;
		st.write((char*)&student,sizeof(StudentData));
		bk.write((char*)&book,sizeof(BookData));
		st.close();
		bk.close();
	} else {
		if(student.status==0) {
			cout<<"\t \t \t \t Students account is already full"<<endl;
			st.close();
			bk.close();
			return;
		}
	}
}
void Menu::IssuedBookList()
{
	system("cls");
	fstream st,bk;
	int rollNo,flag_st=0,flag_bk=0,pos;
	st.open("studentDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.open("bookDetails1.dat",ios::in|ios::out|ios::ate|ios::binary);
	bk.seekg(0,ios::beg);
	st.seekg(0,ios::beg);


	char title[30];
	StudentData student;
	BookData book;
	cout<<endl<<endl<<endl;
	cout<<"\t \t \t--*--*--*--*--*--*--*--*--*--*--*--*--*--*----*--*--*--*--*--*--*--"<<endl<<endl;
	
	int choice = 1;
	while(bk.read((char*)&book,sizeof(BookData))&&choice&&st.read((char*)&student,sizeof(StudentData)))
    {
    	if(student.status==1 && book.status==1) {
    	cout<<endl<<endl;
		cout<<"\t \t \t STUDENT NAME : "<<student.name<<endl<<endl;
		cout<<"\t \t \t BOOK NAME : "<<book.title;
		cout<<endl<<endl;
		cout<<"\t \t \t ISSUED DATE : ";
	    book.issueDate.showDate();
	    cout<<endl<<endl;
        cout<<"\t \t \t RETURN DATE : ";
        book.returnDate.showDate();
		cout<<endl<<endl;
		cout<<"\t \t \t To view next Book details press 1 else press 0: ";
		cin>>choice;
		} 
		
		
		Sleep(2000);
	}
	
		return;
	}	
void welcome()
{ 
    
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t \t \t \t \t ---------------------------"<<endl<<endl;
	cout<<"\t \t \t \t \t  LIBRARY MANAGEMENT SYSTEM "<<endl<<endl;
	cout<<"\t \t \t \t \t            By              "<<endl<<endl;
	cout<<"\t \t \t \t \t        Ananya Manoj        "<<endl;
	cout<<"\t \t \t \t \t         Aswathi R           "<<endl<<endl;
	
	}	
	

    	
	


int main() {
	Menu menu;
	int quit=0;
	int choice;
    welcome();
	while(!quit) {
        
		menu.mainMenu();
		cout<<"\t \t \t \t Please enter your choice: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				system("cls");
				menu.studentMenu();
				cout<<"\t \t \t \t Please enter your choice: ";
				cin>>choice;
				cout<<endl<<endl<<endl<<endl;
				Student s1;
				switch(choice) {
					case 1:
						s1.inputDetails();
						break;
					case 2:
						s1.modifyDetails();
						break;
					case 3:
						s1.searchDetails();
						break;
					case 4:
						s1.deleteDetails();
						break;
					case 5:
						s1.viewAllStudentDetails();
						break;
					default:
						cout<<"Wrong Input!"<<endl;
				}
				break;
			}
			case 2: {

				menu.bookMenu();
				cout<<"\t \t \t \t Please enter your choice: ";
				cin>>choice;
				Book b;
				switch(choice) {
					case 1:
						b.inputDetails();
						break;
					case 2:
						b.modifyDetails();
						break;
					case 3:
						b.searchDetails();
						break;
					case 4:
						b.deleteDetails();
						break;
					case 5:
						b.viewAllBookDetails();
						break;
					default:
						cout<<"\t \t \t \t Wrong Input!"<<endl;
				}
				break;
			}
			case 3:
				menu.issueBook();
				break;
			case 4:
				menu.returnBook();
				break;
			case 5:
				choice=0;
				menu.IssuedBookList();
				break;
			case 6:
				quit++;
				break;
			default:
				cout<<"Please Enter correct input!"<<endl;
				cin>>choice;
				break;
		}

	}
	return 0;
}
