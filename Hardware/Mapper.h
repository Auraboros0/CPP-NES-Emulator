#include <cstdint>
#include <memory>

// The purpose of this class is to take an address and transform it so the proper bank receives it
class Mapper {
    public:
        Mapper(uint8_t prgBanks, uint8_t chrBanks);

    protected:
        uint8_t nPRGBanks = 0;
        uint8_t nCHRBanks = 0;
    
    public:
        // addr is what the CPU/PPU requests. mapped_addr is what that addr is mapped to.
        // mapped_addr is used to index the Cartridge ROM
        // Returns true if addr is successfully mapped
        virtual bool cpuMapRead(uint16_t addr, uint32_t &mapped_addr) = 0;
        virtual bool cpuMapWrite(uint16_t addr, uint32_t &mapped_addr) = 0;
        virtual bool ppuMapRead(uint16_t addr, uint32_t &mapped_addr) = 0;
        virtual bool ppuMapWrite(uint16_t addr, uint32_t &mapped_addr) = 0; 
        
};