#pragma once

# include <iostream>
# include <format>
# include <string>

// type was created to use my own string, but not std::string or always char*
class String
{
private:
	size_t len; // length
	char* str; // string

public:
	String();
	String(const char* _str);
	String(const String& other);
	String(const std::string& s);
	~String();

	size_t length() const;
	const char* c_str() const;

	String& operator= (const String& s);
	String operator+ (const String& s) const;

	friend bool operator==(const String& s1, const String& s2);
	friend bool operator!=(const String& s1, const String& s2);
	friend std::ostream& operator<< (std::ostream& OUT, const String& s);
	friend std::istream& operator>> (std::istream& IN, String& s);
};
