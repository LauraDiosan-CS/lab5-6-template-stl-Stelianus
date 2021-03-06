#include "stdafx.h"
#include<iostream>
#include <string>
#include "Monezi.h"
#include "Repo.h"
#include "Produs.h"
#include "TestProdus.h"
#include "TestRepo.h"
#include "RepoFile.h"

void printMeniu() {
	std::string meniu = "0.Exit.\n";
	meniu += "1.Adauga un produs.\n";
	meniu += "2.Afiseaza produse.\n";
	meniu += "3.Cumpara un produs.\n";
	std::cout << "-----------------------\n";
	std::cout << meniu;
	std::cout << "------------------------\n";
}

int main()
{
	
	//testProdus();
	//testRepo();
	bool c = true;
	int choice, code;
	float price;
	std::string name;
	Monezi mon;
	mon.addMoneda(10);
	mon.addMoneda(10);
	mon.addMoneda(40);
	RepoFile <Produs> re(mon);
	re.loadFromFile();
	while (c) {
		printMeniu();
		std::cout << "Introduceti comanda: ";
		std:: cin >> choice;
		switch (choice) {
		case 1: {
			std:: cout << "Introduceti codul produsului: ";
			std:: cin >> code;
			std:: cout << "Introduceti numele produsului: ";
			std:: cin >> name;
			std:: cout << "Introduceti pretul produsului: ";
			std:: cin >> price;
			Produs p = Produs(code, name, price);
			re.add(p);
			std:: cout << "\n";
			break;
		}
		case 2: {
			std::cout << "Aparatul are urmatoarele produse:\n";
			std::vector<Produs> vec = re.getAll();
			unsigned int i;
			for (i = 0; i<vec.size(); i++) {
				std::cout << vec[i].getCode() << " " << vec[i].getName() << " " << vec[i].getPrice() << "\n";
			}
			std:: cout << "\n";
			break;
		}
		case 3: {
			int cod;
			float suma;

			std:: cout << "Introduceti codul produsului ";
			std:: cin >> cod;
			std:: cout << "Introduceti o suma in bancomat ";
			std:: cin >> suma;
			std::vector<Produs> vec = re.getAll();
			for(unsigned int i=0;i<vec.size();++i)
				if (vec[i].getCode() == cod) {
					bool operatie;
					operatie=re.rest(vec[i].getPrice(), suma);
					if (operatie == true) {
						vec.erase(vec.begin() + i);
						re.remove(i);
					}
						
				}
					
			std:: cout << "\n";
			break;
		}
		case 0: {
			std:: cout << "Aplicatia s-a inchis";
			c = false;
			std:: cout << "\n";
			break; }
		default:
		{
			std::cout << "Comanda invalida. \n";
			std::cout << "Alegeti o optiune: \n";
			break; }
		}

	}
	
	//testRepoFile();
    return 0;
}

