#ifndef LL_H
#define LL_H
#include <cstdlib>
#include "myStack.h"

template <class type>
class LL
{
private:
	struct node
	{
		type item;
		node * next;
		node * prev;
	};

	void clearList();
	void copyList(const LL<type>&);

	node * head;
	
public:

	class iterator
	{
	private:
		node * position;

	public:
		friend class LL;
		iterator() : position(nullptr) {}
		iterator(node * n) : position(n) {}
		type& operator*() { return position->item; }
		bool operator==(const iterator& otherList) { return position == otherList.position; }
		bool operator!=(const iterator& otherList) { return position != otherList.position; }

		iterator operator++(int);
		iterator operator++();

		iterator operator--(int);
		iterator operator--();
	};

	LL();
	LL(const LL<type>&);
	const LL<type>& operator=(const LL<type>&);
	~LL();
	void headInsert(const type&);
	void tailInsert(const type&);
	void headRemove();
	void tailRemove();
	void removeAtPosition(iterator&);
	bool isEmpty() const { return head->next == head; }
	iterator begin() const { return iterator(head->next); }
	iterator end() const { return iterator(head); }
    
    //myStack<type> toStack() const;
    
};
#endif
