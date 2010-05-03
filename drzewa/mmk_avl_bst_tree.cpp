#ifndef _MMK_AVL_BST_TREE_CPP_
#define _MMK_AVL_BST_TREE_CPP_
#include "mmk_avl_bst_tree.h"
#include <iostream>

template<typename Data> Node<Data>::Node() {
	bf = 0;
	left = right = parent = NULL;
}
template<typename Data> Node<Data>::Node(Data val) {
	bf = 0;
	value = val;
	left = right = parent = NULL;
}
template<typename Data> void Node<Data>::print() {
	print(this, 0);
}
template<typename Data> void Node<Data>::print(Node<Data>* root) {
	print(root, 0);
}
template<typename Data> void Node<Data>::print(Node<Data>* root, int t) {
	if (root == NULL)
		return;
	Node<Data>::print(root->right, t + 1);
	for (int i = 0; i < t; ++i)
		std::cout << "    ";
	std::cout.width(2);std::cout.fill('.');std::cout << root->value;std::cout.setf(std::ios::showpos);std::cout << root->bf << std::endl;std::cout.unsetf(std::ios::showpos);
	Node<Data>::print(root->left, t + 1);
}


template<typename Data> Tree<Data>::Tree() {
	root = NULL;
}
template<typename Data> Tree<Data>::Tree(Data value) {
	root = new Node<Data> (value);
}
template<typename Data> void Tree<Data>::print() {
	Node<Data>::print( root);
}


template<typename Data> bst<Data>::bst() {
	this->root = NULL;
}
template<typename Data> bst<Data>::bst(Data value) {
	this->root = new Node<Data> (value);
}
template<typename Data> void bst<Data>::insert(Data value) {
	if (this->root == NULL) {
		this->root = new Node<Data> (value);
		return;
	}
	Node <Data> *tmp = new Node<Data> (value);
	ins(&(this->root), tmp);
}
template<typename Data> void bst<Data>::plant(Data values[], int size) {
	for (int i = 0; i < size; ++i)
		insert(values[i]);
}
template<typename Data> Node<Data>* bst<Data>::search(Data value) {
	tmpe = value;
	s(this->root);
}
template<typename Data> bool bst<Data>::del(Data value) {
	return del(search(value));
}
template<typename Data> bool bst<Data>::del(Node<Data>* n) {
	if (n == NULL) return false;
	Node<Data> *tmp = NULL;
	if (!n->right)
		tmp = n->left;
	else if (!n->left)
		tmp = n->right;
	if (tmp)
		tmp->parent = n->parent;
	if (!n->right || !n->left) {
		if (n->parent) {
			if (n->parent->right == n)
				n->parent->right = tmp;
			else
				n->parent->left = tmp;
		} else
			this->root = tmp;
		delete n;
		return true;
	}
	// zarówno następca jak i poprzednik istnieją
	tmp = successor(n);
	n->value = tmp->value;
	del( tmp );
}
template<typename Data> Node<Data>* bst<Data>::min() {
	return min(this->root);
}
template<typename Data> Node<Data>* bst<Data>::max() {
	return max(this->root);
}
template<typename Data> Node<Data>* bst<Data>::min(Node<Data>* n) {
	while (n->left) n = n->left;
	return n;
}
template<typename Data> Node<Data>* bst<Data>::max(Node<Data>* n) {
	while (n->right) n = n->right;
	return n;
}
template<typename Data> Node<Data>* bst<Data>::successor(Data value) {
	return successor(search(value));
}
template<typename Data> Node<Data>* bst<Data>::predecessor(Data value) {
	return predecessor(search(value));
}
template<typename Data> Node<Data>* bst<Data>::successor(Node<Data>* n) {
	Node<Data> *tmp = n;
	if (n == NULL) return n;
	if (n->right) {
		n = n->right;
		while (n->left)
			n = n->left;
	} else {
		while (n->parent) {
			if (n->parent->right == n)
				n = n->parent;
			else {
				n = n->parent;
				break;
			}
		}
	}
	if (tmp == max(n)) return NULL; // ?return tmp?
	return n;
}
template<typename Data> Node<Data>* bst<Data>::predecessor(Node<Data>* n) {
	Node<Data> *tmp = n;
	if (n == NULL) return n;
	if (n->left) {
		n = n->left;
		while (n->right)
			n = n->right;
	} else {
		while (n->parent) {
			if (n->parent->left == n)
				n = n->parent;
			else {
				n = n->parent;
				break;
			}
		}
	}
	if (tmp == min(n)) return NULL;
	return n;
}
template<typename Data> Node<Data>* bst<Data>::rotate_right(Data val) {
	return rotate_right(search(val));
}
template<typename Data> Node<Data>* bst<Data>::rotate_left(Data val) {
	return rotate_left(search(val));
}
template<typename Data> Node<Data>* bst<Data>::rotate_right(Node<Data>* n) {
	if (n->left == NULL)
		return false;

	n->bf = n->bf + (-n->left->bf > 0 ? -n->left->bf : 0) + 1;
	n->left->bf = n->left->bf + (n->bf > 0 ? n->bf : 0) + 1;

	Node<Data> *tmp = n->left;
	tmp->parent = n->parent;

	n->left = tmp->right;
	if (tmp->right) tmp->right->parent = n;
	tmp->right = n;

	if (n->parent)
		if (n->parent->value < n->value)
			n->parent->right = tmp;
		else
			n->parent->left = tmp;
	else
		this->root = tmp;
	n->parent = tmp;
	return tmp;
}
template<typename Data> Node<Data>* bst<Data>::rotate_left(Node<Data>* n) {
	if (n->right == NULL)
		return false;

	n->bf = n->bf - (n->right->bf > 0 ? n->right->bf : 0) - 1;
	n->right->bf = n->right->bf - (-n->bf > 0 ? -n->bf : 0) - 1;

	Node<Data> *tmp = n->right;
	tmp->parent = n->parent;

	n->right = tmp->left;
	if (tmp->left) tmp->left->parent = n;
	tmp->left = n;

	if (n->parent)
		if (n->parent->value < n->value)
			n->parent->right = tmp;
		else
			n->parent->left = tmp;
	else
		this->root = tmp;
	n->parent = tmp;
	return tmp;
}

