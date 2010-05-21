/* Autor: mmk */

#ifndef _MMK_AVL_BST_TREE_H_
#define _MMK_AVL_BST_TREE_H_
#include <iostream>

namespace mmk {

    template < typename Data > struct Node {
      public:
	Data value;
	short int bf;		//balance factor

	 Node < Data > *left, *right, *parent;
	 Node(const Data & val = NULL, const int & = 0);
	~Node();
	 Node<Data>& operator=(const Node&);		/* -Weffc++ warning-killer */
	 Node(const Node&);
	void print();
	static void print(const Node < Data > *root);
      private:
	static void print(const Node < Data > *root, const int &t);
    };

     template < typename Data > class Tree {
      protected:
	Node < Data > *root;
      public:
	Tree();
	Tree(const Data & value);
	virtual ~Tree();
	 Node < Data > *getRoot() {
	    return root;
	} void print();
	 Tree(const Tree&);		/* -Weffc++ warning-killer */
	 Tree<Data>& operator=(const Tree&);
      protected:
	bool cleanup(Node < Data > *p);
    };
  template < typename Data > class BST:public Tree < Data > {
      public:
	BST();
	virtual ~BST();
	BST(const Data & value);
	void insert(const Data & value);
	void plant(Data values[], const int &size);
	Node < Data > *search(const Data & value);
	inline bool del(const Data & value);
	inline bool del(Node < Data > *n);
	inline Node < Data > *min();
	inline Node < Data > *max();
	static Node < Data > *min(Node < Data > *n);
	static Node < Data > *max(Node < Data > *n);
	inline Node < Data > *successor(const Data & value);
	inline Node < Data > *predecessor(const Data & value);
	static Node < Data > *successor(Node < Data > *n);
	static Node < Data > *predecessor(Node < Data > *n);
	inline Node < Data > *rotate_right(const Data & val);
	inline Node < Data > *rotate_left(const Data & val);
	Node < Data > *rotate_right(Node < Data > *n);
	Node < Data > *rotate_left(Node < Data > *n);
      private:
	Data tmpe;
	Node < Data > *s(Node < Data > *root);
      protected:
	bool delNode(Node < Data > *n);
	Node < Data > *ins(Node < Data > **root, Node < Data > *n);
    };
  template < typename Data > class AVL:public BST < Data > {
      public:
	AVL();
	AVL(const Data & value);
	void plant(Data values[], const int &size);
	void insert(const Data & value);
	inline bool del(const Data & value);
	inline bool del(Node < Data > *n);
      private:
	Node < Data > *delNode(Node < Data > *n);
	//      Node<Data>* insRepair(Node<Data>* p, Node<Data>* son);
	void insRepair(Node < Data > *n);
	void delRepair(Node < Data > *p);
	void balance(Node < Data > *p);
    };
  template < typename Data > class Splay:public BST < Data > {
      public:
	Splay();
	Splay(const Data & value);

	bool insert(const Data & value);
	void plant(Data values[], const int &size);
	inline bool search(const Data & data);
	inline void splay(const Data & data);

	inline bool remove(const Data & value);
	inline bool remove(Node < Data > *n);
      private:
	Node < Data > *find(Node < Data > *root, const Data & data);
	void splay(Node < Data > *p);

    };

    template < typename Data >
	std::ostream & operator<<(std::ostream & out, Node < Data > *l);
    template < typename Data >
	std::ostream & operator<<(std::ostream & out, Tree < Data > *t);
}
#endif
