
#include <string>
#include<fstream>
#include "BankMain.h"
#include "SavingAccount.h"
#include "CurrentAcc.h"
#include "UniversityStudent.h"
#include <string> 
#include<iostream>
using namespace std;
/*
Summary of file
this the big and main project
supporting file
it is used to define all the 
function that i have to
call in my console window when 
the project is running
it  calls the function from classes 
this file also have function that is made to support
and elimate redundant that is i am doing again and again
*/

/*
char Selection() :is a functio used to select the
Account type
it has return type is one of them 
C,U and s for current account,university account
and saving account respectively if 
we try to put other than s,c,u it will
be throw into catch block
*/
char
Selection()
{
	char choice;

	cout << "Kindly Enter your choice :" << endl;

	cout <<
		"1.C For current Account:\n2.S For Saving Account:\n3.U For Saving Account"
		<< endl;

	cin >> choice;

	while (true)

	{

		try
		{

			if (choice == 'c' || choice == 'C' || choice == 's' || choice == 'S'
				|| choice == 'u' || choice == 'U')

			{

				return choice;  //return if correct input are entered

			}

			else

			{

				throw choice; //throw for unexpected choice

			}

		}

		catch (char ch)      //receive input from throw block
		{

			cout << "You Enter the the:" << ch << endl;

			cout << "your choice was not fine Kindly Try Again:" << endl;

			cin >> choice;

		}

	}

}
/*
Write_account():
it is function that takes input from
user after varifying its eligiblity
then ask to enter credentials
There is Money for intial deposite
which is received from the user
on different condition bases
on the different type of Accounts
the all the data is written into
the file using file handling
objects.

*/

void

write_account()
{


	char a = Selection(); //calling function Selection()

	if (a == 'c' || a == 'C')

	{


		fstream f;     // file pointer

		f.open("client1.txt", ios::in | ios::out | ios::app); //opening file 

		if (f.is_open()) //varifing object is open the do the next work 
		{

			CurrentAcc p;

			bool c=p.CreatAccount(); //calling CreatAccount class function
			if (c == false)
			{
				return; //not write the data if the user is not eligible and return back
			}
			//writing data to the file
			f << p.Acc_No << endl;

			f << p.Name << endl;

			f << p.Father_Name << endl;

			f << p.Address << endl;

			f << p.IDCard_No << endl;

			f << p.Money << endl;

			f.close(); //close file

		}

		else

		{

			cout << "Error in the file opening" << endl; //if file is not opened

		}

	}

	else if (a == 's' || a == 'S')


	{

		fstream f;  // file pointer

		f.open("client2.txt", ios::in | ios::out | ios::app);//file opening
		//varifing object is open the do the next work

		if (f.is_open()) 	//varifing object is open the do the next work

		{


			SavingAccount p;

			bool c = p.CreatAccount();//calling CreatAccount class function
			if (c == false)
			{
				return;//not write the data if the user is not eligible and return back
			}
			//writing data to the file
			f << p.Acc_No << endl;

			f << p.Name << endl;

			f << p.Father_Name << endl;

			f << p.Address << endl;

			f << p.IDCard_No << endl;

			f << p.Money << endl;

			f.close(); //closing file


		}
		else
		{

			cout << "Error in the file opening" << endl;

		}


	}


	else if (a == 'U' || a == 'u')

	{

		fstream f; //file pointer

		f.open("client3.txt", ios::in | ios::out | ios::app);

		if (f.is_open())	//varifing object is open the do the next work

		{


			UniversityStudent p;

			bool c = p.CreatAccount(); //calling CreatAccount class function
			if (c == false)
			{
				return; //not write the data if the user is not eligible and return back
			}
			//writing data to the file
			f << p.Acc_No << endl;

			f << p.Name << endl;

			f << p.Father_Name << endl;

			f << p.Address << endl;

			f << p.IDCard_No << endl;

			f << p.Money << endl;

			f.close();//closing file

		}

		else

		{

			cout << "Error in the file opening" << endl;

		}



	}


}

/*
display_all():is a function that 
print all the data 
from all the account on 
the on console window

*/



