listObjs:=List.o Node.o Object.o

cc:=gcc
ccflags:=-MMD -g -Wall

%.o: %.c
	$(cc) $(ccflags) -c $<

all: list test TestObject.o liblistlib.so

list: $(listObjs) TestObject.o
	
liblistlib.so: $(listObjs) 
	$(LD) -shared -o $@ $?
	cp -f liblistlib.so $(HOME)/lib
	cp -f liblistlib.so ../dash/
	cp -f List.h Node.h Object.h $(HOME)/include/list
	cp -f List.h Node.h Object.h ../dash/include/list
	
	
test: TestObject.o liblistlib.so
	$(cc) $(cflags) -o testList -L$(HOME)/lib -I$(HOME)/include test.c TestObject.o -llistlib

.PHONY: clean 

clean:
	rm -f *.[od] testList

