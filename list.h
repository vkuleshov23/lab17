#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
using namespace std;


template <class T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;
	Node(T data) { this->datd = data; }
	Node(T data, Node* next, Node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};


template <class T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	size_t size = 0;
public:
	friend class Node<T>;
	List() : head(NULL), tail(NULL) {}

	void push_back(T data) {
		Node<T>* tmp = new Node<T>(data, NULL, tail);
		if (this->tail) {
			(this->tail)->next = tmp;
		}
		this->tail = tmp;
		if (this->head == NULL) {
			this->head = tmp;
		}
		this->size++;
	}

	void push_front(T data) {
		Node<T>* tmp = new Node<T>(data, head, NULL);
		if (this->head) {
			(this->head)->prev = tmp;
		}
		this->head = tmp;
		if (this->tail == NULL) {
			this->tail = tmp;
		}
		this->size++;
	}

	size_t ssize() const { return this->size; }


	Node<T>* erase(Node<T>* cur) {
		Node<T>* near = NULL;
		Node<T>* tmp = cur->next;
		if (cur->prev) {
			near = cur->prev;
			near->next = cur->next;
		}
		if (cur->next) {
			near = cur->next;
			near->prev = cur->prev;
		}
		if (cur == this->tail) { this->tail = near; }
		if (cur == this->head) { this->head = near; }
		cur->next = NULL;
		cur->prev = NULL;
		delete cur;
		this->size--;
		return tmp;
	}

	void find_and_erase(const T& value) {
		T val = value;
		Node<T>* cur = head;
		while (cur) {
			if (cur->data == val) {
				cur = this->erase(cur);
			}
			else cur = cur->next;
			
		}
		if (this->size == 0) {
			this->head = NULL;
			this->tail = NULL;
		}
	}

	Node<T>* at(int iter) {
		if (iter <= 0) return NULL;
		if (iter > this->size) return NULL;
		Node<T>* cur = NULL;
		if ((this->size - (size_t)iter) < ((size_t)iter)) {
			cur = head;
			for (int i = 1; i < iter; i++) {
				cur = cur->next;
			}
		}
		else {
			cur = tail;
			for (int i = 1; i <= (this->size - (size_t)iter); i++) {
				cur = cur->prev;
			}
		}
		return cur;
	}

	void clear() {
		Node<T>* cur = head;
		while (cur) {
			cur = this->erase(cur);
		}
		this->head = NULL;
		this->tail = NULL;
	}



	void printl() const {
		if (this->ssize()) {
			Node<T>* cur = head;
			cout << "{ ";
			while (cur) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << "}\n";
		}
	}
	~List() { this->clear(); }
};
#endif _LIST_H_
