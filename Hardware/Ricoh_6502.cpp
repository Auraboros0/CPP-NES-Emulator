#include "Ricoh_6502.h"

Ricoh_6502::Ricoh_6502() {
    using a = Ricoh_6502;
	lookup = 
	{
		{ "BRK", &a::BRK, &a::IMM, 7 },{ "ORA", &a::ORA, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::ZP0, 3 },{ "ASL", &a::ASL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHP", &a::PHP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::IMM, 2 },{ "ASL", &a::ASL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABS, 4 },{ "ASL", &a::ASL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BPL", &a::BPL, &a::REL, 2 },{ "ORA", &a::ORA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ZPX, 4 },{ "ASL", &a::ASL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLC", &a::CLC, &a::IMP, 2 },{ "ORA", &a::ORA, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABX, 4 },{ "ASL", &a::ASL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "JSR", &a::JSR, &a::ABS, 6 },{ "AND", &a::AND, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "BIT", &a::BIT, &a::ZP0, 3 },{ "AND", &a::AND, &a::ZP0, 3 },{ "ROL", &a::ROL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLP", &a::PLP, &a::IMP, 4 },{ "AND", &a::AND, &a::IMM, 2 },{ "ROL", &a::ROL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "BIT", &a::BIT, &a::ABS, 4 },{ "AND", &a::AND, &a::ABS, 4 },{ "ROL", &a::ROL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BMI", &a::BMI, &a::REL, 2 },{ "AND", &a::AND, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ZPX, 4 },{ "ROL", &a::ROL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEC", &a::SEC, &a::IMP, 2 },{ "AND", &a::AND, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ABX, 4 },{ "ROL", &a::ROL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "RTI", &a::RTI, &a::IMP, 6 },{ "EOR", &a::EOR, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "EOR", &a::EOR, &a::ZP0, 3 },{ "LSR", &a::LSR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHA", &a::PHA, &a::IMP, 3 },{ "EOR", &a::EOR, &a::IMM, 2 },{ "LSR", &a::LSR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::ABS, 3 },{ "EOR", &a::EOR, &a::ABS, 4 },{ "LSR", &a::LSR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BVC", &a::BVC, &a::REL, 2 },{ "EOR", &a::EOR, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ZPX, 4 },{ "LSR", &a::LSR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLI", &a::CLI, &a::IMP, 2 },{ "EOR", &a::EOR, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ABX, 4 },{ "LSR", &a::LSR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "RTS", &a::RTS, &a::IMP, 6 },{ "ADC", &a::ADC, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ADC", &a::ADC, &a::ZP0, 3 },{ "ROR", &a::ROR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLA", &a::PLA, &a::IMP, 4 },{ "ADC", &a::ADC, &a::IMM, 2 },{ "ROR", &a::ROR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::IND, 5 },{ "ADC", &a::ADC, &a::ABS, 4 },{ "ROR", &a::ROR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BVS", &a::BVS, &a::REL, 2 },{ "ADC", &a::ADC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ZPX, 4 },{ "ROR", &a::ROR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEI", &a::SEI, &a::IMP, 2 },{ "ADC", &a::ADC, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ABX, 4 },{ "ROR", &a::ROR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "???", &a::NOP, &a::IMP, 2 },{ "STA", &a::STA, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZP0, 3 },{ "STA", &a::STA, &a::ZP0, 3 },{ "STX", &a::STX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "DEY", &a::DEY, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 2 },{ "TXA", &a::TXA, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "STY", &a::STY, &a::ABS, 4 },{ "STA", &a::STA, &a::ABS, 4 },{ "STX", &a::STX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "BCC", &a::BCC, &a::REL, 2 },{ "STA", &a::STA, &a::IZY, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZPX, 4 },{ "STA", &a::STA, &a::ZPX, 4 },{ "STX", &a::STX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "TYA", &a::TYA, &a::IMP, 2 },{ "STA", &a::STA, &a::ABY, 5 },{ "TXS", &a::TXS, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::NOP, &a::IMP, 5 },{ "STA", &a::STA, &a::ABX, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::XXX, &a::IMP, 5 },
		{ "LDY", &a::LDY, &a::IMM, 2 },{ "LDA", &a::LDA, &a::IZX, 6 },{ "LDX", &a::LDX, &a::IMM, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "LDY", &a::LDY, &a::ZP0, 3 },{ "LDA", &a::LDA, &a::ZP0, 3 },{ "LDX", &a::LDX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "TAY", &a::TAY, &a::IMP, 2 },{ "LDA", &a::LDA, &a::IMM, 2 },{ "TAX", &a::TAX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "LDY", &a::LDY, &a::ABS, 4 },{ "LDA", &a::LDA, &a::ABS, 4 },{ "LDX", &a::LDX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "BCS", &a::BCS, &a::REL, 2 },{ "LDA", &a::LDA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "LDY", &a::LDY, &a::ZPX, 4 },{ "LDA", &a::LDA, &a::ZPX, 4 },{ "LDX", &a::LDX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "CLV", &a::CLV, &a::IMP, 2 },{ "LDA", &a::LDA, &a::ABY, 4 },{ "TSX", &a::TSX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 4 },{ "LDY", &a::LDY, &a::ABX, 4 },{ "LDA", &a::LDA, &a::ABX, 4 },{ "LDX", &a::LDX, &a::ABY, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "CPY", &a::CPY, &a::IMM, 2 },{ "CMP", &a::CMP, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPY", &a::CPY, &a::ZP0, 3 },{ "CMP", &a::CMP, &a::ZP0, 3 },{ "DEC", &a::DEC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INY", &a::INY, &a::IMP, 2 },{ "CMP", &a::CMP, &a::IMM, 2 },{ "DEX", &a::DEX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "CPY", &a::CPY, &a::ABS, 4 },{ "CMP", &a::CMP, &a::ABS, 4 },{ "DEC", &a::DEC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BNE", &a::BNE, &a::REL, 2 },{ "CMP", &a::CMP, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ZPX, 4 },{ "DEC", &a::DEC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLD", &a::CLD, &a::IMP, 2 },{ "CMP", &a::CMP, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ABX, 4 },{ "DEC", &a::DEC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "CPX", &a::CPX, &a::IMM, 2 },{ "SBC", &a::SBC, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPX", &a::CPX, &a::ZP0, 3 },{ "SBC", &a::SBC, &a::ZP0, 3 },{ "INC", &a::INC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INX", &a::INX, &a::IMP, 2 },{ "SBC", &a::SBC, &a::IMM, 2 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::SBC, &a::IMP, 2 },{ "CPX", &a::CPX, &a::ABS, 4 },{ "SBC", &a::SBC, &a::ABS, 4 },{ "INC", &a::INC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BEQ", &a::BEQ, &a::REL, 2 },{ "SBC", &a::SBC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ZPX, 4 },{ "INC", &a::INC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SED", &a::SED, &a::IMP, 2 },{ "SBC", &a::SBC, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ABX, 4 },{ "INC", &a::INC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
	};
}

// Addressing Modes --------- Returned value is # of additional clock cycles

// Implied
// No data in instruction, sometimes means function operates on accumulator
uint8_t Ricoh_6502::IMP() {
	fetched = a;
	return 0;
}

// There is data in the instruction. This data is stored in the next byte
uint8_t Ricoh_6502::IMM() {
	addr_abs = pc++;
	return 0;
}

// Zero pagr addressing. Get the byte that is in page 0
uint8_t Ricoh_6502::ZP0() {
	addr_abs = readFromBus(pc);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

// Zero page addressing with X register offset
// Same as above but the saved address is offset
uint8_t Ricoh_6502::ZPX() {
	addr_abs = (readFromBus(pc) + x);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

// Zero page addressing with Y register offset
// Same as above but the saved address is offset
uint8_t Ricoh_6502::ZPY() {
	addr_abs = (readFromBus(pc) + y);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

// 3 Byte Instruction
// Stores a full 16 bit address at addr_abs
// Does this by reading the 8 bits at the pc addr, and the 8 bits that come after that pc addr
// Then combining them into a 16 bit int

uint8_t Ricoh_6502::ABS() {
	uint16_t lo = readFromBus(pc);
	pc++;
	uint16_t hi = readFromBus(pc);
	pc++;

	addr_abs = hi << 8  | lo;
	return 0;
}

// Absolute Address with X register offset
uint8_t Ricoh_6502::ABX() {
	uint16_t lo = readFromBus(pc);
	pc++;
	uint16_t hi = readFromBus(pc);
	pc++;

	addr_abs = (hi << 8  | lo) + x;

	// Check if x offset moves us to a new page
	if ((addr_abs & 0xFF00) != (hi << 8)) {
		return 1;
	} else {
		return 0;
	}
}

// Absolute Address with Y register offset
uint8_t Ricoh_6502::ABY() {
	uint16_t lo = readFromBus(pc);
	pc++;
	uint16_t hi = readFromBus(pc);
	pc++;

	addr_abs = (hi << 8  | lo) + y;

	// Check if y offset moves us to a new page
	if ((addr_abs & 0xFF00) != (hi << 8)) {
		return 1;
	} else {
		return 0;
	}
}

// Indirect addressing, pointers pretty much
// Interprets the next 16 bits as an address rather than a value
// Stores value that is found at this new address
uint8_t Ricoh_6502::IND() {
	uint8_t ptr_lo = readFromBus(pc);
	pc++;
	uint8_t ptr_hi = readFromBus(pc);
	pc++;

	uint16_t ptr = (ptr_hi << 8) | ptr_lo;
	
	// readFromBus(ptr + 1) is the more significant half (0xFF00)
	// readFromBus(ptr + 0) is the less significant half (0x00FF)

	// There exists a bug in the NES hardware that causes the page (ptr_hi) to wrap around
	// If the lower bits equal 0x00FF. So if ptr = 0x10FF, ptr + 1 would be 0x1000 instead of 0x1100
	// This error is being replicated since game developers worked around it
	if (ptr_lo == 0x00FF) {
		addr_abs = (readFromBus(ptr & 0xFF00) << 8 | readFromBus(ptr + 0));
	}
	else {
		addr_abs = (readFromBus(ptr + 1) << 8) | readFromBus(ptr + 0);
	}
	return 0;
}

// Same as above with X offset
uint8_t Ricoh_6502::IZX() {
	uint16_t t = readFromBus(pc);
	pc++;

	// Looks confusing but (uint16_t)(var) is just casting the var to uint16_t
	// This is done because x may can potentially cause an overflow when using 8 bit ints
	uint16_t lo = readFromBus((uint16_t)(t + (uint16_t)(x) & 0x00FF));
	uint16_t hi = readFromBus((uint16_t)(t + (uint16_t)(x + 1) & 0x00FF));

	addr_abs = (hi << 8) | lo;
	return 0;
}

// Works differently than IZX
// Adds the y offset to the final result rather than to the pointers themselves
uint8_t Ricoh_6502::IZY() {
	uint16_t t = readFromBus(pc);
	pc++;

	uint16_t lo = readFromBus((uint16_t)(t & 0x00FF));
	uint16_t hi = readFromBus((uint16_t)((t + 1) & 0x00FF));

	addr_abs = (hi << 8) | lo;
	addr_abs += y;

	// If the y offset has forced us onto a new page
	if ((addr_abs & 0xFF00) != hi << 8) {
		return 1;
	} else {
		return 0;
	}
}

// Relative addressing, used only by branching instructions
// Cannot jump any distance further than 127 bytes from the branch instruction
uint8_t Ricoh_6502::REL() {
	addr_rel = readFromBus(pc);
	pc++;
	// Checking if address is negative or positive
	// This forces addr_rel within the range -128 <-> +127
	if (addr_rel & 0x80) { // Not checking 0xFF80 because readFromBus() returns 8 bits. 
		addr_rel |= 0xFF00;
	}
}

// Instructions -------------------- We know where our data is now that we have addr_modes, now we can execute on 
// Returned int is additional clock cycles

// Fetch our data using the addr_abs set by one of our addressing modes
uint8_t Ricoh_6502::fetch() {
	// Implied addressing mode modifies fetched directly, so we need to specify if it is used
	if (!(lookup[opcode].addrmode == &Ricoh_6502::IMP)) {
		fetched = readFromBus(addr_abs);
	}
		return fetched;
}

// Perform the AND operation on register a using the fetched value
uint8_t Ricoh_6502::AND() {
	fetch();
	a = a & fetched;
	SetFlag(Z, a == 0x00); // Was the result of the operation 0?
	SetFlag(N, a & 0x80); // Was the result of the operation positive or negative?
	return 1;
}

// Branch if Carry Bit is set. Only used with REL
uint8_t Ricoh_6502::BCS() {
	if (GetFlag(C)) { // Check carry bit
		cycles++;
		addr_abs = addr_rel + pc;

		// Check if abs address & pc are on same page
		if ((addr_abs & 0xFF00) != (pc & 0xFF00)) {
			cycles++;
		}
		pc = addr_abs;
	}
	return 0;
}

// Clear Carry Bit
uint8_t Ricoh_6502::CLC() {
	SetFlag(C, 0);
	return 0;
}

// Addition with carry bit
// Use carry bit depending on if interpreting ints as signed or unsigned
// Ex: 0x8F + 0x7F = 0x01|0E.
// If signed, don't add carry bit to result but set negative if it is set. -15 / -0x0E
// If unsigned, add carry bit. 270 = 0x010E
uint8_t Ricoh_6502::ADC() {
	fetch();
	uint16_t temp = (uint16_t)a + (uint16_t)fetched + uint16_t(GetFlag(C));

	SetFlag(C, temp > 255); 
	SetFlag(Z, (temp & 0x00FF) == 0); 
	SetFlag(N, temp & 0x0080);
	// Do register a and fetched have the same signage? If so, does the signage of the addition's result match the signage of a?
	SetFlag(V, (a & 0x80) == (fetched & 0x80) && ((a & 0x80) != ((a + fetched) & 0x80)));
	a = temp & 0x00FF;
	return 1;
}

// Subtraction with carry bit
uint8_t Ricoh_6502::SBC() {
	fetch();
	uint16_t value = fetched ^ 0x00FF; // Inverting the fetched value, equivalent to multiplying by -1.
	uint16_t temp = (uint16_t)a + (uint16_t)value + uint16_t(GetFlag(C));

	SetFlag(C, temp > 255); 
	SetFlag(Z, (temp & 0x00FF) == 0); 
	SetFlag(N, temp & 0x0080);
	// Do register a and fetched have the same signage? If so, does the signage of the addition's result match the signage of a?
	SetFlag(V, (a & 0x80) == (value & 0x80) && ((a & 0x80) != ((a + value) & 0x80)));
	a = temp & 0x00FF;
	return 1;
}

// Push Accumulator (a) to stack
uint8_t Ricoh_6502::PHA() {
	// Stack is located in page 1.
	writeToBus(0x0100 + stkp, a);
	stkp--; // Stack grows downwards
	return 0;
}

// Pop from stack
uint8_t Ricoh_6502::PLA() {
	stkp++;
	a = readFromBus(0x0100 + stkp);
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);
	return 0;
}

// Return from interrupt
uint8_t Ricoh_6502::RTI() {
	// The interrupt functions store data to the stack in this order:
	// 1: Program Counter higher bits (page)
	// 2: Program Counter lower bits
	// 3: Status Register
	// Since stacks are last in first out, I'll have to fetch this info in reverse order.
	stkp++;
	status = readFromBus(0x0100 + stkp);
	status &= ~B;
	status &= ~U;
	stkp++;
	pc = readFromBus(0x0100 + stkp); 
	stkp++;
	pc |= readFromBus(0x0100 + stkp) << 8;
	stkp++; // Kill stack
	return 0;

	// I was working ahead a little bit, this is a remnant of that
	// uint16_t pc_addy = (readFromBus(0x0100 + stkp + 1) << 8) | (readFromBus(0x0100 + stkp));
}