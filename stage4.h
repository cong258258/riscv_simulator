#include <bits/stdc++.h>
using namespace std;
extern memoryman my_memory;
extern int idst;
extern int exst;
extern int memst;
extern int wbst;
extern int MEM_cyc;
class Stage4
{
public:
	Stage4() = default;
	~Stage4() = default;
	void do_it(EXMEM &exmem, MEMWB &memwb)
	{
		// cout <<"---------------stage4        ---------------" << endl;
		if(!memst)
		{
			// cout << "stage4 no instruction" << endl;
			return;
		}
		if(wbst)
		{
			// cout << "wb not finish" << endl;
			return;
		}
		accessman my_access(exmem);
		if(my_access.fail)
		{
			// cout << "stage4 fail!" << endl;
			return;
		}
		memwb.op = my_access.op;
		memwb.rs1 = exmem.rs1;
		memwb.rs2 = exmem.rs2;
		memwb.rd = exmem.rd;
		memwb.imm = my_access.imm;
		memwb.pc = my_access.pc;
		memwb.rs1_num = my_access.rs1_num;
		memwb.rs2_num = my_access.rs2_num;
		memwb.rd_num = my_access.rd_num;
		// ios::sync_with_stdio(false);
		// cout << "rs1   " << bitset<5>(memwb.rs1) << "     rs2   " << bitset<5>(memwb.rs2) << "     rd    " << bitset<5>(memwb.rd) << "     pc     " << bitset<8>(memwb.pc) << endl; 
		// cout <<"imm   " << bitset<32>(memwb.imm) << endl;
		// cout <<"rs1_num   " << bitset<32>(memwb.rs1_num) << endl;
		// cout <<"rs2_num   " << bitset<32>(memwb.rs2_num) << endl;
		// cout <<"rd_num    " << bitset<32>(memwb.rd_num) << endl << endl << endl;
		memst = 0;
		wbst = 1;
	}
};