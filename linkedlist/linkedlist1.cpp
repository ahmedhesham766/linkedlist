#include "linkedlist1.h"
#include <iostream>
using namespace std;

template<class t>
linkedlist1<t>::linkedlist1()
{
	first = last = NULL;
	count = 0;
}

template<class t>
int linkedlist1<t> ::listsize()
{
	return count;
}

template<class t>
bool linkedlist1<t>::isEmpty()
{
	return (count == 0);
}

template<class t>
int linkedlist1<t>::seqSearch (t x)
{
	node* cur = first;
	int pos = 0;
	while (cur != NULL)
	{
		if (cur->item == x)
		{
			return pos;
		}
		cur = cur->next;
		pos++;
	}
	return -1;
}

template<class t>
void linkedlist1<t>::remove(t x)
{
	if (isEmpty())
	{
		cout << "list is empty" << endl;
		return;
	}
	else
	{
		node* temp = first;
		node* prev = NULL;
		if (temp->item == x)
		{
			first = first->next;
			temp->next = NULL;
			delete temp;
			count--;
			if (count == 0)
			{
				last = NULL;
			}
		}
		else
		{
			while(temp!=NULL &&  temp->item != x)
			{
				prev = temp;
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "the item is not there\n";
				return;
			}
			else
			{
				prev->next = temp->next;
				if (last == temp)
				{
					last = prev;
				}
				delete temp;
				count--;
			}
		}
	}
}

template <class t>
void linkedlist1<t>::insertfirst (t x)
{
	node* newnode = new node;
	newnode->item = x;
	if (isEmpty())
	{
		first = last = newnode;
		newnode->next = NULL;
	}
	else
	{
		newnode->next = first;
		first = newnode;
	}
	count++;
}

template<class t>
void linkedlist1<t>::insertend(t x)
{
	node* newnode = new node;
	newnode->item = x;
	if (isEmpty())
	{
		first = last = newnode;
		newnode->next = NULL;
	}
	else
	{
		last->next = newnode;
		newnode->next = NULL;
		last = newnode;
	}
	count++;
}

template<class t>
void linkedlist1<t>::insertAt(t x, int pos)
{
	if (pos < 0 || pos > count)
	{
		cout << "invalid pos";
	}
	else
	{
		node* newnode = new node;
		newnode->item = x;
		if (pos == 0)
		{
			insertfirst(x);
		}
		else if (pos == count)
		{
			insertend(x);
		}
		else
		{
			node* cur = first;
			node* prev = NULL;
			for (int i = 1; i <= pos; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			prev->next = newnode;
			newnode->next = cur;
			
			count++;
		}
	}
}

template<class t>
void linkedlist1<t>::removeAt(int pos)
{
	if (pos < 0 || pos> count)
	{
		cout << "out of range" << endl;
	}
	else
	{
		node* temp = first;
		node* prev = NULL;
		if (pos == 0)
		{
			first = first->next;
			temp->next = NULL;
			delete temp;
			count--;
			if (count == 0)
			{
				last = NULL;
			}
		}
		else if (pos == count)
		{
			removelast();
		}
		else
		{
			temp = first->next;
			prev = first;
			for (int i = 1; i < pos; i++)
			{
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			if (last == temp)
			{
				last = prev;
			}
			delete temp;
			count--;
		}
	}
}


template<class t>
void linkedlist1<t>::display()
{
	node* cur = first;
	cout << "[";
	while (cur != NULL)
	{
		cout << cur->item <<" ";
		cur = cur->next;
	}
	cout << "]" << endl;
}


template<class t>
void linkedlist1<t>::clearlist()
{
	node* cur;
	while (first != NULL)
	{
		cur = first;
		first = first->next;
		delete cur;
	}
	last = NULL;
	count = 0;
}


template<class t>
void linkedlist1<t>::insertOrdered(t x)
{
	node* newnode = new node;
	newnode->item = x;
	if (isEmpty())
	{
		first = last = NULL;
		first = newnode;
		count= 1;
	}
	else if (first->item >= x)
	{
		newnode->next = first;
		first = newnode;
		count++;
	}
	else
	{
		node* cur = first->next;
		node* prev = first;
		while (cur != NULL)
		{
			if (cur->item >= x)
			{
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL)
		{
			last->next = newnode;
			newnode->next = NULL;
			last = newnode;
			count++;
		}
		else
		{
			prev->next = newnode;
			newnode->next = cur;
			count++;
		}
	}
}

template<class t>
void linkedlist1<t>::removefirst()
{
	if (isEmpty())
	{
		cout << "list is  empty" << endl;
	}
	else if (count == 1)
	{
		delete first;
		last = first = NULL;
		count = 0;
	}
	else
	{
		node* temp = first;
		first = first->next;
		temp->next = NULL;
		delete temp;
		count--;
	}
}


template<class t>
void linkedlist1<t>::removelast()
{
	if (isEmpty())
	{
		cout << "list is empty" << endl;
	}
	else if (count == 1)
	{
		delete first;
		last = first = NULL;
		count = 0;
	}
	else
	{
		node* cur = first->next;
		node* prev = first;
		while (cur != last)
		{
			prev = cur;
			cur = cur->next;
		}
		last = prev;
		prev->next = NULL;
		delete cur;
		count--;
	}
}

template<class t>
void linkedlist1<t>::removelast2()
{
	if (count == 0)
	{
		cout << "list is empty" << endl;
	}
	else if (count == 1)
	{
		delete first;
		last = first = NULL;
		count--;
	}
	else
	{
		node* cur = first;
		while (cur->next != last)
		{
			cur = cur->next;
		}
		delete last;
		cur->next = NULL;
		last = cur;
		count--;
	}

}

template<class t>
 linkedlist1<t>::~linkedlist1()
{
	 clearlist();
}

 template <class t>
 void linkedlist1<t>::reverse()
 {
	 node* prev, * hold, * cur;
	 prev = NULL;
	 cur = first;
	 hold = first->next;
	 while (hold != NULL)
	 {
		 hold = cur->next;
		 cur->next = prev;
		 prev = cur;
		 cur = hold;
	 }
	 first = prev;
 }
