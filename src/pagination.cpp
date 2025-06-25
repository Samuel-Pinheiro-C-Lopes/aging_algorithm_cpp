#include "alias.h"

#include "page.h"
#include "aging_algorithm.h"

#include<iostream>

void tickAndPrint(AgingAlgorithm& AA, const Vtr<bool>& ca) {
	AA.tick(ca);
	AA.printPages();
	AA.tick(ca);
	AA.printPages();
	AA.tick(ca);
}

int main(int argv, char* argc[]) {
	AgingAlgorithm AA;
	Vtr<bool> ca = {0, 0, 1, 0, 1, 0, 1, 0};
	
	for (auto it = ca.begin(); it != ca.end(); ++it)
		AA.addPage();

	tickAndPrint(AA, ca);

	ca = {1, 1, 1, 1, 1, 1, 1, 0};

	tickAndPrint(AA, ca);

	ca = {0, 0, 1, 1, 0, 0, 1, 1};

	tickAndPrint(AA, ca);

	return 0;	
}
