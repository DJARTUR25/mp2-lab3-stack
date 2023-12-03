#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "TStack.h"

using namespace std;

class TCalc
{
	string infix, postfix;
	TStack<double> D;
	TStack<char> C;
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
	}

	void get_postfix() {
		cout << postfix;
	}

	int prior(char op) {
		if ((op == '(') || (op == ')')) return 0;
		if ((op == '+') || (op == '-')) return 1;
		if ((op == '*') || (op == '/')) return 2;
		if (op == '^') return 3;
	}
public: 
	TCalc() {
		infix = "";
	}
	TCalc(string s) {
		infix = s;
	}
	double CalcPostfix();
	void ToPostfix();			// функция перевода строки из инфиксной в постфиксную. В начале почистить стек!
	double Calc();
};