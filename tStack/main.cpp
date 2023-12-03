#include "TStack.h"
using namespace std;

int main() {
	/*TStack<int> s;
	s.print();
	cout << endl;
	cout << endl;
	cout << "_____________________________\n";
	for (int i = 0; i < 5; i++) {
		s.Push(i);
	}
	s.print();
	cout << "_____________________________" << endl;

	//������� ����� ����� ���, ��� ��������� ������

	while (!s.empty()) {
		s.Pop();
	} */

	string str = "(2+2)*2 + (3*4)";				//���������, ��� �� ������ ����� ���� (...)
	TStack<char> s(20);							//�������, ���� ���� ���� )...( ��� ���� �������� ������
	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.Push(str[i]);
		if (str[i] == ')') {
			if (!s.empty())
				s.Pop();
			else
				res = 1;
		}
	}
	if (!s.empty())
		res = 2;

	// res = 0 -> ��� ��; res = 1 -> ���� �������� ������ ); res = 2 -> ���� �������� ������ (
	 
}