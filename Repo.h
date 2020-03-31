#pragma once
#ifndef REPO_H_
#define REPO_H_

#include <vector>
#include <fstream>
#include "Produs.h"
#include "Monezi.h"

template <typename T>
class Repo
{
private:
	std::vector<T> v;
	Monezi monezi;
public:
	Repo();
	~Repo();
	Repo(const Monezi mon);
	void add(T e);
	void remove(int pos);
	int getLen() const { return v.size(); }
	std::vector<T> getAll() const { return v; }
	//void loadFromFile();
	bool rest(float pret, float suma);


};

#endif /* REPO_H_ */

template<typename T>
inline Repo<T>::Repo()
{
}

template<typename T>
inline Repo<T>::~Repo()
{
}

template<typename T>
inline Repo<T>::Repo( const Monezi mon) : monezi(mon) {}

template<typename T>
inline void Repo<T>::add(T e) {
	v.push_back(e);
}
template<typename T>
inline void Repo<T>::remove(int pos) {
	v.erase(v.begin() + pos );
}

template<typename T>
inline bool Repo<T>::rest(float pret, float suma)
{
	float r = suma - pret;
	std::vector<int> vec = monezi.getAll();

	if (r<0) {
		std::cout << "Bani insuficienti" << "\n";

	}
	if (monezi.getSuma() < r) {
		std::cout << "Aparatul nu are monezile necesare pentru rest" << "\n";
		return false;
	}
	else {
		while (r >= 0) {

			if (((r - 0.5) >= 0) && (vec[2]>0)) {
				r -= 0.5;

				monezi.decrement(2);
			}
			else break;
		}
		while (r >= 0) {

			if ((r >= 0.1) && (vec[1]>0)) {
				r = float(r - 0.1);

				monezi.decrement(1);
			}
			else break;
		}
		while (r >= 0) {

			if ((r >= 0.05) && (vec[0]>0)) {
				r = float(r - 0.05);

				monezi.decrement(0);
			}
			else break;
		}

		if (r == 0) {
			std:: cout << "Aparatul a dat rest cu succes! " << "\n";
			std::cout << "Aparatul mai are acum: " << monezi.getAll()[2] << " monezi de 50 de bani, " << monezi.getAll()[1] << " monezi de 10 de bani, " << monezi.getAll()[0] << " monezi de 5 de bani. ";
			return true;
		}
		else {
			std:: cout << "Aparatul nu are monezile necesare pentru rest" << "\n";
			return false;
		
		}

		
	}
}
;
