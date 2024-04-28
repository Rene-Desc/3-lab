#include <string.h>
#include"class_string.hpp"

int main(){
	st::string s1("abcd");
	s1.print();
	st::string s2 = s1;
	s2.print();
	st::string s3;
	s3 = s1;
	s3.print();
	st::string tmp("rrr");
	st::string s4("a");
	s4.print();
	s4 = s4 + tmp;
	s4.print();
	st::string s5("aabbcc");
	s5 += tmp;
	s5[2] = 't';
	s5.print();
	int a = s1 < s5;
	std::cout << a << '\n';
	int b = s1 == s1;
	std::cout << b << '\n';

	std::cout << s5.find('b') << '\n';
	s5.at(6) = 'r';
	s5.print();
	std::cout << s5 << '\n';

	st::string s(7);
	std::cin >> s;
	
	std::cout << s;
}