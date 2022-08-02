#include <iostream>
#include "queue_linked_list.hpp"
#include "queue_array.hpp"


int main() {
	/* Testing Queue using LinkedList */
	std::cout << "Testing Queue with Linked List..." << std::endl;
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

	/* Testing Queue using Array */
	std::cout << "\nTesting Queue with Array..." << std::endl;
	QueueArray<int> qa(5);
		for (int i=0; i < 5; i++) {
			qa.enq(i);
		}

		qa.enq(5);


		std::cout << qa.front() << std::endl; // output 0
		qa.deq();
		std::cout << qa.front() << std::endl; // output 1
		qa.deq();
		qa.deq();

		qa.enq(10);
		qa.enq(11);
		qa.enq(12);

		while (!qa.empty()) {
			std::cout << qa.deq() << std::endl; // output 3-5 then 10 - 12
		}

	return 0;
}
