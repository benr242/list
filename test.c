//#include "ourhdr.h"
#include "List.h"
#include "TestObject.h"

int main (int argc, char **argv)
{
	ListPtr myList = createList(toGetKey, toToString, NULL, NULL);

	TestObjectPtr top1 = createTestObject(1, "ben");
	TestObjectPtr top2 = createTestObject(2, "tamar");
	TestObjectPtr top3 = createTestObject(3, "kain");

	addAtRear(myList, createNode(createObject(top1->key, top1)));

	addAtRear(myList, createNode(createObject(top2->key, top2)));

	addAtRear(myList, createNode(createObject(top3->key, top3)));

	printList(myList);

	return 0;
}
