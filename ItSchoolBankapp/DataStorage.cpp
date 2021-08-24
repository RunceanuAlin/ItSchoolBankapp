#include "DataStorage.h"

DataStorage::DataStorage()
{
}

DataStorage::DataStorage(ContBancar* contCurent)
{
	nume = contCurent->GetNume();
	prenume = contCurent->GetPrenume();
	iban = contCurent->GetIban();
}

DataStorage::~DataStorage()
{
	datecont.clear();
}

void DataStorage::scriereDate()
{
	std::ofstream continut("ListaConturi.csv");
	continut << nume << ' ' << prenume << ' ' << iban << std::endl;
	continut.close();
}

void DataStorage::citireDate()
{
	std::ifstream continut("ListaConturi.csv");
	while (continut >> nume >> prenume >> iban)
	{
		ContBancar* cont = new ContBancar(nume, prenume, iban);
		datecont.push_back(cont);
	}

}

ContBancar* DataStorage::getConturi(int index)
{
	return datecont.at(index);
}