#include "Bus.h"
Bus::Bus() {

}

Bus::~Bus() {

}

uint8_t Bus::cpuRead(uint16_t addr) {
    // Check Cartridge Range First

    // Then Check CPU Range

    // Then Check PPU Range
}

void Bus::cpuWrite(uint16_t addr, uint8_t data) {
    // Check Cartridge Range First

    // Then Check CPU Range

    // Then Check PPU Range
}