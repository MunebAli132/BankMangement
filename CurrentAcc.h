#pragma once
#include "BankMain.h"
/*
this file has the functions 
that we have to define in cpp
file for current account
*/
class CurrentAcc :public BankMain
{


public:

    CurrentAcc();// default constructor 

    bool CreatAccount();//This a function that is used to create account

    void ShowAccount();//this is function used
    void Dep();

    void With();

    int interestRat();//It is used to return interest rat

    void Modify(); //it used to modify account

};


