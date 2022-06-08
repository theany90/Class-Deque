#include "Deque.h"
#include <iostream>
using namespace std;
//constructors

Deque::Deque(int deque_size, int type_size) :array(nullptr), t_size(type_size), front(-1), rear(0) {
  	this->size = deque_size; 
  	array = new unsigned char[size * type_size];
  }
  
Deque::Deque(const Deque& Que) {
	this->array  = Que.array; 
	this->rear   = Que.rear; 
	this->front  = Que.front; 
	this->t_size = Que.t_size; 
	this->size   = Que.size; 
}
Deque::~Deque() {
	delete[] array; 
}
void Deque::operator=(const Deque& Que) {
	this->array  = Que.array; 
	this->rear   = Que.rear; 
	this->front  = Que.front; 
	this->t_size = Que.t_size; 
	this->size   = Que.size; 
	
}

bool Deque::operator==(const Deque& Que) {
	if((this->array == Que.array) && (this->rear == Que.rear) && (this->front == Que.front) && (this->t_size == Que.t_size) && (this->size == Que.size)) {
		return true;
	}
	else {
		return false; 
	}
}
bool Deque::operator!=(const Deque& Que) {
	if((this->array != Que.array) || (this->rear != Que.rear) || (this->front != Que.front) || (this->t_size != Que.t_size) || (this->size != Que.size)) {
		return true;
	}
	else {
		return false; 
	}
}


void Deque::memCpy(void *dest, void *src, unsigned long n) {
  	char *csrc = (char *)src;
  	char *cdest = (char *)dest;
  	
  	for(int i = 0; i < n; i++) {
  		cdest[i] = csrc[i];
	  }
  }
  
bool Deque::isFull() {
	return ((front == 0 && rear == size - 1) || front == rear + 1);
}
  
bool Deque::isEmpty() {
	return (front == -1); 
}

void Deque::insertfront(void *data) {
	if(isFull()) {
		return; 
	}
	
	if (front == -1) {
		front = 0; 
		rear = 0; 
	}
	
	else if(front == 0) {
		front = size - 1; 
	}
	else {
		front = front - 1; 
	}
	memCpy(array + (front * 4), data, t_size); 
}

void Deque::insertrear(void *data) {
	if(isFull()) {
		return; 
	}
	
	if (front == -1) {
		front = 0; 
		rear = 0; 
	}
	
	else if(rear == size - 1) {
		rear = 0;
	}
	else {
		rear = rear + 1;  
	}
	memCpy(array + (rear * 4), data, t_size); 
}

void Deque::deletefront() {
	 if (isEmpty()) {
    	return;
  }

  if (front == rear) {
   		front = -1;
    	rear = -1;
	 } 
  else if (front == size - 1)
    front = 0;

  else
    front = front + 1;
}

void Deque::deleterear() {
  if (isEmpty()) {
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (rear == 0)
    rear = size - 1;
  else
    rear = rear - 1;
}

void * Deque::getFront() {
	if (isEmpty()) {
		void * empty;
    	return empty; 
  	}
  	return at(front);
}
  
void * Deque::getRear() {
	
	if (isEmpty()) {
		void * empty;
    	return empty; 
  	}
  	return at(rear);
}
void * Deque::at(int n) {
	return array + (n * t_size);
}

void * Deque::operator[](int n) {
	return array + (n * t_size); 
}



