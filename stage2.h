#include <bits/stdc++.h>
using namespace std;
extern registerman my_register;
extern int idst;
extern int exst;
extern int memst;
extern int wbst;
class Stage2
{
public:
	Stage2() = default;
	~Stage2() = default;
	void do_it(IFID &ifid, IDEX &idex)
	{
		// cout <<"---------------stage2        ---------------" << endl;
		if(!idst)
		{
			// cout << "stage2 no instruction" << endl;
			return;
		}
		if(exst)
		{
			// cout << "exe not finish" << endl;
			return;
		}
		instructionman myinstruction(ifid.code, ifid.pc);
		if(myinstruction.fail)
		{
			// cout << "stage2 fail!" << endl;
			return;
		}
		idex.op = myinstruction.op;
		idex.rs1 = myinstruction.rs1;
		idex.rs2 = myinstruction.rs2;
		idex.rd = myinstruction.rd;
		idex.imm = myinstruction.imm;
		idex.pc = myinstruction.pc;
		idex.rs1_num = myinstruction.rs1_num;
		idex.rs2_num = myinstruction.rs2_num;
		idex.rd_num = myinstruction.rd_num;
		// cout <<"rs1_num   " << bitset<32>(idex.rs1_num) << endl;
		// cout <<"rs2_num   " << bitset<32>(idex.rs2_num) << endl;
		// cout <<"rd_num    " << bitset<32>(idex.rd_num) << endl << endl << endl;
		idst = 0;
		exst = 1;
	}
};