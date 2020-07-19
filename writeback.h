#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
extern registerman my_register;
class writebackman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0, pc = 0;
	unsigned rs1_num = 0, rs2_num = 0, rd_num = 0;
	void writeback()
	{
		switch(op)
		{
			case EMPTY:
				break;
			case AUIPC:
				my_register[rd] = rd_num;
				break;
			case JAL:
				my_register.reglock[rd]--;
				my_register[rd] = rd_num;
				my_register.redirectpc(npc);
				break;
			 case JALR:
			 my_register.reglock[rd]--;
			 	my_register[rd] = rd_num;
				my_register.redirectpc(npc);
				break;
			 case BEQ: case BNE: case BLT: case BGE: case BLTU: case BGEU:
				my_register.redirectpc(pc);
				break;	
			case LUI: case LB: case LH: case LW: case LBU: case LHU: case ADDI: case SLTI: case SLTIU: case XORI: case ORI: case ADD: case SUB: case SLL: case SLT: case SLTU: case XOR: case SRL: case SRA: case OR: case AND: case ANDI: case SLLI: case SRLI: case SRAI:
				my_register.reglock[rd]--;
				my_register[rd] = rd_num;
				break;
			case SB: case SH: case SW:
				break;
			default:
				cout << "errorwriteback" << endl;
				break;

		}
	} 
	writebackman(MEMWB &asdf):kind(asdf.kind),op(asdf.op),rs1(asdf.rs1),rs2(asdf.rs2),rd(asdf.rd),rs1_num(asdf.rs1_num),rs2_num(asdf.rs2_num),rd_num(asdf.rd_num),imm(asdf.imm),pc(asdf.pc)
	{
		writeback();
	}
	~writebackman() = default;
};