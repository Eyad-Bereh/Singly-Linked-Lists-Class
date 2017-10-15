/*
SSList (Singly Linked Lists) Class
*/
#ifndef __SSLIST__
#define __SSLIST__
#include <iostream>
#include <ctime>
#include <cstdlib>

/*
The Node Class Holds Only Two Data Memebers:
1-)The "next" Field Which Is A Pointer Of The Type Node.
2-)The "data" Field Which Is Just An Integer.
*/
template<class T>
class Node {
public:
	T data;
	Node<T> *next;

	Node(T value, Node<T> *nxt = NULL) {
		data = value;
		next = nxt;
	}

	Node() {
		data = T();
		next = NULL;
	}
};

/*
The SLList Contains The Follwing Data Memebers:
1-)"head" Represents The Start Of The List.
2-)"tail" Represents The End Of The List.
*/
template<class T>
class SLList {
private:
	Node<T> *head, *tail;

public:
	SLList() {
		head = tail = NULL;
	}

	void Add2Head(T value) {
		Node<T> *n = new Node<T>(value, NULL);
		if (head == NULL) {
			head = tail = n;
		}
		else {
			n->next = head;
			head = n;
		}
	}

	void Add2Tail(T value) {
		Node<T> *n = new Node<T>(value, NULL);
		if (head == NULL) {
			head = tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
	}

	int Count() {
		int s = 0;
		Node<T> *n = head;
		while (n != 0) {
			s++;
			n = n->next;
		}
		return s;
	}

	void DeleteHead() {
		Node<T> *temp = new Node<T>();
		if (head == NULL) {
			return;
		}
		else if (head == tail) {
			head = tail = NULL;
		}
		else {
			temp = head->next;
			delete head;
			head = temp;
		}
	}


	void DeleteTail() {
		if (head == NULL) {
			return;
		}
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			Node<T> *n = this->Access(this->Count() - 2);
			n->next = NULL;
			delete tail;
			tail = n;

			/*
			Node *n=head;
			while (n->next!=tail) {
			n=n->next;
			}
			n->next=0;
			delete tail;
			tail=n;
			*/
		}
	}

	bool NodeExist(T key) {
		int i = 0;
		while (i < this->Count()) {
			if (this->Access(i)->data == key) {
				return true;
			}
			i++;
		}
		return false;
	}

	int IndexOf(T key) {
		int i = 0;
		int index = -1;
		while (i < this->Count()) {
			if (this->Access(i)->data == key) {
				index = i;
				break;
			}
			i++;
		}
		return index;
	}

	void DeleteNodeByKey(T value) {
		int i = 0;
		while (i < this->Count()) {
			if (this->Access(i)->data == value) {
				this->DeleteNodeAt(i);
				i = 0;
			}
			i++;
		}
	}

	Node<T>* Access(int index) {
		Node<T> *n = head;
		int i = 0;
		while (i<index) {
			n = n->next;
			i++;
		}
		return n;
	}

	Node<T>* operator[](int index) {
		Node<T> *n = head;
		int i = 0;
		while (i<index) {
			n = n->next;
			i++;
		}
		return n;
	}

	void DeleteNodeAt(int index) {
		Node<T> *before = this->Access(index - 1);
		Node<T> *after = this->Access(index + 1);
		before->next = after;
	}

	void InsertNodeAt(int index, T value) {
		Node<T> *before = this->Access(index - 1);
		Node<T> *temp = this->Access(index);
		Node<T> *n = new Node<T>(value, temp);
		before->next = n;
	}

	void SortList() {
		Node<T> *n = new Node<T>();
		for (int i = 0; i < this->Count(); i++) {
			for (int j = i; j < this->Count(); j++) {
				if (i == j) {
					continue;
				}
				else {
					if (this->Access(i)->data > this->Access(j)->data) {
						n->data = this->Access(i)->data;
						this->Access(i)->data = this->Access(j)->data;
						this->Access(j)->data = n->data;
					}
				}
			}
		}
	}

	int LastIndexOf(T key) {
		int i = 0;
		int index = -1;
		while (i< this->Count()) {
			if (this->Access(i)->data == key) {
				index = i;
			}
			i++;
		}
		return index;
	}

	int* IndicesOf(T key, int &length) {
		length = 0;
		int i = 0;
		while (i< this->Count()) {
			if (this->Access(i)->data == key) {
				length++;
			}
			i++;
		}
		T *indices = new T[length];
		int index = 0;
		i = 0;
		while (i< this->Count()) {
			if (this->Access(i)->data == key) {
				indices[index] = i;
				index++;
			}
			i++;
		}
		return indices;
	}

	bool IsSorted() {
		int i = 0;
		bool __IsSorted = true;
		while (i < this->Count() - 1) {
			if (!(this->Access(i)->data <= this->Access(i + 1)->data)) {
				__IsSorted = false;
				break;
			}
			i++;
		}
		return __IsSorted;
	}

	void InsertNodeInSortedList(T value) {
		int i = 0;
		int index = 0;
		if (this->IsSorted()) {
			while (i < this->Count()) {
				if (this->Access(i)->data <= value) {
					index++;
				}
				i++;
			}
			this->InsertNodeAt(index, value);
		}
		else {
			this->SortList();
			while (i < this->Count()) {
				if (this->Access(i)->data <= value) {
					index++;
				}
				i++;
			}
			this->InsertNodeAt(index, value);
		}
	}

	int RepetitionsOf(T value) {
		int s = 0;
		int i = 0;
		while (i < this->Count()) {
			if (this->Access(i)->data == value) {
				s++;
			}
			i++;
		}
		return s;
	}

	T SumOfDataFields() {
		T s = 0;
		int i = 0;
		while (i < this->Count()) {
			s += (this->Access(i)->data);
			i++;
		}
		return s;
	}

	T ProductOfDataFields() {
		T s = 1;
		int i = 0;
		while (i < this->Count()) {
			s *= (this->Access(i)->data);
			i++;
		}
		return s;
	}

	T MaxOfDataFields() {
		T max = this->Access(0)->data;
		int i = 0;
		while (i < this->Count()) {
			if (max < this->Access(i)->data) {
				max = this->Access(i)->data;
			}
			i++;
		}
		return max;
	}

	T MinOfDataFields() {
		T min = this->Access(0)->data;
		int i = 0;
		while (i < this->Access(i)->data) {
			if (min>this->Access(i)->data) {
				min = this->Access(i)->data;
			}
			i++;
		}
		return min;
	}

	void ReverseValues() {
		T temp;
		int i = 0;
		int length = this->Count();
		while (i < length / 2) {
			temp = this->Access(i)->data;
			this->Access(i)->data = this->Access(length - i - 1)->data;
			this->Access(length - i - 1)->data = temp;
			i++;
		}
	}

	void FillWith(T value) {
		int i = 0;
		while (i < this->Count()) {
			this->Access(i)->data = value;
			i++;
		}
	}

	T Random() {
		srand(time(0));
		return this->Access(rand() % (this->Count()))->data;
	}

	T* GetAllKeys() {
		int i = 0;
		T *keys = new T[this->Count()];
		while (i < this->Count()) {
			keys[i] = this->Access(i)->data;
			i++;
		}
		return keys;
	}

	~SLList() {
		Node<T> *n = head;
		Node<T> *m;
		while (n != NULL) {
			m = n->next;
			delete n;
			n = m;
		}
		head = tail = NULL;
	}
};

#endif
