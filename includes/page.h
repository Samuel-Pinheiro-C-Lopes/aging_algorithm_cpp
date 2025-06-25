#ifndef PAGE_H
#define PAGE_H

#include "alias.h"

class Page {
private:
	const int id;
	bool referenced;
	uint8_t age;
	static constexpr int COUNTER_BITS = 8;
public:
	Page(int id) : id(id), referenced(false), age(0) {};
	
	uint8_t getAge() const;
	void increaseAge();
	void printAge() const;
	void printId() const;
	void resetAge();	
	void refreshAge();
};

#endif
