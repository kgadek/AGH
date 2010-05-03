#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node {
    int value;
    node *next;
    node *prev;
};

node *push(node * head, int val)
{				/*ważne! head->prev */
    /*zawsze wstawiamy na początek */
    node *tmp = (node *) malloc(sizeof(node));
    if (head)
	head->prev = tmp;
    tmp->value = val;
    tmp->next = head;
    tmp->prev = NULL;
    return tmp;
}


node *pop(node * head)
{
    node *result;
    if (!head)
	return NULL;			/*pusta kolejka */
    else if (head->next == NULL) {	/* kolejka ma tylko jeden element */
	result = head;
	head = NULL;
	return result;
	/* powinno być zwolnienie pamięci */
    } else {
	while (head && head->next)
	    head = head->next;
	/*jesteśmy na ostatnim elemencie */

	head->prev->next = NULL;
	return head;
    }


}




int main()
{
    node *f = NULL;
    f = push(f, 25);		/*ważne! podstawić wartość zwracaną z funkcji */
    f = push(f, 12);
    f = push(f, 30);
    printf("%d", (pop(f))->value);
    printf("%d", (pop(f))->value);
    printf("%d", (pop(f))->value);

    return 0;
}
