# include <iostream>
# include <cstring>
# include <algorithm>
# include "String.h"

String::String() : str{ new char[1] {'\0'} }, len{ 0 } {}

String::String(const char* _str)
{
	len = std::strlen(_str);
	str = new char[len + 1];
	std::copy(_str, _str + len + 1, str);
}

String::String(const String& other)
{
	len = other.len;
	str = new char[len + 1];
	std::copy(other.str, other.str + len + 1, str);
}

String::~String() { delete[] str; }

size_t String::length() const { return len; }

const char* String::c_str() const { return str; }

String& String::operator= (const String& s)
{
	if (this == &s) return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	std::copy(s.str, s.str + len + 1, str);
	return *this;
}

String String::operator+ (const String& s) const
{
	String res;
	delete[] res.str;
	res.len = this->len + s.len;
	res.str = new char[res.len + 1];
	std::copy(this->str, this->str + this->len, res.str);
	std::copy(s.str, s.str + s.len + 1, res.str + this->len);
	return res;
}

bool operator==(const String& s1, const String& s2)
{ 
	return std::strcmp(s1.str, s2.str) == 0;
}

bool operator!=(const String& s1, const String& s2)
{
	return std::strcmp(s1.str, s2.str) != 0;
}

std::ostream& operator<< (std::ostream& OUT, const String& s)
{
	OUT << s.str;
	return OUT;
}

std::istream& operator>> (std::istream& IN, String& s)
{
	char buffer[256];
	IN.getline(buffer, 256);
	s = String(buffer);
	return IN;
}
