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