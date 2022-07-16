#include <iostream>
#include "queue_linked_list.hpp"


int main() {

	QueueLinkedList<int> qll;

	qll.enq(5);
	qll.enq(6);
	qll.enq(7);
	qll.enq(4);

	std::cout << qll.front() << std::endl;

	qll.deq();
	std::cout << qll.front() << std::endl;

	qll.enq(12);
	qll.enq(86);
	qll.enq(2);

	while (!qll.empty()) {
		std::cout << qll.deq() << std::endl;

	}

	return 0;
}
