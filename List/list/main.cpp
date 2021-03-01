#include <iostream>
#include "list.h"




int main() 
{
	
	MyList<int> list;
	for (int i = 1; i <= 5; i++)
	{
		list.addToBegin(i);
	}
	
	list.printAll();
	std::cout << std::endl << "size: " << list.getSize() << std::endl;
	std::cout << "index 1: " << list.getElemByIndex(1) << std::endl;
	
	
	
	return 0;
}
