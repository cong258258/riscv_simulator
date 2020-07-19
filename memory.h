#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
extern registerman my_register;
class memoryman
{
	unsigned *memory;
public:
	memoryman()
	{
		memory = new unsigned[500000];
		init_all(); 
	}
	~memoryman()
	{
		delete [] memory;
	}
	void init_all()
	{
		for(int i = 0; i < 500000; i++)
			memory[i] = 0;
		unsigned now_addr = 0;
		while(!cin.eof())
		{
			char str[15];
			cin >> str;
			stringstream ss(str);
			if(str[0] == '@')
			{
				ss.get();
				ss >> hex >> now_addr;
				ss.clear();
				ss.str("");
			}
			else
			{
				unsigned tmphex;
				ss >> hex >> tmphex;
				ss.clear();
				ss.str("");
				memory[now_addr] = tmphex;
				now_addr++;
			}
			
		}
	}
	unsigned read_memory_by_pc(int len = 4)
	{
		unsigned pc = my_register.getpc();
		unsigned tmpmem = 0;
		for(int i = len - 1; i >= 0; i--)
		{
			tmpmem = tmpmem << 8;
			tmpmem += memory[pc+i];
		}
		return tmpmem;
	}
	unsigned read_memory_given(int pos, int len = 4)
	{
		unsigned tmpmem = 0;
		for(int i = len - 1; i >= 0; i--)
		{
			tmpmem = tmpmem << 8;
			tmpmem += memory[pos+i];
		}
		return tmpmem;
	}
	void store_memory(unsigned pos, unsigned bin, unsigned len)
	{
		for(int i = 0; i < len; i++)
		{
			memory[pos+i] = bin & (0b11111111);
			bin = bin >> 8;
		}
	}
}; 
