#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "Konto.h"



char selection;
int main() {

    void addAccount(std::vector<Konto> &);
    void addAccount(std::string, std::vector<Konto> &);

    bool running = true;
    std::string sTemp;
    int iTemp;
    int withdrawamount;
    int depositamount;
    int transfacc = 0;
    srand(time(NULL));
    std::vector<Konto> konten;
    std::vector<Konto> &refkonten = konten;






    enum menu {
        create = '1', withdraw = '2', deposit = '3', deactivate = '4', transfer = '5', shutdown = '6',
        destroyaccount = '8' , test = '9'
    };

    while (running) {


        std::cout << "Pleas select what u want to do from the following options :\n"
                  << "1.Create a Account\n"
                  << "2.withdraw from existing account\n"
                  << "3.deposit into your account\n"
                  << "4.deactivate an account\n"
                  << "5.Transfair money\n"
                  << "6.shut down the programm\n>";
        fflush(stdin);
        std::cin >> selection;

        /* if(isdigit(selecteion)== false)
         {
             std::cout<< "the only valide inputs are numbers";
             selecteion = 0;

         }*/
        try {
            switch (selection) {


                case create :
                    addAccount(refkonten);

                    break;

                case withdraw :

                    std::cout << "Please input your account ID\n>";
                    std::cin >> iTemp;

                    if (konten.at(iTemp).loginCheck() == true) {


                        std::cout << "Please input the amount u want to withdraw\n>";
                        std::cin >> withdrawamount;
                        konten.at(iTemp).logaction(selection, withdrawamount, iTemp,refkonten);
                        konten.at(iTemp).withdraw(withdrawamount);
                    }
                    break;

                case deposit :

                    std::cout << "Please input your account ID\n>";
                    std::cin >> iTemp;
                    if (konten.at(iTemp).loginCheck() == true) {


                        std::cout << "Please input the amount u want to deposit\n>";
                        std::cin >> depositamount;
                        konten.at(iTemp).logaction(selection, depositamount, iTemp,refkonten);
                        konten.at(iTemp).deposit(depositamount);
                    }
                    break;

                case deactivate :
                    std::cout << "Please input the ID of the account u want to deactivate" << std::endl;
                    std::cin >> iTemp;
                    if (konten.at(iTemp).loginCheck() == true) {
                        konten.at(iTemp).logaction(selection,iTemp,refkonten);
                        konten.at(iTemp).deactivateAccount();

                    }
                    break;

                case transfer:
                    std::cout << "Please input your account ID\n>";
                    std::cin >> iTemp;
                    if (konten.at(iTemp).loginCheck() == true) {


                        std::cout << "Please input the amount u want to transfer\n>";
                        std::cin >> depositamount;


                        std::cout << "Input the ID of the account u want to transfer to\n>";
                        std::cin >> transfacc;

                        konten.at(iTemp).logaction(selection, iTemp, depositamount, transfacc, refkonten);
                        konten.at(iTemp).transfairfunds(depositamount, transfacc, refkonten);
                    }
                    break;

                case shutdown:

                    std::cout << "Are you shure u want to shut down the program [Y/N]\n>";
                    std::cin >> sTemp;
                    if (sTemp == "Y" || sTemp == "y") {
                        std::cout << "Program is shutting down" <<
                                  std::endl;
                        konten.at(iTemp).logaction();
                        running = false;
                    }

                    break;
                case destroyaccount:
                    std::cout<< "Please input the ID of the account u want to destroy completely\n>";
                    std::cin>>iTemp;
                    konten.at(iTemp).loginCheck();
                    konten.at(iTemp).logaction(selection,0,iTemp,refkonten);
                    konten.at(iTemp).~Konto();

                    break;

                case test:
                    std::cout << "now starting test"<<std::endl;
                    for (int i = 0; i < 10; i++) {
                        addAccount(std::to_string(i),refkonten);
                        konten.at(i).deposit(1000000);
                    }
                    for (int i = 0; i < 50; i++)
                    {
                    int account1 = rand() % 10;
                    int account2 = rand() % 10;
                    int transfam = rand() % 10000;
                    konten.at(account1).logaction('5',account1,transfam,account2,refkonten );
                    konten.at(account1).transfairfunds(transfam,account2,refkonten);

                    }

                    for (int i = 0; i < 10; i++) {
                        std:: cout << "balance is " << konten.at(i).balance<<" of account "<<konten.at(i).kontoInhaber<<std::endl;
                    }
                    std::cout <<"the test has finished"<<std::endl;


                    break;

                default:
                    std::cout << "Pleas select one out of the 6 options\n\n";
                    break;


            }


        }
            catch (...) {
                std::cout << "the account you are trying to acces doesen't exist " << std::endl;
            }

    }




    return 0;
}

    void addAccount(std::vector<Konto> &konten) {
        static int pos = 0;
        std::string temp = "";
        std::string temppasw = "";
        std::cout << "Please input pleas input you name\n>";
        std::cin >> temp;
        std::cout << "Please set a password\n>";
        std::cin >> temppasw;
        konten.push_back(createAccount(temp,temppasw));
        std::cout<<"the account was created with the ID: "<<pos<<std::endl<<std::endl;
        konten.at(pos).logaction(selection,pos,konten);
        pos++;


    }

    void addAccount(std::string temp,std::vector<Konto> &konten)
    {
    static int pos = 0;
    std::string temppasw = " ";
        konten.push_back(createAccount(temp,temppasw));
        konten.at(pos).logaction('1',pos,konten);
        pos++;

    }

