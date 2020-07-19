#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
extern int npc;
extern int idst;
extern guessman my_guess;
class executeman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0, pc = 0, guess_status = 0;
	unsigned idcode = 0;
	void execute()
	{
		switch(op)
		{
			case EMPTY:
				break;
			case LUI:
				rd = imm;
				break;
			case AUIPC:
				rd = imm + pc;
				break;
			case JAL:
				rd = pc + 4;
				// npc = pc + imm;
				break;
			case JALR:
				rd = pc + 4;
				// npc = rs1 + imm;
				break;	
				// {
				// 	npc = pc + imm;
				// 	idst = 0;
				// // }else
				// {
				// 	npc = pc + 4;
				// 	idst = 0;
				// }
			case BEQ:
				if(rs1 == rs2)
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
				break;
			case BNE:
				if(rs1 != rs2)
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
				break;
			case BLT:
				if(int(rs1) < int(rs2))
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
				break;
			case BGE:
				if(int(rs1) >= int(rs2))
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						// my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
				break;
			case BLTU:
				if(rs1 < rs2)
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
				break;
			case BGEU:
				if(rs1 >= rs2)
				{
					if(guess_status == 1)
						my_guess.guess_right_taken(idcode);
					else
					{
						my_guess.guess_wrong_taken(idcode);
						npc = pc + imm;
						idst = 0;
					}
				}
				else
				{
					if(guess_status == 0)
						my_guess.guess_right_not_taken(idcode);
					else
					{
						my_guess.guess_wrong_not_taken(idcode);
						npc = pc + 4;
						idst = 0;
					}
				}
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
	executeman(IDEX &asdf):kind(asdf.kind),op(asdf.op),rs1(asdf.rs1_num),rs2(asdf.rs2_num),rd(asdf.rd_num),imm(asdf.imm),pc(asdf.pc),guess_status(asdf.guess_status),idcode(asdf.codeid)
	{
		// printf("idcode %d", idcode);
		execute();
	}
	~executeman() = default;
};