#ifndef QUEUE_LINKED_LIST_HPP_
#define QUEUE_LINKED_LIST_HPP_


template <typename T>
class QueueLinkedList {
private:
	struct Node {
		T val;
		Node* next;

		Node() : val{}, next{nullptr} {}
		Node(T v) : val{v}, next{nullptr} {}
		Node(T v, Node* n) : val{v}, next{nullptr} {}
	};

	Node* head, *tail;
	unsigned queueSize;

public:
	// default constructor
	QueueLinkedList() : head{nullptr}, tail{nullptr}, queueSize{0} {}

	// destructor
	~QueueLinkedList() {
		while (head) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	// add, remove, and find methods
	void enq(T obj) {
		Node* toAdd = new Node(obj);
		queueSize++;
		if (!head) {
			// first thing in the queue
			head = tail = toAdd;
			return;
		}

		tail->next = toAdd;
		tail = tail->next;
	}

	T deq() {
		if (!head) {
			throw;
		}
		queueSize--;
		Node* toDelete = head;
		T res = toDelete->val;
		head = head->next;
		delete toDelete;
		return res;
	}

	T front() {
		if (!head) {
			throw;
		}

		return head->val;
	}

	unsigned size() {
		return queueSize;
	}

	bool empty() {
		return queueSize == 0;
	}
};


#endif
