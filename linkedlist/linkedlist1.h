#pragma once
template<class t>
class linkedlist1
{
	struct node
	{
		node* next;
		t item;
	};
	node* first;
	node* last;
	int count;
public:
	linkedlist1();
	int listsize();
	bool isEmpty();
	int seqSearch(t);
	void remove(t);
	void insertfirst(t);
	void insertend(t);
	void insertAt(t, int);
	void removeAt(int);
	void display();
	void clearlist();
	void insertOrdered(t);
	void removefirst();
	void removelast();
	void removelast2 ();
	int removeoddsumEven();
	void reverse();
	~linkedlist1();

};

