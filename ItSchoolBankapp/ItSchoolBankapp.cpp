// ItSchoolBankapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Bank.h"
#include<fstream>

int main()
{
   
    //instantam o banca
    Bank* itSchoolBank = new Bank();
    bool isRunning = true;
   
    do
    {
        system("CLS");

        std::cout << "Meniu Principal \n";
        std::cout << "1 -> Adaugare cont \n";
        std::cout << "2 -> Vizualizare conturi \n";
        std::cout << "3 -> Modificare conturi \n";
        std::cout << "9 -> Exit \n";
        std::cout << "Introduceti optiunea \n";
        char optiune;
        std::cin >> optiune;
        switch (optiune)
        {
        case '1':
            system("CLS");
            itSchoolBank->adaugareCont();
            break;
        case'2':
            system("CLS");
            itSchoolBank->vizualizareConturi();
            break;
        case'3':
            system("CLS");
            itSchoolBank->modificareConturi();
            break;
        case'9':
            std::cout << "Thank you \n";
            isRunning = false;
            break;
        default:
            system("CLS");
            std::cout << "Optiunea nu este valida \n";
            break;
        }

    } while (isRunning);







    delete itSchoolBank;
}

