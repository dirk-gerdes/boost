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
	//boost::interprocess::shared_memory_object::remove("MySharedMemory");
	boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "MySharedMemory", 1024);
	
	//MyClass *i = managed_shm.construct<MyClass>("MyObject")(99);
	try
	{
		MyClass *i = managed_shm.construct<MyClass>("MyObject")(12);
	
        std::cout << i->geti() << std::endl;
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

