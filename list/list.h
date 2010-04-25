#ifndef _LIST_
#define _LIST_
#include <iostream>
using namespace std;

class list {
	class el {
		public:
			el *next;
			int value;
			el() {next = NULL;}
			el(int val) {next = NULL;value=val;}
		};
	public:
		el* head;
		list() {head=NULL;}
		list(int value) {
			head->value = value;
			head->next = NULL;
		}
		void add(int value) {
			el* tmp = new el(value);
			tmp->next = head;
			head = tmp;
		}
		void print() {
			el* h = head;
			for(; h; h=h->next) {
				cout << h->value << " ";
			}
			cout << "\n";
		}
		void insertionsort() {
			el* sorted = new el;
			while( head ) {
				el* next = head->next;
				insert(&sorted, head);
				head = next;
			}
			head = sorted;
		}
		void d(el** p) {
			if(*p==NULL) return;
			if(*p==head) {
				head=head->next;
			} else {
				el* h;
				for(h=head; h->next!=NULL && h->next!=*p; h=h->next);
				if(h->next) h->next = h->next->next;
			}
		}
		void selectionsort() {
			el* sorted = NULL;
			el* h, *min, *p=NULL, *pmin;
			
			while( head ) {
// 			print();
				for(min=h=head; h!=NULL; h=h->next)
					if( h->value < min->value ) min = h;
					
				d(&min);
				
				if(sorted!=NULL) sorted->next = min;
				else p=min;
				sorted = min;
				sorted->next = NULL;
			}
			head = p;
		}
	private:
		void insert(el** head, el* node) {
			while(*head && (*head)->value < node->value) head = & (*head)->next;
			node->next = *head;
			*head = node;
		}
};


class list2 {
	class lel {
		public:
		lel *next;
		lel *prev;
		int value;
		lel() {next=prev=NULL;}
		lel(int val) {next=prev=NULL;value=val;}
	};
public:
	lel *tail;
	lel *head;
	list2() {
		tail = head = NULL;
	}
	list2(int val) {
		head = new lel;
		head->value = val;
		head->next = head->prev = NULL;
		tail = head;
	}
	void print() {
		for(lel *k=head;k!=NULL;k=k->next) {
			std::cout << k->value << ' ';
		}
		std::cout << ' ' << std::endl;
	}
	void insert(int val) {
		lel *tmp = new lel;
		tmp->value = val;
		tmp->next = head;
		tmp->prev = NULL;
		if(empty()) {
			tail = tmp;
		} else {
			head->prev = tmp;
		}
		head = tmp;
	}
	bool del(lel *p) {
		if(p==NULL) {
			std::cout << "ERROR: element is not on the list!" << std::endl;
			return -1;
		} else if(!empty()) {
			if(p==head && p==tail) {
				head = NULL;
				tail = NULL;
			} else {
				if(p != head)
					p->prev->next = p->next;
				else {
					head = p->next;
					head->prev = NULL;
				}
				if(p != tail)
					p->next->prev = p->prev;
				else {
					tail = p->prev;
					tail->next = NULL;
				}
			}
			delete(p);
			return 0;
		}
		return -1;
	}
	lel* search(int val) {
		for(lel *k=head;k!=NULL;k=k->next) {
			if(k->value==val)
				return k;
		}
		return NULL;
	}
	bool empty() {
		if(head == NULL)
			return true;
		return false;
	}
	void mergesort() {
		msort(&head);
	}
	int length() {
		int i=0;
		lel* h = head;
		for(; h!=NULL; h=h->next) i++;
		return i;
	}
	void selectionsort() {
		lel* min;
		lel* sorted = new lel; sorted->prev = sorted->next = NULL; sorted->value=-1;
		lel* k = sorted;
		while( head!=NULL ) {
			min = head;
			for(lel* h = head; h!=NULL; h=h->next)
				if( h->value < min->value ) min = h;

			if( min->next != NULL )
				min->next->prev = min->prev;
			if( min->prev != NULL )
				min->prev->next = min->next;
			else
				head = head->next;
			k->next = min;
			min->prev = k;
			min->next = NULL;
			k = min;
		}
		head = sorted->next;
		sorted->next = NULL; delete(sorted); sorted=NULL;
	}
	void insert(lel** head, int val) {
		while( *head && (*head)->value<=val ) head = &(*head)->next;
		lel* el = new lel(val);
		el->next = *head;
		if(*head) el->prev = (*head)->prev;
		else el->prev = NULL; 
		*head = el;
	}
	void insertionsort() {
		lel* k = new lel(-1);
		lel* sorted = k;
		while( head ) {
			insert(&(sorted->next), head->value);
			head->prev = k;
			head = head->next;
		}
		head = sorted->next;
		delete(sorted);
	}
private:
	void printme(lel *h) {
		for(lel *k=h;k!=NULL;k=k->next) {
			std::cout << k->value << ' ';
		}
// 		std::cout << ' ' << std::endl;
	}
	int length(lel *h) {
		int i=0;
		for(; h!=NULL; h=h->next) i++;
		return i;
	}
	void merge(lel** p1, lel** p2) {
		if( *p2 == NULL ) return;
		lel* guard = new lel;
		guard->value = -1;
		guard->prev = NULL; guard->next = NULL;
		lel* tmp;
		lel* k = guard;
		lel** p;
		while( *p1 && *p2 ) {
			if( (*p1)->value < (*p2)->value ) p = p1;
			else p = p2;
			tmp = (*p)->next;
			(*p)->prev = k;
			k->next = *p;
			k = *p;
			if( tmp ) (*p)->next->prev = (*p)->next = NULL;
 			*p = tmp;
		}
		if( ! (*p1==NULL && *p2==NULL) )
			if( *p1==NULL ) k->next = *p2;
			else  k->next = *p1;
		*p1 = (guard->next);
		(*p1)->prev = NULL;
		guard->next = NULL;
		delete(guard);
		
	}
	void msort(lel** h) {
		int size = length(*h)/2;
		if( size == 0 ) return;
		lel* p2 = *h;
		lel* p1 = p2;
		for(int i = 0; i < size; ++i) p2 = p2->next;
		p2->prev->next = NULL;
		p2->prev = NULL;
		msort(&p1);
		msort(&p2);
		merge(&p1, &p2);
		*h = p1;
	}
};
#endif
