
#include "pch.h"
#include <iostream>
#include<time.h>
using namespace std;
struct elem {
	int x;
	elem* next;
};

class Bar {
private:
	elem* head;
public:
	Bar() {
		elem* one = new elem;
		elem* two = new elem;
		elem* three = new elem;
		one->x = 1;
		two->x = 2;
		three->x = 3;
		one->next = two;
		two->next = three;
		three->next = one;
		head = one;
	}

	int spin() {
		elem* temp = head;
		
			for (int i = 0; i < (rand() % 10); i++) {
				temp = temp->next;
			}
			cout << "|"<<temp->x<<"| ";
		return temp->x;
	}
	

	~Bar() {
		elem* temp = head;
		for (int i = 0; i < 3;i++) {
			temp = head;
			head = temp->next;
			delete temp;
		}
	}
};

int main()
{
	int spin1, spin2, spin3;
srand(time(NULL));
Bar B1, B2, B3;
while (true) {
	spin1 = B1.spin();
	spin2 = B2.spin();
	spin3 = B3.spin();
	if ((spin1 == spin2) && (spin2 == spin3)) {
		cout <<" - Win"<<endl;
	}
	else cout << " - Loose" << endl;
	getchar();
}
}