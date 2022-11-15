//
// Created by KCF on 08/11/2022.
//
#include <ctime>
#include <string>
#include <vector>
#include <ratio>
#include <chrono>

#ifndef KONTOVERWALTUNG_KONTO_H
#define KONTOVERWALTUNG_KONTO_H


class Konto {
public:

    
    bool activ = true;
    std::string kontoInhaber = " ";
    std::string password = "";
    int balance = 0;

    void transfairfunds(int,int,std::vector<Konto>&);

    bool loginCheck();

    void deactivateAccount();

    void deposit(int);

    void withdraw(int);


    Konto(std::string,std::string);

    ~Konto();


    static void logaction(char, int, std::vector<Konto>&);
    void logaction(char,int,int,std::vector<Konto>&);
    void logaction(char, int, int, int, std::vector<Konto>);
    void logaction();

};

Konto createAccount(std::string,std::string);

#endif //KONTOVERWALTUNG_KONTO_H
