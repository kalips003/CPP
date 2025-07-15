#include "MateriaSource.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
MateriaSource::MateriaSource() {
	for (int i = 0; i < MEMORY_LIMIT; i++)
		memory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < MEMORY_LIMIT; i++) {
		if (other.memory[i])
			memory[i] = other.memory[i]->clone();
		else
			memory[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < MEMORY_LIMIT; i++) {
			delete memory[i];
			if (other.memory[i])
				memory[i] = other.memory[i]->clone();
			else
				memory[i] = NULL;
		}
	}
	return *this;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < MEMORY_LIMIT; i++)
		delete memory[i];
}
///////////////////////////////////////////////////////////////////////////////]
void MateriaSource::learnMateria(AMateria* ptr) {
	for (int i = 0; i < MEMORY_LIMIT; i++) {
		if (!memory[i]) {
			memory[i] = ptr->clone();
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MEMORY_LIMIT; i++) {
		if (memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	}
	return NULL;
}
