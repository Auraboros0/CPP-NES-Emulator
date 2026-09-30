RAM is only 2KB (0x0000 -> 0x1FFF), but has 8KB of address space because of mirroring

Mirroring is just taking the data stored in RAM's 2KB and making it accessible from 3 extra addresses.
    - Data at 0x1FFF can be accessed by reading 0x3FFF. 