#pragma once
#include "node.h"


template<class ValueType>
class List
{
private:
	Node<ValueType> *First;
public:
	List();
	List(const List<ValueType>& l);
	~List();
	Node<ValueType>* Find(ValueType k);
	void PushAfter(ValueType findkey, ValueType k);
	int PushEnd(ValueType k);
	Node<ValueType>* GetFirst(void);
	void Remove(ValueType findkey);
	void PushStart(ValueType k);
	int operator==(const List<ValueType>& l)const;
	int operator!=(const List<ValueType>& l)const;
	void PushBefore(ValueType findkey, ValueType k);
	void Print()const;
};

template<class ValueType>
List<ValueType>::List();


template<class ValueType>
List<ValueType>::List(const List<ValueType>& l);

template<class ValueType>
List<ValueType>::~List();

template<class ValueType>
Node<ValueType>* List<ValueType>::Find(ValueType k);

template<class ValueType>
void List<ValueType>::PushAfter(ValueType findkey, ValueType k);

template<class ValueType>
int List<ValueType>::PushEnd(ValueType k);

template<class ValueType>
Node<ValueType>* List<ValueType>::GetFirst(void);

template<class ValueType>
void List<ValueType>::Remove(ValueType findkey);

template<class ValueType>
void List<ValueType>::PushStart(ValueType k);

template<class ValueType>
int List<ValueType>::operator==(const List<ValueType>& l)const;

template<class ValueType>
int List<ValueType>::operator!=(const List<ValueType>& l)const;

template <class ValueType>
void List<ValueType>::PushBefore(ValueType findkey, ValueType k);

template<class ValueType>
void List<ValueType>::Print()const;