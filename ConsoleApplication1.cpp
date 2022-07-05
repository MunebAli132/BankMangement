
/*
Min testing file 
main manue
calling functions
*/
#include "BankMain.h"
#include "SavingAccount.h"
#include "CurrentAcc.h"
#include "UniversityStudent.h"
#include<fstream>
#include<iostream>
using namespace std;
//All functions prototype
char Selection();

void write_account();

void display_all();

void display_sp();

void delete_account();

void modify_account();

void ReturnMoney();

void Interest();

void ExchangeRate();

void ExchangeRateCal();

int
main()
{

    int ch;
    system("color 2F");

    do
                    //do while loop for manu and user interface
    {

        cout << "\n\n\t\t\t\t======================\n";

        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";

        cout << "\n\t\t\t\t======================\n";


        cout << "\t\t\t\t    ::MAIN MENU::\n";

        cout << "\n\t\t\t\t1. NEW ACCOUNT";

        cout << "\n\t\t\t\t2. INTEREST RATE";

        cout << "\n\t\t\t\t3. ALL ACCOUNT HOLDER LIST";

        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";

        cout << "\n\t\t\t\t5. SEARCHING PARICULAR ACCOUNT";

        cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";

        cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";

        cout << "\n\t\t\t\t8. EXCHANGE RATE INTO FORINTS";

        cout << "\n\t\t\t\t9. EXCHANGE CALCULATOR";

        cout << "\n\t\t\t\t10. EXIT";

        cout << "\n\n\t\t\t\tSelect Your Option (1-10): ";

        cin >> ch;

                                          //switch statemnts for selecteding multiple options
        switch (ch)

        {

        case 1:

            write_account();

            break;

        case 2:

            Interest();

            break;

        case 3:

            display_all();

            break;

        case 4:

            ReturnMoney();

            break;

        case 5:

            display_sp();

            break;

        case 6:

            delete_account();

            break;

        case 7:

            modify_account();

            break;

        case 8:

            ExchangeRate();

            break;

        case 9:

            ExchangeRateCal();

            break;

        default:
            cout << "\a";

        }

        cin.ignore();

        cin.get();

    } while (ch != 10);

    return 0;


}




