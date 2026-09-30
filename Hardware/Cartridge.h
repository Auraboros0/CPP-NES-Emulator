#include <cstdint>
#include <vector>
#include <string>
#include <Mapper.h>

class Cartridge
{
public:
    Cartridge(const std::string &filename);
    bool cpuRead(uint16_t addr, uint8_t &data);
    bool cpuWrite(uint16_t addr, uint8_t data);

    bool ppuRead(uint16_t addr, uint8_t &data);
    bool ppuWrite(uint16_t addr, uint8_t data);

    bool imageValid();
    std::ifstream file;

    // Helper functions (mainly used for organization)
    bool validateROM(const char name[4]);

private:
    std::shared_ptr<Mapper> pMapper;
    std::vector<uint8_t> PRG_RAM;
    std::vector<uint8_t> CHR_RAM;
    std::vector<uint8_t> PRG_ROM;
    std::vector<uint8_t> CHR_ROM;
    uint8_t nMapperID = 0; // Which mapper is being used?
    uint8_t nPRGBanks = 0; // How many banks in PRG
    uint8_t nCHRBanks = 0; // How many banks in CHR
    // Mapper information
};