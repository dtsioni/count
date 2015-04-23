#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	size_t data;
	struct node *next;
}node;
struct node *newNode();
struct node **insertTable(struct node *head[], size_t val);
struct node *insertList(struct node *head, size_t val);
void countAddresses(struct node *head[]);
