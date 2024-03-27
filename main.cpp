/*
# Author:             James Calder
# BannerID:           
# Course:             CS 181
# Assignment:         PA4
# Date Assigned:      Monday, Mar. 18, 2024
# Date Due:           Saturday, Mar. 30, 2024   11:55 pm

# Description:        This program will exercise Object Oriented concepts with C++.

# Certification of Authenticity:
    I certify that this assignment is entirely my own work.
*/

//This program should process information for several managers and return the highest paid manager as well as the group average pay.

#include <iostream>
#include <iomanip>

#include "Employee.h"
#include "Manager.h"

using namespace std;

int main()
{
    cout << "Enter number of managers: ";
    int manNum;
    cin >> manNum;
    cout << endl;

    Manager* managers[manNum]; //array used to store pointers to each manager

    for (int i = 0; i<manNum; i++)
    {
        string name;
        double wage, hours, bonus;
        cout << "Enter manager " << i << " name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;

        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;

        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        Manager * man = new Manager(name, wage, hours, bonus); //creating dynamic manager object with user specified data
        managers[i] = man;

        cout << endl;
    }

    string highestName;
    double highestComp = 0;
    double avgPay = 0;
    for (int i = 0; i<manNum; i++)
    {
        avgPay += managers[i]->calcPay();
        if (managers[i]->calcPay() > highestComp) //comparing compensation to previous highest
        {
            highestComp = managers[i]->calcPay();
            highestName = managers[i]->getName();
        }

        delete managers[i]; //clearing memory used for dynamic objects
    }
    avgPay /= manNum;

    cout << fixed << setprecision(2); //formatting double output
    cout << "Highest paid manager is " << highestName << " who is paid $" << highestComp << endl;
    cout << "Average pay is $" << avgPay << endl;

    return 0;
}