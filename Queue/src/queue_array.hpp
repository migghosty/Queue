#ifndef QUEUE_ARRAY_HPP_
#define QUEUE_ARRAY_HPP_

#include <iostream>

template <typename T>
class QueueArray {
private:
	unsigned _front;
	unsigned rear;
	T* arr;
	unsigned arrTableSize;
	unsigned arrSize;

public:
	// default constructor
	QueueArray() : _front{0}, rear{0}, arr{new T[10]}, arrTableSize{10}, arrSize{0} {}

	// overload constructor
	QueueArray(unsigned tbSize) : _front{0}, rear{0}, arr{new T[tbSize]}, arrTableSize{tbSize}, arrSize{0} {}

	// destructor
	~QueueArray() {
		delete[] arr;
	}

	// add, remove, and find methods
	void enq(T obj) {
		if (arrSize >= arrTableSize) {
			// expand array
			T* newArray = new T[arrTableSize * 2 + 1];
			for (unsigned i=0; i < arrTableSize; i++) {
				newArray[i] = arr[(i+_front)%arrTableSize];
			}
			arrTableSize = arrTableSize * 2 + 1;
			delete[] arr;
			arr = newArray;
			_front = 0;
			rear = arrSize;
		}
		arrSize++;
		arr[rear++] = obj;
		rear = rear % arrTableSize;
	}

	T deq() {
		if (arrSize == 0)
			throw;
		arrSize--;
		T res = arr[_front++];
		_front = _front % arrTableSize;
		return res;
	}

	T front() {
		if (arrSize == 0)
			throw;
		return arr[_front];
	}

	unsigned size() {
		return arrSize;
	}

	bool empty() {
		return arrSize == 0;
	}

};



#endif
