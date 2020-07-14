#include <bits/stdc++.h>
using namespace std;
extern registerman my_register;
class Stage5
{
public:
	Stage5() = default;
	~Stage5() = default;
	void do_it(MEMWB &memwb)
	{
		// cout <<"---------------stage5        ---------------" << endl;
		writebackman my_writeback(memwb);
		// cout << " 运算" << dec << my_writeback.op << endl << "rs1   " << bitset<5>(my_writeback.rs1) << "     rs2   " << bitset<5>(my_writeback.rs2) << "     rd    " << bitset<5>(my_writeback.rd) << "     pc     " << bitset<8>(my_writeback.pc) << endl; 
		// cout <<"imm   " << bitset<32>(my_writeback.imm) << endl;
		// cout <<"rs1_num   " << bitset<32>(my_writeback.rs1_num) << endl;
		// cout <<"rs2_num   " << bitset<32>(my_writeback.rs2_num) << endl;
		// cout <<"rd_num    " << bitset<32>(my_writeback.rd_num) << endl << endl << endl;
	}
};