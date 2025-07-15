#include "AMateria.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::AMateria(const AMateria &other) : type(other.type) {
}
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		(void)other;
	return *this;
}
AMateria::~AMateria() {}
///////////////////////////////////////////////////////////////////////////////]
std::string const & AMateria::getType() const {
	return type;
}
void AMateria::use(ICharacter& target) {
	std::cout << C_333 << "* does... something to " << target.getName() << C_333 << " *" << std::endl;
}

