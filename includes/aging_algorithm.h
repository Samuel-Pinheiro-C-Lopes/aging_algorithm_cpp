#ifndef AGING_ALGORITHM_H
#define AGING_ALGORITHM_H

#include "alias.h"

#include "page.h"

class AgingAlgorithm {
private:
	static constexpr int PAGE_COUNT = 8;
	Map<int, Ptr<Page>> pages;
public:
	AgingAlgorithm() : pages() {
	//		this->pages.reserve(this->PAGE_COUNT);	
		this->pages.max_load_factor(0.75f);
		this->pages.rehash(this->PAGE_COUNT);
	};

	void tick(const Vtr<bool>& pageAccesses);
	void printPages() const;
	Ptr<Page> getNextToSubstitute() const;
	bool addPage();
	bool addPage(const Ptr<Page>& newPage);
	bool addPage(const int id);
};

#endif
