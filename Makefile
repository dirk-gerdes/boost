LDFLAGS:= -lboost_system -lboost_thread  -L/usr/local/lib
CFLAGS:= -I/usr/local/include
UNITFLAGS:= -lboost_unit_test_framework
CC := c++


all:	unit_test thread sharedmemread sharedmemwrite



unit_test:	unit_test.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $(UNITFLAGS) unit_test.cpp -o unit_test

thread:	thread.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) thread.cpp -o thread

sharedmemread:	sharedmemread.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sharedmemread.cpp -o sharedmemread

sharedmemwrite:	sharedmemwrite.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sharedmemwrite.cpp -o sharedmemwrite



clean:
	rm thread sharedmemread sharedmemwrite
