#include "Object.h"

ObjectPtr createObject(int key, void *data)
{
	//printf("the key is %d\n", key);
	ObjectPtr newObject = (ObjectPtr) malloc (sizeof(Object));
	newObject->key = key;

	/*
	char *ss = (char *)data;
	newObject->data = malloc(sizeof(char)*(strlen(ss)+1));
	
	strcpy(newObject->data, data);
	*/
	newObject->data = data;
	
	return newObject;
}
