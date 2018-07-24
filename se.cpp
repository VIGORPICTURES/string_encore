#include "se.h"
#include <cstring>
#include <iostream>

void se::malloc(size_t &arr_size)
{
	strarr = new char[arr_size+1];
	arrsize = arr_size;
	strarr[arrsize] = '\0';
}

void se::mfree()
{
	delete[]strarr;
}

size_t se::length(char * chararr)
{
	size_t t_arrsize = 0;
	while (chararr[t_arrsize] != '\0')
	{
		t_arrsize++;
	}
	return t_arrsize;
}

se::se()
{
	operator=("");
}

se::se(char * chararr)
{
	operator=(chararr);
	
}

se::se(size_t malloc_size)
{
	malloc(malloc_size);
}

void se::operator=(char * chararr)
{
	/*
	se temp_object;
	temp_object.arrsize = length(chararr);
	temp_object.malloc(temp_object.arrsize);
	memcpy(temp_object.strarr, chararr, temp_object.arrsize);
	*/
	
	if (arrsize != 0)
	{
	delete[]strarr;
	}
	strarr = NULL;
	arrsize = length(chararr);
	//std::cout << "\n se::se(char chararr[]) arrsize: " << arrsize;
	malloc(arrsize);
	mcopy(strarr, chararr);
	
	//return temp_object;
}

void se::operator=(se * se_object)
{
	memcpy(this, se_object, sizeof(se_object));
}

void se::operator+=(se & se_object)
{
	append(se_object);
}

void se::operator+= (char * chararr)
{
	append(chararr);
}

char & se::operator[](size_t pos)
{
	return strarr[pos];
}

se se::operator+(se & se_object)
{
	size_t temp_object_arr_size = arrsize+se_object.arrsize;
	se temp_object(temp_object_arr_size);
	//temp_object.malloc(temp_object_arr_size);
	memcpy(temp_object.strarr, strarr, arrsize);
	memcpy(temp_object.strarr + arrsize, se_object.strarr, se_object.arrsize);
	return temp_object;
}

se se::operator+(char * chararr)
{
	size_t temp_object_arr_size = arrsize + length(chararr);
	se temp_object(temp_object_arr_size);
	//se temp_object;
	//temp_object.malloc(temp_object_arr_size);
	memcpy(temp_object.strarr, strarr, arrsize);
	memcpy(temp_object.strarr + arrsize, chararr, length(chararr));
	
	return temp_object;
}

void se::mcopy(char* dest, char * src)
{
	size_t dest_size = length(dest);
	//std::cout << "\n se::mcopy dest_size: " << dest_size;
	size_t src_size = length(src);
	//std::cout << "\n se::mcopy src_size: " << src_size;
	if (dest_size != src_size)
	{
		std::cout << "\n MCOPY: ERROR: Destination and source size dismatch!";
	}
	else
	{
		memcpy(dest, src, dest_size);
	}

}

void se::append(se & se_object)
{
	arrsize += se_object.arrsize;
	char * temp_arr = new char[arrsize+1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize);
	char * tempPTR = &temp_arr[arrsize-se_object.arrsize];
	memcpy(tempPTR, se_object.strarr, se_object.arrsize);
	operator=(temp_arr);
}

void se::append(se & se_object, size_t subpos, size_t sublen)
{
	arrsize += sublen;
	char * temp_arr = new char[arrsize + 1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize);
	char * tempPTR = &temp_arr[arrsize - sublen];
	char * se_objectPTR = se_object.strarr + subpos;
	memcpy(tempPTR, se_objectPTR, sublen);
	operator=(temp_arr);
}

void se::append(char * chararr, size_t charcount) //append n(charcount) from *charchar counting from pos 0.
{
	if (charcount == 0) charcount = length(chararr);
	arrsize += charcount;
	char * temp_arr = new char[arrsize + 1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize);
	char * tempPTR = &temp_arr[arrsize - charcount];
	memcpy(tempPTR, chararr, charcount);
	operator=(temp_arr);
}

void se::append(size_t charcount, char character)
{
	arrsize += charcount;
	char * temp_arr = new char[arrsize + 1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize - charcount);
	for (size_t i = charcount; i > 0; i--)
	{
		temp_arr[arrsize - i] = character;
	}
	operator=(temp_arr);
}

char * se::begin()
{
	char* arrPTR;
	arrPTR = strarr;
	return arrPTR;
}

char * se::end()
{
	char* arrPTR;
	arrPTR = strarr+arrsize;
	return arrPTR;
}

void se::append(char * start_pos, char * end_pos)
{
	size_t charcount = end_pos - start_pos;
	arrsize += charcount;
	char * temp_arr = new char[arrsize + 1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize-charcount);
	memcpy(temp_arr+(arrsize - charcount), start_pos, charcount);
	operator=(temp_arr);
}

void se::clear()
{
	if (arrsize != 0 || strarr != NULL)	mfree();
	strarr = NULL;
	arrsize = 0;
}

void se::assign(se & se_object)
{
	operator=(se_object);
}

void se::assign(se & se_object, size_t subpos, size_t sublen)
{
	clear();
	malloc(sublen);
	memcpy(strarr, se_object.strarr + subpos, sublen);
}

void se::assign(char * chararr, size_t count)
{
	clear();
	malloc(count);
	memcpy(strarr, chararr, count);
}

void se::assign(char * chararr)
{
	operator=(chararr);
}

void se::assign(size_t count, char character)
{
	clear();
	malloc(count);
	for (size_t i = count; i > 0; i--)
	{
		strarr[arrsize - i] = character;
	}
}

void se::assign(char * start_pos, char * end_pos)
{
	size_t charcount = end_pos - start_pos;
	clear();
	malloc(charcount);
	memcpy(strarr, start_pos, charcount);
}

char & se::at(size_t pos)
{
	if (pos >= 0 && pos <= arrsize)	return strarr[pos];
	else
	{
		std::cout << "\n Error handling here. Throw out_of_range exception";
		return strarr[arrsize];
	}
}

char & se::back()
{
	return strarr[arrsize-1];
}

int se::compare(se & se_object)
{
	if (arrsize != se_object.arrsize) return -1;
	else
	{
		size_t it = 0;
		while (it <= arrsize)
		{
			if (strarr[it] != se_object.strarr[it]) break;
			it++;
		}
		if (it-1 == arrsize) return 0;
		else
		{
			if (strarr[it] < se_object.strarr[it]) return 1;
			else return -1;
		}
	}

}

int se::compare(size_t pos, size_t len, se & se_object)
{
	size_t it = 0;
	if (arrsize != len) return -1;
	else
	{
		while (it < len)
		{
			if (strarr[it] != se_object.strarr[pos]) break;
			pos++;
			it++;
		}
		if (it == len) return 0;
		else
		{
			if (strarr[it] < se_object.strarr[pos-1]) return 1;
			else return -1;
		}
	}
	return 0;
}

void se::showarr(char * carr)
{
	std::cout << "\n /-------------------SHOW ARR-------------------/" << std::endl;
	for (size_t i = 0; i <= arrsize; i++)
	{
		if (carr[i] == '\0') std::cout << "|X|";
		else
			std::cout << carr[i];
	}
	std::cout << "\n /------------------/SHOW ARR-------------------/";

}

se::~se()
{
}
