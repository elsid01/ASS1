#include "LL.h"

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
	iterator current(position);
	position = position->next;

	return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{
	position = position->next;

	return *this;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
	iterator current(position);
	position = position->prev;

	return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
	position = position->prev;

	return *this;
}

template <class type>
LL<type>::LL()
{
    head = new node;
    head->next = head;
    head->prev = head;
}

template <class type>
LL<type>::LL(const LL<type>& otherList)
{
    head = new node;
    head->next = head;
    head->prev = head;
    
    copyList(otherList);
}

template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& otherList)
{
	if (this != &otherList)
	{
        clearList();
        copyList(otherList);
	}

	return *this;
}

template <class type>
LL<type>::~LL()
{
    clearList();
    delete head;
}

template <class type>
void LL<type>::headInsert(const type& item)
{
    node* newNode = new node;
    newNode->item = item;
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}

template <class type>
void LL<type>::tailInsert(const type& item)
{
    node* newNode = new node;
    newNode->item = item;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
}

template <class type>
void LL<type>::headRemove()
{
  if(!isEmpty())
  {
      node* toDelete = head->next;
      head->next = toDelete->next;
      toDelete->next->prev = head;
      delete toDelete;
  }
}

template <class type>
void LL<type>::tailRemove()
{
	if(!isEmpty())
    {
        node* toDelete = head->prev;
        head->prev = toDelete->prev;
        toDelete->prev->next = head;
        delete toDelete;
    }
}

template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator & it)
{
	if(it.position != head)
    {
        node* toDelete = it.position;
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        it.position = toDelete->next;
        delete toDelete;
    }
}

template <class type>
void LL<type>::clearList()
{
	while(!isEmpty())
    {
        headRemove();
    }
}

template <class type>
void LL<type>::copyList(const LL<type>& otherList)
{
    for(iterator it = otherList.begin(); it != otherList.end(); ++it)
    {
        tailInsert(*it);
    }
}
