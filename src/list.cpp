#include "list.h"
#include "node.cpp"
#include "node.h"

template<class ValueType>
List<ValueType>::List() //конструктор по умолчанию
{
	First = 0;
}

template<class ValueType>
List<ValueType>::List(const List<ValueType>& l) //конструктор копирования
{
	First = 0;
	Node<ValueType>* tmp = l.First;
	while (tmp != 0)
	{
		PushEnd(tmp->key);
		tmp = tmp->Next;
	}
}

template<class ValueType>
List<ValueType>::~List() //деструктор
{
	Node<ValueType> *tmp = First;
	while (First != 0)
	{
		First = First->Next;
		delete tmp;
		tmp = First;
	}
}

template<class ValueType>
Node<ValueType>* List<ValueType>::Find(ValueType k) //поиск по ключу
{
	if (First == 0)
		throw
			exception("List doesn't exist");	
	Node<ValueType>* tmp = First;
	while ((tmp != 0) && (k != tmp->key))
		tmp = tmp->Next;
	if (tmp == 0)
	{
		delete tmp;
		throw
			exception("Key was not found");
	}
	return tmp;
}

template<class ValueType>
void List<ValueType>::PushAfter(ValueType findkey, ValueType k) //вставка после указанного ключа
{
	Node<ValueType>* l = Find(findkey);
	Node<ValueType>* tmp = l->Next;
	Node<ValueType>* n;
	try
	{
		n = new Node<ValueType>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create node");
	}
	l->Next = n;
	n->Next = tmp;
}

template<class ValueType>
int List<ValueType>::PushEnd(ValueType k) //вставка в конец
{
	if (First == 0)
	{
		PushStart(k);
		return 0;
	}
	Node<ValueType>* n;
	try
	{
		n = new Node<ValueType>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create node");
	}
	Node<ValueType>* first = First;
	while (first->Next != 0)
		first = first->Next;
	first->Next = n;
	return 0;
}

template<class ValueType>
Node<ValueType>* List<ValueType>::GetFirst(void) //получение указателя на начало
{
	return First;
}

template<class ValueType>
void List<ValueType>::Remove(ValueType findkey) 
{
	if (!First)
		throw
		exception("List is empty");
	Node<ValueType>* n = Find(findkey);
	if (First == n)
	{
		First = First->Next;
		return;
	}
	Node<ValueType>* tmp = First;
	while (tmp->Next != n)
		tmp = tmp->Next;
	tmp->Next = n->Next;
	delete n;
}

template<class ValueType>
void List<ValueType>::PushStart(ValueType k) //вставка в начало
{
	Node<ValueType>* tmp;
	try
	{
		tmp = new Node<ValueType>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create list");
	}
	tmp->Next = First;
	First = tmp;
}

template<class ValueType>
int List<ValueType>::operator==(const List<ValueType>& l)const //перегрузка сравнения на равенство
{
	Node<ValueType>* f1 = First;
	Node<ValueType>* f2 = l.First;
	while ((f1 != 0) && (f2 != 0)) 
	{
		if (f1->key != f2->key)
			return 0;
		f1 = f1->Next;
		f2 = f2->Next;
	}
	if (f1 != f2)
		return 0;
	return 1;
}

template<class ValueType>
int List<ValueType>::operator!=(const List<ValueType>& l)const //перегрузка на неравенство
{
	return !(*this == l);
}

template <class ValueType>
void List<ValueType>::PushBefore(ValueType findkey, ValueType k) //вставка перед элементов с заданным ключом
{
	Node<ValueType>* n = Find(findkey);
	if (First == n)
	{
		PushStart(k);
		return;
	}
	Node<ValueType>* prevnode = First;
	while (prevnode->Next != n)
		prevnode = prevnode->Next;
	Node<ValueType>* t = prevnode->Next;
	Node<ValueType>* tmp = new Node<ValueType>(k);
	prevnode->Next = tmp;
	tmp->Next = t;
}

template<class ValueType>
void List<ValueType>::Print()const //вывод списка
{
	if (!First)
	{
		cout << "List is empty";
		return;
	}
	Node<ValueType>* tmp = First;
	while (tmp != 0)
	{
		cout << tmp->key << ' ';
		tmp = tmp->Next;
	}
	cout << endl;
}