#include <bits/stdc++.h>
using namespace std;
class executeman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0, pc = 0;
	void execute()
	{
		switch(op)
		{
			case LUI:
				break;
			case AUIPC:
				rd = imm + pc;
				break;
			case JAL:
				break;
			case JALR:
				break;	
			case BEQ:
				if(rs1 == rs2)
					pc += imm;
				else
					pc += 4;
				break;
			case BNE:
				if(rs1 != rs2)
					pc += imm;
				else
					pc += 4;
				break;
			case BLT:
				if(int(rs1) < int(rs2))
					pc += imm;
				else
					pc += 4;
				break;
			case BGE:
				if(int(rs1) >= int(rs2))
					pc += imm;
				else
					pc += 4;
				break;
			case BLTU:
				if(rs1 < rs2)
					pc += imm;
				else
					pc += 4;
				break;
			case BGEU:
				if(rs1 >= rs2)
					pc += imm;
				else
					pc += 4;
				break;
			case LB: case LH: case LW: case LBU: case LHU:
				imm += rs1; 
				break;
			case ADDI:
				rd = rs1 + imm;
				break;
			case SLTI:
				if((int)rs1 < int(imm))
					rd = 1;
				break;
			case SLTIU:
				if(rs1 < imm)
					rd = 1;
				break;
			case XORI:
				rd = rs1 ^ imm;
				break;
			case ORI:
				rd = rs1 | imm;
				break;
			case ANDI:
				rd = rs1 & imm;
				break;
			case SLLI:
				rd = rs1 << (imm & 0b11111);
				break;
			case SRLI:
				rd = rs1 >> (imm & 0b11111);
				break;
			case SRAI:
				rd = int(rs1) >> (imm & 0b11111);
				break;
			case SB: case SH: case SW:
				imm = rs1 + imm;
				break;
			case ADD:
				rd = rs1 + rs2;
				break;
			case SUB:
				rd = rs1 - rs2;
				break;
			case SLL:
				rd = rs1 << rs2;
				break;
			case SLT:
				if(int(rs1) < int(rs2))
					rd = 1;
				break;
			case SLTU:
				if(rs1 < rs2)
					rd = 1;
				break;
			case XOR:
				rd = rs1 ^ rs2;
				break;
			case SRL:
				rd = rs1 >> rs2;
				break;
			case SRA:
				rd = int(rs1) >> rs2;
				break;
			case OR:
				rd = rs1 | rs2;
				break;
			case AND:
				rd = rs1 & rs2;
				break;
			default:
				cout << "errorexe" << endl;
				break;

		}
	} 
	executeman(IDEX &asdf):kind(asdf.kind),op(asdf.op),rs1(asdf.rs1_num),rs2(asdf.rs2_num),rd(asdf.rd_num),imm(asdf.imm),pc(asdf.pc)
	{
		execute();
	}
	~executeman() = default;
};