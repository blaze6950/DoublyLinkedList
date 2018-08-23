#include <iostream>
using namespace std;

#include "List.h"

template<typename T>
void printList(list<T>& l);

int main()
{
	list<int> l1;
	l1.add(12);
	l1.add(23);
	l1.add(34);

	printList(l1);

	l1.remove(1);
	printList(l1);

	l1.remove(1);
	printList(l1);

	l1.remove(0);
	printList(l1);

}

template<typename T>
void printList(list<T>& l)
{
	for (size_t i = 0; i < l.getSize(); i++)
	{
		cout << l[i] << "\t";
	}
	cout << endl;
}