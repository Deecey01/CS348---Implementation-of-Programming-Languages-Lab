# 2-Way Associative Cache Simulator
A 32-bit x86 assembly implementation of a 2-way associative cache memory simulator.

## Features

1. Cache Organization
   - 4 sets with 2 blocks each (total 8 blocks)
   - FIFO (First-In-First-Out) replacement policy
   - Valid bit tracking for each block
   - Tag and value storage for each block

2. Operations
   - Read: Check if data exists in cache (hit/miss)
   - Write: Update or add new data to cache
   - Cache display after each operation
   - Exit option to terminate program

3. Cache Display Format
   - Set number (0-3)
   - Block number within set (0-1)
   - Valid bit (0/1)
   - Tag (memory address)
   - Value stored


## Compilation and Execution

# Compile the assembly code
nasm -f elf32 220101039.asm -o 220101039.o
# Link the object file
gcc -no-pie -m32 220101039.o -o 220101039
# Run the program
./220101039


## Usage Instructions

1. Main Menu Options:
   - Enter 0: Exit the program
   - Enter 1: Read operation
   - Enter 2: Write operation

2. Read Operation:
   - Enter the memory address to read
   - Program will display:
     * Cache hit/miss status
     * Value (if it's a hit)
     * Current cache contents

3. Write Operation:
   - Enter the memory address to write
   - Enter the value to write
   - Program will display:
     * Cache hit/miss status
     * Current cache contents

4. Cache Display:
   After each operation, the cache contents are displayed in the following format:

   Current Cache Contents:
   Set Block Valid Tag Value
   0   0     1     123 456
   0   1     0     0   0
   ...

## Implementation Details

1. Set Calculation:
   - Set index = address % 4
   - Each set has 2 blocks
   - FIFO policy manages block replacement within sets

2. Cache Organization:
   - cache_tags: Stores memory addresses (32-bit)
   - cache_values: Stores data values (32-bit)
   - cache_valid: Tracks valid blocks (8-bit)
   - fifo_bits: Manages replacement policy (8-bit)

## Example Usage
Enter 0 to quit, 1 for read, 2 for write: 2
Enter address to write: 123
Enter value to write: 456
Cache Miss!
Current Cache Contents:
Set Block Valid Tag Value
0   0     1     123 456
0   1     0     0   0
...

Enter 0 to quit, 1 for read, 2 for write: 1
Enter address to read: 123
Cache Hit!
456
Current Cache Contents:
...


## Notes
- The cache is initially empty (all valid bits set to 0)
- FIFO replacement happens only when both blocks in a set are occupied
- The program maintains cache coherency for repeated writes to the same address