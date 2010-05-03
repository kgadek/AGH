/* Autor: mmk */

#ifndef _TREE_H_
#define _TREE_H_
#include <iostream>

template<typename Data>
struct Node {
	short int bf; //balance factor
	Data value;
	Node<Data> *left, *right, *parent;
	Node();
	Node(Data val);
	void print();
	static void print(Node<Data>* root);
private:
	static void print(Node<Data>* root, int t);
};

template<typename Data>
class Tree {
public:
	Node<Data> *root;
	Tree();
	Tree(Data value);
	void print();
	// 	private:

};
template<typename Data>
class bst: public Tree<Data> {
public:
	bst();
	bst(Data value);
	void insert(Data value);
	void plant(Data values[], int size);
	Node<Data>* search(Data value);
	bool del(Data value);
	bool del(Node<Data>* n);
	Node<Data>* min();
	Node<Data>* max();
	static Node<Data>* min(Node<Data>* n);
	static Node<Data>* max(Node<Data>* n);
	Node<Data>* successor(Data value);
	static Node<Data>* successor(Node<Data>* n);
	Node<Data>* predecessor(Data value);
	static Node<Data>* predecessor(Node<Data>* n);
	Node<Data>* rotate_right(Data val);
	Node<Data>* rotate_left(Data val);
	Node<Data>* rotate_right(Node<Data>* n);
	Node<Data>* rotate_left(Node<Data>* n);
private:
	Data tmpe;
	Node<Data>* s(Node<Data>* root);
protected:
	void ins(Node<Data>** root, Node<Data>* n);
};
template<typename Data>
class avl: public bst<Data> {
public:
	avl();
	avl(Data value);
	void plant(Data values[], int size);
	void insert(Data value);
	bool del(Data value);
	bool del(Node<Data>* n);
private:
	Node<Data>* delNode(Node<Data>* n);
	// 	Node<Data>* insRepair(Node<Data>* p, Node<Data>* son);
	void insRepair(Node<Data>* n);
	void delRepair(Node<Data>* p);
	void balance(Node<Data>* p);
};

template<typename Data> std::ostream & operator<<(std::ostream &out,
		Node<Data>* l);
template<typename Data> std::ostream & operator<<(std::ostream &out,
		Tree<Data>* t);
#endif
