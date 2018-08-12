#include <iostream>
#include <stdio.h>
#include "se.h"
#include <conio.h>
#include <windows.h>

int main()
{
	/*
		//-------------insert---------------//
		se str = "to be question";
		se str2 = "the ";
		se str3 = "or not to be";
		str.insert(6, str2);
		str.insert(6, str3, 3, 4);
		str.insert(10, "that is cool", 8);
		str.insert(10, "to be ");
		str.insert(15, 1, ':');
		str.showarr();
	*/

	/*
			//-------------replace---------------//
			se str = "this is a test string.";
			se str2 = "n example";
			se str3 = "sample phrase";
			se str4 = "useful.";
			std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*";
			//str.showarr();
			str.replace(9, 5, str2);
			str.replace(19, 6, str3, 7, 6);
			str.replace(8, 10, "just a");
			str.replace(8, 6, "a shorty", 7);
			str.replace(22, 1, 3, '!');
			str.showarr();
	*/
	
	/*
	//-------------rfind/find---------------//
	se str("The sixth sick sheik's sixth sheep's sick.");
	se key("sixth");
	std::cout <<"\n RFIND: " << str.find(key);
	*/

	/*
	//-------------front/back---------------//
	se str("test string");
	str.back() = 'T';
	str.showarr();
	*/

	/*
	bool arg = false;
	while (arg)
	{
		while (arg)
		{
			std::cout << '*';
			Sleep(100);

			if (_kbhit())
			{
				char ch = _getch();
				std::cout << "\n CHAR: " << (int)ch;
				switch (ch)
				{
				case 27:               // press ESC to exit
					arg = false;
					break;
				
				}
			}
		}
	}
	*/

	std::cout << "\n";
	system("pause");
	return 0;
}