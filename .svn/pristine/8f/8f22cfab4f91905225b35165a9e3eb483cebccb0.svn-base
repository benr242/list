/*
 * TestObject.h
 *
 *  Created on: Sep 2, 2008
 *      Author: benr242
 */

#ifndef TESTOBJECT_H_
#define TESTOBJECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct testObject TestObject;
typedef struct testObject *TestObjectPtr;

struct testObject
{
	int key;
	char *name;
};

int *toGetKey(void *);
char *toToString(void *);

TestObjectPtr createTestObject(int, char *);

#endif /* TESTOBJECT_H_ */
