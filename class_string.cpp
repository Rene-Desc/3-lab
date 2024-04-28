#include"class_string.hpp"

namespace st {
	string::string() {
		lengh = 0;
		str = new char[0];
	}
	
	string::string(unsigned int leng) {
		lengh = leng;
		str = new char[lengh];
	}


	string::string(const char* strr) {
		lengh = strlen(strr) + 1;
		str = new char[lengh];
		std::copy(strr, strr + lengh, str);
	}

	string::string(const string &other) {
		lengh = other.lengh;
		str = new char[lengh];
		std::copy(other.str, other.str + lengh, str);
	}


	void string::operator=(const string &other) {
		delete[] str;
		lengh = other.lengh;
		str = new char[lengh];
		std::copy(other.str, other.str + lengh, str);
	}

	void string::ext(unsigned int n) {
		char *a = new char[lengh];

		for (unsigned int i = 0; i < lengh; i++) {
			a[i] = str[i];
		}

		str = new char[lengh + n + 1];

		for (unsigned int i = 0; i < lengh + n; i++) {
			if (i < lengh) str[i] = a[i];
		}

		str[lengh + n] = '\0';

		lengh += n;
		delete[] a;
	}

	string string::operator+(const string &other) {
		string tmp(this->str);
		tmp.ext(other.lengh);
		strcat_s(tmp.str, tmp.lengh, other.str);
		tmp.str[tmp.lengh - 1] = '\0';

		return tmp;
	}

	string string::operator+=(const string &other) {
		string tmp(other);
		*this = *this + tmp;
		return tmp;
	}

	char& string::operator[](unsigned int n) {
		return str[n];
	}

	bool string::operator<(const string &other) {
		if (strcmp(this->str, other.str) < 0) { return 1; }
		else { return 0; }
	}

	bool string::operator>(const string &other) {
		if (strcmp(this->str, other.str) > 0) { return 1; }
		else { return 0; }
	}

	bool string::operator==(const string &other) {
		if (strcmp(this->str, other.str) == 0) { return 1; }
		else { return 0; }
	}


	unsigned int string::length() {
		return lengh;
	}



	unsigned int string::find(char a) {
		for (unsigned int i = 0; i < lengh; i++) {
			if (str[i] == a) { return i; }
		}
		return -1;
	}

	char& string::at(unsigned int n) {
		if (n >= 0 && n < lengh) return str[n];
		std::cout << "String index out of range";
	}



	char* string::c_str() {
		return str;
	}

	void string::print() {
		for (unsigned int i = 0; i < lengh; i++) {
			std::cout << str[i];
		}
		std::cout << '\n';
	}

	string::~string() {
		delete[] str;
	}

	std::ostream& operator<<(std::ostream& out, const string& other) {
		out << other.str;
		return out;
	}

	std::istream& operator>>(std::istream& in, string& other) {
		int n = other.lengh;
		char* a = new char[n];
		std::cin >> a;
		other.str = a;
		other.lengh = n;

		return in;
	}
}