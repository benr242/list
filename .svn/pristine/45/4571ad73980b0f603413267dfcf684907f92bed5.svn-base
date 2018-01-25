/*
 * TestObject.c
 *
 *  Created on: Sep 2, 2008
 *      Author: benr242
 */

#include "TestObject.h"

int *toGetKey(void *to)
{
	TestObjectPtr tobject = (TestObjectPtr)to;
	return &(tobject->key);
}

char *toToString (void *to)
{
	TestObjectPtr tobject = (TestObjectPtr)to;

	return tobject->name;
}

TestObjectPtr createTestObject (int key, char *nname)
{
	TestObjectPtr to = (TestObjectPtr)malloc(sizeof(TestObject));

	to->key = key;
	to->name = nname;

	return to;
}
