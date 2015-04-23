#include <stdio.h>
#include <stdlib.h>
#include "count.h"
struct node *newNode(){
	node *ptr;
	ptr = (node *) malloc(sizeof(node));
	ptr->data = -1;
	ptr->next = NULL;
	return ptr;
}
struct node **insertTable(struct node *head[], size_t val){
	/* find the proper index for our size_t val, and then send it to be placed in the chain */
	int index;
	node *listHead;
	index = val % 1000;
	listHead = head[index];
	head[index] = insertList(listHead, val);
	return head;

}
struct node * insertList(struct node *head, size_t val){
	/* insert size_t val into our linked list, unsorted */
	node *insert = newNode();
	node *ptr;
	insert->data = val;
	if( head == NULL )
	{ /* empty list  */
		head = insert;
	}else{/*need to search list for our element. if we don't find it, add to the end */
		ptr = head;
		if(ptr->data == val)
		{/* if first item in the list is the same value */
			free(insert);
			return head;
		}
		/* otherwise search rest of list */
		while(ptr->next != NULL)
		{
			if(ptr->data == val)
			{
				free(insert);
				return head;
			}
			ptr = ptr->next;
		}
		/* check if the last item in the list is val */
		if(ptr->data == val)
		{
			free(insert);
			return head;
		}
		/* we never found our item in the list */
		/* ptr is now at last item of list */
		ptr->next = insert;
	}
	return head;
}
void countAddresses(struct node *head[]){
	int counter;
	int uniqueAddresses;
	node *ptr;
	uniqueAddresses = 0;
	for(counter = 0; counter < 1000; counter++)
	{
		/* go down list searching for non null lists */
		ptr = head[counter];
		/* count length of list */
		while( ptr != NULL )
		{
			uniqueAddresses++;
			ptr = ptr->next;
		}
	}
	printf("%i\n", uniqueAddresses);
	
}
int main(int argc, char** argv) {
	char *fileName;
	FILE *filePointer;
	size_t value;/*sets char array to 16*/
	node *table[1000];
	int counter;
	for(counter = 0; counter < 1000; counter++)
	{
		table[counter] = NULL;
	}	
	if(argc != 2)
	{
		/* incorrect number of arguments */
		printf("error\n");
		exit(0);
	}
	fileName = argv[1];
	filePointer = fopen(fileName, "r");
	if(filePointer == NULL)
	{
		/* file doesn't exist */
		printf("error\n");
		exit(0);
	}
	while( fscanf(filePointer, "%lx", &value) != EOF )
	{
		/* add each line to our hash table */
		insertTable(table, value);
		
	}
	countAddresses(table);
	fclose(filePointer);
	return 0;
}