void
display_all()
{

	while (true)


	{

		fstream f; //file pointer

		f.open("client1.txt", ios::in | ios::app | ios::binary); //opening file in appending mode 

		CurrentAcc p; //CurrentAccunt Type object craeting

		if (f.is_open()) //file opening checker 

		{
			//taking data from the file
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;

			while (!f.eof())    //while loop goes to the end og file

			{

				p.ShowAccount(); //printing data on console window

				cout << "------------------------------------------" << endl;

				cout << "------------------------------------------" << endl;


				f >> p.Acc_No;   //taking data again

				f >> p.Name;

				f >> p.Father_Name;

				f >> p.Address;

				f >> p.IDCard_No;

				f >> p.Money;

			}


		}

		f.close(); //closing file

		break;

	}


	while (true)

	{


		fstream f;  //creaking file pointer

		f.open("client2.txt", ios::in | ios::app | ios::binary); //opening file

		SavingAccount p; //SavingAccount type object

		if (f.is_open())    //checking file opening

		{
			 //taking data from the file
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;


			while (!f.eof())   //take data until the end of file

			{

				p.ShowAccount();  //printing data from the file

				cout << "------------------------------------------" << endl;

				cout << "------------------------------------------" << endl;
				//taking data from the file
				f >> p.Acc_No;

				f >> p.Name;

				f >> p.Father_Name;

				f >> p.Address;

				f >> p.IDCard_No;

				f >> p.Money;
			}

		}

		f.close(); //closing file from the file

		break;


	}

	while (true)

	{


		fstream f;    //file pointer

		f.open("client3.txt", ios::in | ios::app | ios::binary); //opening file

		UniversityStudent p;  //UniversityStudent type object

		if (f.is_open())   //opening file changing

		{
			//taking data from the file
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;



			while (!f.eof())   //moves until the end of file

			{

				p.ShowAccount();  //showing data

				cout << "------------------------------------------" << endl;

				cout << "------------------------------------------" << endl;
				//taking data from the file
				f >> p.Acc_No;

				f >> p.Name;

				f >> p.Father_Name;

				f >> p.Address;

				f >> p.IDCard_No;

				f >> p.Money;

			}

		}

		f.close(); //closing file

		break;


	}


}


/*
the is a function that used to print 
the data of specific account
when have to enter the account number
and account type file searching
the particular account 

*/

void
display_sp()
{

	char Acc[14];  

	cout << "Enter the Account No:";

	cin >> Acc;   //taking account number that user 

	int flg = 0;

	while (true)

	{

		fstream f; //file pointer

		f.open("client1.txt", ios::in | ios::app | ios::binary); //opeing file

		CurrentAcc p;

		if (f.is_open())  //checking file opening

		{
			//taking data from the file
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;

			while (!f.eof())  //read until the end og file

			{

				if (!strcmp(Acc, p.Acc_No))  //comparing give account number to existing in file

				{

					p.ShowAccount();  //showing all the data of account

					flg = 1;
					f.close(); //closing the file
					return;

				}

				else

				{

					f >> p.Acc_No;

					f >> p.Name;

					f >> p.Father_Name;

					f >> p.Address;

					f >> p.IDCard_No;

					f >> p.Money;

				}

			}

		}


		break;


	}

	while (true)

	{


		fstream f;   //file pointer

		f.open("client2.txt", ios::in | ios::app | ios::binary); //opening file for raeding

		SavingAccount p;

		if (f.is_open())

		{
			//data reading
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;


			while (!f.eof())

			{

				if (!strcmp(Acc, p.Acc_No)) //account number comparing

				{

					p.ShowAccount();

					flg = 1;
					f.close(); //file closing

					return;

				}

				else

				{

					f >> p.Acc_No;

					f >> p.Name;

					f >> p.Father_Name;

					f >> p.Address;

					f >> p.IDCard_No;

					f >> p.Money;

				}


			}

		}

		break;


	}

	while (true)

	{


		fstream f;  //file pointer

		f.open("client3.txt", ios::in | ios::app | ios::binary); //file opening

		UniversityStudent p; //object creating

		if (f.is_open())

		{

			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;

			while (!f.eof())

			{

				if (!strcmp(Acc, p.Acc_No)) //comparing account

				{

					p.ShowAccount();

					flg = 1;

					return;

				}

				else

				{

					f >> p.Acc_No;

					f >> p.Name;

					f >> p.Father_Name;

					f >> p.Address;

					f >> p.IDCard_No;

					f >> p.Money;

				}

			}

		}

		f.close(); //file closing

		break;

	}


	if (flg == 0)

	{

		cout << "Record could not be found";  

	}



}

