#pragma once
#ifndef REPOFILE_H_
#define REPOFILE_H_
#include "Repo.h"
#include "Monezi.h"
template <typename T>
class RepoFile : public Repo<T> {

public:
	RepoFile();
	~RepoFile();
	RepoFile(Monezi mon);
	void loadFromFile();


};
#endif /*REPOFILE_H_*/

template<typename T>
inline RepoFile<T>::RepoFile():Repo<T>()
{
}

template<typename T>
inline RepoFile<T>::~RepoFile()
{
}

template<typename T>
inline RepoFile<T>::RepoFile(Monezi mon):Repo<T>(mon)
{
}



template<typename T>
inline void RepoFile<T>::loadFromFile()
{
	std::ifstream in;
	in.open("Datein.txt");
	if (in) {
		while (!in.eof()) {
			int cod, pret;
			std::string denumire;
			in >> cod >> denumire >> pret;
			Produs p = Produs(cod, denumire, pret);
			this->add(p);

		}
		in.close();
	}
	else
		std::cout << "imput file error";
}
;
