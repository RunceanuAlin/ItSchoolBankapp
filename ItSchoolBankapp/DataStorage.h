#pragma once
#include "ContBancar.h"
#include <fstream>
#include<string>
#include <vector>
class DataStorage
{
	std::string nume;
	std::string prenume;
	std::string iban;
	std::vector <ContBancar*> datecont;

public:
	DataStorage();
	DataStorage(ContBancar* contCurent);
	~DataStorage();
	void scriereDate();
	void citireDate();
	ContBancar* getConturi(int index);
    int dimensiuneData() 
	{ 
		return datecont.size(); 
	};
};