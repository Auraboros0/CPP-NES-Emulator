// This will be what acts as the NES
// Connects all devices, calls their functions
#pragma once  // Modern header guard that prevents multiple inclusions
#include <cstdint>
#include <memory>
#include <array>
#include "Ricoh_6502.h"

class Ricoh_6502;

class Bus
{
public:
    Bus();
    ~Bus();

    // Devices
    Ricoh_6502 CPU;
    std::array<uint8_t, 2048> RAM;
    // Cartridge cartridge* = nullptr

    // Device connection methods
    void loadCartridge();

    // CPU Controls
    uint8_t cpuRead(uint16_t addr);
    void cpuWrite(uint16_t addr, uint8_t data);

private:
    // CPU
    // PPU
    // Cartridge
}