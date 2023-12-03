#pragma once
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>

using namespace std;

template <class T>
class TStack
{
	T* pMem;		//массив 
	int MaxSize;	//размер стека
	int CurrInd;	//индекс вершины стека
public:
	TStack(int _MaxSize = 10) {			//конструктор по умолчанию
		if (_MaxSize < 0) throw ("Wrong size!\n");
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	~TStack() { delete[] pMem; }		//деструктор
	TStack(const TStack& s) {			//конструктор копирования
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
		for (int i = 0; i <= CurrInd; i++) pMem[i] = s.pMem[i];
	}

	int size() { return MaxSize; }

	int idx() { return CurrInd; }

	void print() {
		for (int i = 0; i <= CurrInd; i++)
			cout << pMem[i] << "  ";
		cout << endl;
		cout << endl;
	}
	
	bool empty() {				//операция проверки, есть ли что-то в стеке (проверка на пустоту)
		if (CurrInd < 0) 
			return true;
		else 
			return false;
	}

	bool full() {				//операция проверки, можно ли добавить что-то в стек (проверка на полноту)
		if (CurrInd == MaxSize - 1)
			return true;
		else
			return false;
	}

	void Push(const T &elem) {			//операция добавления элемента на вершину стека
		if (CurrInd + 1 >= MaxSize)
			throw ("Stack overflow!\n");
		CurrInd++;
		pMem[CurrInd] = elem;
	}

	T Pop() {							//операция удаления элемента с вершины стека
		if (CurrInd == -1)
			throw ("Stack is empty!\n");
		T res = pMem[CurrInd];
		CurrInd--;
		return res;
	}

	void Clear() {					// очистка стека
		CurrInd = -1;
		delete[] pMem;
	}

	friend istream& operator>>(istream& istr, TStack& s)		// ввод с клавиатуры
	{
		for (int i = 0; i < s.MaxSize; i++)
			istr >> s.pMem[i];
		return istr;
	}

	friend ostream& operator<<(ostream& ostr, const TStack& s)	// вывод с клавиатуры
	{
		if (s.CurrInd == -1) {
			ostr << "Stack Is Empty" << endl;
		}
		else {
			for (int i = 0; i < s.CurrInd; i++)
				ostr << s.pMem[i] << ' ';
			ostr << endl;
		}
		return ostr;
	}
};