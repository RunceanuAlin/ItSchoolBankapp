#pragma once
#include <string>

enum class TIP_CONT
{

	CONT_RON, CONT_EURO, INDISPONIBIL

};
class ContBancar
{
private:
	std::string nume;
	std::string prenume;
	int sold;
	TIP_CONT eTipCont;
	std::string IBAN;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);
	std::string GetNume();
	std::string GetPrenume();
	std::string GetIban();
	~ContBancar();
};