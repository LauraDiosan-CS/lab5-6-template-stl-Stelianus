#pragma once
#ifndef MONEZI_H_
#define MONEZI_H_

#include <iostream>
#include <vector>

class Monezi {
private:
	 std:: vector<int> monezi;
public:
	Monezi();
	~Monezi();
	void addMoneda(int m);
	int getLen();
	float getSuma();
	std::vector<int> getAll();
	void decrement(int poz);
};


#endif /* MONEZI_H_ */

