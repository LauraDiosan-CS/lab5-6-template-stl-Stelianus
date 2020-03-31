#pragma once
#ifndef PRODUS_H_
#define PRODUS_H_
#include <string>
class Produs {
private:
	int code;
	std::string  name;
	float price;
public:
	Produs();
	Produs(int code, std::string name, float price);
	Produs(const Produs&p);
	virtual ~Produs();
	int getCode();
	void setCode(int code);
	std::string getName();
	void setName(std::string  name);
	float getPrice();
	void setPrice(float price);
	Produs& operator=(const Produs& s);
};




#endif /* PRODUS_H_ */


