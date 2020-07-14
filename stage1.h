#include <bits/stdc++.h>
using namespace std;
extern memoryman my_memory;
extern registerman my_register;
class Stage1
{
public:
	Stage1() = default;
	~Stage1() = default;
	int do_it(IFID &a)
	{
		a.code = my_memory.read_memory_by_pc();
		if(a.code == 0x0ff00513)
			return 1;
		a.pc = my_register.getpc();
		// cout <<"---------------stage1" << hex << setw(8) << a.code << "---------------pc:" << hex << setw(2) << my_register.getpc() << endl;
		my_register.movepc(4);
		return 0;
	}
};