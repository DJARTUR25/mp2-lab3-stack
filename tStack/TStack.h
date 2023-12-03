#pragma once
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>

using namespace std;

template <class T>
class TStack
{
	T* pMem;		//������ 
	int MaxSize;	//������ �����
	int CurrInd;	//������ ������� �����
public:
	TStack(int _MaxSize = 10) {			//����������� �� ���������
		if (_MaxSize < 0) throw ("Wrong size!\n");
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	~TStack() { delete[] pMem; }		//����������
	TStack(const TStack& s) {			//����������� �����������
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
	
	bool empty() {				//�������� ��������, ���� �� ���-�� � ����� (�������� �� �������)
		if (CurrInd < 0) 
			return true;
		else 
			return false;
	}

	bool full() {				//�������� ��������, ����� �� �������� ���-�� � ���� (�������� �� �������)
		if (CurrInd == MaxSize - 1)
			return true;
		else
			return false;
	}

	void Push(const T &elem) {			//�������� ���������� �������� �� ������� �����
		if (CurrInd + 1 >= MaxSize)
			throw ("Stack overflow!\n");
		CurrInd++;
		pMem[CurrInd] = elem;
	}

	T Pop() {							//�������� �������� �������� � ������� �����
		if (CurrInd == -1)
			throw ("Stack is empty!\n");
		T res = pMem[CurrInd];
		CurrInd--;
		return res;
	}

	void Clear() {					// ������� �����
		CurrInd = -1;
		delete[] pMem;
	}

	friend istream& operator>>(istream& istr, TStack& s)		// ���� � ����������
	{
		for (int i = 0; i < s.MaxSize; i++)
			istr >> s.pMem[i];
		return istr;
	}

	friend ostream& operator<<(ostream& ostr, const TStack& s)	// ����� � ����������
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