#include "se.h"
#include <cstring>
#include <iostream>
#include <conio.h>

#define buffer size_t 16

void se::malloc(size_t &arr_size)
{
	strarr = new char[arr_size+1];
	arrsize = arr_size;
	strarr[arrsize] = '\0';
}

void se::mfree()
{
	delete[]strarr;
	//test
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

std::ostream& operator << (std::ostream& os, se & ob)
{
	for (size_t i = 0; i <= ob.arrsize; i++)
	{
		os << ob.strarr[i];
	}
	return os;
}

std::istream& operator >> (std::istream& is, se & ob)
{

	//to do
	std::cout << "\n To DO!";
	/*
	size_t temp_size = 10;
	ob.mfree();
	ob.malloc(temp_size);
	char val = 0;
	for (size_t i = 0; i < temp_size; i++)
	{
		is >> ob.strarr[i];
		std::cout << ob.strarr[i];
		if (ob.strarr[i] == 12)break;
	}
	*/
	return is;
	

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

//-----------------------------------------------------------APPEND---------------------------------------------//

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

void se::append(char * start_pos, char * end_pos)
{
	size_t charcount = end_pos - start_pos;
	arrsize += charcount;
	char * temp_arr = new char[arrsize + 1];
	temp_arr[arrsize] = '\0';
	memcpy(temp_arr, strarr, arrsize - charcount);
	memcpy(temp_arr + (arrsize - charcount), start_pos, charcount);
	operator=(temp_arr);
}

//-----------------------------------------------------------MISC---------------------------------------------//


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

void se::clear()
{
	if (arrsize != 0 || strarr != NULL)	mfree();
	strarr = NULL;
	arrsize = 0;
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


char & se::front()
{
	return strarr[0];
}

char & se::back()
{
	return strarr[arrsize - 1];
}

size_t se::find(char * chararr)
{
	size_t chararr_length = length(chararr);
	size_t pos = -1;
	char * ptr1 = chararr;
	for (size_t i = 0; i < arrsize; i++)
	{
		if (*ptr1 == '\0') return i-chararr_length;
		if (strarr[i] == *ptr1)
		{
			ptr1++;
			continue;
		}
		if (strarr[i] != *ptr1) ptr1 = chararr;
	}
	return pos;
}

size_t se::find(se & ob)
{
	size_t chararr_length = ob.arrsize;
	size_t pos = -1;
	char * ptr1 = ob.strarr;
	for (size_t i = 0; i < arrsize; i++)
	{
		if (*ptr1 == '\0') return i - chararr_length;
		if (strarr[i] == *ptr1)
		{
			ptr1++;
			continue;
		}
		if (strarr[i] != *ptr1) ptr1 = ob.strarr;
	}
	return pos;
}

size_t se::rfind(char * chararr)
{
	size_t chararr_length = length(chararr);
	size_t pos = -1;
	char * ptr1 = chararr+chararr_length-1;
	for (size_t i = arrsize; i > 0; i--)
	{
		if (*ptr1 == '\0') return i-chararr_length-1;
		if (strarr[i] == *ptr1)
		{
			ptr1++;
			continue;
		}
		if (strarr[i] != *ptr1) ptr1 = chararr+chararr_length-1;
	}
	return pos;
}

size_t se::rfind(se & ob)
{
	size_t chararr_length = ob.arrsize;
	size_t pos = -1;
	char * ptr1 = ob.strarr + ob.arrsize - 1;
	for (size_t i = arrsize; i > 0; i--)
	{
		if (*ptr1 == '\0') return i - chararr_length - 1;
		if (strarr[i] == *ptr1)
		{
			ptr1++;
			continue;
		}
		if (strarr[i] != *ptr1) ptr1 = ob.strarr + ob.arrsize - 1;
	}
	return pos;
}

//-----------------------------------------------------------ASSIGN---------------------------------------------//

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

//-----------------------------------------------------------COMPARE---------------------------------------------//

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

//-----------------------------------------------------------INSERT---------------------------------------------//

void se::insert(size_t insert_pos, se &se_object)
{
	size_t temp_size = arrsize + se_object.arrsize;
	se temp_object(temp_size);
	memcpy(temp_object.strarr, strarr, insert_pos);
	memcpy(temp_object.strarr + insert_pos, se_object.strarr, se_object.arrsize);
	memcpy(temp_object.strarr + (insert_pos + se_object.arrsize), strarr + insert_pos, arrsize - insert_pos);
	mfree();
	malloc(temp_size);
	memcpy(strarr, temp_object.strarr, temp_size);
}

void se::insert(size_t insert_pos, se &ob, size_t ob_start_pos, size_t ob_count)
{
	size_t temp_size = arrsize + ob_count;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, insert_pos);
	memcpy(t_ob.strarr+insert_pos, ob.strarr + ob_start_pos, ob_count);
	memcpy(t_ob.strarr+(insert_pos+ob_count), this->strarr + insert_pos, arrsize - insert_pos);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

void se::insert(size_t insert_pos, char * chararr, size_t char_count)
{
	size_t temp_size = arrsize + char_count;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, insert_pos);
	memcpy(t_ob.strarr + insert_pos, chararr, char_count);
	memcpy(t_ob.strarr + (insert_pos + char_count), this->strarr + insert_pos, arrsize - insert_pos);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

void se::insert(size_t insert_pos, char * chararr)
{
	size_t chararr_size = length(chararr);
	size_t temp_size = arrsize + chararr_size;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, insert_pos);
	memcpy(t_ob.strarr + insert_pos, chararr, chararr_size);
	memcpy(t_ob.strarr + (insert_pos + chararr_size), this->strarr+insert_pos, this->arrsize - insert_pos);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

void se::insert(size_t insert_pos, size_t no_of_repeats, char character)
{
	char * chararr = new char[no_of_repeats];
	for (size_t i = 0; i < no_of_repeats; i++)
	{
		chararr[i] = character;
	}

	size_t temp_size = this->arrsize + no_of_repeats;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, insert_pos);
	memcpy(t_ob.strarr + insert_pos, chararr, no_of_repeats);
	memcpy(t_ob.strarr + (insert_pos + no_of_repeats), this->strarr + insert_pos, arrsize - insert_pos);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

//-----------------------------------------------------------REPLACE---------------------------------------------//

void se::replace(size_t start_pos, size_t count, se & ob)
{
	size_t temp_size = arrsize - count + ob.arrsize;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, start_pos);
	memcpy((t_ob.strarr + start_pos), ob.strarr, ob.arrsize);
	memcpy(t_ob.strarr + start_pos + ob.arrsize, this->strarr + start_pos + count,this->arrsize-start_pos-count);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
	}

void se::replace(size_t start_pos, size_t count, se & ob, size_t ob_start_pos, size_t ob_count)
{
	size_t temp_size = arrsize - count + ob_count;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, start_pos);
	memcpy(t_ob.strarr + start_pos, ob.strarr + ob_start_pos, ob_count);
	memcpy(t_ob.strarr + start_pos + ob_count, this->strarr + start_pos + count, this->arrsize - start_pos - count);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

void se::replace(size_t start_pos, size_t len, char * chararr, size_t chararr_count)
{
	size_t chararr_len = 0;
	if(chararr_count == 0)chararr_len = length(chararr);
	else chararr_len = chararr_count;
	size_t temp_size = arrsize - len + chararr_len;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, start_pos);
	memcpy(t_ob.strarr + start_pos, chararr, chararr_len);
	memcpy(t_ob.strarr + start_pos + chararr_len, this->strarr + start_pos + len, arrsize - start_pos - len);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}

void se::replace(size_t start_pos, size_t len, size_t character_count, char character)
{
	size_t temp_size = arrsize - len + character_count;
	se t_ob(temp_size);
	memcpy(t_ob.strarr, this->strarr, start_pos);
	/*//WHAAAAT?!
	for (size_t i = character_count; i >= 0; i--)
	{
		if (i == 0)
		{
			t_ob.strarr[start_pos] = character;
			break;
		}
			t_ob.strarr[start_pos + i] = character;	
	}
	*/
	size_t i = character_count;
	while (i > 0)
	{
		t_ob.strarr[start_pos+i-1] = character;
		i--;
	}

	memcpy(t_ob.strarr + start_pos+character_count, this->strarr + start_pos+len, arrsize - start_pos - len);
	mfree();
	malloc(temp_size);
	memcpy(strarr, t_ob.strarr, temp_size);
}




void se::showarr(char * carr)
{
	if (carr!=0)
	{
		size_t carr_length = length(carr);
	std::cout << "\n /-------------------SHOW ARR-------------------/" << std::endl;
	for (size_t i = 0; i <= carr_length; i++)
	{
		if (carr[i] == '\0') std::cout << "|X|";
		else
			std::cout << carr[i];
	}
	std::cout << "\n /------------------/SHOW ARR-------------------/";
	}
	else
	{
		std::cout << "\n /-------------------SHOW ARR(this)-------------/" << std::endl;
		for (size_t i = 0; i <= this->arrsize; i++)
		{
			if (strarr[i] == '\0') std::cout << "|X|";
			else
				std::cout << strarr[i];
		}
		std::cout << "\n /------------------/SHOW ARR-------------------/";

	}
}

se::~se()
{
}
