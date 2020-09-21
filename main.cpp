#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List<int> check;

	check.printl();

	for (int i = 0; i < 5; i++) {
		check.push_back(i);
	}
	check.printl();
	
	check.push_back(12);
	cout << check.ssize();
	check.printl();

	check.push_front(13);
	cout << check.ssize();
	check.printl();

	check.find_and_erase(2);
	check.find_and_erase(4);

	check.find_and_erase(12);
	cout << check.ssize();
	check.printl();

	check.find_and_erase(13);
	check.printl();

	Node<int>* a = new Node<int>(0, NULL, NULL);
	a = check.at(2);

	check.push_back(123);
	check.clear();
	delete a;
	return 0;
}