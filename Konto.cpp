//
// Created by KCF on 08/11/2022.
//
#include <iostream>
#include <iomanip>
#include <vector>
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

void Konto::transfairfunds(int transferamount, std::vector<Konto> &konten) {

    int transfacc = 0;
    std::cout << "Input the ID of the account u want to transfer to\n>";
    std::cin >> transfacc;

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
std::cout <<"Are you shure you want to deaktivate your account[Y/N]";
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


void Konto::logaction(int selection)
{
 std::fstream Log;
 Log.open("Log",iso::out);
 if(!Log) {
     std::cout << "Error while creating the file";
 }
 else{
     switch (selection) {

         case 1 :

         break;

         case 2:

             break;

         case 3:

             break;

         case 4:

             break;

         case 5:

             break;

         case 6:

             break


     }
 }



}




