#include "common.hpp"
#include <iostream>

using namespace std;

// dumpCore function
// Takes as parameters all the registers and the memory, along with a start page and an end page.
// Prints out the current value of all registers, and then every page in the memory starting at
// the startPage and ending at the endPage.
void dumpCore(const int acc, const int instCount, const int instReg, const int inReg, int (&memory)[PAGES][ROWS][COLUMNS], const int startPage, const int endPage) {
	printf("%-22s%06d\n", "accumulator", acc);
	printf("%-22s%06d\n", "instructionCounter", instCount);
	printf("%-22s%06d\n", "indexRegister", inReg);
	printf("%-26s%02d\n", "operationCode", instReg / 10000);
	printf("%-24s%04d\n", "operand", instReg % 1000);
	cout << endl << "Memory" << endl << "  ";
	for (int i = startPage; i <= endPage; i++) {
		printf("\nPage #%d\n", i);
		cout << "  ";
		for (int a = 0; a < COLUMNS; a++) {
			printf(" %6d", a);
		}
		cout << endl;
		for (int j = 0; j < ROWS; j++) {
			printf("%2d ", j * ROWS);
			for (int k = 0; k < COLUMNS; k++) {
				printf("%06d ", memory[i][j][k]);
			}
			cout << endl;
		}
	}
}

// executeInstruction function
// Takes as parameters all the registers and the memory.
// Executes the current instruction specified in the instruction register.
// All operation codes are defined in the header file.
int executeInstruction(int &acc, int &instCount, int &instReg, int &inReg, int (&memory)[PAGES][ROWS][COLUMNS]) {

	// Separate the instructionRegister into the operation code (first two digits) and the operand (last four digits)
	const int opCode = instReg / 10000;
	const int operand = instReg % 10000;

	int page = operand / 100;
	int row = (operand % 100) / 10;
	int column = operand % 10;

	switch(opCode) {
		case READ:						// Read from terminal into memory
			int input;
			cout << "Input: ";
			cin >> input;
			memory[page][row][column] = input;
			break;
		case WRITE:						// Write from memory to terminal
			cout << memory[page][row][column] << endl;
			break;
		case LOAD:						// Load from memory to accumulator
			acc = memory[page][row][column];
			break;
		case LOADIM:					// Load the operand into accumulator
			acc = operand;
			break;
		case STORE:						// Store from accumulator into specified memory location
			memory[page][row][column] = acc;
		case ADD:
			acc += memory[page][row][column];
		case SUBTRACT:
			acc -= memory[page][row][column];
		case MULTIPLY:
			acc *= memory[page][row][column];
		case DIVIDE:
			acc /= memory[page][row][column];
		case HALT:						// End execution of program
			dumpCore(acc, instCount, instReg, inReg, memory, 0, 0);
			return 1;
		default: break;
	}
	instCount++;
	return 0;
}