#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
extern memoryman my_memory;
extern registerman my_register;
extern int idst;
extern int exst;
extern int memst;
extern int wbst;
extern int npc;
class Stage1
{
public:
	Stage1() = default;
	~Stage1() = default;
	void do_it(IFID &ifid)
	{
		// cout <<"---------------stage1        ---------------";
		if(idst)
		{
			// cout << "id not finish" << endl;
			return;
		}
		// cout << "npc" << npc << "    ";
		my_register.redirectpc(npc);
		ifid.pc = my_register.getpc();
		ifid.code = my_memory.read_memory_by_pc(4);
		// cout << hex << ifid.code << "    pc:" << hex << setw(2) << ifid.pc << endl;
		if(ifid.code == 0x0ff00513)
			return;
		npc += 4;
		idst = 1;
	}
};