#include <bits/stdc++.h>
using namespace std;
extern memoryman my_memory;
extern registerman my_register;
extern int MEM_cyc;
class accessman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0, pc = 0;
	unsigned rs1_num = 0, rs2_num = 0, rd_num = 0;
	int fail = 0;
	void access()
	{
		if(op == LB || op == LH || op == LW || op == LBU || op == LHU || kind == s)
			if(MEM_cyc < 3)
			{
				MEM_cyc++;
				fail = 1;
				return;
			}
		switch(op)
		{
			case EMPTY:
				break;
			case LUI:
				break;
			case AUIPC:
				break;
			case JAL:
				break;
			case JALR:
				break;	
			case BEQ: case BNE: case BLT: case BGE: case BLTU: case BGEU:
				break;
			case LB: 
				rd_num = my_memory.read_memory_given(imm, 1);
				break;
			case LH:
				rd_num = my_memory.read_memory_given(imm, 2);
				break;
			case LW:
				rd_num = my_memory.read_memory_given(imm, 4);
				break;
			case LBU:
				rd_num = my_memory.read_memory_given(imm, 1);
				break;
			case LHU:
				rd_num = my_memory.read_memory_given(imm, 2);
				break;
			case ADDI: case SLTI: case SLTIU: case XORI: case ORI: case ANDI: case SLLI: case SRLI: case SRAI:
				break;
			case SB:
				my_memory.store_memory(imm, rs2_num, 1);
				break;
			case SH:
				my_memory.store_memory(imm, rs2_num, 2);
				break;
			case SW:
				my_memory.store_memory(imm, rs2_num, 4);
				break;
			case ADD: case SUB: case SLL: case SLT: case SLTU: case XOR: case SRL: case SRA: case OR: case AND:
				break;
			default:
				cout << "errorexe" << endl;
				break;

		}
	} 
	accessman(EXMEM &asdf):kind(asdf.kind),op(asdf.op),rs1(asdf.rs1),rs2(asdf.rs2),rd(asdf.rd),rs1_num(asdf.rs1_num),rs2_num(asdf.rs2_num),rd_num(asdf.rd_num),imm(asdf.imm),pc(asdf.pc)
	{
		access();
	}
	~accessman() = default;
};