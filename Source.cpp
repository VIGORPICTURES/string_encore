#include <iostream>
#include <stdio.h>
#include "se.h"

int main()
{

	se to1;
	to1 = "to be question";
	se to2 = "the ";
	to1.insert(6, to2);
	//to1.showarr(to1.strarr);
	//to2.showarr(to2.strarr);
	to1.showarr(to1.strarr);
	std::cout << "\n";
	system("pause");
	return 0;
}