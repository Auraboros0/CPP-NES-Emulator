#include <cstdint>
/* idx will be used as follows: add_tbl[idx & F0][idx & 0F]*/
struct instruction {
    uint8_t idx;
    uint8_t length;
    uint8_t clockCount;
};