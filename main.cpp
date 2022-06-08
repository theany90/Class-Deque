#include <iostream>
#include "Deque.h"
using namespace std;

int menu() {
	int opt = 1, type, size; 
	bool isInt = false; 
	
	char data; 
	int element; 
	cout << "Do you want your queue to will be int or char?"; 
	X:
	cout << "\n1 for int 2 for char: "; 
	cin >> type;
	switch(type) {
		case 1: 
		type = 4; 
		isInt = true; 
		break; 
		case 2: 
		type = 1;
		isInt = false;  
		break; 
		default: 
		cout << "There's no option at " << type << "!"; 
		goto X; 
	}
	cout << "Please set size of the double ended queue (0 for exit): "; 
	cin >> size; 
	
	Deque dq(size, type); 
	
	if(size == 0) {
		cout << "Entered 0, program now exiting"; 
		exit(0);
	}
	while(opt != 0) {
		
		cout << "\n 1) Insert element to front\n 2) Insert element to rear\n 3) Delete from front\n 4) Delete from rear\n 5) Get front\n 6) Get rear\nPlease choose the action you want to do: ";
		cin >> opt;  
		switch(opt) {
		case 0: 
		exit(0);
		break; 
		
		case 1: 
		if(isInt) {
			cout << "Please enter the integer you want to insert: "; 
			cin >> element; 
			dq.insertfront(&element);
		}
		else {
			cout << "Please enter the char you want to insert: "; 
			cin >> data; 
			dq.insertfront(&data);
		}
		break; 
		case 2: 
		if(isInt) {
			cout << "Please enter the integer you want to insert: "; 
			cin >> element; 
			dq.insertrear(&element);
		}
		else {
			cout << "Please enter the char you want to insert: "; 
			cin >> data; 
			dq.insertrear(&data);
		}
		break; 
		case 3: 
		if(dq.isEmpty()) {
			cout << "You have to add something before deleting!";
		}
		else {
			if(isInt) {
				cout << *(int*)dq.getFront() << " deleted."; 
				dq.deletefront();
			}
			else {
				cout << *(char*)dq.getFront() << " deleted."; 
				dq.deleterear();
			}
		}
		break; 
		case 4: 
		if(dq.isEmpty()) {
			cout << "You have to add something before deleting!";
		}
		else {
			if(isInt) {
				cout << *(int*)dq.getRear() << " deleted."; 
				dq.deleterear();
			}
			else {
				cout << *(char*)dq.getRear() << " deleted."; 
				dq.deleterear();
			}
		}
		break; 	
		
		case 5:
		if(dq.isEmpty()) {
			cout << "You have to add something before getting!";
		}
		else {
			if(isInt) {
				cout << "Your value at the front of queue is:  " << *(int*)dq.getFront(); 
			}
			else {
				cout << "Your value at the front of queue is:  " << *(char*)dq.getFront(); 
			}
		}
		break; 
		case 6: 
		if(dq.isEmpty()) {
			cout << "You have to add something before getting!";
		}
		else {
			if(isInt) {
				cout << "Your value at the rear of queue is:  " << *(int*)dq.getRear(); 
			}
			else {
				cout << "Your value at the rear of queue is:  " << *(char*)dq.getRear(); 
			}
		}
		break; 
	}
	}
}

template<class T>
T sum(T a, T b) {
	
	return a + b;  
}


int main() {
	menu();

  return 0;
}


