#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>


using namespace std;

class library
{

private:


	string title;
	string isbn;
	string author;
	int stock;
public:

	library(string a, string b, string c, int d)
	{
		title = a;
		isbn = b;
		author = c;
		stock = d;


	}
	void display(library book[], int size)
	{



		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". Book name is: " << book[i].title << endl;
			cout << "- Book Author is: " << book[i].author << endl;
			cout << "- Book isbn is: " << book[i].isbn << endl;
			cout << "- In Stock : " << book[i].stock << endl;

			cout << endl;
		}

		cout << endl;





	}


	void search(library book[], int size)
	{


		string chi;
		bool found = false;

		cout << "Enter book author or isbn or title to search for any book" << endl;
		cin >> chi;

		for (int i = 0; i < size; i++)
		{
			if (chi == book[i].author || chi == book[i].isbn || chi == book[i].title)
			{

				cout << "Book found! Details:" << endl;
				cout << "Book name is: " << book[i].title << endl;
				cout << "Book Author is: " << book[i].author << endl;
				cout << "Book isbn is: " << book[i].isbn << endl;
				cout << "In Stock : " << book[i].stock << endl;

				found = true;

				cout << endl;

			}


		}
		if (!found)
		{

			cout << "Book not found. Enter Again : " << endl;

		}

		cout << endl;


	}


	void fine(library book[], int size)
	{
		string choi;
		int ret;
		int time = 12;
		int fine = 500;
		cout << "Enter Book name you want to return: ";
		cin >> choi;

		cout << "Enter return date" << endl;
		cin >> ret;


		for (int i = 0; i < size; i++)
		{
			if (choi == book[i].title && ret <= time)
			{

				cout << book[i].title << " Book Has been returned on time " << endl;
				book[i].stock++;

			}
			else if (choi == book[i].title && ret > time)
			{

				cout << "As per late submission you have been imposed an fine of  " << fine << " rs." << endl;

				book[i].stock++;


			}

		}

		cout << endl;


	}

	void borrow(library book[], int size)

	{
		string choi;
		bool found = false;

		cout << "Enter BOOK name you want to borrow :" << endl;
		cin >> choi;
		cout << endl;
		int time = 12;

		for (int i = 0; i < size; i++)
		{
			if (choi == book[i].title && book[i].stock != 0)
			{

				cout << "Book Is borrowed SUCCESSFULLY " << endl;
				cout << "Book name is: " << book[i].title << endl;
				cout << "Book Author is: " << book[i].author << endl;
				cout << "Book isbn is: " << book[i].isbn << endl;
				cout << "In Stock : " << book[i].stock << endl;
				cout << "Your due date to return is : " << time << " october" << endl;
				found = true;

				book[i].stock--;
			}


		}

		if (!found)
		{

			cout << "Book is out of stock " << endl;


		}
		cout << endl;

	}


};



void mainmenu()
{
	int choi;

	library book[] =
	{
		{ "DSA", "453-757", "AHMAD", 5 },
		{"OOP", "765-464", "AHSAN", 4},
		{"CP", "184-8356", "MUHAMMAD", 10 },
		{"DBMS"," 984-6573", "ARSLAN", 3},
		{"AI", "345-275", "ahmad", 7}
	};

	int size = sizeof(book) / sizeof(book[0]);




	do
	{


		cout << "Press (1) to view all books " << endl;
		cout << "Press (2) to search for any book " << endl;
		cout << "Press (3) to checkout or borrow books " << endl;
		cout << "Press (4) to return book " << endl << endl;
		cout << "Press (0) to exit " << endl << endl;
		cout << "Enter your choice: ";
		cin >> choi;

		switch (choi)
		{

		case 1:

			book[size].display(book, size);



			break;

		case 2:


			book[size].search(book, size);


			break;

		case 3:


			book[size].borrow(book, size);


			break;

		case 4:

			book[size].fine(book, size);
			break;


		case 0:

			return ;

		}




	} while (choi!=0);




}





void regi(string log, string pass)
{



	cout << "Enter Name :  ";
	cin >> log;

	cout << "Enter Password: ";
	cin >> pass;

	ofstream file;

	file.open("C://Users/msi/Desktop" + log + ".txt");

	file << log << endl << pass << endl;

	file.close();

	cout << "Registration successful " << endl;

	cout << endl;


}

void logi()
{

	string log, log1;
	string pass, pass1;
	int ch;

	cout << "Enter Name :  ";
	cin >> log;

	cout << "Enter Password: ";
	ch = _getch();
	
	while (ch != 13)
	{

		pass.push_back(ch);
		cout << '*';
		ch = _getch();

	}
	cout << endl;

	//cin >> pass;

	ifstream read("C://Users/msi/Desktop" + log + ".txt");
	getline(read, log1);
	getline(read, pass1);

	if (log1 == log && pass1 == pass)
	{

		cout << "Login Successfull " << endl << endl;
		mainmenu();

	}
	else
	{

		cout << "Incorrect username or password try again " << endl;


	}

	cout << endl;
	

}




void logo()
{

	cout << setfill('*') << setw(120);
	cout << " ";
	cout << endl << endl;

	cout << setfill(' ') << setw(62);
	cout << "  WELCOME TO " << endl << endl;


	cout << "                     *                        * *             * *               ***********" << endl;
	cout << "                     *                        *   *         *   *               *" << endl;
	cout << "                     *                        *      *     *    *               *" << endl;
	cout << "                     *                        *       *   *     *               *" << endl;
	cout << "                     *                        *         *       *               ***********" << endl;
	cout << "                     *                        *                 *                         *" << endl;
	cout << "                     *                        *                 *                         *" << endl;
	cout << "                     *                        *                 *                         *" << endl;
	cout << "                     *************            *                 *               ***********" << endl;


	cout << endl;
	cout << setfill('*') << setw(120);
	cout << " ";

	cout << endl;
}






int main()
{



	system("color 90");
	logo();

	string log;
	string pass;


	int choi;



	do {

		cout << "Press (1) to register " << endl;
		cout << "Press (2) to login " << endl;
		cout << "Press (0) to terminate the program " << endl;
		cout << "Enter your choice: ";
		cin >> choi;
		cout << endl;


		switch (choi)
		{


		case 1:
			regi(log, pass);
			break;

		case 2:

			logi();
			break;

		case 0:

			return 0;

		}



	} while (choi!=0);




	return 0;


}

