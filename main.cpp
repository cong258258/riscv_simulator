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
int main()
{
	while(1)
	{
		if(stage1.do_it(ifid))
			break;
		stage2.do_it(ifid, idex);
		stage3.do_it(idex, exmem);
		if(stage4.do_it(exmem, memwb))
		{
			// printf("-----------------end process-----------------\n");
			// for(int i = 0; i < 32; i++)
		 // 		printf("%X   ", my_register[i]);
			// printf("\n\n");
			// if(flag == 1)
			// {
			// 	cout << " 运算" << dec << memwb.op << endl << "rs1   " << bitset<5>(memwb.rs1) << "     rs2   " << bitset<5>(memwb.rs2) << "     rd    " << bitset<5>(memwb.rd) << "     pc     " << bitset<8>(memwb.pc) << endl; 
			// 	cout <<"imm   " << bitset<32>(memwb.imm) << endl;
			// 	cout <<"rs1_num   " << bitset<32>(memwb.rs1_num) << endl;
			// 	cout <<"rs2_num   " << bitset<32>(memwb.rs2_num) << endl;
			// 	cout <<"rd_num    " << bitset<32>(memwb.rd_num) << endl << endl << endl;
			// 	for(int i = 0; i < 32; i++)
			// 	 	cout << hex << setw(8) << my_register[i] << "   ";
			// 	cout << endl << endl;
			// }
			continue;
		}
		stage5.do_it(memwb);

		// printf("-----------------end process-----------------\n");
		// for(int i = 0; i < 32; i++)
		//  	printf("%X   ", my_register[i]);
		// printf("\n\n");
		// cout << "mem" << endl;
		// for(int i = 131004; i < 131100; i+=4)
		// 	cout << hex << setw(8) << my_memory.read_memory_given(i) << "   ";
		// cout << endl << endl;
	}
	printf("%d\n", (my_register[10] & 255u));
	return 0;
}