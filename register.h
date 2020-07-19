#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
class registerman
{
	unsigned *x;  //x0爱怎么写怎么写
	const unsigned real_x0 = 0;   //真的硬编码的x0
	unsigned pc = 0;
public:
	int *reglock;
	class reglock_error{};
	registerman()
	{
		x = new unsigned[32];
		for(int i = 0; i < 32; i++)
			x[i] = 0;
		reglock = new int[32];
		for(int i = 0; i < 32; i++)
			reglock[i] = 0;
	}
	~registerman()
	{
		delete [] x;
		delete [] reglock;
	}
	const unsigned &operator[](int numm) const
	{
		if(numm)
			return x[numm];
		else
			return real_x0;
	}
	unsigned &operator[](int numm)
	{
		if(reglock[numm] && numm != 0)
		{
			throw reglock_error();
		}
		x[0] = 0;
		return x[numm];
	}
	unsigned getpc() const
	{
		return pc;
	}
	void movepc(int numm)
	{
		pc += numm;
	}
	void redirectpc(unsigned addr)
	{
		pc = addr;
	}
	// void showall()
	// {
	// 	for(int i = 0; i < 32; i++)
	// 	 	cout << hex << setw(8) << x[i] << "   ";
	// }
};
