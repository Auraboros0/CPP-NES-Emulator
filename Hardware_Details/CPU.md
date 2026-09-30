Outputs 16-bit address
Reads & Writes Data 8-bits at a time (Relies on signal to determine which)
Runs on 1.79MHz clock

When outputting an address to the bus, the device whose range corresponds to the address
will respond in some manner:
    1: Device can only write
        - Device send a response (data) to CPU
    2: Device can only Read
        - Device will read data sent by CPU
    3: Device accepts input & can outputting
        - If data is sent by CPU, behaves like 2
        - Else, behaves like 1


Registers: All store 8 bit values
    A: Accumulator
    X: 
    Y:
    stkp: Stack Pointer (Holds temp values, such as the arguments of a function)
    pc: Program Counter (Holds address of next instruction)
    stat: Status Register (Holds CPU State, I recall this being used to track if the last
                           operation was N Z or P. N & P are one bit, Z is another)

Status Register bits:
    0 1 2 3 4 5 6 7
    C Z I D B   V N

    Carry
    Zero 
    Interrupt Disable
    Decimal Mode
    Break

    Overflow
    Negative


What happens on each clock cycle?
    1: Outputs program counter value to bus
    2: Receives 8 bit instruction
        2a: Instruction length can be 1 byte, 2 byte, etc. May require multiple clock cycles
        2b: First byte of any instruction tells us the size (length) & duration (clock cycles)
    3: Executes that instruction
    4: Output data if needed

