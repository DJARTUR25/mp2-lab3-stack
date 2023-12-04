#pragma once
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

template <class T>
class TQueue
{

	T* pMem;
	int size, start, finish, count;

public:
	TQueue(int _size) {
		pMem = new T[_size];
		size = _size;
		count = 0;			
		start = 0;
		finish = -1;
	}

	TQueue(const TQueue& s) {
		size = s.size;
		pMem = new T[size];
		for (int i = 0; i < size; i++) 
			pMem[i] = s.pMem[i];
		count = s.count;
		start = s.start;
		finish = s.finish;
	}
	~TQueue() { delete[] pMem; }

	size() { return size; }

	clear() {
		delete[] pMem;
		count = 0;
		start = 0;
		finish = -1;
	}

	bool operator == (const TQueue& s) {			//operator ==
		if (size != s.size) return false;
		else {
			if (start != s.srart) return false;
			else {
				if (finish != s.finish) return false;
				else {
					for (int i = 0; i < size; i++) {
						if (pMem[i] != s.pMem[i]) return false;
					}
				}
			}
		}
		return true;
	}

	bool operator != (const TQueue& s) {			//operator != 
		if (*this == s) return false;
		else return true;
	}

	bool empty() {									//check of empty queue: if count = 0 -> queue is empty
		if (count == 0) return true;
		else return false;
	}

	bool full() {									//check of full queue: if count = size -> queue is full
		if (count == size) return true;
		else return false;
	}

							//push & pop
	void Push(const T& el) {
	//	finish = finish % size; than u can delete next 2 strings

		finish++;
		if (finish == size) finish = 0;			//or finish -= size, but i don t sure that it`ll work


		//	if (*this.full() == true) throw ("Can`t Push!!")


		pMem[finish] = el;				//in pMem[finish] can be element. Need to add check of execution "can we push here?"
		count++;
	}

	T Pop() {
		T el = pMem[start];
		start++;						
		if (start == size) start = 0;
		count--;
		return el;
	}

	T front() { return pMem[start]; }			// front returns 1st element in the queue
	T back() { return pMem[finish]; }			// returns last element in the queue

	// Also add tests.
	//next: list.
};


//						WHAT ABOUT BRANCHES IN GITHUB???
// 
// 
//git branch - check all ur branches
//git branch -r - show where looks ur head
//git branch newbranch - create new branch "newbranch"
//git checkout newbranch - switch branches
//git pull - download all changes from GitHub
//git merge - merged branches, if they are not equal
//git merge -h - do consol info about merge
//git merge --
//
// u can create the new branch, do something in new branch, and if it goes wrong return to last branch
// also u can merge this branches in one, if in github u can see "ABLE TO MERGE". U can choose who where will merge. 
// Will be created MERGE COMMIT. Later u can return to him.
// If in branches edited the same strings, will be conflict. U can solute this conflict only by hands :-)
// If u work in team, choose the team-leader, who will agree or not agree with commits. It exclude many conflicts.
// U can choose Barkalov))) He will confirm ur merges. After merge u can delete not main branches.

// to the next: finish tests of TCalc, TStack; finish TQueue; solute the same task as on the test in class 
// (do class TDoubleStacl *orTDStack*): in 1 array do 2 stacks, write constructors (copy, inicialization), Push/Pop to 1st and 2nd;
// empty1, empty2, full. Add executions