#include <iostream>
#include <boost/thread.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>

using namespace std;

class MyClass
{
public:
	MyClass( int i)
	{
		this->i = i;
	}
	int geti()
	{
		return i;
	};
protected:
	int i;
};

int main(int argc, char* argv[])
{
	boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "MySharedMemory", 1024);
	
	try
    {
        
        std::pair<MyClass*, std::size_t> p = managed_shm.find<MyClass>("MyObject");
        if (p.first)
            std::cout << (*p.first).geti() << std::endl;

	}
	catch(...)
	{
		cout << "Exception" << endl;
	}
	return 0;
}

