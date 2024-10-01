#include "common.hpp"
//#include <stdio.h>
#include <iostream>

using namespace std;

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
// Takes as input all the registers and the memory
int executeInstruction(int &acc, int &instCount, int &instReg, int &inReg, int (&memory)[PAGES][ROWS][COLUMNS]) {

    const int opCode = instReg / 10000;
    const int operand = instReg % 10000;

    cout << "instReg: " << instReg << endl;
    cout << "opCode: " << opCode << endl;
    cout << "instCount: " << instCount << endl;

    int page = operand / 100;
    int row = (operand % 100) / 10;
    int column = operand % 10;

    switch(opCode) {
        case READ:
            int input;
            cout << "Input: ";
            cin >> input;
            memory[page][row][column] = input;
            break;
        case WRITE:
            dumpCore(acc, instCount, instReg, inReg, memory, 0, 0);
            break;
        case HALT:
            dumpCore(acc, instCount, instReg, inReg, memory, 0, 0);
            return 1;
        default: break;
    }
    instCount++;
    return 0;
}