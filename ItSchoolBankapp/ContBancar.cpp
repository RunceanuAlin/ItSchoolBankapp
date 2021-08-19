#include "ContBancar.h"


ContBancar::ContBancar(std::string nume, std::string prenume, std::string iban)
{
	this->nume = nume;
	this->prenume = prenume;
	IBAN = iban;
	sold = 0;
	eTipCont = TIP_CONT::CONT_RON;
}

std::string ContBancar::GetNume()
{
	return nume;
}

std::string ContBancar::GetPrenume()
{
	return prenume;
}

std::string ContBancar::GetIban()
{
	return IBAN;
}
