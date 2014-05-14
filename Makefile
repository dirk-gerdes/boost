LDFLAGS:= -lboost_system -lboost_thread -L/usr/local/lib
CFLAGS:= -I/usr/local/include
CC := c++


all:	thread

thread:	thread.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) thread.cpp -o thread

clean:
	rm thread
