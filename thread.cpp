#include <iostream>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::bind;

void thread_func( int i)
{
	sleep( i);
	cout << "("<< i << ")" << "Thread" << endl;
}

int main()
{
	boost::thread t( bind( thread_func, 1));
	boost::thread u( bind( thread_func, 2));
	t.join();
	u.join();
}



