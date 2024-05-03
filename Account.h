#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

class Account {
protected:
    string ID, holderName, type;
    string username, password;
    int startingBalance, pincode;
    double current_balance;
public:
    Account() {
        current_balance = 50000;
        username = "ahsan";
        password = "12345";
    }
    bool login();
    void menu();
    void showCustomer();
    void Withdraw_Cash(double, double);
    void Deposit_Cash(double, double);
    void Cash_Transfer(int, int, int, int);
    void Display_Balance(double);
    void bar_Load();
    void showAdministrator();
    void createAccount();
    void date();
    void SearchRecord();
    void updateRecord();
    void delRecord();
};

#endif // !ACCOUNT_H
