#ifndef _MMK_AVL_BST_TREE_CPP_
#define _MMK_AVL_BST_TREE_CPP_
#include "mmk_avl_bst_tree.h"
#include <iostream>
#include <cassert>

namespace mmk {

	template<typename Data> Node<Data>::Node(const Data& val, const int& vbf) :
		value(val), bf(vbf) {
		left = right = parent = NULL;
	}
	template<typename Data> Node<Data>::~Node() {
		// 	bf = 0;
		left = right = parent = NULL;
	}
	template<typename Data> void Node<Data>::print() {
		print(this, 0);
	}
	template<typename Data> void Node<Data>::print(const Node<Data>* root) {
		print(root, 0);
	}
	template<typename Data> void Node<Data>::print(const Node<Data>* root, const int& t) {
		if (root == NULL) return;
		Node<Data>::print(root->right, t + 1);
		for (int i = 0; i < t; ++i)
			std::cout << "    ";
		std::cout.width(2);
		std::cout.fill('.');
		std::cout << root->value;
		std::cout.setf(std::ios::showpos);
		std::cout << root->bf << std::endl;
		std::cout.unsetf(std::ios::showpos);
		Node<Data>::print(root->left, t + 1);
	}

	template<typename Data> Tree<Data>::Tree() :
		root(NULL) {
	}
	template<typename Data> Tree<Data>::Tree(const Data& value) :
		root(new Node<Data> (value)) {
	}
	template<typename Data> void Tree<Data>::print() {
		Node<Data>::print( root);
	}
	template<typename Data> Tree<Data>::~Tree() {
		std::cout << "~Tree()\n";
		cleanup( root);
	}
	template<typename Data> bool Tree<Data>::cleanup(Node<Data>* p) {
		if (!p) return false;
		cleanup(p->right);
		cleanup(p->left);
		// 	std::cout << "cleanup: " <<  p << std::endl;
		delete (p);
	}

