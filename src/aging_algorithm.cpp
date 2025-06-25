#include"aging_algorithm.h"

void AgingAlgorithm::tick(const Vtr<bool>& pageAccesses) {
	Ptr<Page> currentPage = nullptr;

	Vtr<bool>::const_iterator vtrIt = pageAccesses.begin();
	Map<int, Ptr<Page>>::iterator mapIt = this->pages.begin();


	while (mapIt != this->pages.end() && vtrIt != pageAccesses.end()) {
		if (*(vtrIt)) 
			mapIt->second->refreshAge();

		mapIt->second->increaseAge();

		++vtrIt;
		++mapIt;
	}
}

void AgingAlgorithm::printPages() const {
	for (Map<int, Ptr<Page>>::const_iterator it = this->pages.begin(); it != this->pages.end(); ++it) {
		it->second->printId();
		it->second->printAge();
	}
}

Ptr<Page> AgingAlgorithm::getNextToSubstitute() const {
	Ptr<Page> currentPage = nullptr;

	for (Map<int, Ptr<Page>>::const_iterator it = this->pages.begin(); it != this->pages.end(); ++it)
		if (currentPage == nullptr || it->second->getAge() < currentPage->getAge())
			currentPage = it->second;

	return currentPage;
}

bool AgingAlgorithm::addPage() {
	Ptr<Page> newPage = std::make_shared<Page>(this->pages.size());

	return this->addPage(newPage);
}

bool AgingAlgorithm::addPage(const Ptr<Page>& newPage) {
	return this->pages.insert(std::make_pair(this->pages.size(), newPage)).second;
}

bool AgingAlgorithm::addPage(const int id) {
	Ptr<Page> newPage = std::make_shared<Page>(id);

	return this->addPage(newPage);
}

