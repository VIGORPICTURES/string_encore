#include <iostream>
#include <stdio.h>
#include "se.h"

int main()
{

	se to1;
	to1 = "test";
	se to2 = "test string1";
	se to3 = "blabla ";
	se to4 = to1 + " dupa " + to2 + to3 + "_error";
	to1.showarr(to1.strarr);
	to2.showarr(to2.strarr);
	to4.showarr(to4.strarr);
	std::cout << "\n";
	system("pause");
	return 0;
}