/*
dalete_account():
function is used to delet the account
when we enter the its relevant account number 
and account type
*/
void
delete_account()
{

	fstream  inFile;   //file for input
	fstream  inFile1;
	fstream  inFile2;
	fstream  outFile;//file for output

	int flag = 0;

	char Acc[14];

	cout << "Enter the Account Number you want to delet:";

	cin >> Acc;

	char choic = Selection(); //calling Selection function for getting account type

	
	while (choic == 'c' || choic == 'C')
	{
		inFile.open("client1.txt", ios::out | ios::in | ios::app | ios::binary); //opening files

		if (inFile.is_open())  //checking for file opening

		{
			outFile.open("Temp.txt", ios::out | ios::in | ios::app | ios::binary); //temporary file opening
			CurrentAcc p;
			while (!inFile.eof()) //reading until end

			{

				inFile >> p.Acc_No;

				inFile >> p.Name;

				inFile >> p.Father_Name;

				inFile >> p.Address;

				inFile >> p.IDCard_No;

				inFile >> p.Money;

				if (strcmp(p.Acc_No, Acc) != 0)

				{
					 //putting data in put file if the are not match
					outFile << p.Acc_No << endl;

					outFile << p.Name << endl;

					outFile << p.Father_Name << endl;

					outFile << p.Address << endl;

					outFile << p.IDCard_No << endl;

					outFile << p.Money << endl;

				}

				else

				{

					flag++;

				}

			}

		}

		inFile.close(); //closing flile

		outFile.close(); //closing file
		//Now thw outFile is without the Account
		remove("client1.txt");  //removing old file

		rename("Temp.txt", "client1.txt"); //renaming of file
		if (flag != 0)
		{
			cout << "\n\nRecord Deleted ..";

			return;

		}

		else if(flag==0)

		{

			cout << "The Account Cannot found." << endl;

		}

		break;

	}



	while (choic == 'S' || choic == 's')

	{
		//opening temoprary file for saving Account
		inFile1.open("client2.txt", ios::out | ios::in | ios::app | ios::binary); //opening file

		outFile.open("Temp2.txt",ios::out| ios::in | ios::app | ios::binary);

		SavingAccount p; //Savingaccount type object

		while (!inFile1.eof())  //moves until the end
		{
			//reading data from inFile1
			inFile1 >> p.Acc_No;

			inFile1 >> p.Name;

			inFile1 >> p.Father_Name;

			inFile1 >> p.Address;

			inFile1 >> p.IDCard_No;

			inFile1 >> p.Money;

			if (strcmp(p.Acc_No, Acc) != 0)

			{
				//puting data into the file
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

			}

			else

			{

				flag++;

			}

		}

		inFile1.close(); //closing the file

		outFile.close(); //closing the output file
		remove("client2.txt"); //removing older file

		rename("Temp2.txt", "client2.txt"); //renaming undated file

		if (flag != 0)

		{

			cout << "\n\nRecord Deleted ..";

			return;

		}

		else if(flag==0)

		{

			cout << "The Account Could not found" << endl;

		}

		break;


	}


	while (choic == 'u' || choic == 'U')

	{

		if (inFile2.is_open())  //check file is open or not

		{
			inFile2.open("client3.txt", ios::out | ios::in | ios::app | ios::binary);//opening file

			outFile.open("Temp3.txt",ios::out| ios::in | ios::app | ios::binary);
			UniversityStudent p;

			while (!inFile2.eof()) //read until the end

			{
				//taking data from the file
				inFile2 >> p.Acc_No;

				inFile2 >> p.Name;

				inFile2 >> p.Father_Name;

				inFile2 >> p.Address;

				inFile2 >> p.IDCard_No;

				inFile2 >> p.Money;

				if (strcmp(p.Acc_No, Acc) != 0)

				{
					//writing data into the file
					outFile << p.Acc_No << endl;

					outFile << p.Name << endl;

					outFile << p.Father_Name << endl;

					outFile << p.Address << endl;

					outFile << p.IDCard_No << endl;

					outFile << p.Money << endl;

				}
				else
				{

					flag++;

				}

			}

		}

		inFile2.close();//closing  file

		outFile.close();
		remove("client3.txt"); //remove older file

		rename("Temp3.txt", "client3.txt"); //rename file
		if (flag != 0)

		{

			cout << "\n\nRecord Deleted ..";

			return;

		}

		else if(flag==0)
			 
		{

			cout << "Rcord could not found" << endl;

		}

		break;

	}
}

