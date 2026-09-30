#include "Cartridge.h"
#include <fstream>

// Checklist:

// Loading the .nes file. x (Constructor)
// Parsing the iNES header. x (Constructor)
// Loading PRG ROM. 
// Loading CHR ROM/RAM.
// Determining the mapper.
// CPU to cartridge address mapping.
// PPU to cartridge address mapping.
// Bank switching through mapper.
// Mirroring.

Cartridge::Cartridge(const std::string &filename)
{

    struct iNESHeader
    {
        char name[4];
        uint8_t prg_rom_chunks;
        uint8_t chr_rom_chunks;
        uint8_t mapper1;
        uint8_t mapper2;
        uint8_t prg_ram_size;
        uint8_t tv_system1;
        uint8_t tv_system2;
        char unused[5];
    } header;

    file.open(filename, std::ifstream::binary);

    // Read header.
    // Param 1 interprets header struct as a block of chars
    // Param 2 determines # of bytes read. Reads only the header bytes
    file.read(reinterpret_cast<char*>(&header), sizeof(iNESHeader));

    // Check if header is valid
    if (!validateROM(header.name)) {
        // Handle invalid ROM
    }

    




    // Read header
    // Read trainer if present
    // Read PRG-ROM
    // Read CHR-ROM
    // Create mapper

}

bool Cartridge::validateROM(const char name[4]) {
    if (
        name[0] != 'N' ||
        name[1] != 'E' ||
        name[2] != 'S' ||
        name[3] != 0x1A
    ) {
        return false;
    }
    return true;
}

bool Cartridge::cpuRead(uint16_t addr, uint8_t &data)
{
    uint32_t mapped_addr = 0;
    if (pMapper->cpuMapRead(addr, mapped_addr))
    {
        data = PRG_RAM[mapped_addr];
        return true;
    }
    return false;
}

bool Cartridge::cpuWrite(uint16_t addr, uint8_t data)
{
}
