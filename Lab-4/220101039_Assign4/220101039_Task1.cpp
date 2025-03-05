//NAME     : DIVYANSH CHANDAK
//ROLL NO. : 220101039
//ASSIGNMENT - 4
//-------------------------------------------------------------------------
// Write a C program to implement an assembler that processes assembly
// code in two passes.
// The program should support the given instruction set:
// ADD, SUB, MUL, DIV, COMP, JMP, JLE, JE, JGE, JNE, JL, JG, MOV, RESW,
// RESB, BYTE, WORD, CALL, RET, PUSH, POP, LDA, LDX, LDL, RD, WD, TD,
// STA, STX, STL, LDCH, STCH.
//--------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

const int FIELD_SIZE = 8;
const int MAX_TEXT_RECORD = 60;

class AssemblyInstruction {
private:
    string labelField;
    string operationField;
    string operandField;
    int memoryAddress;
    string machineCode;

public:
    AssemblyInstruction() : memoryAddress(0) {}
    
    void setFields(const string& label, const string& op, const string& operand) {
        labelField = label;
        operationField = op;
        operandField = operand;
    }

    void setAddress(int addr) { memoryAddress = addr; }
    void setMachineCode(const string& code) { machineCode = code; }
    
    string getLabel() const { return labelField; }
    string getOperation() const { return operationField; }
    string getOperand() const { return operandField; }
    int getAddress() const { return memoryAddress; }
    string getMachineCode() const { return machineCode; }
    
    bool isComment() const { return labelField == "."; }
};

class Assembler {
private:
    vector<AssemblyInstruction> instructions;
    map<string, int> symbolTable;
    map<string, string> operationTable;
    int programStart;
    int programLength;
    string programName;

    // Initialize operation codes
    void setupOperationCodes() {
        vector<pair<string, string>> ops = {
            {"ADD", "18"}, {"SUB", "1C"}, {"MUL", "20"}, {"DIV", "24"},
            {"LDA", "00"}, {"LDX", "04"}, {"LDL", "08"}, {"STA", "0C"},
            {"STX", "10"}, {"STL", "14"}, {"LDCH", "50"}, {"STCH", "54"},
            {"COMP", "28"}, {"JEQ", "30"}, {"JGT", "34"}, {"JLT", "38"},
            {"J", "3C"}, {"JSUB", "48"}, {"RSUB", "4C"},
            {"TIX", "2C"}, {"TD", "E0"}, {"RD", "D8"}, {"WD", "DC"}
        };

        for (const auto& op : ops) {
            operationTable[op.first] = op.second;
        }
    }

    // Utility functions
    string trimWhitespace(const string& str) {
        auto start = str.find_first_not_of(" \t\r\n");
        if (start == string::npos) return "";
        auto end = str.find_last_not_of(" \t\r\n");
        return str.substr(start, end - start + 1);
    }

    string intToHexString(int value, int width) {
        ostringstream oss;
        oss << uppercase << hex << setfill('0') << setw(width) << value;
        return oss.str();
    }

    // AssemblyInstruction parseInputLine(const string& line) {
    //     AssemblyInstruction inst;
    //     if (line.empty()) return inst;

    //     if (line[0] == '.') {
    //         inst.setFields(".", "", "");
    //         return inst;
    //     }

    //     // Ensure the line has enough length
    //     string label = (line.length() >= FIELD_SIZE) 
    //                 ? trimWhitespace(line.substr(0, FIELD_SIZE)) 
    //                 : "";
    //     string op = (line.length() >= FIELD_SIZE * 2) 
    //                 ? trimWhitespace(line.substr(FIELD_SIZE, FIELD_SIZE)) 
    //                 : "";
    //     string operand = (line.length() > FIELD_SIZE * 2) 
    //                     ? trimWhitespace(line.substr(FIELD_SIZE * 2)) 
    //                     : "";

    //     inst.setFields(label, op, operand);
    //     return inst;
    // }
    AssemblyInstruction parseInputLine(const string& line) {
        AssemblyInstruction inst;
        if (line.empty()) return inst;
        
        if (line[0] == '.') {
            inst.setFields(".", "", "");
            return inst;
        }

        string label = trimWhitespace(line.substr(0, FIELD_SIZE));
        string op = trimWhitespace(line.substr(FIELD_SIZE, FIELD_SIZE));
        string operand = trimWhitespace(line.substr(FIELD_SIZE * 2));
        
        inst.setFields(label, op, operand);
        return inst;
    }

public:
    Assembler() {
        setupOperationCodes();
        programStart = 0;
        programLength = 0;
    }

