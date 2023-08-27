#include "Array.hpp"

int main( void ) {
	Array<int>	*p = new Array<int>(10);
	

	for (size_t i = 0; i < (*p).getSize(); i++)
	{
		(*(p))[i] = 42;
		std::cout << "Element [" << i << "] is : " << (*(p))[i]<<std::endl;
	}
	
	Array<int>	a(5);
	for (size_t i = 0; i < a.getSize(); i++)
	{
		(a)[i] = 27;
		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
	}
	std::cout << "Copy\n";
	a = *p;
	for (size_t i = 0; i < a.getSize(); i++)
	{
		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
	}
	std::cout << "Post modif A\n";

	for (size_t i = 0; i < (*p).getSize(); i++)
	{
		// (*(p))[i] = 42;
		std::cout << "Element [" << i << "] is : " << (*(p))[i]<<std::endl;
	}
	
	std::cout << "P is not modified !\n";


//test modifying B who was copy constructed of a
	Array<int> B = Array<int>(a);

	for (size_t i = 0; i < (B).getSize(); i++)
	{
		std::cout << "Element [" << i << "] is : " << (B)[i]<<std::endl;
		B[i] = 17072000;
	}
	std::cout << "B was modifed\n";
	for (size_t i = 0; i < (B).getSize(); i++)
	{
		std::cout << "Element [" << i << "] is : " << (B)[i]<<std::endl;
	}
	std::cout << "A is now:\n";
	for (size_t i = 0; i < a.getSize(); i++)
	{
		(a)[i] = 15;
		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
	}
	// (*p)[111];

	Array<std::string> S(5);
	for (size_t i = 0; i < S.getSize(); i++)
	{
		std::cout << "S[" << i << "] = " << S[i] << std::endl;	/* code */
	}
	
	delete p;
	// Array<char> a;

return 0;
}
