#include <stdio.h>
#include <stdlib.h>

struct trienode {
    char font;
    struct trienode *other;
    struct trienode *next;
};

void init(struct trienode **head)
{
    *head = NULL;
}

struct trienode *insert(const char *slowo, struct trienode *head) /* 'const char' by mozna bylo
							 bezposrednio podac string */
{
    if (*slowo) {
	if (head) {
	    struct trienode *p = head;
	    if (p->font <= *slowo) {
		while (p->other && (p->other->font <= *slowo))
		    p = p->other;
		if (p->font == *slowo) {
		    slowo++;
		    p->next = insert(slowo, p->next);
		} else {
		    struct trienode *t = p->other;
		    p->other =
			(struct trienode *)
			malloc(sizeof(struct trienode));
		    p->other->other = t;
		    p->other->font = *slowo;
		    p->other->next = NULL;
		    slowo++;
		    p->other->next = insert(slowo, p->other->next);
		}
	    } else {
		head = (struct trienode *) malloc(sizeof(struct trienode));
		head->other = p;
		head->font = *slowo;
		head->next = NULL;
		slowo++;
		head->next = insert(slowo, head->next);
	    }
	} else {
	    head = (struct trienode *) malloc(sizeof(struct trienode));
	    head->other = NULL;
	    head->font = *slowo;
	    head->next = NULL;
	    slowo++;
	    head->next = insert(slowo, head->next);
	}
    }
    return head;
}

void wypisz(struct trienode *head, int deep)
{
    int i;
    while (head) {
	for (i = deep; i > 0; i--)
	    printf(" ");
	printf("%c\n", head->font);
	deep++;
	wypisz(head->next, deep);
	deep--;
	head = head->other;
    }
}

struct trienode *delete(const char *slowo, struct trienode *head) /* 'const char' by mozna bylo
							 bezposrednio podac string */
{
    if (*slowo) {
	struct trienode *p = head;
	if (p->font == *slowo) {
	    p->next = delete(++slowo, p->next);
	    if (!p->next) {
		head = p->other;
		free(p);
	    }
	} else {
	    while (p->other->font != *slowo)
		p = p->other;
	    p->other->next = delete(++slowo, p->other->next);
	    if (!p->other->next) {
		struct trienode *t = p->other;
		p->other = p->other->other;
		free(t);
	    }
	}
    }
    return head;
}

int isnotin(const char *slowo, struct trienode *head) /* 'const char' by mozna bylo
							 bezposrednio podac string */
{
    int czy = 0;
    if (*slowo) {
	while (head && (head->font != *slowo))
	    head = head->other;
	if (!head)
	    czy++;
	else
	    czy += isnotin(++slowo, head->next);
    }
    return czy;
}


int main(void)
{
    struct trienode *drzewo;
    int czy;
    init(&drzewo);
    drzewo = insert("radek", drzewo);
    drzewo = insert("rad", drzewo);
    drzewo = insert("radzio", drzewo);
    drzewo = insert("igor", drzewo);
    drzewo = insert("iga", drzewo);
    drzewo = insert("ignorancja", drzewo);
    drzewo = insert("iglica", drzewo);
    drzewo = insert("izydor", drzewo);
    drzewo = insert("absolutorium", drzewo);
    drzewo = insert("deizm", drzewo);
    drzewo = insert("radek", drzewo);
    drzewo = delete("radek", drzewo);
    wypisz(drzewo, 0);
    czy = isnotin("rad", drzewo);
    printf("%i\n", czy);
    czy = isnotin("radzio", drzewo);
    printf("%i\n", czy);
    czy = isnotin("raca", drzewo);
    printf("%i\n", czy);
    return 0;
}
