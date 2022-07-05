#include "BankMain.h"
#include<iostream>
#include<string>
/*
cpp file of BankMain haderfile
Defination of Functions
constructor and Destrucots
*/
BankMain::BankMain() //constructor for Dynamic memory allocation
{


    Acc_No = new char[14];


    Name = new char[20];


    Father_Name = new char[20];	
    Address = new char[50];


    IDCard_No = new char[14];


    Type = '\0';


    interest = 0;


    Money = 0;


}

BankMain::~BankMain()
{				//Destructos  for Dynamic memory return to system

    delete[]Acc_No;


    delete[]Name;


    delete[]Father_Name;

    delete[]Address;


    delete[]IDCard_No;



}
