#pragma once

class se
{
public:
	char * strarr;
	size_t arrsize;
	se();
	se(char * chararr);
	~se();

	size_t length(char * chararr);
	void malloc(size_t &arr_size);
	void mfree();
	void mcopy(char * dest, char * src);
	void showarr(char *);

	//-----------operators------------------//
	void operator= (char * chararr);
	void operator= (se * se_object);
	void operator+=(se & se_object);
	void operator+=(char * chararr);
	char & operator[](size_t pos);
	se operator+(se & se_object);
	//test branch

	//-----------append------------------//
	void append(se & se_object);
	void append(se & se_object, size_t subpos, size_t sublen);
	void append(char * chararr, size_t charcount = 0);
	void append(size_t charcount, char character);
	char * begin();
	char *  end();
	void append(char * start_pos, char * end_pos);
	//append-initializerlist - todo

	//-----------misc------------------//
	void clear();
	char & at(size_t pos);
	char & back();

	//-----------assign------------------//
	void assign(se & se_object);
	void assign(se & se_object, size_t subpos, size_t sublen);
	void assign(char * chararr, size_t count);
	void assign(char * chararr);
	void assign(size_t count, char character);
	void assign(char * start_pos, char * end_pos);
	//assign-initializerlist - todo

	//-----------compare------------------//
	int compare(se & se_object);
	int compare(size_t pos, size_t len, se & se_object);

};

