//
// Created by KCF on 08/11/2022.
//
#include <string>
#include <vector>

#ifndef KONTOVERWALTUNG_KONTO_H
#define KONTOVERWALTUNG_KONTO_H


class Konto {
public:
    bool activ = true;
    std::string kontoInhaber = " ";
    std::string password = "";
    int balance = 0;

    void transfairfunds(int,std::vector<Konto>&);

    bool loginCheck();

    void deactivateAccount();

    void deposit(int);

    void withdraw(int);

    Konto(std::string,std::string);

    void logaction(int);


};

Konto createAccount(std::string,std::string);

#endif //KONTOVERWALTUNG_KONTO_H
