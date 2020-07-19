#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
extern registerman my_register;
extern guessman my_guess;
extern int npc;
class instruction_decode_error{};
class instructionman
{
public:
	Kind kind;
	Op op;
	unsigned rs1 = 0, rs2 = 0, rd = 0, imm = 0;
	unsigned rs1_num = 0, rs2_num = 0, rd_num = 0;
	unsigned pc = 0;
	int fail = 0;
	unsigned codeid = 0;
	unsigned guess_status = 0;
	unsigned subcode(unsigned &code, int from, int to)
	{
		unsigned length = to - from + 1;
		unsigned tpnum = (1 << length) - 1;
		return (code >> from) & tpnum;
	}
	unsigned subbit(unsigned &code, int p)
	{
		return (code >> p) & 1u;
	}
	Op get_spec_op(Kind k, unsigned &code)
	{
		switch(k)
		{
			case b:
				switch(subcode(code, 12, 14))
				{
					case 0b000:
						return BEQ;
					case 0b001:
						return BNE;
					case 0b100:
						return BLT;
					case 0b101:
						return BGE;
					case 0b110:
						return BLTU;
					case 0b111:
						return BGEU;
					default:
						cout << "errorb" << endl;
						break;
				}
			case i:
				switch(subcode(code, 12, 14))
				{
					case 0b000:
						return LB;
					case 0b001:
						return LH;
					case 0b010:
						return LW;
					case 0b100:
						return LBU;
					case 0b101:
						return LHU;
					default:
						cout << "errori" << endl;
						break;
				}
			case ii:
				switch(subcode(code, 12, 14))
				{
					case 0b000:
						return ADDI;
					case 0b010:
						return SLTI;
					case 0b011:
						return SLTIU;
					case 0b100:
						return XORI;
					case 0b110:
						return ORI;
					case 0b111:
						return ANDI;
					case 0b001:
						return SLLI;
					case 0b101:
						if(subcode(code, 25, 31) == 0)
							return SRLI;
						else
							return SRAI;
					default:
						cout << "errorii" << endl;
						break;
				}
			case s:
				switch(subcode(code, 12, 14))
				{
					case 0b000:
						return SB;
					case 0b001:
						return SH;
					case 0b010:
						return SW;
					default:
						cout << "errors" << endl;
						break;
				}
			case r:
				switch(subcode(code, 12, 14))
				{
					case 0b000:
						if(subcode(code, 25, 31) == 0)
							return ADD;
						else
							return SUB;
					case 0b001:
						return SLL;
					case 0b010:
						return SLT;
					case 0b011:
						return SLTU;
					case 0b100:
						return XOR;
					case 0b101:
						if(subcode(code, 25, 31) == 0)
							return SRL;
						else
							return SRA;
					case 0b110:
						return OR;
					case 0b111:
						return AND;
					default:
						cout << "errorii" << endl;
						break;
				}
			default:
				cout << "errorop" << endl;
				break;

		}
		return ERR;
	} 
	void get_kind_and_op(unsigned &code)
	{
		unsigned opcode = (code & (0b1111111));
		switch(opcode)
		{
			case 0:
				kind = empty;
				op = EMPTY;
				break;
			case 55:
				kind = u;
				op = LUI;
				break;
			case 23:
				kind = u;
				op = AUIPC;
				break;
			case 111:
				kind = j;
				op = JAL;
				break;
			case 103:
				kind = i;
				op = JALR;
				break;
			case 99:
				kind = b;
				op = get_spec_op(b, code);
				break;
			case 3:
				kind = i;
				op = get_spec_op(i, code);
				break;
			case 19:
				kind = i;
				op = get_spec_op(ii, code);
				break;
			case 35:
				kind = s;
				op = get_spec_op(s, code);
				break;
			case 51:
				kind = r;
				op = get_spec_op(r, code);
				break;
			default:
				throw instruction_decode_error();
				break;
		}
	}
	instructionman(unsigned code = 0, unsigned ppc = 0)
	{
		pc = ppc;
		get_kind_and_op(code);
		switch(op)
		{
			case EMPTY:
				break;
			case LUI: case AUIPC:
				rd = subcode(code, 7, 11);
				imm = code & 0b11111111111111111111000000000000u;
				break;
			case JAL:
				rd = subcode(code, 7, 11);
				if(subbit(code, 31))
					imm = (0b111111111111) << 20;		 
				imm += (subcode(code, 12, 19) << 12) + (subbit(code, 20) << 11) + (subcode(code, 25, 30) << 5) + (subcode(code, 21, 24) << 1);
				break;
			case JALR:
				rd = subcode(code, 7, 11);
				rs1 = subcode(code, 15, 19);
				imm = subcode(code, 20, 31);
				if(subbit(code, 31))
					imm |= 0b11111111111100000000000000000000u;
				break;
			case BEQ: case BNE: case BLT: case BGE: case BLTU: case BGEU:
				rs1 = subcode(code, 15, 19);
				rs2 = subcode(code, 20, 24);
				if(subbit(code, 31))
					imm = (0b11111111111111111111) << 12;
				imm += (subbit(code, 7) << 11) + (subcode(code, 25, 30) << 5) + (subcode(code, 8, 11) << 1);
				// rs1_num = my_register[rs1];
				// rs2_num = my_register[rs2];
				break;
			case LH: case LB: case LW: case LBU: case LHU: 
				rd = subcode(code, 7, 11);
				rs1 = subcode(code, 15, 19);
				imm = subcode(code, 20, 31);
				if(subbit(code, 31))
					imm |= 0b11111111111111111111000000000000u;
				// rs1_num = my_register[rs1];
				break;
			case SB: case SH: case SW:
				rs1 = subcode(code, 15, 19);
				rs2 = subcode(code, 20, 24);
				imm = (subcode(code, 25, 31) << 5) + (subcode(code, 7, 11));
				if(subbit(code, 31))
					imm |= (0b11111111111111111111) << 12;
				// rs1_num = my_register[rs1];
				// rs2_num = my_register[rs2];
				break;
			case ADDI: case SLTI: case SLTIU: case XORI: case ORI: case ANDI: case SLLI: case SRLI: case SRAI:
				rd = subcode(code, 7, 11);
				rs1 = subcode(code, 15, 19);
				imm = subcode(code, 20, 31);
				if(subbit(code, 31))
					imm |= 0b11111111111111111111000000000000u;
				// rs1_num = my_register[rs1];
				break;
			case ADD: case SUB: case SLL: case SLT: case SLTU: case XOR: case SRL: case SRA: case OR: case AND:
				rd = subcode(code, 7, 11);
				rs1 = subcode(code, 15, 19);
				rs2 = subcode(code, 20, 24);
				// rs1_num = my_register[rs1];
				// rs2_num = my_register[rs2];
				break;
		}
		if(rs1 != 0 && my_register.reglock[rs1])
		{
			fail = 1;
			return;
		}
		else if(rs1)
			rs1_num = my_register[rs1];
		if(rs2 != 0 && my_register.reglock[rs2])
		{
			fail = 1;
			return;
		}
		else if(rs2)
			rs2_num = my_register[rs2];
		if(rd)
			my_register.reglock[rd]++;
		if(op == JALR)
			npc = ((rs1_num + imm) & (~1));
		if(op == JAL)
			npc = pc + imm;
		if(kind == b)
		{
			codeid = (code & 0b111111111111111);
			guess_status = my_guess.do_guess(codeid);
			if(guess_status)
				npc = pc + imm;
			else
				npc = pc + 4;
		}
		
	}
	~instructionman() = default;
};
