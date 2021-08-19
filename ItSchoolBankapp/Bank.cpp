#include "Bank.h"
#include <ctime>

Bank::Bank()
{
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

TIP_CONT Bank::eSelectCurrency()
{
	std::cout << "Alegeti moneda contului din lista de mai jos: \n";
	std::cout << "1->EURO \n";
	std::cout << "3->RON \n";
	std::cout << "Selectie: \n";
	int iChosenCurrency; std::cin >> iChosenCurrency;

	switch (iChosenCurrency)
	{
	case '1':
		return TIP_CONT::CONT_EURO;
	case '2':
		return TIP_CONT::CONT_RON;
	default:
		return TIP_CONT::INDISPONIBIL;
	}
}

std::string Bank::createIban()
{

	std::string sIban[6]{ "RO", "ITBK" };

	TIP_CONT eUserCurrency{ eSelectCurrency() };

	for (int i = 5; i > 2; i--)
	{
		(i == 5) ? srand(time(NULL)) : srand(std::stoi(sIban[i + 1]));

		sIban[i] = std::to_string(rand() % 9999 + 1000);
	}

	switch (eUserCurrency)
	{
	case TIP_CONT::INDISPONIBIL:
		return "IBAN invalid.\n";
	case TIP_CONT::CONT_EURO:
		sIban[2] = "EEUR";
		break;
	case TIP_CONT::CONT_RON:
	{
		srand(std::stoi(sIban[3]));
		sIban[2] = std::to_string(rand() % 8999 + 1000);
	}
	break;
	default:
		break;
	}

	srand(time(NULL) + std::stoi(sIban[4])); std::string sValidationCode = std::to_string(rand() % 89 + 10);
	sIban[0] += sValidationCode;

	std::string sGeneratedIban;
	for (auto sequence : sIban)
		sGeneratedIban += sequence;

	return sGeneratedIban;
}



void Bank::adaugareCont()
{
	system("CLS");
	std::cout << "Introduceti numele utilizatorului: \n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele utilizatorului: \n";
	std::string prenume;
	std::cin >> prenume;
	std::string iban = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(cont);
	std::cout << "1 -> pentru crearea unui cont \n";
	std::cout << "2 -> pentru meniul principal \n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case'1':
		adaugareCont();
		break;
	default:
		break;
	}
}





void Bank::vizualizareConturi()
{
	system("CLS");
	std::string nume;
	std::cin >> nume;
	std::string prenume;
	std::cin >> prenume;
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;
	if (!m_ConturiBancare.empty())
	{
		for (int i = 0; i < m_ConturiBancare.size(); i++)
		{

			std::cout << "Contul " << i + 1 << " : " << m_ConturiBancare[i]->GetNume() << std::endl;
			std::cout << m_ConturiBancare[i]->GetPrenume() << std::endl;
			//std::cout << m_ConturiBancare[i]->GetIban() << std::endl;
			//std::cout << m_ConturiBancare[i]->GetSold() << std::endl;
		}
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case'1':
			std::cout << "Going back \n";
			break;
		default:
			break;

		}
	}
	else
	{
		std::cout << "Niciun cont inregistrat \n";



	}
}

void Bank::modificareConturi()
{
	system("CLS");
	//intrebati operatorul care cont doreste sa il modifice
	std::cout << "Introduceti numele si prenumele contului \n";
	std::cout << "Introduceti numele de familie \n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele \n";
	std::string prenume;
	std::cin >> prenume;
	ContBancar* temp = nullptr;

	//cautam contul


	std::vector<ContBancar*>::iterator it;

	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->GetNume() && prenume == (*it)->GetPrenume())
		{
			temp = *it;
			break;

		}
	}

	//in cazul in care nu avem cont gasit
	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit \n";
		std::cout << "1-> intoarcere la meniul principal \n";
		std::cout << "2-> creati un cont \n";
		std::cout << "3-> cautati un alt cont \n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case'1':
			std::cout << "Going back \n";
			break;
		case'2':
			adaugareCont();
			break;
		case'3':
			modificareConturi();
			break;
		default:
			break;
		}


	}
	else
	{
		std::cout << "Ce modificari vreti sa faceti? \n";
		std::cout << "1->Pentru stergere cont \n";
		m_ConturiBancare.erase(it);
		std::cout << "2->Pentru modificare nume \n";
		std::cout << "3-> Pentru modificare prenume \n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case'1':
			m_ConturiBancare.erase(it);
			break;
		case'2':
			std::cout << "Introduceti noul nume \n";
			std::cin >> nume;
			break;
		case'3':
			std::cout << "Introduceti noul prenume \n";
			std::cin >> prenume;
			break;
		default:
			break;
		}



	}





}
