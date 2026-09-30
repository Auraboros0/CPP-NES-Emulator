64KB of address space
16 bit

PPU has its own bus.

PPU - CPU - RAM - APU - CONTROLS - CARTRIDGE - MAPPER
 |
 |
 L - 8KB PATTERN - 2KB NAMETABLE - 1Byte PALETTES
     0000->1FFF    2000->2FFF      3F00->3FFF

0x0000 -> 0x1FFF targets CPU
0x2000 -> 0x3FFF targets PPU