// 	private:
template<typename Data> Node<Data>* bst<Data>::s(Node<Data>* root) {
	if (root == NULL)
		return NULL;
	else if (root->value == tmpe) {
		// // 				std::cout << "found:\t" << root->value << endl;
		return root;
	} else if (root->value < tmpe)
		return s(root->right);
	else
		return s(root->left);
}
// 	protected:
template<typename Data> void bst<Data>::ins(Node<Data>** root, Node<Data>* n) {
	Node<Data> *parent = NULL;
	while (*root) {
		parent = *root;
		if ((*root)->value < n->value)
			root = &(*root)->right;
		else if ((*root)->value != n->value)
			root = &(*root)->left;
		// 				co gdy są równe?
	}
	n->parent = parent;
	*root = n;
}


template<typename Data> avl<Data>::avl() {
	this->root = NULL;
}
template<typename Data> avl<Data>::avl(Data value) {
	this->root = new Node<Data> (value);
}
template<typename Data> void avl<Data>::plant(Data values[], int size) {
	// 	std::cout << "avl::plant\n";
	for (int i = 0; i < size; ++i)
		insert(values[i]);
}
template<typename Data> void avl<Data>::insert(Data value) {
	// 	std::cout << "avl::insert "<<value<<"\n";
	if (this->root == NULL) {
		this->root = new Node<Data> (value);
		return;
	}
	Node<Data> *tmp = new Node<Data> (value);
	ins(&(this->root), tmp);
	insRepair( tmp);
}
template<typename Data> void avl<Data>::balance(Node<Data>* p) {
	if (p->bf == 2) {
		if (p->right->bf < 0) {
			rotate_right(p->right);
		}
		rotate_left(p);
	} else if (p->bf == -2) {
		if (p->left->bf > 0) {
			rotate_left(p->left);
		}
		rotate_right(p);
	}
}
template<typename Data> void avl<Data>::insRepair(Node<Data>* n) {
	for (;;) {
		if (n->bf < -1 || n->bf > 1) {
			balance(n);
			break;
		}
		if (n->parent != NULL) {
			if (n == n->parent->left)
				n->parent->bf--;
			else
				n->parent->bf++;
			n = n->parent;
			if (n->bf == 0)
				break;
		} else
			//root
			break;
	}
}
// template<typename Data> Node<Data>* avl<Data>::insRepair(Node<Data>* p, Node<Data>* son) {
// 	if (!p)
// 		return NULL;
// 
// 	if (p->right == son)
// 		p->bf += 1;
// 	else if (p->left == son)
// 		p->bf -= 1;
// 
// 	if (p->bf == 2) {
// 		if (p->right->bf < 0) {
// 			rotate_right(p->right);
// 		}
// 		rotate_left(p);
// 		return p;
// 	} else if (p->bf == -2) {
// 		if (p->left->bf > 0) {
// 			rotate_left(p->left);
// 		}
// 		rotate_right(p);
// 		return p;
// 	}
// 	return insRepair(p->parent, p);
// }
template<typename Data> void avl<Data>::delRepair(Node<Data>* n) {
	for (;;) {
		if (n->bf < -1 || n->bf > 1) {
			balance(n);
			n = n->parent;
			if (n->bf != 0)
				break;
		}
		if (n->parent != NULL) {
			if (n == n->parent->right)
				n->parent->bf--;
			else
				n->parent->bf++;
			n = n->parent;
			if (n->bf == -1 || n->bf == 1)
				break;
		} else
			//root
			break;
	}
}

template<typename Data> bool avl<Data>::del(Data value) {
	Node<Data> *node = search(value);
	if (!node)
		return false;
	Node<Data> *p = delNode(node);
	// 	if( !p ) return true;
	if (p != NULL && p->bf != -1 && p->bf != 1)
		delRepair( p);
}
template<typename Data> bool avl<Data>::del(Node<Data>* node) {
	if (!node)
		return false;
	Node<Data> *p = delNode(node);
	// 	if( !p ) return true;
	if (p != NULL && p->bf != -1 && p->bf != 1)
		delRepair( p);
}
template<typename Data> Node<Data>* avl<Data>::delNode(Node<Data>* n) {
	if (n == NULL) return NULL;
	Node<Data> *result = n->parent;
	Node<Data> *tmp = NULL;
	if (!n->right)
		tmp = n->left;
	else if (!n->left)
		tmp = n->right;

	if (tmp) tmp->parent = n->parent;
	if (!n->right || !n->left) {
		if (n->parent) {
			if (n->parent->right == n) {
				n->parent->right = tmp;
				n->parent->bf--;
			} else {
				n->parent->left = tmp;
				n->parent->bf++;
			}
		} else
			this->root = tmp;
		delete n;
		return result;
	} else {
		// zarówno następca jak i poprzednik istnieją
		tmp = successor(n);
		n->value = tmp->value;
		return delNode( tmp);
	}
}
template<typename Data> std::ostream & operator<<(std::ostream &out,
		Node<Data>* l) {
	if (l)
		out << l->value;
	else
		out << "NULL";
	return out;
}
template<typename Data> std::ostream & operator<<(std::ostream &out,
		Tree<Data>* t) {
	if (t)
		t->print();
	else
		out << "NULL";
	return out;
}
#endif
