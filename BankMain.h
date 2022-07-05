#pragma once
/*
this file define the main class
variable 
and methods
*/
#include<string>
class BankMain
{


public:
    char* Acc_No;    //Variable for storing Account Number

    char* Name;     //Variable for  Number of account holder

    char* Father_Name;   //Variable for  account holder's father name

    char* Address;         //Variable for  account holder's address

    char* IDCard_No;       //Variable for  account IDCARD number

    double Money;          //Variable for  storing Money

    char Type;       //Account Type

    int interest;     //interset value

    BankMain();      //constructor

    ~BankMain();     //Destructors


    virtual bool CreatAccount() = 0;   //function for creating Account

    virtual void ShowAccount() = 0;  //function for showing Account details

    virtual void Dep() = 0;

    virtual void With() = 0;

    virtual int interestRat() = 0; //function that returns the interst rate

    virtual void Modify() = 0; //class function that is used to modify data


};


