enum Kind {u, j, i, b, s, r, ii, empty};
enum Op
{
	EMPTY,
	LUI, AUIPC,   // u
	JAL,     // j
	JALR,    // i
	BEQ, BNE, BLT, BGE, BLTU, BGEU, // b
	LB, LH, LW, LBU, LHU, //i，加载指令
	SB, SH, SW, //s，保存指令
	ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI, // i，立即数运算
	ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND,  // r，运算
	ERR
};
struct IFID
{
	unsigned code;
	unsigned pc;
};
struct IDEX
{
	Kind kind;
	Op op;
	unsigned rs1, rs2, rd, imm;
	unsigned rs1_num, rs2_num, rd_num;
	unsigned pc;
	unsigned codeid;
	unsigned guess_status;
};
struct EXMEM
{
	Kind kind;
	Op op;
	unsigned rs1, rs2, rd, imm;
	unsigned rs1_num, rs2_num, rd_num;
	unsigned pc;
	unsigned codeid;
	unsigned guess_status;
};
struct MEMWB
{
	Kind kind;
	Op op;
	unsigned rs1, rs2, rd, imm;
	unsigned rs1_num, rs2_num, rd_num;
	unsigned pc;
	unsigned codeid;
	unsigned guess_status;
};