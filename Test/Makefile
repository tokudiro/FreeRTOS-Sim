MAKETOP:=..
CPPFLAGS=-I$(MAKETOP)/Project -I$(MAKETOP)/Source/include/ -I$(MAKETOP)/Source/portable/GCC/POSIX/
CFLAGS=-g -O0 -Werror -Wall
LDFLAGS=-lpthread

all: test_tasks test_queue

tasks.o: $(MAKETOP)/Source/tasks.c
	gcc -c -o $@ $(CPPFLAGS) $(CFLAGS) $^

queue.o: $(MAKETOP)/Source/queue.c
	gcc -c -o $@ $(CPPFLAGS) $(CFLAGS) $^

.c.o:
	gcc -c -o $@ $(CPPFLAGS) $(CFLAGS) $^

test_tasks: stub.o tasks.o test_tasks.o
	g++ -o $@ $(LDFLAGS) $^ `pkg-config --libs cpputest`

test_queue: stub.o queue.o test_queue.o
	g++ -o $@ $(LDFLAGS) $^ `pkg-config --libs cpputest`


clean:
	rm -f test_tasks *~ *.o

.PHONY: clean all
