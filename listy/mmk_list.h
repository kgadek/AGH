/* Autor: mmk */

#ifndef _MMK_LIST_
#define _MMK_LIST_

#include <iostream>

namespace mmk {

	template<class D> struct Node;
	template<class D> struct Node2;
	template<class D> class List;
	template<class D> class List2;
	template<class D> std::ostream & operator<<(std::ostream&, Node<D>*);
	template<class D> std::ostream & operator<<(std::ostream&, List<D>*);
	template<class D> std::ostream & operator<<(std::ostream&, Node2<D>*);
	template<class D> std::ostream & operator<<(std::ostream&, List2<D>*);

	template<class D>
	struct Node {
		Node<D> *next;
		D data;
		Node(const D& d) :
			data(d), next(NULL) {
		}
	};
	template<class D>
	class List {
	public:
		Node<D>* head;
		List() :
			head(NULL) {
		}
		List(const D& d) :
			head(new Node<D> (d)) {
		}
		~List() {
			Node<D>* h;
			for (h = head; h; head = h) {
				h = h->next;
				delete (head);
			}
		}
		void insert(const D& d) {
			Node<D>* tmp = new Node<D> (d);
			tmp->next = head;
			head = tmp;
		}
		void print() {
			std::cout << this;
		}
		void insertionsort() {
			Node<D>* sorted = new Node<D> ;
			while (head) {
				Node<D>* next = head->next;
				insert(&sorted, head);
				head = next;
			}
			head = sorted;
		}
		void remove(Node<D>** p) {
			if (*p == NULL) return;
			if (*p == head) {
				head = head->next;
			} else {
				Node<D>* h;
				for (h = head; h->next != NULL && h->next != *p; h = h->next)
					;
				if (h->next) h->next = h->next->next;
			}
		}
		void selectionsort() {
			Node<D>* sorted = NULL;
			Node<D>* h, *min, *p = NULL, *pmin;

			while (head) {
				for (min = h = head; h != NULL; h = h->next)
					if (h->data < min->data) min = h;

				remove(&min);

				if (sorted != NULL)
					sorted->next = min;
				else p = min;
				sorted = min;
				sorted->next = NULL;
			}
			head = p;
		}
	private:
		void insert(Node<D>** head, Node<D>* node) {
			while (*head && (*head)->data < node->data)
				head = &(*head)->next;
			node->next = *head;
			*head = node;
		}
	};

