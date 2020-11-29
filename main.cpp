#include <iostream>
#include "list.h"


int main()
{
	List<int> check;

	List<int> check3;

	List<char> check2;

	List<Point> p;

	Point t = Point(2, 3 ,4);
	p.push_back(t);
	t = Point(4, 5, 6);
	p.push_back(t);
	p.printl();

	check.printl();

	for (int i = 0; i < 15; i++) {
		check.push_back(i);
	}
	check.printl();
	
	char b = 'b';
	
	for (int i = 0; i < 45; i++) {
		b++;
		check2.push_back(b);
	}
	
	std::cout << check2.ssize();
	check2.printl();

	std::cout << check.ssize();
	check.printl();
	

	check.push_front(13);
	std::cout << check.ssize();
	check.printl();

	check.find_and_erase(2);
	check.find_and_erase(4);

	check.find_and_erase(12);
	std::cout << check.ssize();
	check.printl();

	check.find_and_erase(13);
	check.printl();

	Node<int>* a = new Node<int>(0, NULL, NULL);
	try {
		a = check.at(2);
		a = check.at(1);
	} catch (MyException& err) {
		std::cout << err.get() << std::endl;
	}

	check.push_back(123);

	check3 = check;
	check3.printl();

	List<char> c(check2);
	cout << "c(1):\n";
	c.printl();
	c = c;
	cout << "c(2):\n";
	c.printl();
	cout << ":c\n";

	delete a;
	return 0;
}