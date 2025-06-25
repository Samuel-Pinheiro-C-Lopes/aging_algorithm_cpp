#include"page.h"

#include<iostream>

void Page::increaseAge() {
	this->age >>= 1;	
};

void Page::refreshAge() {
	this->age |= 1 << (this->COUNTER_BITS - 1);
}

void Page::printAge() const {
	for (int i = this->COUNTER_BITS - 1; i >= 0; --i)
		std::cout << ((this->age >> i) & 1);
	std::cout << std::endl;
};

void Page::printId() const {
	std::cout << this->id << std::endl;
}

void Page::resetAge() {
	this->age = 0;
};

uint8_t Page::getAge() const {
	return this->age;
}