	template<class D>
	struct Node2 {
		Node2<D> *next, *prev;
		D data;
		Node2() :
			next(NULL), prev(NULL) {
		}
		Node2(const D& d) :
			data(d), next(NULL), prev(NULL) {
		}
	};
	template<class D>
	class List2 {
	public:
		Node2<D> *tail, *head;
		List2() :
			head(NULL), tail(NULL) {
		}
		List2(const D& d) {
			head = new Node2<D> (d);
			tail = head;
		}
		void print() {
			std::cout << this;
		}
		void insert(const D& d) {
			Node2<D> *tmp = new Node2<D> (d);
			tmp->next = head;
			if (empty()) {
				tail = tmp;
			} else {
				head->prev = tmp;
			}
			head = tmp;
		}
		bool remove(Node2<D> *p) {
			if (p == NULL) {
				std::cout << "ERROR: element is not on the list!" << std::endl;
				return -1;
			} else if (!empty()) {
				if (p == head && p == tail) {
					head = NULL;
					tail = NULL;
				} else {
					if (p != head)
						p->prev->next = p->next;
					else {
						head = p->next;
						head->prev = NULL;
					}
					if (p != tail)
						p->next->prev = p->prev;
					else {
						tail = p->prev;
						tail->next = NULL;
					}
				}
				delete (p);
				return 0;
			}
			return -1;
		}
		Node2<D>* search(int val) {
			for (Node2<D> *k = head; k != NULL; k = k->next) {
				if (k->data == val) return k;
			}
			return NULL;
		}
		bool empty() {
			if (head == NULL) return true;
			return false;
		}
		void mergesort() {
			msort(&head);
		}
		int length() {
			int i = 0;
			Node2<D>* h = head;
			for (; h != NULL; h = h->next)
				i++;
			return i;
		}
		void selectionsort() {
			Node2<D>* min;
			Node2<D>* sorted = new Node2<D> ();

			Node2<D>* k = sorted;
			while (head != NULL) {
				min = head;
				for (Node2<D>* h = head; h != NULL; h = h->next)
					if (h->data < min->data) min = h;

				if (min->next != NULL) min->next->prev = min->prev;
				if (min->prev != NULL)
					min->prev->next = min->next;
				else head = head->next;
				k->next = min;
				min->prev = k;
				min->next = NULL;
				k = min;
			}
			head = sorted->next;
			sorted->next = NULL;
			delete (sorted);
			sorted = NULL;
		}
		void insert(Node2<D>** head, int val) {
			while (*head && (*head)->data <= val)
				head = &(*head)->next;
			Node2<D>* node = new Node2<D> (val);
			node->next = *head;
			if (*head)
				node->prev = (*head)->prev;
			else node->prev = NULL;
			*head = node;
		}
		void insertionsort() {
			Node2<D>* k = new Node2<D> (-1);
			Node2<D>* sorted = k;
			while (head) {
				insert(&(sorted->next), head->data);
				head->prev = k;
				head = head->next;
			}
			head = sorted->next;
			delete (sorted);
		}
	private:
		int length(Node2<D> *h) {
			int i = 0;
			for (; h != NULL; h = h->next)
				i++;
			return i;
		}
		void merge(Node2<D>** p1, Node2<D>** p2) {
			if (*p2 == NULL) return;
			Node2<D>* guard = new Node2<D> ;
			guard->data = -1;
			guard->prev = NULL;
			guard->next = NULL;
			Node2<D>* tmp;
			Node2<D>* k = guard;
			Node2<D>** p;
			while (*p1 && *p2) {
				if ((*p1)->data < (*p2)->data)
					p = p1;
				else p = p2;
				tmp = (*p)->next;
				(*p)->prev = k;
				k->next = *p;
				k = *p;
				if (tmp) (*p)->next->prev = (*p)->next = NULL;
				*p = tmp;
			}
			if (!(*p1 == NULL && *p2 == NULL)) if (*p1 == NULL)
				k->next = *p2;
			else k->next = *p1;
			*p1 = (guard->next);
			(*p1)->prev = NULL;
			guard->next = NULL;
			delete (guard);

		}
		void msort(Node2<D>** h) {
			int size = length(*h) / 2;
			if (size == 0) return;
			Node2<D>* p2 = *h;
			Node2<D>* p1 = p2;
			for (int i = 0; i < size; ++i)
				p2 = p2->next;
			p2->prev->next = NULL;
			p2->prev = NULL;
			msort(&p1);
			msort(&p2);
			merge(&p1, &p2);
			*h = p1;
		}
	};

	template<typename D> std::ostream & operator<<(std::ostream &out, Node<D>* l) {
		if (l)
			out << l->data;
		else out << "NULL";
		return out;
	}
	template<typename D> std::ostream & operator<<(std::ostream &out, Node2<D>* l) {
		if (l)
			out << l->data;
		else out << "NULL";
		return out;
	}
	template<typename D> std::ostream & operator<<(std::ostream &out, List<D>* t) {
		Node<D>* h = t->head;
		for (; h; h = h->next)
			out << h << " -> ";
		out << "NULL";
		out << "\n";
		return out;
	}
	template<typename D> std::ostream & operator<<(std::ostream &out, List2<D>* t) {
		Node2<D>* h = t->head;
		for (; h; h = h->next)
			out << h << " -> ";
		out << "NULL";
		out << "\n";
		return out;
	}

}
#endif
