#include "stdafx.h"
#include <string>
#include <iostream>
#include "Produs.h"

Produs::Produs() {
	this->code = 0;
	this->name ="";
	this->price = 0;


}

Produs::Produs(int code, std::string  name, float price) {
	this->code = code;
	this->price = price;
	this->name = name;
}

Produs::Produs(const Produs&c) {
	this->code = c.code;
	this->price = c.price;
	this->name = c.name;
}

Produs::~Produs() {}

int Produs::getCode() {
	return this->code;
}

void Produs::setCode(int code) {
	this->code = code;
}

std::string Produs::getName() {
	return this->name;
}


void Produs::setName(std::string name) {
	this->name = name;
}


float Produs::getPrice() {
	return this->price;
}

void Produs::setPrice(float price) {
	this->price = price;
}

Produs&Produs::operator=(const Produs&c) {
	if (this != &c) {
		this->setCode(c.code);
		this->setName(c.name);
		this->setPrice(c.price);

	}
	return *this;

}