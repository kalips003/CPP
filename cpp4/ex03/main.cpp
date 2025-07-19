#include "src/AMateria.hpp"
#include "src/ICharacter.hpp"
#include "src/Character.hpp"
#include "src/Cure.hpp"
#include "src/Ice.hpp"
#include "src/IMateriaSource.hpp"
#include "src/MateriaSource.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	ICharacter* fred = new Character(C_320 "FREEED" RESET);
	ICharacter* me = new Character(C_315 "Me??" RESET);

	ice->AMateria::use(*fred);
	cure->AMateria::use(*fred);
	ice->use(*fred);
	cure->use(*me);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(NULL);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("hello general kenobi");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(2);
	delete tmp;

	Character me_clone = *(dynamic_cast<Character*>(me));

	std::cout << std::endl;
	me->use(0, *fred);
	me->use(1, *fred);
	me->use(2, *fred);
	me->use(3, *fred);
	delete me;
	
	std::cout << std::endl;
	me_clone.use(0, *fred);
	me_clone.use(1, *fred);
	me_clone.use(2, *fred);
	me_clone.use(3, *fred);

	delete ice;
	delete cure;
	delete fred;
	delete src;

	return 0;
}
