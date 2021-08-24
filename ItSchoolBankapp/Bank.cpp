#include "Bank.h"
#include <ctime>

Bank::Bank()
{
	DataStorage* data = new DataStorage();
	data->citireDate();
	if (data->dimensiuneData() > 0)
	{
		for (int i = 0; i < data->dimensiuneData(); i++)
		{
			m_ConturiBancare.push_back(data->getConturi(i));
		}
	}
	delete data;
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

TIP_CONT Bank::selectareMoneda()
{
	std::cout << "Alegeti moneda contului din lista de mai jos: \n";
	std::cout << "1->EURO \n";
	std::cout << "2->RON \n";
	std::cout << "Selectie: \n";
	int optiune; std::cin >> optiune;

	switch (optiune)
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

	
	std::string iban = "RO";
	for (int i = 0; i < 2; i++)
	{
		int temp = 0;
		srand(time(0) + i);
		temp = rand() % 9 + i;
		iban += std::to_string(temp);
	}
	iban += "ITSCHOOL";
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++)
		{
			int temp = 0;
			srand(time(0) + i + k);
			temp = rand() % 9;
			iban += std::to_string(temp);
		}
	}
	return iban;
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
	DataStorage* data = new DataStorage(cont);
	data->scriereDate();
	delete data;
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
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->GetNume()
			<< ' ' << m_ConturiBancare[i]->GetIban() << std::endl;

	}
	std::cout << "1 -> Revenire la meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	default:
		system("CLS");
		break;
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
