#include "mmk_list.h"
#include <iostream>
namespace mmk {

	template<class D>
	class Stack {
		mmk::List<D>* list;
	public:
		Stack() :
			list(new List<D> ) {
		}
		~Stack() {
			delete (list);
		}
		void push(const D& data) {
			list->insert(data);
		}
		D pop() {
			if (!list->head) throw "Stack is empty!";
			const D tmp = list->head->data;
			list->head = list->head->next;
			return tmp;
		}
		bool empty() {
			return (list->head ? true : false);
		}
	};

}