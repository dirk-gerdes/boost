#include <iostream>
using std::cout;
using std::endl;
class CTestclass
{
public:
	CTestclass(){cout << "Constructor" << endl;};
	void setI( int _i) {i=_i;};
	int getI(){return i;};
protected:
	int i;
};
