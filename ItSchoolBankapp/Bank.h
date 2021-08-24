#pragma once
#include"ContBancar.h"
#include <vector>
#include<iostream>
#include <fstream>
#include "DataStorage.h"

class Bank
{
public:

	Bank();
	~Bank();
	TIP_CONT selectareMoneda();
	void adaugareCont();
	void vizualizareConturi();
	void modificareConturi();
	std::string createIban();

	std::vector<ContBancar*> m_ConturiBancare;
	

};