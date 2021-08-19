#pragma once
#include"ContBancar.h"
#include <vector>
#include<iostream>
#include <fstream>

class Bank
{
public:

	Bank();
	~Bank();
	TIP_CONT eSelectCurrency();
	void adaugareCont();
	void vizualizareConturi();
	void modificareConturi();
	std::string createIban();

	std::vector<ContBancar*> m_ConturiBancare;
	

};