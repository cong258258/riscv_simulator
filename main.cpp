#include <bits/stdc++.h>
#include "tmp.h"
#include "register.h"
#include "memory.h"
#include "instruction.h"
#include "memory_access.h"
#include "execute.h"
#include "writeback.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
using namespace std;
memoryman my_memory;
registerman my_register;
IFID ifid;
IDEX idex;
EXMEM exmem;
MEMWB memwb;
Stage1 stage1;
Stage2 stage2;
Stage3 stage3;
Stage4 stage4;
Stage5 stage5;
int idst = 0;
int exst = 0;
int memst = 0;
int wbst = 0;
int npc = 0;
int MEM_cyc = 0;
int main()
{
	// freopen("naive.data", "r", stdin); 
	while(ifid.code != 0x0ff00513 || idst || exst || memst || wbst)
	{
		// printf("-----------------process start---------------\n");
		stage5.do_it(memwb);
		// cout << hex << memwb.pc << endl;
		// cout << hex << npc << endl;
		stage4.do_it(exmem, memwb);
		// cout << hex << exmem.pc << endl;
		// cout << hex << npc << endl;
		stage3.do_it(idex, exmem);
		// cout << hex << idex.pc << endl;
		// cout << hex << npc << endl;
		stage2.do_it(ifid, idex);
		// cout << hex << ifid.pc << endl;
		// cout << hex << npc << endl;
		stage1.do_it(ifid);
		// cout << hex << npc << endl;
		// printf("-----------------end process-----------------\n");
		// my_register.showall();
		// printf("\n\n");
		// cout << " 运算" << dec << memwb.op << endl << "rs1   " << bitset<5>(memwb.rs1) << "     rs2   " << bitset<5>(memwb.rs2) << "     rd    " << bitset<5>(memwb.rd) << "     pc     " << bitset<8>(memwb.pc) << endl; 
		// cout <<"imm   " << bitset<32>(memwb.imm) << endl;
		// cout <<"rs1_num   " << bitset<32>(memwb.rs1_num) << endl;
		// cout <<"rs2_num   " << bitset<32>(memwb.rs2_num) << endl;
		// cout <<"rd_num    " << bitset<32>(memwb.rd_num) << endl << endl << endl;
		// cout << "reglock" << my_register.reglock[14] << endl;
		// cout << "mem" << endl;
		// for(int i = 131004; i < 131100; i+=4)
		// 	cout << hex << setw(8) << my_memory.read_memory_given(i) << "   ";
		// cout << endl << endl;
	}


		// 	{
		// 	// printf("-----------------end process-----------------\n");
		// 	// for(int i = 0; i < 32; i++)
		//  // 		printf("%X   ", my_register[i]);
		// 	// printf("\n\n");
		// 	// if(flag == 1)
		// 	// {
		// 	// 	cout << " 运算" << dec << memwb.op << endl << "rs1   " << bitset<5>(memwb.rs1) << "     rs2   " << bitset<5>(memwb.rs2) << "     rd    " << bitset<5>(memwb.rd) << "     pc     " << bitset<8>(memwb.pc) << endl; 
		// 	// 	cout <<"imm   " << bitset<32>(memwb.imm) << endl;
		// 	// 	cout <<"rs1_num   " << bitset<32>(memwb.rs1_num) << endl;
		// 	// 	cout <<"rs2_num   " << bitset<32>(memwb.rs2_num) << endl;
		// 	// 	cout <<"rd_num    " << bitset<32>(memwb.rd_num) << endl << endl << endl;
		// 	// 	for(int i = 0; i < 32; i++)
		// 	// 	 	cout << hex << setw(8) << my_register[i] << "   ";
		// 	// 	cout << endl << endl;
		// 	// }
		// 	continue;
		// }
	printf("%d\n", (my_register[10] & 255u));
	return 0;
}
