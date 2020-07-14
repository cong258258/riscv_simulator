#include <bits/stdc++.h>
using namespace std;
extern memoryman my_memory;
extern registerman my_register;
class accessman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0, pc = 0;
	unsigned rs1_num = 0, rs2_num = 0, rd_num = 0;
	unsigned if_jump = 0;
	void access()
	{
		switch(op)
		{
			case LUI:
				break;
			case AUIPC:
				break;
			case JAL:
				my_register[rd] = my_register.getpc();
				my_register.redirectpc(pc + imm);
				if_jump = 1;
				break;
			case JALR:
				my_register[rd] = my_register.getpc();
				my_register.redirectpc(my_register[rs1] + imm);
				if_jump = 1;
				break;	
			case BEQ: case BNE: case BLT: case BGE: case BLTU: case BGEU:
				my_register.redirectpc(pc);
				if_jump = 1;
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