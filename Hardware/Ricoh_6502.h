// The CPU
// All Opcodes and Addressing Modes will come from Javidx9's NES Emulator
#pragma once  // Modern header guard that prevents multiple inclusions
#include <cstdint>
#include <string>
#include <vector>
#include "Bus.h"

class Bus;

class Ricoh_6502
{
public:
    // Initializers
    Ricoh_6502();
    ~Ricoh_6502();

    void setBus(Bus *bus) {NES = bus;};
    Bus *NES = nullptr;

    // Registers
    uint8_t a = 0x00;
    uint8_t x = 0x00;
    uint8_t y = 0x00;
    uint8_t pc = 0x00;
    uint8_t stkp = 0x00;
    uint8_t status = 0x00;

    // Address storage
    uint16_t addr_rel = 0x0000;
    uint16_t addr_abs = 0x0000;
    uint8_t fetched = 0x00; // Whatever is read from bus
    uint8_t opcode = 0x00;
    uint8_t cycles = 0;


    // Status Register
    // 0 1 2 3 4 5 6 7
    // C Z I D B   V N
    enum STAT_FLAGS {
        C = 1 << 0,
        Z = 1 << 1,
        I = 1 << 2,
        D = 1 << 3,
        B = 1 << 4,
        U = 1 << 5,
        V = 1 << 6,
        N = 1 << 7
    };

    bool GetFlag(STAT_FLAGS F);
    void SetFlag(STAT_FLAGS F, bool v);

    // Opcode table
	struct INSTRUCTION
	{
		std::string name; // The 3 letter mnemonic	
		uint8_t (Ricoh_6502::*operate )(void) = nullptr; // The Opcode
		uint8_t (Ricoh_6502::*addrmode)(void) = nullptr; // The Addr Mode (Immediate Value? Read from Memory?)
		uint8_t cycles = 0; // # of cycles the instruction will take to finish
	};

	std::vector<INSTRUCTION> lookup;

    // Main Methods
    void clock();
    void reset();
    void irq();
    void nmi();

    // Bus Methods
    uint8_t readFromBus(uint16_t addr);
    void writeToBus(uint16_t addr, uint8_t data);

    uint8_t fetch();


private: 
	// Addressing Modes =============================================
	uint8_t IMP();	uint8_t IMM();	
	uint8_t ZP0();	uint8_t ZPX();	
	uint8_t ZPY();	uint8_t REL();
	uint8_t ABS();	uint8_t ABX();	
	uint8_t ABY();	uint8_t IND();	
	uint8_t IZX();	uint8_t IZY();

private: 
	// Opcodes ======================================================

	uint8_t ADC();	uint8_t AND();	uint8_t ASL();	uint8_t BCC();
	uint8_t BCS();	uint8_t BEQ();	uint8_t BIT();	uint8_t BMI();
	uint8_t BNE();	uint8_t BPL();	uint8_t BRK();	uint8_t BVC();
	uint8_t BVS();	uint8_t CLC();	uint8_t CLD();	uint8_t CLI();
	uint8_t CLV();	uint8_t CMP();	uint8_t CPX();	uint8_t CPY();
	uint8_t DEC();	uint8_t DEX();	uint8_t DEY();	uint8_t EOR();
	uint8_t INC();	uint8_t INX();	uint8_t INY();	uint8_t JMP();
	uint8_t JSR();	uint8_t LDA();	uint8_t LDX();	uint8_t LDY();
	uint8_t LSR();	uint8_t NOP();	uint8_t ORA();	uint8_t PHA();
	uint8_t PHP();	uint8_t PLA();	uint8_t PLP();	uint8_t ROL();
	uint8_t ROR();	uint8_t RTI();	uint8_t RTS();	uint8_t SBC();
	uint8_t SEC();	uint8_t SED();	uint8_t SEI();	uint8_t STA();
	uint8_t STX();	uint8_t STY();	uint8_t TAX();	uint8_t TAY();
	uint8_t TSX();	uint8_t TXA();	uint8_t TXS();	uint8_t TYA();

    // Catch-all for illegal/illegitimate opcodes
	uint8_t XXX();
};