#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> registers(32);
vector<int> memory(16);

// Conversions
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') decimal += base;
        base *= 2;
    }
    return decimal;
}

int hexToBinary(string hex){
   return stoul(hex, nullptr, 16);
}

// Print Registers and Memory 
void printRegistersAndMemory() {

    // Print Registers 0–15
    cout << "\n===== REGISTERS (0–15) =====\n";
    for (int i = 0; i < 16; i++) {
        cout << "R[" << i << "] - ";

        // Print value in 4-digit hex
        cout << setw(4) << setfill('0') << hex << registers[i];

        // Switch back to normal decimal formatting
        cout << dec << endl;
    }

    // Print Memory 0–15
    cout << "\n===== MEMORY (0–15) =====\n";
    for (int i = 0; i < 16; i++) {
        cout << "M[" << i << "] - ";

        // Print value in 4-digit hex
        cout << setw(4) << setfill('0') << hex << memory[i];

        // Switch back to normal decimal formatting
        cout << dec << endl;
    }

    // Reset fill back to space for safety
    cout << setfill(' ');
}


// Operations 
void op_add(int rs, int rt, int rd){
    registers[rd] = registers[rs] + registers[rt];
    cout << "Instruction: add $" << rd << ", $" << rs << ", $" << rt << endl;
}

void op_sub(int rs, int rt, int rd){
    registers[rd] = registers[rs] - registers[rt];
    cout << "Instruction: sub $" << rd << ", $" << rs << ", $" << rt << endl;
}

void op_xor(int rs, int rt, int rd){
    registers[rd] = registers[rs] ^ registers[rt];
    cout << "Instruction: xor $" << rd << ", $" << rs << ", $" << rt << endl;
}

void op_or(int rs, int rt, int rd){
    registers[rd] = registers[rs] | registers[rt];
    cout << "Instruction: or $" << rd << ", $" << rs << ", $" << rt << endl;
}

void op_and(int rs, int rt, int rd){
    registers[rd] = registers[rs] & registers[rt];
    cout << "Instruction: and $" << rd << ", $" << rs << ", $" << rt << endl;
}

void op_lw(int rs, int rt, int imm){
    registers[rt] = memory[(registers[rs] + imm) % 16];
    cout << "Instruction: lw $" << rt << ", " << imm << "($" << rs << ")" << endl;
}

void op_sw(int rs, int rt, int imm){
    memory[(registers[rs] + imm) % 16] = registers[rt];
    cout << "Instruction: sw $" << rt << ", " << imm << "($" << rs << ")" << endl;
}

void op_addi(int rs, int rt, int imm){
    registers[rt] = registers[rs] + imm;
    cout << "Instruction: addi $" << rt << ", $" << rs << ", " << imm << endl;
}

void op_beq(int rs, int rt, int imm){
    cout << "Instruction: beq $" << rs << ", $" << rt << ", " << imm << endl;
    if (registers[rs] == registers[rt]) {
        cout << "Branch Taken.\n";
    }
}

void op_bne(int rs, int rt, int imm){
    cout << "Instruction: bne $" << rs << ", $" << rt << ", " << imm << endl;
    if (registers[rs] != registers[rt]) {
        cout << "Branch Taken.\n";
    }
}

// Instruction Decoder 
void processInstruction(int binary){
    int opcode = (binary >> 26) & 0x3F;
    int rs = (binary >> 21) & 0x1F;
    int rt = (binary >> 16) & 0x1F;
    int rd = (binary >> 11) & 0x1F;
    int shamt = (binary >> 6) & 0x1F;
    int func = binary & 0x3F;
    int imm = binary & 0xFFFF;

    if (imm & 0x8000) imm |= 0xFFFF0000;

    cout << "\nDecoded Fields:\n";
    cout << "opcode: " << opcode << " rs: " << rs 
         << " rt: " << rt << " rd: " << rd
         << " shamt: " << shamt << " funct: " << func << endl;

    // R Format
    if(opcode == 0){
        if(func == 0x20) op_add(rs, rt, rd);
        else if(func == 0x22) op_sub(rs, rt, rd);
        else if(func == 0x24) op_and(rs, rt, rd);
        else if(func == 0x25) op_or(rs, rt, rd);
        else if(func == 0x26) op_xor(rs, rt, rd);
        else cout << "Unknown R-format\n";
    }
    // I Format
    else{
        if(opcode == 0x08) op_addi(rs, rt, imm);
        else if(opcode == 0x23) op_lw(rs, rt, imm);
        else if(opcode == 0x2B) op_sw(rs, rt, imm);
        else if(opcode == 0x04) op_beq(rs, rt, imm);
        else if(opcode == 0x05) op_bne(rs, rt, imm);
        else cout << "Unknown I-format\n";
    }

    registers[0] = 0;
    printRegistersAndMemory();
}

//Main
int main() {

    for(int i=0; i<32; i++) registers[i] = i;
    for(int i=0; i<16; i++) memory[i] = i;

    string hex;

    while (true){
        cout << "\nEnter 8-digit HEX instruction (or q to quit): ";
        cin >> hex;
        if (hex == "q") break;

        if (hex.length() != 8){
            cout << "ERROR: Must be exactly 8 hex digits.\n";
            continue;
        }

        int bin = hexToBinary(hex);

        cout << "Binary: " << decimalToBinary(bin) << endl;

        processInstruction(bin);
    }

    return 0;
}
