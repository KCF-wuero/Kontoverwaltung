//
// Created by KCF on 08/11/2022.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Konto.h"



Konto ::Konto(std::string kontoInhaber,std::string password)
{

    this->kontoInhaber = kontoInhaber;
    this->password = password;
    this->balance = 0;

}

Konto createAccount(std::string inhaber,std:: string password)
{



    Konto Account(inhaber,password);

    return Account;
}

void Konto::withdraw(int withdrawAmount)
{

         if(balance > withdrawAmount)
         {
             balance -= withdrawAmount ;
             return;
         }
         else
         {
             std::cout << "Your balance is to low"<<std::endl;
         }



}

bool Konto::loginCheck() {

    if(!activ)
    {
    std::cout<<"Your account has been disabled\n";
        return false ;
    }
    std::string sTemp;
    std::cout << "Please input your accounts password\n>";
    std::cin >> sTemp;
    if (sTemp == password) {
        std::cout<<"Your Accounts balance is: "<<balance<<std::endl;
        return true;

    } else {
        std::cout << "The password you input is wrong\n";
        return false;
    }




}

   void Konto::deposit(int depositamount)
   {
        if (depositamount > 0){

            balance += depositamount;

        }
        else
        {
            std::cout<<"you canot deposit 0 or negativ numbers"<<std::endl;
        }

   }

void Konto::transfairfunds(int transferamount,int transfacc, std::vector<Konto> &konten) {



    if (transferamount < balance && activ && transferamount > 0) {

        balance -= transferamount;

        konten.at(transfacc).balance += transferamount;
        std::cout << "The funds have been transferd successfully" << std::endl;
    } else {
        std::cout << "The transfer has failed Please check your balance" << std::endl;

    }
}
void Konto::deactivateAccount()
{
    std::string sTemp;
        std::cout <<"Are you shure you want to deaktivate your account[Y/N]\n>";
        std::cin >> sTemp;
    if(sTemp == "y"||sTemp == "Y")
    {
        activ = false;
        std::cout << "your account has been succesfully deactivated\n";
    }
    else
    {
        std::cout <<"your account has not been deactivated\n";


    }
}


void Konto::logaction(char selection,int kontoID,std::vector<Konto>& Konto)
{
    std::fstream Log;
        Log.open("Log.txt",std::fstream::app);
    if(!Log)
        std::cout << "Error while creating the file";


     switch (selection) {

         case '1' :
             Log << "Account has been created by " << Konto.at(kontoID).kontoInhaber << std::endl;
         break;


         case '4':
            Log<<"The account from "<<Konto.at(kontoID).kontoInhaber << " was deaktivated"<<std::endl;
             break;





     }


}

void Konto::logaction()
{
    std::fstream Log;
        Log.open("Log.txt", std::fstream::app);
    if(!Log)
        std::cout << "Error while creating the file";






        Log << "The programm has been shut down " << std::endl;



}

void Konto::logaction(char selection,int amount,int kontoID,std::vector<Konto>& Konto)
{

    std::fstream Log;
        Log.open("Log.txt",std::fstream::app);
    if(!Log)
        std::cout << "Error while creating the file";
switch(selection)
{
    case '2':
        Log <<Konto.at(kontoID).kontoInhaber << " withdrew " << amount <<" from his account"<<std::endl;
        break;


    case '3':
        Log << Konto.at(kontoID).kontoInhaber <<" has deposited "<< amount <<" to his account"<<std::endl;
        break;


    case '8':
        Log << Konto.at(kontoID).kontoInhaber <<" has been destroyed"<<std::endl;
        break;


}




}

void Konto::logaction(char selection, int kontoID, int amount, int transfairtarget, std::vector<Konto> Konto) {

    std::fstream Log;
        Log.open("Log.txt",std::fstream::app);
    if(!Log)
        std::cout << "Error while creating the file";

    if(selection == '5')
    {
        Log << Konto.at(kontoID).kontoInhaber <<" tranfeired "<< amount << " to " <<Konto.at(transfairtarget).kontoInhaber<< std::endl;

    }

}


Konto::~Konto(){};



