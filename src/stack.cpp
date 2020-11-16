#include "stack.h"
#include "list.cpp"
#include "list.h"

template<class ValueType>
Stack<ValueType>::Stack()
{
	list = new List<ValueType>();
}

template<class ValueType>
Stack<ValueType>::~Stack()
{
	delete list;
}

template<class ValueType>
Stack<ValueType>::Stack(const Stack<ValueType>& stack)
{
	list = new List<ValueType>(*(stack.list));
}

template<class ValueType>
int Stack<ValueType>::IsEmpty(void)const
{
	return(list->GetFirst() == 0);
}

template<class ValueType>
int Stack<ValueType>::IsFull(void)const
{
	Node<ValueType> *tmp;
	try
	{
		tmp = new Node<ValueType>;
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

template<class ValueType>
void Stack<ValueType>::Push(const ValueType k)
{
	if (IsFull())
		throw
		exception("Stack is full");
	list->PushStart(k);
}

template<class ValueType>
ValueType Stack<ValueType>::Pop()
{
	if (IsEmpty())
		throw
			exception ("Stack is empty");
	ValueType tmp = list->GetFirst()->key;
	list->Remove(tmp);
	return tmp;
}

template <class ValueType>
int Stack<ValueType>::operator==(const Stack<ValueType>& s)const
{
	return (*list == *(s.list));
}

template <class ValueType>
int Stack<ValueType>::operator!= (const Stack<ValueType>& s)const
{
	return (*list != *(s.list));
}

template <class ValueType>
void Stack<ValueType>::Print()const
{
	Stack<ValueType>* s = new Stack<ValueType>(*this);
	while (!(s->IsEmpty()))
		cout << s->Pop() << endl;
}

template <class ValueType>
ValueType Stack<ValueType>::GetKey()
{
	if (IsEmpty())
		throw
		exception ("Stack is empty");
	return list->GetFirst()->key;
}