#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
    int val;
    node *next;
};

void insert(node ** head, int value)
{				/* wstawianie na pierwszy element listy */
    node *p = (node *) malloc(sizeof(node));
    p->next = *head;
    p->val = value;
    *head = p;
}

void insert_sorted(node ** head, int value)
{				/* wstawiwanie do listy posortowanej */
    node *p;
    while (*head && value > (*head)->val)
	head = &((*head)->next);
    p = (node *) malloc(sizeof(node));
    p->val = value;
    p->next = *head;
    *head = p;
}

void delete(node ** head, int value)
{
    node *tmp = NULL;
    while (*head && (*head)->val != value)
	head = &((*head)->next);
    if (*head) {
	tmp = (*head);
	*head = (*head)->next;
    }
    if(tmp)
	free(tmp);
}

int main()
{
    node *f = NULL;

    insert_sorted(&f, 25);
    printf("%d", f->val);
    insert_sorted(&f, 35);
    printf("%d", f->val);
    insert_sorted(&f, 5);
    printf("%d", f->val);
    delete(&f, 25);
    return 0;
}
