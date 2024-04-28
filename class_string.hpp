#pragma once
#include <iostream>
namespace st {
	class string {
		unsigned int lengh;
		char* str;
	public:
		string();
		friend std::ostream& operator<<(std::ostream& out, const string& other);
		friend std::istream& operator>>(std::istream& in, string& other);

		string(unsigned int leng);


		string(const char* strr);

		string(const string &other);


		void operator=(const string &other);

		void ext(unsigned int n);

		string operator+(const string &other);

		string operator+=(const string &other);

		char& operator[](unsigned int n);

		bool operator<(const string &other);

		bool operator>(const string &other);

		bool operator==(const string &other);

		unsigned int length();

		unsigned int find(char a);

		char& at(unsigned int n);

		char* c_str();

		void print();

		~string();
	};

	std::ostream& operator<<(std::ostream& out, const string& other);

	std::istream& operator>>(std::istream& in, string& other);

}


