#include "linkedlist1.cpp"
#include <iostream>
using namespace std;

int main()
{
	linkedlist1<int> l1;
	l1.insertAt(10, 0);
	l1.insertAt(15, 1);
	l1.insertAt(20, 2);
	l1.insertAt(25, 3);
	l1.insertend(30);
	l1.insertfirst(5);
	l1.remove(15);
	cout<<"length:"<<l1.listsize()<<endl;
	l1.removeAt(3);
	l1.removeAt(4);
	l1.removeAt(6);
	l1.insertOrdered(11);
	l1.insertOrdered(30);
	l1.removefirst();
	l1.display();
	cout<<"pos:"<<l1.seqSearch(30)<<endl;
	l1.reverse();
	l1.display();
	return 0;
}