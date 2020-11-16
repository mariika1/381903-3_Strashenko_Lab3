#pragma once
#include "list.h"


template<class ValueType>
class Stack
{
private:
	List<ValueType> *list;
public:
	Stack();
	Stack(const Stack<ValueType>&);
	~Stack();
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const ValueType);
	ValueType Pop();
	int operator==(const Stack<ValueType>& s)const;
	int operator!=(const Stack<ValueType>& s)const;
	void Print()const;
	ValueType GetKey();
};

template<class ValueType>
Stack<ValueType>::Stack();

template<class ValueType>
Stack<ValueType>::Stack(const Stack<ValueType>&);

template<class ValueType>
int Stack<ValueType>::IsEmpty(void)const;

template<class ValueType>
int Stack<ValueType>::IsFull(void)const;

template<class ValueType>
void Stack<ValueType>::Push(const ValueType k);

template<class ValueType>
ValueType Stack<ValueType>::Pop();

template <class ValueType>
int Stack<ValueType>::operator!=(const Stack<ValueType>& s)const;

template <class ValueType>
int Stack<ValueType>::operator==(const Stack<ValueType>& s)const;

template <class ValueType>
void Stack<ValueType>::Print()const;

template <class ValueType>
ValueType Stack<ValueType>::GetKey();
