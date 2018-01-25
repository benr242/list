#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Node.h"

/*

	list.c
		Contains functions to manipulate a doubly-linked list.

*/


/* private methods */

static NodePtr reverse(NodePtr L);
static void print(ListPtr, NodePtr);

ListPtr createList(int *(*getKey)(void *),
					char *(*toString)(void *),
					void (*freeObject)(void *),
					Boolean (*compare)(void *, void *))
{
	ListPtr list;
	list = (ListPtr) malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;

	list->getKey = getKey;
	list->toString = toString;
	list->freeObject = freeObject;
	list->compare = compare;

	return list;
}

void freeList(ListPtr L)
{
	NodePtr tmpNode = L->head;
	NodePtr next;

	//call freeNode for each Node in the List
	while (tmpNode)
	{
		next = tmpNode->next;
		freeNode(tmpNode, L->freeObject);
		tmpNode = next;
	}
	free(L);
}

int getListSize(ListPtr L)
{
	return L->size;
}

Boolean isEmpty(ListPtr L)
{
	if (L->size == 0)
		return TRUE;
	else
		return FALSE;
}

void addAtFront(ListPtr list, NodePtr node)
{
	//just in case
	if (list == NULL) return;
	if (node == NULL) return;

	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}

void addAtRear(ListPtr list, NodePtr node)
{
	if (list == NULL) return;
	if (node == NULL) return;

	list->size++;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
}

void removeFront(ListPtr list)
{
	if (list == NULL) return;
	if (list->size == 0) return;

	//NodePtr toRemove = list->head;
	list->size--;

	if (list->size == 0)
	{
		list->head = NULL;
		list->tail = NULL;
	} else if (list->size == 1) {
		list->head = list->head->next;
		list->tail = list->head;
		list->head->prev = NULL;
	} else {
		list->head = list->head->next;
		list->head->prev = NULL;
	}

	//return toRemove->obj->data;
}

void removeRear(ListPtr list)
{
	if (list == NULL) return;
	if (list->size == 0) return;
	if (list->tail == NULL) return;

	//NodePtr toRemove = list->tail;
	list->size--;

	if (list->size == 0)
	{
		list->head = NULL;
		list->tail = NULL;
	} else if (list->size == 1) {
		list->tail = list->tail->prev;
		list->head = list->tail;
		list->tail->next = NULL;
	} else {
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}

	//return toRemove->obj->data;
}

//do not free the data. that'll be done elsewhere
void removeNode(ListPtr list, NodePtr node)
{
	if (list == NULL) return;
	if (node == NULL) return;

	//tmpNode will hold the NodePtr if it is found
	//i need that to remove the node //this is a test
	//NodePtr emptyNode;
	//void *tmpData = listSearch(list, &emptyNode, obj);

	if (node)
	{
		//the easy cases
		if (node == list->head)
		{
			removeFront(list);
		}
		else if (node == list->tail)
		{
			removeRear(list);
		}
		else //it was in the middle
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			//should free the node now
			list->size--;
		}

		//free the emptyNode, but maybe not the data (it might be returned)

	}
}

//find the data, and get the node it was in
//if found, remove the node from the list
//returns the data... none of the other 'remove's should return anything
/*
 * @params: obj == an ObjectPtr->data to find
 * @return:
 */
void *removeListObject(ListPtr list, void *obj)
{
	if (list == NULL) return NULL;
	if (obj == NULL) return NULL;

	NodePtr emptyNode;
	//find the node/data, but do not free the data
	void *tmpData = listSearch(list, &emptyNode, obj);
	//remove and free the node
	removeNode(list, emptyNode);

	if (tmpData)
		return tmpData;
	else
		return NULL;
}

/* toFind should be an ObjectPtr->data
 * @params:	foundNode == initially empty, but will receive a list node if it is found
 *			toFind == a key to use, with the list->compare method, to find a ObjectPtr->data
 * @return 	ObjectPtr->data if it is found
 * @side	foundNode will store the address of the Node if it is found
 * */
void *listSearch (ListPtr list, NodePtr *foundNode, void *toFind)
{
	//NodePtr tmpNode = list->head;
	*foundNode = list->head;

	while (*foundNode)
	{
		if (list->compare((*foundNode)->obj->data, toFind))
			break;
		*foundNode = (*foundNode)->next;
	}

	if (*foundNode)
	{
		return (*foundNode)->obj->data;
	}
	else
		return NULL;
}

int listGetMax(ListPtr list)
{
	int max = 0;

	if (list->size == 0)
		return max;

	NodePtr node = list->head;

	while (node)
	{
		if (node->obj->key > max)
			max = node->obj->key;

		node = node->next;
	}

	return max;
}

void reverseList(ListPtr L)
{
	if (L == NULL) return;
	L->tail = L->head;
	L->head  = reverse (L->head);
}

static NodePtr reverse(NodePtr L)
{
	NodePtr list = NULL;
	while (L != NULL) {
		NodePtr tmp = L;
		L = L->next;
		if (L != NULL) L->prev = tmp;
		tmp->next = list;
		tmp->prev = L;
		list = tmp;
	}
	return list;
}

void printList(ListPtr L)
{
	if (L) print(L, L->head);
}

static void print(ListPtr list, NodePtr node)
{
	//int count = 0;
	char *output;
	while (node)
	{
		//ObjectPtr o = node->obj;
		//JobPtr j = (JobPtr)o->data;
		//printf("--------%d\n", j->key);
		//output = list->toString(node->obj);

		output = list->toString(node->obj->data);
		printf(" %s -->\n",output);
		//free(output);
		node = node->next;
		//count++;
		//if ((count % 6) == 0)
		//	printf("\n");
	}
    //printf(" NULL \n");
}