    void firstPass(const string& inputFile) {
        ifstream inFile(inputFile);
        ofstream intermediateFile("intermediate.txt");
        
        int locationCounter = 0;
        string line;
        
        while (getline(inFile, line)) {
            AssemblyInstruction inst = parseInputLine(line);
            
            if (inst.isComment()) {
                intermediateFile << "." << setw(7) << " " << line << "\n";
                continue;
            }

            if (inst.getOperation() == "START") {
                programStart = stoi(inst.getOperand(), nullptr, 16);
                locationCounter = programStart;
                programName = inst.getLabel();
                inst.setAddress(locationCounter);
                instructions.push_back(inst);
                intermediateFile << setw(4) << hex << uppercase 
                               << locationCounter << setw(4) << " " << line << "\n";
                continue;
            }

            inst.setAddress(locationCounter);

            if (!inst.getLabel().empty()) {
                if (symbolTable.find(inst.getLabel()) == symbolTable.end()) {
                    symbolTable[inst.getLabel()] = locationCounter;
                    cout << setw(8) << inst.getLabel() << " :" 
                             << setw(5) << intToHexString(locationCounter, 4) << "\n";
                } else {
                    cout << "Error: Duplicate symbol\n";
                }
            }

            if (inst.getOperation() == "END") {
                programLength = locationCounter - programStart;
                instructions.push_back(inst);
                intermediateFile << setw(8) << " " << line << "\n";
                break;
            }

            // Update location counter
            if (operationTable.find(inst.getOperation()) != operationTable.end()) {
                locationCounter += 3;
            } else if (inst.getOperation() == "WORD") {
                locationCounter += 3;
            } else if (inst.getOperation() == "RESW") {
                locationCounter += 3 * stoi(inst.getOperand());
            } else if (inst.getOperation() == "RESB") {
                locationCounter += stoi(inst.getOperand());
            } else if (inst.getOperation() == "BYTE") {
                if (inst.getOperand()[0] == 'C') {
                    locationCounter += inst.getOperand().length() - 3;
                } else if (inst.getOperand()[0] == 'X') {
                    locationCounter += (inst.getOperand().length() - 3) / 2;
                }
            }

            instructions.push_back(inst);
            intermediateFile << setw(4) << hex << uppercase 
                           << locationCounter - (locationCounter > programStart ? 3 : 0)
                           << setw(4) << " " << line << "\n";
        }
    }

    void secondPass() {
        ofstream objectFile("output.txt");
        
        // Write header record
        objectFile << "H" << setw(6) << left << programName
                  << intToHexString(programStart, 6)
                  << intToHexString(programLength, 6) << "\n";

        string textRecord;
        string startAddress;

        for (auto& inst : instructions) {
            if (inst.isComment()) {
                continue;
            }

            string objectCode;
            if (operationTable.find(inst.getOperation()) != operationTable.end()) {
                objectCode = operationTable[inst.getOperation()];
                if (!inst.getOperand().empty()) {
                    int addressValue = 0;
                    string operand = inst.getOperand();
                    
                    if (operand.find(",X") != string::npos) {
                        operand = operand.substr(0, operand.find(","));
                        addressValue = 32768;
                    }
                    
                    if (symbolTable.find(operand) != symbolTable.end()) {
                        addressValue += symbolTable[operand];
                        objectCode += intToHexString(addressValue, 4);
                    } else {
                        objectCode += "0000";
                    }
                } else {
                    objectCode += "0000";
                }
                
                inst.setMachineCode(objectCode);
            } else if (inst.getOperation() == "BYTE") {
                if (inst.getOperand()[0] == 'C') {
                    for (size_t i = 2; i < inst.getOperand().length() - 1; i++) {
                        objectCode += intToHexString(inst.getOperand()[i], 2);
                    }
                } else if (inst.getOperand()[0] == 'X') {
                    objectCode = inst.getOperand().substr(2, inst.getOperand().length() - 3);
                }
                inst.setMachineCode(objectCode);
            } else if (inst.getOperation() == "WORD") {
                objectCode = intToHexString(stoi(inst.getOperand()), 6);
                inst.setMachineCode(objectCode);
            }

            // Handle text records
            if (!objectCode.empty()) {
                if (textRecord.empty()) {
                    startAddress = intToHexString(inst.getAddress(), 6);
                }

                if (textRecord.length() + objectCode.length() <= MAX_TEXT_RECORD) {
                    textRecord += objectCode;
                } else {
                    objectFile << "T" << startAddress 
                             << intToHexString(textRecord.length() / 2, 2)
                             << textRecord << "\n";
                    textRecord = objectCode;
                    startAddress = intToHexString(inst.getAddress(), 6);
                }
            } else if (!textRecord.empty()) {
                objectFile << "T" << startAddress 
                         << intToHexString(textRecord.length() / 2, 2)
                         << textRecord << "\n";
                textRecord.clear();
            }
        }

        // Write last text record if exists
        if (!textRecord.empty()) {
            objectFile << "T" << startAddress 
                     << intToHexString(textRecord.length() / 2, 2)
                     << textRecord << "\n";
        }

        // Write end record
        objectFile << "E" << intToHexString(programStart, 6) << "\n";
    }
    
};

int main(){
    Assembler assembler;
    assembler.firstPass("sample_input.txt");
    assembler.secondPass();
    return 0;
}