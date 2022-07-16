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

	return 0;
}
