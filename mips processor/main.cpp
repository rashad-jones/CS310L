#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> registers(32);

vector <int> memory(16);


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
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int hexToBinary(string hex){
   int binaryNumber = stoul(hex, nullptr, 16);
}

void op_add(int rs, int rt, int rd){
    registers[rd] = registers[rs] + registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_sub(int rs, int rt, int rd){
    registers[rd] = registers[rs] - registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_xor(int rs, int rt, int rd){
    registers[rd] = registers[rs] ^ registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_or(int rs, int rt, int rd){
    registers[rd] = registers[rs] | registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_and(int rs, int rt, int rd){
    registers[rd] = registers[rs] & registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_lw(int rs, int rt){
    // TODO, check that rs is in bounds
    registers[rt] = memory[rs];
    // TODO: cout out actual instruction per step 7
}

void op_sw(int rs, int rt){
    // TODO, check that rs is in bounds
    memory[rs] = registers[rt];
    // TODO: cout out actual instruction per step 7
}

void op_addi(int rs, int rt, int imi){
    registers[rt] = registers[rs] + imi;
}

int processInstruction(int binary){
    int opcode = (binary >> 26) & 0x3F;
    int rs = (binary >> 21) & 0x1F;
    int rt = (binary >> 16) & 0x1F;
    int rd = (binary >> 11) & 0x1F;
    int shamt = (binary >> 6) & 0x1F;
    int func = binary & 0x3F;
    int imi = binary & 0xFFFF;


    //R-Format
    if(opcode == 0){
        if(func == 0x20){
            op_add(rs, rt, rd);
        }else if{

        }
    }else{
        if(opcode == 0x08){
            op_addi(rs, rt, imi);
        }else if()
    }
}



int main() {
   
   for(int i= 0; i < 32; i++){
       registers[i]= i;
   }
   for(int i= 0; i < 16; i++){
       memory[i]= i;
   }
   
   

    int choice;
    
    do {
        cout << "\n------ Base Conversion Menu ------" << endl;
        cout << "1. Convert Decimal to Binary" << endl;
        cout << "2. Convert Binary to Decimal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (choice == 1) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Binary: " << decimalToBinary(decimal) << endl;
            processInstruction(binary);
        } else if (choice == 2) {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            cout << "Decimal: " << binaryToDecimal(binary) << endl;
        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
        } else if (choice == 4){
            cout << "Enter a hex number: ";
            cin >> hex;
            int userBinary = hexToBinary(hex);
            processInstruction(userBinary);
        }else {
            cout << "Invalid choice. Please try again." << endl;
        }
        
    } 
    cout << "Enter a hex number: ";
            cin >> hex;

    int userBinary = hexToBinary(hex);
        
    processInstruction(userBinary)
    return 0;
}
