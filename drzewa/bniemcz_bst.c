#include <stdio.h>
#include <stdlib.h>
typedef struct Node *pNode;
struct Node {
    int data;
    pNode parent;
    pNode left;
    pNode right;
};

pNode makeNode(int val)
{
    pNode node = (pNode) malloc(sizeof(pNode));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

pNode insert(pNode root, pNode node)
{
    pNode parent = NULL, x = root;
    while (x != NULL) {
	parent = x;		/*zapamiętanie parenta */
	if (node->data < x->data)
	    x = x->left;
	else
	    x = x->right;
    }
    node->parent = parent;
    if (!parent)		/* puste drzewo */
	root = node;
    else if (node->data < parent->data)
	parent->left = node;
    else
	parent->right = node;
    return root;
}

void insertPtrToPtr(pNode * node, pNode el)
{				/*el - element do wstawienia */
    pNode tmp = NULL;
    while (*node) {
	tmp = *node;
	if (el->data < (*node)->data)
	    node = &((*node)->left);
	else
	    node = &((*node)->right);
    }
    el->parent = tmp;
    *node = el;

    /* el->parent = *parent - żeby dodać odwołanie do parenta, trzebaby
     * ciągnąć za sobą wskaźnik na poprzedni element
     */
}


int minimum(pNode node)
{
    if (!node)
	return 0;
    else
	while (node->left)
	    node = node->left;
    return node->data;
}

int maximum(pNode node)
{
    if (!node)
	return 0;
    else
	while (node->right)
	    node = node->right;
    return node->data;
}

pNode successor(pNode node)
{
    if (!node)
	return 0 /*error */ ;
    if (node->right) {		/*jeśli node ma prawego syna to wybieramy najmniejszy z wiekszych */
	node = node->right;
	while (node->left)
	    node = node->left;
	return node;
    } else			/*jeśli nie ma syna, to szukamy parenta który jako lewego syna ma
				  naszego node'a */
	while (node->parent && node->parent->right == node)
	    node = node->parent;
    return node->parent;
}

pNode predecessor(pNode node)
{
    if (!node)
	return 0 /*error */ ;
    if (node->left) {		/*jeśli node ma lewego syna to wybieramy największy z mniejszych */
	node = node->left;
	while (node->right)
	    node = node->right;
	return node;
    } else			/*jeśli nie ma syna, to szukamy parenta który jako prawego syna ma
				  naszego node'a */
	while (node->parent && node->parent->left == node)
	    node = node->parent;
    return node->parent;
}

pNode delete(pNode root, pNode node)
{
    if (node->right) {
	pNode n = successor(node);
	/*zamiana zawartości noda z następnikiem
	 * tak żeby node nie miał już prawego syna
	 */
	int data = n->data;
	n->data = node->data;
	node->data = data;
	root = delete(root, n);
    } else {			/* nie mamy już prawego syna */

	if (node->parent)
	    if (node->parent->left == node)
		node->parent->left = node->left;
	    else
		node->parent->right = node->left;
	else
	    root = node->left;

	if (node->left)
	    node->left->parent = node->parent;
	/*delete node; */
    }
    return root;
}

void rotation_left(pNode * root, pNode node)
{
    pNode tmp = node->right;
    node->right = tmp->left;
    if (tmp->left)
	tmp->left->parent = node;
    tmp->parent = node->parent;

    if (node->parent == NULL)
	*root = tmp;
    else if (node->parent->right == node)
	node->parent->right = tmp;
    else
	node->parent->left = tmp;
    tmp->left = node;
    node->parent = tmp;
}


int main()
{

    pNode node, root = NULL;

    /*
     * testowanie inserta 
     *
     node = makeNode(10);
     root=insert(root, node);
     node = makeNode(20);
     root=insert(root, node);
     node = makeNode(0);
     root=insert(root, node);
     node = makeNode(3);
     root=insert(root, node);
     */

    node = makeNode(5);
    insertPtrToPtr(&root, makeNode(3));
    insertPtrToPtr(&root, node);
    insertPtrToPtr(&root, makeNode(15));
    insertPtrToPtr(&root, makeNode(4));

    rotation_left(&root, node);

    pNode x = makeNode(6);
    insertPtrToPtr(&root, x);
    pNode y = predecessor(x);


    printf("%d ", y->data);

    return 0;
}
