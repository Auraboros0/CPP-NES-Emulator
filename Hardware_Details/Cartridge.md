Consists of two memories, a mapper, two read/write data outlets and two read addr intakes

Memories: PRG & CHR
    PRG: Program. Program Memory
    CHR: Character. Graphic Memory

Memories: Banks
    A PRG bank is 16KB
    A CHR bank is 8KB
    Memories are split into separate "Banks". Bank 1 of PRG could contain Level One's data. Bank 2 could contain Level Two's data. Same thing for CHR. Bank 1 for Level One, 2 for Two.
    
    This gives the developer freedom over how they want to partition their data. Maybe they have few levels but a large amount of visuals per level. Or many levels with few visuals

Mapper: Maps incoming Addresses
    - Determines whether to access PRG or CHR
    - Determines which Bank to read from
    - Example: Whenever the PPU wants the current level's background tiles, it will always
               access 0x2000.
               0x2000 refers to Bank 1 Level 1, but since the current level is 3, it actually
               reads from 0x2200, Bank 3 Level 3.

               This saves the PPU the trouble of calculating where exactly the tiles are located. 

    - CPU & PPU are oblivious to the mapper doing anything at all.


