#include <iostream>
#include <string>
#include <fstream>
#include "common.hpp"

using namespace std;

// LOAD FROM FILE
// This function takes as input the name of a file and the memory.
// It will open the file with the given filename, and load it into
// the memory line by line.
void loadFile(string& fileName, int (&memory)[PAGES][ROWS][COLUMNS]) {
    ifstream inputFile;
    inputFile.open(fileName);

    string line;
    int counter = 0;
    while (getline(inputFile, line)) {
        line = line.substr(0, line.find(';'));              // Remove all comments from each line
        memory[counter / 100][counter % 100 / 10][counter % 10] = stoi(line);
        counter++;
    }

    cout << "File fully loaded." << endl;
}

int main() {
    // REGISTERS
    int accumulator = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int indexRegister = 0;
    char openFile;

    // LOAD MEMORY
    // Initialize every memory location with value of 0
    int memory[PAGES][ROWS][COLUMNS];
    for (int i = 0; i < PAGES; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLUMNS; k++) {
                memory[i][j][k] = 0;
            }
        }
    }

    cout << "*** Welcome to Simpletron V2! ***" << endl
         << "Do you have a file that contains your SML program? (y/N) ";
    // LOADING PHASE
    // Loading values into the memory of the program. There are two different modes, one where it will read from a file
    // and one where values can be manually loaded.
    cin >> openFile;
    openFile = tolower(openFile);
    if (openFile == 'y') {
        string fileName;
        cout << "Enter name of file, INCLUDING the file extension: ";
        cin >> fileName;
        loadFile(fileName, memory);
    } else {
        cout << "***    Please enter your program one instruction (or data word) at a time.     ***" << endl
             << "***     I will type the location number and a question mark (?). You then      ***" << endl
             << "*** type the word for that location. Type the word GO to execute your program. ***" << endl;
        int counter = 0;
        string input;
        do {
            printf("%05d ? ", counter);
            cin >> input;
            if (tolower(input[0]) == 'g' && tolower(input[1]) == 'o') {
                break;
            }
            memory[0][counter / 10][counter % 10000] = stoi(input);
            counter++;
        } while (true);
    }

    // EXECUTION PHASE
    // For every loop, the instruction register is set to the contents of the memory address whose value is in the
    // instruction counter. The instruction is then executed using the executeInstruction function, which will return 1
    // if a halt is encountered, a -1 if an error occurs, and 0 if the program is to continue running.
    do {
        instructionRegister = memory[instructionCounter / 100][instructionCounter % 100 / 10][instructionCounter % 10];
        if(executeInstruction(accumulator, instructionCounter, instructionRegister, indexRegister, memory) != 0) break;
    } while (instructionCounter < PAGES*ROWS*COLUMNS);

    return 0;
}
