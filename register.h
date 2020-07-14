#include <bits/stdc++.h>
using namespace std;
class registerman
{
	unsigned *x;  //x0爱怎么写怎么写
	const unsigned real_x0 = 0;   //真的硬编码的x0
	unsigned pc = 0;
public:
	const int regsize = 32;
	registerman()
	{
		x = new unsigned[32];
		memset(x, 0, sizeof(x));
	}
	~registerman()
	{
		delete [] x;
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
};
