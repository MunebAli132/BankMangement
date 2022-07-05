#pragma once
#include "BankMain.h"
/*
this file has the functions
that we have to define in cpp
file for saving account
*/
class SavingAccount :public BankMain
{


public:
    SavingAccount();// default constructor 
   
    bool CreatAccount();//This a function that is used to create account

    void ShowAccount();//this is function used
    void Dep();

    void With();

    int interestRat();//It is used to return interest rat

    void Modify(); //it used to modify account
    
};