	template<typename Data> BST<Data>::BST() {
		this->root = NULL;
	}
	template<typename Data> BST<Data>::BST(const Data& value) {
		this->root = (new Node<Data> (value));
	}
	template<typename Data> BST<Data>::~BST() {
		std::cout << "~BST()\n";
	}
	template<typename Data> void BST<Data>::insert(const Data& value) {
		Node < Data > *tmp = new Node<Data> (value);
		ins(&(this->root), tmp);
	}
	template<typename Data> void BST<Data>::plant(Data values[], const int& size) {
		for (int i = 0; i < size; ++i)
			insert(values[i]);
	}
	template<typename Data> Node<Data>* BST<Data>::search(const Data& value) {
		tmpe = value;
		return s(this->root);
	}
	template<typename Data> inline bool BST<Data>::del(const Data& value) {
		return delNode(search(value));
	}
	template<typename Data> inline bool BST<Data>::del(Node<Data>* n) {
		return delNode(n);
	}
	// private
	template<typename Data> bool BST<Data>::delNode(Node<Data>* n) {
		if (n == NULL) return false;
		Node < Data > *tmp = NULL;
		if (!n->right)
			tmp = n->left;
		else if (!n->left) tmp = n->right;
		if (tmp) tmp->parent = n->parent;
		if (!n->right || !n->left) {
			if (n->parent) {
				if (n->parent->right == n)
					n->parent->right = tmp;
				else n->parent->left = tmp;
			} else this->root = tmp;
			delete n;
			return true;
		}
		// zarówno następca jak i poprzednik istnieją
		tmp = successor(n);
		n->value = tmp->value;
		del( tmp);
	}
	// public
	template<typename Data> inline Node<Data>* BST<Data>::min() {
		return min(this->root);
	}
	template<typename Data> inline Node<Data>* BST<Data>::max() {
		return max(this->root);
	}
	template<typename Data> Node<Data>* BST<Data>::min(Node<Data>* n) {
		while (n->left)
			n = n->left;
		return n;
	}
	template<typename Data> Node<Data>* BST<Data>::max(Node<Data>* n) {
		while (n->right)
			n = n->right;
		return n;
	}
	template<typename Data> inline Node<Data>* BST<Data>::successor(const Data& value) {
		return successor(search(value));
	}
	template<typename Data> inline Node<Data>* BST<Data>::predecessor(const Data& value) {
		return predecessor(search(value));
	}
	template<typename Data> Node<Data>* BST<Data>::successor(Node<Data>* n) {
		Node < Data > *tmp = n;
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
	template<typename Data> Node<Data>* BST<Data>::predecessor(Node<Data>* n) {
		Node < Data > *tmp = n;
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
	template<typename Data> inline Node<Data>* BST<Data>::rotate_right(const Data& val) {
		return rotate_right(search(val));
	}
	template<typename Data> inline Node<Data>* BST<Data>::rotate_left(const Data& val) {
		return rotate_left(search(val));
	}
	template<typename Data> Node<Data>* BST<Data>::rotate_right(Node<Data>* n) {
		if (n->left == NULL) return false;

		n->bf += -(n->left->bf < 0 ? n->left->bf : 0) + 1;
		n->left->bf += (n->bf > 0 ? n->bf : 0) + 1;

		Node < Data > *tmp = n->left;
		tmp->parent = n->parent;

		n->left = tmp->right;
		if (tmp->right) tmp->right->parent = n;
		tmp->right = n;

		if (n->parent)
			if (n->parent->value < n->value)
				n->parent->right = tmp;
			else n->parent->left = tmp;
		else this->root = tmp;
		n->parent = tmp;
		return tmp;
	}
	template<typename Data> Node<Data>* BST<Data>::rotate_left(Node<Data>* n) {
		if (n->right == NULL) return false;

		n->bf += -(n->right->bf > 0 ? n->right->bf : 0) - 1;
		n->right->bf += +(n->bf < 0 ? n->bf : 0) - 1;

		Node < Data > *tmp = n->right;
		tmp->parent = n->parent;

		n->right = tmp->left;
		if (tmp->left) tmp->left->parent = n;
		tmp->left = n;

		if (n->parent)
			if (n->parent->value < n->value)
				n->parent->right = tmp;
			else n->parent->left = tmp;
		else this->root = tmp;
		n->parent = tmp;
		return tmp;
	}

	// 	private:
	template<typename Data> Node<Data>* BST<Data>::s(Node<Data>* root) {
		if (root == NULL)
			return NULL;
		else if (root->value == tmpe) {
			// // 				std::cout << "found:\t" << root->value << endl;
			return root;
		} else if (root->value < tmpe)
			return s(root->right);
		else return s(root->left);
	}
	// 	protected:
	template<typename Data> Node<Data>* BST<Data>::ins(Node<Data>** root, Node<Data>* n) {
		Node < Data > *parent = NULL;
		while (*root) {
			parent = *root;
			if ((*root)->value < n->value)
				root = &(*root)->right;
			else if ((*root)->value != n->value)
				root = &(*root)->left;
			else return (*root);
			// 				co gdy są równe?
		}
		n->parent = parent;
		*root = n;
		return n;
	}

	template<typename Data> AVL<Data>::AVL() {
		this->root = NULL;
	}
	template<typename Data> AVL<Data>::AVL(const Data& value) {
		this->root = new Node<Data> (value);
	}
	template<typename Data> void AVL<Data>::insert(const Data& value) {
		Node < Data > *tmp = new Node<Data> (value);
		ins(&(this->root), tmp);
		insRepair( tmp);
	}
	template<typename Data> void AVL<Data>::plant(Data values[], const int& size) {
		for (int i = 0; i < size; ++i)
			insert(values[i]);
	}
	template<typename Data> void AVL<Data>::balance(Node<Data>* p) {
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
	template<typename Data> void AVL<Data>::insRepair(Node<Data>* n) {
		for (;;) {
			if (n->bf < -1 || n->bf > 1) {
				balance(n);
				break;
			}
			if (n->parent != NULL) {
				if (n == n->parent->left)
					n->parent->bf--;
				else n->parent->bf++;
				n = n->parent;
				if (n->bf == 0) break;
			} else
			//root
			break;
		}
	}
	template<typename Data> void AVL<Data>::delRepair(Node<Data>* n) {
		if (!n || n->bf == -1 || n->bf == 1) return;
		for (;;) {
			if (n->bf < -1 || n->bf > 1) {
				balance(n);
				n = n->parent;
				if (n->bf != 0) break;
			}
			if (n->parent != NULL) {
				if (n == n->parent->right)
					n->parent->bf--;
				else n->parent->bf++;
				n = n->parent;
				if (n->bf == -1 || n->bf == 1) break;
			} else
			//root
			break;
		}
	}

	template<typename Data> inline bool AVL<Data>::del(const Data& value) {
		return del(search(value));
	}
	template<typename Data> inline bool AVL<Data>::del(Node<Data>* node) {
		if (!node) return false;
		Node < Data > *p = delNode(node);
		// // 	if( !p ) return true;
		delRepair( p);
	}
	template<typename Data> Node<Data>* AVL<Data>::delNode(Node<Data>* n) {
		if (n == NULL) return NULL;
		Node < Data > *result = n->parent;
		Node < Data > *tmp = NULL;
		if (!n->right)
			tmp = n->left;
		else if (!n->left) tmp = n->right;

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
			} else this->root = tmp;
			delete n;
			return result;
		} else {
			// zarówno następca jak i poprzednik istnieją
			tmp = successor(n);
			n->value = tmp->value;
			return delNode(tmp);
		}
	}
	template<typename Data> Splay<Data>::Splay() {
		this->root = NULL;
	}
	template<typename Data> Splay<Data>::Splay(const Data& data) {
		this->root = new Node<Data> (data);
	}
	template<typename Data> inline bool Splay<Data>::search(const Data& data) {
		splay(data);
		if (this->root->value == data) return true;
		return false;
	}
	template<typename Data> inline void Splay<Data>::splay(const Data& data) {
		// 	std::cout<<"splay data: " << data << " \n";
		Node < Data > *s = find(this->root, data);
		// 	std::cout << s << "\n";
		splay( s);
		// 	std::cout<<"splay root: " << this->root << " \n";
	}
	template<typename Data> inline void Splay<Data>::splay(Node<Data>* node) {
		Node<Data> *p, *g; // p-parent, g-grandparent
		if (node == this->root)
			;
		else if (node->parent == this->root) {
			if (node->parent->right == node)
				rotate_left(this->root);
			else rotate_right(this->root);
		} else {
			p = node->parent;
			g = p->parent;
			if (node == p->left && p == g->left) {
				rotate_right(g);
				rotate_right(p);
			} else if (node == p->right && p == g->right) {
				rotate_left(g);
				rotate_left(p);
			} else if (node == p->left && p == g->right) {
				rotate_right(p);
				rotate_left(g);
			} else if (node == p->right && p == g->left) {
				rotate_left(p);
				rotate_right(g);
			}
			splay(node);
		}
	}
	template<typename Data> Node<Data>* Splay<Data>::find(Node<Data>* root, const Data& data) {
		if (!root)
			return NULL;
		else if (root->value == data) {
			return root;
		} else if (root->value < data) {
			if (!root->right) return root;
			return find(root->right, data);
		} else {
			if (!root->left) return root;
			return find(root->left, data);
		}
	}
	template<typename Data> bool Splay<Data>::insert(const Data& data) {
		Node<Data>* node = new Node<Data> (data), *p;
		p = ins(&(this->root), node); // ins zwraca node, jeśli udało się wstawić albo element który już był w tablicy
		// 	std::cout << "insert node: " << node << "\n";
		splay(p);
		if (p == node) return true;
		delete (node); // p!=node
		return false;
	}
	template<typename Data> bool Splay<Data>::remove(const Data& data) {
		Node < Data > *f = find(this->root, data);
		std::cout << f << std::endl;
		if (!f) return false;
		assert(f != NULL);
		if (f->value == data) // czy znaleźliśmy element?
		return remove(f);
		splay( f);
		return false;
	}
	template<typename Data> bool Splay<Data>::remove(Node<Data>* n) { // n musi należeć do drzewa
		if (!n) return false;
		Node < Data > *tmp = n->parent; // gdy n==root to tmp==NULL
		delNode(n); // delNode ustawi this->root na NULL gdy n==root
		if (tmp) splay( tmp); // jeśli n==root, tmp==NULL, a więc nie robimy splaya
		return true;
	}
	template<typename Data> void Splay<Data>::plant(Data values[], const int& size) {
		for (int i = 0; i < size; ++i)
			insert(values[i]);
	}
	template<typename Data> std::ostream & operator<<(std::ostream &out, Node<Data>* l) {
		if (l)
			out << l->value;
		else out << "NULL";
		return out;
	}
	template<typename Data> std::ostream & operator<<(std::ostream &out, Tree<Data>* t) {
		if (t)
			t->print();
		else out << "NULL";
		return out;
	}
}
#endif
