#pragma once
#include "TCalc.h"

double TCalc::CalcPostfix() {			// в конце очистить стек!
	for (int i = 0; i < postfix.length(); i++) {
		if ((postfix[i] >= '0') && (postfix[i] <= '9'))
			D.Push(postfix[i] - '0');
		else 
			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/')) {
				double x1, x2, res;
				x2 = D.Pop(); x1 = D.Pop();
				if (postfix[i] == '+') res = x1 + x2;
				if (postfix[i] == '-') res = x1 - x2;
				if (postfix[i] == '*') res = x1 * x2;
				if (postfix[i] == '/') res = x1 / x2;
				D.Push(res);
			}
	}
	double res = D.Pop();
	return res;
}

void TCalc::ToPostfix() {
	//очистить стек C до начала работы
	string str = "(" + infix + ")";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			C.Push('(');
		}
		else 
			if ((str[i] >= '0') && (str[i] <= '9')) {
				postfix += str[i];
			}
		if (str[i] == ')') {
			char El = C.Pop();
			while (El != '(') {
				postfix += El;
				El = C.Pop();
			}
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {
			char El = C.Pop();
			while (prior(El) >= prior(str[i])) {
				postfix += El;
				El = C.Pop();
			}
		}
	}
}

double TCalc::Calc() {
	C.Clear(); D.Clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++) {					// проверка условий для подсчета операций
		if (str[i] == '(') C.Push(str[i]);
		if (str[i] == ')') {
			char elem = C.Pop();
			while (elem != ')') {
				double x1 = D.Pop();
				double x2 = D.Pop();
				double y = 0;
				if (elem == '+') y = x1 + x2;
				if (elem == '-') y = x1 - x2;
				if (elem == '*') y = x1 * x2;
				if (elem == '/') y = x1 / x2;				// добавить функцию ^ - возведение в степень, приоритет = 3
				if (elem == '^') y = pow(x1, x2);
				D.Push(y);
				elem = C.Pop();
			}
		}
		if ((str[i] >= '0') && (str[i] <= '9')) {			//вычисляет число 
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			D.Push(x);
			i = i + pos - 1;
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {			//добавляет в стек операнды, вычисляет, если
			char elem = C.Pop();																//приоритет меньше, что считает
			while (prior(elem) > prior(str[i])) {
				double y;
				double x2 = D.Pop();
				double x1 = D.Pop();
				if (elem == '+') y = x1 + x2;
				if (elem == '-') y = x1 - x2;
				if (elem == '*') y = x1 * x2;
				if (elem == '/') y = x1 / x2;	// может быть неточный ответ. При тесте сравниваем не вручную вбитые значения, а то, что посчитает компилятор
				if (elem == '^') y = pow(x1, x2);
				D.Push(y);
				elem = C.Pop();
			}
			C.Push(elem);
			C.Push(str[i]);
		}
	}
	return D.Pop();
}