#include <bits/stdc++.h>
using namespace std;
class Stage3
{
public:
	Stage3() = default;
	~Stage3() = default;
	void do_it(IDEX &idex, EXMEM &exmem)
	{
		// cout <<"---------------stage3        ---------------" << endl;
		executeman myexecute(idex);
		exmem.op = myexecute.op;
		exmem.rs1 = idex.rs1;
		exmem.rs2 = idex.rs2;
		exmem.rd = idex.rd;
		exmem.imm = myexecute.imm;
		exmem.pc = myexecute.pc;
		exmem.rs1_num = myexecute.rs1;
		exmem.rs2_num = myexecute.rs2;
		exmem.rd_num = myexecute.rd;
		// cout << " 运算" << dec << exmem.op << endl << "rs1   " << bitset<5>(exmem.rs1) << "     rs2   " << bitset<5>(exmem.rs2) << "     rd    " << bitset<5>(exmem.rd) << "     pc     " << bitset<8>(exmem.pc) << endl; 
		// cout <<"imm   " << bitset<32>(exmem.imm) << endl;
		// cout <<"rs1_num   " << bitset<32>(exmem.rs1_num) << endl;
		// cout <<"rs2_num   " << bitset<32>(exmem.rs2_num) << endl;
		// cout <<"rd_num    " << bitset<32>(exmem.rd_num) << endl << endl << endl;
	}
};