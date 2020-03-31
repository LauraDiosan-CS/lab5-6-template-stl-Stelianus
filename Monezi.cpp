#include "stdafx.h"
#include "Monezi.h"


Monezi::Monezi()
{
}


Monezi::~Monezi()
{
}

void Monezi::addMoneda(int m) {
	monezi.push_back(m);
}

int Monezi::getLen() {
	return monezi.size();
}

float Monezi::getSuma()
{
	int suma = 0;
	suma = monezi[2] * 0.5 + monezi[1] * 0.1 + monezi[0] * 0.05;
	return suma;
}

std::vector<int> Monezi::getAll() {
	return monezi;
}

void Monezi::decrement(int poz) {
	monezi[poz]--;
}