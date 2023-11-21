#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include "TStack.h"

using namespace std;

class TCalc
{
	string infix, postfix;
	string set_infix(string s) {
		infix = s;
	}
	string set_infix() {
		string s;
		cin >> s;
		infix = s;
	}
	void get_infix() {
		cout << infix;
	};
	void get_postfix() {
		cout << postfix;
	};
	TStack<double> D;
	TStack<char> C;
	int prior(char op) {
		if ((op == '(') || (op == ')')) return 0;
		if ((op == '+') || (op == '-')) return 1;
		if ((op == '*') || (op == '/')) return 2;
	}
public: 
	TCalc() {
		infix = "";
	}
	TCalc(string s) {
		infix = s;
	}
	double CalcPostfix();
	void ToPostfix();			// функция перевода строки из инфиксной в постфиксную. В начале почистить стек метлой!
};