#include "src/Base.hpp"
#include "src/A.hpp"
#include "src/B.hpp"
#include "src/C.hpp"

#include <iostream>

void	identify(Base* p);
void	identify(Base& p);

///////////////////////////////////////////////////////////////////////////////]
int main() {

    Base *ptr = generate();
    A *a = new A;
    B *b = new B;
    C *c = new C;

    std::cout << C_333 "A* is: " RESET; identify(a);
    std::cout << C_333 "B* is: " RESET; identify(b);
    std::cout << C_333 "C* is: " RESET; identify(c);
    std::cout << std::endl << C_430 "Random ptr is: " RESET; identify(ptr);

    delete a;
    delete b;
    delete c;

    A aa;
    B bb;
    C cc;

    std::cout << std::endl;
    identify(aa);
    identify(bb);
    identify(cc);
    std::cout << std::endl << C_430 "Random ptr is: " RESET; identify(*ptr);

    std::cout << std::endl << C_430 "Random ptr is: " RESET; identify(*ptr);

    delete ptr;

	return 0;
}

