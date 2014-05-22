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
	boost::interprocess::shared_memory_object::remove("MySharedMemory");
	boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "MySharedMemory", 1024);
	
	try
	{
        int temp;
        std::cout << "Enter an Integer:";
        std::cin >> temp;
		MyClass *i = managed_shm.construct<MyClass>("MyObject")(temp);
	
		std::cout << i->geti() << std::endl;
	} 
	catch(...)
	{
		cout << "Exception" << endl;
	}
	return 0;
}