/*
modify_account():This function is used to 
modify the data
that are already 
stored in the file
it works similar like the delet 
function it also store
the new data after delecting the
accout on the request of user
*/
void
modify_account()
{

	char Acc[14];

	cout << "Enter the Account Number you want to modify" << endl;

	cin >> Acc;
	char Sele_t = Selection(); //selecting the account type
	bool found = false;

	fstream inFile;

	while (Sele_t =='c'|| Sele_t =='C')

	{
		fstream outFile;    

		outFile.open("Temp1.txt", ios::in | ios::out | ios::app);//opening the file 
		
		CurrentAcc p; //creating the object

		inFile.open("client1.txt", ios::binary | ios::in | ios::out);

		while (!inFile.eof()) //read until the last
		{

			inFile >> p.Acc_No;

			inFile >> p.Name;

			inFile >> p.Father_Name;

			inFile >> p.Address;

			inFile >> p.IDCard_No;

			inFile >> p.Money;

			if (strcmp(p.Acc_No, Acc) == 0) //if the account number matches

			{

				p.ShowAccount();

				cout << "\n\n\t\t\tEnter The New Details of account" << endl;

				p.Modify();
				//writing into the file modifiled data
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

				cout << "\n\n\t\t\tRecord Updated";

				found = true;

			}
			else
			{
				//writing into the file all the previous data without modification
				//modification only done when the account number matches
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

			}

		}
		inFile.close();
		outFile.close();
		remove("client1.txt");//removing older file
		rename("Temp.txt", "client1.txt");//renaming file
		if (found == false)
		{
			cout << "Record coud not found:" << endl;
		}
		return;

	}


	while (Sele_t=='s'|| Sele_t=='S')

	{

		fstream outFile;  

		outFile.open("Temp.txt", ios::in | ios::out | ios::app);//opening file

		SavingAccount p;

		inFile.open("client2.txt", ios::binary | ios::in | ios::out);

		while (!inFile.eof())

		{
			//reading data from the file
			inFile >> p.Acc_No;

			inFile >> p.Name;

			inFile >> p.Father_Name;

			inFile >> p.Address;

			inFile >> p.IDCard_No;

			inFile >> p.Money;

			if (strcmp(p.Acc_No, Acc) == 0)

			{

				p.ShowAccount();

				cout << "\n\n\t\t\tEnter The New Details of account" << endl;

				p.Modify();
				//writing modified data
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

				cout << "\n\n\t\t\tRecord Updated";

				found = true;

			}
			else
			{
				//writing unmodified data
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

			}

		}
		inFile.close();//closing file
		outFile.close();
		remove("client2.txt");//renaming older file
		rename("Temp.txt", "client1.txt"); //renaming new modified file with older name 
		if (found == false)
		{
			cout << "Record coud not found:" << endl;
		}
		return;

	}


	while (Sele_t=='u'||Sele_t=='U')

	{

		fstream outFile; //file pointer
		outFile.open("Temp.txt", ios::in | ios::out | ios::app);//file opening

		UniversityStudent p;

		inFile.open("client3.txt", ios::binary | ios::in | ios::out);

		while (!inFile.eof())

		{
			//reading data fro the user

			inFile >> p.Acc_No;

			inFile >> p.Name;

			inFile >> p.Father_Name;

			inFile >> p.Address;

			inFile >> p.IDCard_No;

			inFile >> p.Money;

			if (strcmp(p.Acc_No, Acc) == 0)

			{

				p.ShowAccount();//showing  data

				cout << "\n\n\t\t\tEnter The New Details of account" << endl;

				p.Modify(); //modifying data
				//writing agiain to the file
				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

				cout << "\n\n\t\t\tRecord Updated";

				found = true;

			}
			else
			{

				outFile << p.Acc_No << endl;

				outFile << p.Name << endl;

				outFile << p.Father_Name << endl;

				outFile << p.Address << endl;

				outFile << p.IDCard_No << endl;

				outFile << p.Money << endl;

			}

		}
		inFile.close();
		outFile.close();
		remove("client3.txt"); //renaming older file
		 
		rename("Temp.txt", "client3.txt");//renaming new modified file with older name 
		if (found == false)
		{
			cout << "Record coud not found:" << endl;
		}
		return;



	}


}
/*

this is a function used to print money of
selected account from  the user

*/

