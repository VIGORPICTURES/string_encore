#pragma once
#include <iostream>
class se
{
public:
	char * strarr;
	size_t arrsize;
	se();
	se(char * chararr);
	se(size_t malloc_size);
	~se();

	size_t length(char * chararr);
	void malloc(size_t &arr_size);
	void mfree();
	void mcopy(char * dest, char * src); 
	void showarr(char * carr = 0);

	//-----------operators------------------//
	void operator= (char * chararr);
	void operator= (se * se_object);
	void operator+=(se & se_object);
	void operator+=(char * chararr);
	char & operator[](size_t pos);
	se operator+(se & se_object);
	se operator+(char * chararr);
	friend std::ostream& operator << (std::ostream& os, se & ob);
	friend std::istream& operator >> (std::istream& os, se & ob);
	//-----------append------------------//
	void append(se & se_object);
	void append(se & se_object, size_t subpos, size_t sublen);
	void append(char * chararr, size_t charcount = 0);
	void append(size_t charcount, char character);
	void append(char * start_pos, char * end_pos);

	
	//append-initializerlist - todo

	//-----------misc------------------//
	char * begin();
	char *  end();
	void clear();
	char & at(size_t pos);
	char & front();
	char & back();
	size_t find(char * chararr);
	size_t find(se &ob);
	size_t rfind(char * chararr);
	size_t rfind(se &ob);

	//-----------assign------------------//
	void assign(se & se_object);
	void assign(se & se_object, size_t subpos, size_t sublen);
	void assign(char * chararr, size_t count);
	void assign(char * chararr);
	void assign(size_t count, char character);
	void assign(char * start_pos, char * end_pos);
	//assign-initializerlist - todoe

	//-----------compare------------------// to do?!
	int compare(se & se_object);
	int compare(size_t pos, size_t len, se & se_object);

	//-----------insert------------------// 
	void insert(size_t insert_pos, se &se_object);
	void insert(size_t insert_pos, se &ob, size_t ob_start_pos, size_t ob_count);
	void insert(size_t insert_pos, char * chararr, size_t char_count);
	void insert(size_t insert_pos, char * chararr);
	void insert(size_t insert_pos, size_t no_of_repeats, char character);

	//-----------replace-----------------//
	void replace(size_t start_pos, size_t count, se & ob);
	void replace(size_t start_pos, size_t count, se & ob, size_t ob_start_pos, size_t ob_count);
	void replace(size_t start_pos, size_t len, char * chararr, size_t chararr_count = 0);
	void replace(size_t start_pos, size_t len, size_t character_count, char character);

};

