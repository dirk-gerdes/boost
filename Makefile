LDFLAGS:= -lboost_system -lboost_thread -lrt -L/usr/local/lib
CFLAGS:= -I/usr/local/include
CC := c++


all:	thread sharedmemread sharedmemwrite

thread:	thread.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) thread.cpp -o thread

sharedmemread:	sharedmemread.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sharedmemread.cpp -o sharedmemread

sharedmemwrite:	sharedmemwrite.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sharedmemwrite.cpp -o sharedmemwrite



clean:
	rm thread sharedmemread sharedmemwrite
