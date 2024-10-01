#ifndef COMMON_HPP
#define COMMON_HPP

// ALL SML FUNCTIONS
constexpr int READ = 10;
constexpr int WRITE = 11;
constexpr int LOAD = 20;
constexpr int LOADIM = 21;
constexpr int LOADX = 22;
constexpr int LOADIDX = 22;
constexpr int STORE = 25;
constexpr int STOREIDX = 26;
constexpr int ADD = 30;
constexpr int ADDX = 31;
constexpr int SUBTRACT = 32;
constexpr int SUBTRACTX = 33;
constexpr int DIVIDE = 34;
constexpr int DIVIDEX = 35;
constexpr int MULTIPLY = 36;
constexpr int MULTIPLYX = 37;
constexpr int INC = 38;
constexpr int DEC = 39;
constexpr int BRANCH = 40;
constexpr int BRANCHNEG = 41;
constexpr int BRANCHZERO = 42;
constexpr int SWAP = 43;
constexpr int HALT = 45;

// Hardcoded variables for number of pages, rows, and columns
constexpr int PAGES = 1;
constexpr int ROWS = 10;
constexpr int COLUMNS = 10;

int executeInstruction(int &acc, int &instCount, int &instReg, int &inReg, int (&memory)[PAGES][ROWS][COLUMNS]);

void dumpCore(int acc, int instCount, int instReg, int inReg, int (&memory)[PAGES][ROWS][COLUMNS],
              int startPage, int endPage);

#endif