void
ReturnMoney()
{


	char Acc[14];

	cout << "Enter the Account No:" << endl;

	cin >> Acc;

	int flg = 0;


	while (true)


	{

		fstream f;//file pointer

		f.open("client1.txt", ios::in | ios::app | ios::binary);//file opening

		CurrentAcc p;
		//taking data from the file
		f >> p.Acc_No;

		f >> p.Name;

		f >> p.Father_Name;

		f >> p.Address;

		f >> p.IDCard_No;

		f >> p.Money;

		while (!f.eof()) //read until the end

		{

			if (!strcmp(Acc, p.Acc_No))//true when the account numbers matches

			{
				cout << "The amount of money in your Account is:" << endl;
				cout << p.Money;//print Money
				f.close(); //file close

				flg = 1;

				return;

			}


			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;

		}

		break;



	}




	while (true)

	{


		fstream f; //file pointer

		f.open("client2.txt", ios::in | ios::app | ios::binary); //opening  file

		SavingAccount p; //SavingAccount object

		if (f.is_open()) //check file opening

		{

			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;


			while (!f.eof()) //pointer moves until the end

			{

				if (!strcmp(Acc, p.Acc_No)) //comparing Account Number

				{
					cout << "The amount of money in your Account is:" << endl;
					
					cout << p.Money << endl;

					flg = 1;

					f.close();//closing file


					return;

				}

				f >> p.Acc_No;

				f >> p.Name;

				f >> p.Father_Name;

				f >> p.Address;

				f >> p.IDCard_No;

				f >> p.Money;



			}

		}

		break;


	}

	while (true)

	{


		fstream f; //file ponter 

		f.open("client3.txt", ios::in | ios::app | ios::binary); //file opening

		UniversityStudent p; //UniversityStudent object

		if (f.is_open()) //checking for file opening

		{
			//reading data from the file
			f >> p.Acc_No;

			f >> p.Name;

			f >> p.Father_Name;

			f >> p.Address;

			f >> p.IDCard_No;

			f >> p.Money;

          while (!f.eof())

			{

				if (!strcmp(Acc, p.Acc_No))

				{
					cout << "The amount of money in your Account is:" << endl;
					cout << p.Money << endl;
					f.close();//closing the file
					flg = 1;

					return;

				}

				f >> p.Acc_No;

				f >> p.Name;

				f >> p.Father_Name;

				f >> p.Address;

				f >> p.IDCard_No;

				f >> p.Money;


			}

		}

		

		break;

	}

	if (flg == 0)

	{

		cout << "Record could not be found";

	}


}


/*
this is a function that return the
interest rat per trasection on
selected account type
*/



void
Interest()
{


	cout << "Select your Account Type:" << endl;

	char ch = Selection();

	if (ch == 'c' || ch == 'C')

	{

		CurrentAcc a;

		cout << "The interest rate of Current Account is:" << endl;

		cout << a.interestRat();

	}

	else if (ch == 's' || ch == 'S')

	{

		SavingAccount a;

		cout << "The interest rate of Saving Account is:" << endl;

		cout << a.interestRat();


	}

	else if (ch == 'u' || ch == 'U')

	{

		UniversityStudent a;

		cout << "The interest rate of Universiy Account is:" << endl;

		cout << a.interestRat();

	}

	else

	{

		try  //try block
		{

			if (ch != 'c' || ch != 'C' || ch != 'S' || ch != 's' || ch != 'U'
				|| ch != 'u')

			{

				throw ch; //throw exception

			}

		}

		catch (char a)
		{

			cout << a;

			cout << "this is not good choic." << endl;

		}
	}


}

/*
ExchangeRat():This is a function that is 
used to print the exchange from differnt other 
currencies into the Hungarian Forints
*/
void

ExchangeRate()
{

	ifstream file;

	file.open("exchange.txt", ios::in | ios::app | ios::binary); //opening the existing file

	if (!file)

	{

		cout << "You have not added file for Currencyexchange" << endl;

	}

	while (!file.eof())

	{

		string a;

		getline(file, a); //getting data from the file

		cout << a << endl;

	}

}

/*
ExchangeRateCal():
this function more or less 
works like calculator that 
used to amount to Money in forints
from other currencies

*/


void
ExchangeRateCal()
{

	int sel, l;

	cout << "Enter the Number in Manu:" << endl;

	cout << "1.DOLLAR(AMERICAN)TO HUF" << endl;

	cout << "2.POUND TO HUF" << endl;

	cout << "3.EURO   TO HUF" << endl;

	cout << "4.TURKISH LIRA TO HUF" << endl;

	cout << "5.RYAL TO HUF" << endl;

	cout << "6.PAKISTANI RUPEE TO HUF" << endl;

	cout << "7.INDIAN RUPEE TO HUF" << endl;

	cin >> l;

	cout << "Enter the amount:" << endl;

	cin >> sel;

	switch (l)

	{

	case 1:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 325;

		break;

	case 2:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 400;

		break;

	case 3:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 350;

		break;

	case 4:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 45;

		break;

	case 5:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 80;

		break;

	case 6:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 2;

		break;

	case 7:

		cout << "YOUR MONEY IN HUF IS:" << endl;

		cout << sel * 4;

		break;

	default:

		cout << "You slected wrong choice" << endl;

		break;

	}


}




