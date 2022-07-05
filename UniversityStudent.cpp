#include "UniversityStudent.h"
#include<iostream>
using namespace std;
/*
this file has the deifnation
of function that are prsent
in the header file
for student Account
*/

UniversityStudent::UniversityStudent() //default constructor
{

    Type = 'u';

    interest = 10;
}
/*
this function that get data from user
on the basis of asking his eligiblity
of the Account opening person varify the
eligiblity by 'y' sign then it will ask for futher inputs
it will ask to enter the amonut of will >=0
if you put wrong amount then it will ask you
agian to enter the money
until you enter >=0
if you enter this money it will proceed next
and print the message of account has been
open succeefully
*/
bool
UniversityStudent::CreatAccount()
{

    char choice;
    /*
    criteria for university student's account opening
    */
    cout << "Welcome to bank system kindly first read the requirments:" <<
        endl;

    cout <<
        "1.You should be 18 years old\n2.You must have Pakistani valid ID card.\n3.You must be a university Student.\n4. you must have the proof of your Active smester\n5.If you donot have id card you can enter the your Father Id"
        << endl;

    cout << "You have these Documents y|n " << endl;

    cin >> choice;


    if (choice == 'y' || choice == 'Y')

    {

        cout << "you can creat ccount!!!" << endl;

        cout << "Kindly ender your Data correctly:" << endl;

        cout << "Please Enter the Account Number" << endl;

        cin >> Acc_No; //getting clients account number

        cout << "Pleae Enter the The Name of Person:" << endl;

        cin.ignore();

        cin.get(Name, 20);//getting client's account name

        cout << "Enter the Father Name :" << endl;

        cin.ignore();

        cin.get(Father_Name, 20);//getting client's father name

        cout << "Enter the home address :" << endl;

        cin.ignore();

        cin.get(Address, 50);//getting client's address

        cin.ignore();

        cout << "Enter Id card No: :" << endl;

        cin.get(IDCard_No, 14);//getting clients idcard number

        cout << "How much money you want to Enter first time" << endl;


        while (2 > 1)

        {
            cin >> Money;

            if (Money >= 0)

            {
                cout << "Your account has been created successfully";
                return true;

                break;
            }

            else

            {

                cout << "Kindly Enter the Valid money again" << endl;


            }


        }

    }

    else if (choice == 'n' || choice == 'N')

    {

        cout << "your cannot ceart current accout" << endl;
        return false;


    }

    else

    {

     cout << "your choice was not correct" << endl;
       return false;


    }

}

/*
this is a funtion that is used
to print all the attributes on the
console secreen when is called
*/

void
UniversityStudent::ShowAccount()
{

    cout << "Account Number is:" << Acc_No << endl;

    cout << "The name of Account holder is:" << Name << endl;

    cout << "The father name is :" << Father_Name << endl;

    cout << "The address is given as:" << Address << endl;

    cout << "The ID card is :" << IDCard_No << endl;

    cout << "The money in it is:" << Money << endl;


}

void

UniversityStudent::Dep()
{


    double x;

    cout << "Enter the amout that you want to Enter";

    cin >> x;

    Money = Money + x;


}

void

UniversityStudent::With()
{


    if (Money - interest < 0)

    {

        cout << "you cannot perform this process" << endl;

    }

    else

    {

        Money = Money - interest;

        cout << "the withdrawal is done" << endl;

    }


}



int
UniversityStudent::interestRat() //return interest rate
{

    return interest;

}

/*
this function used to modify the attributes
values*/



void
UniversityStudent::Modify()
{


    cout << "Please Enter the Account Number" << endl;


    cin >> Acc_No;

    cout << "Pleae Enter the The Name of Person:" << endl;

    cin.ignore();

    cin.get(Name, 20);

    cout << "Enter the Father Name :" << endl;

    cin.ignore();

    cin.get(Father_Name, 20);

    cout << "Enter the home address :" << endl;

    cin.ignore();

    cin.get(Address, 50);

    cin.ignore();

    cout << "Enter Id card No: :" << endl;

    cin.get(IDCard_No, 14);

    cout << "How much money you want to Enter first time" << endl;

    cin >> Money;

    cout << "Your account has been modfoied successfully";

}
