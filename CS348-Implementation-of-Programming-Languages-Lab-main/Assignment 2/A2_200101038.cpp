#include <bits/stdc++.h>

using namespace std;

#define T_RECORD_MAX 30

// struct to store the arguments of parsed instructions
struct instruction
{
    string label;
    string mnemonic;
    string operand;
    string address;
};

// struct to store info of text records
struct t_record
{
    string start;
    string objectCode;
    int length;
};

map<string, string> symtab, optable;
string prog_length;

typedef struct instruction instruction;
typedef struct t_record t_record;

// Function which takes input from a file and returns a struct with parsed arguments
instruction parser()
{
    string str;
    vector<string> array;
    instruction code;
    do
    {
        getline(cin, str);
        int i = 0;
        while (i < str.length() && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        // check if the instruction is a comment
        if (str[i] == '.')
            cout << "     " << str << endl;
        else
        // else parse the instruction into arguments
        {

            string word = "";
            // add the next character to 'word' till an empty character is reached
            // then push it to the temporary array
            int i = 0;
            while (i < str.length())
            {
                if (str[i] == ' ')
                {
                    if (word != "")
                        array.push_back(word);
                    word = "";
                }
                else
                {
                    word = word + str[i];
                }
                i++;
            }
            array.push_back(word);

            break;
        }
    } while (true);
    // if array has 3 arguments including label, store them into the struct to be returned
    if (array.size() == 3)
    {
        code.address = "";
        code.label = array[0];
        code.mnemonic = array[1];
        code.operand = array[2];
    }
    // if array has 2 arguments (no label), store them into the struct to be returned.
    else
    {
        code.address = "";
        code.label = "";
        code.mnemonic = array[0];
        code.operand = (array.size() == 2) ? array[1] : "";
    }

    // return the struct with the parsed arguments
    return code;
}

// Function which takes input from the intermediate file and returns a struct with parsed arguments
instruction inter_parser()
{
    string str;
    vector<string> array;
    instruction code;
    while (true)
    { // take instruction input from intermediate file
        getline(cin, str);
        int i = 0;
        while (i < str.length() && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        // check for comments
        if (str[i] != '.')
        // else parse the instruction into arguments
        {

            string word = "";
            // add the next character to 'word' till an empty character is reached
            // then push it to the temporary array
            int i = 0;
            while (i < str.length())
            {
                if (str[i] == ' ')
                {
                    if (word != "")
                        array.push_back(word);
                    word = "";
                }
                else
                {
                    word = word + str[i];
                }
                i++;
            }
            array.push_back(word);

            break;
        }
    }
    // if label is present
    if (array.size() == 4)
    {
        code.address = array[0];
        code.label = array[1];
        code.mnemonic = array[2];
        code.operand = array[3];
    }
    // if label is absent
    else
    {
        code.address = array[0];
        code.label = "";
        code.mnemonic = array[1];
        code.operand = (array.size() == 3) ? array[2] : "";
    }
    // return the parsed arguments in the form of a struct
    return code;
}



// function to convert decimal number to hex string
string decToHex(int n, int pad = 0)
{
    // ans string to store hexadecimal number
    string ans = "";

    while (n != 0)
    {
        // remainder variable to store remainder
        int rem = 0;

        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;

        // check if temp < 10
        if (rem < 10)
        {
            ch = rem + 48;
        }
        else
        {
            ch = rem + 55;
        }

        // updating the ans string with the character variable
        ans.insert(0, 1, ch);
        n = n / 16;
    }
    while (ans.size() < pad)
        ans.insert(0, 1, '0');
    return ans;
}

// function to convert hex string to decimal number
int hexToDec(string str)
{
    int y;
    stringstream stream;
    stream << str;
    stream >> hex >> y;
    return y;
}

// function for adding 2 strings
string add(string str, string adder, int isHex)
{
    // Adding hex and hex
    if (isHex)
    {
        int num1 = hexToDec(str);
        int num2 = hexToDec(adder);
        int sum = num1 + num2;
        return decToHex(sum);
    }
    // Adding decimal and hex
    else
    {
        int num1 = hexToDec(str);
        int num2 = atoi(adder.c_str());
        int sum = num1 + num2;

        return decToHex(sum);
    }
}

// defining the opcode table
void init_optable()
{
    optable.insert(pair<string, string>("ADD", "18"));
    optable.insert(pair<string, string>("SUB", "1C"));
    optable.insert(pair<string, string>("MUL", "20"));
    optable.insert(pair<string, string>("DIV", "24"));
    optable.insert(pair<string, string>("COMP", "28"));
    optable.insert(pair<string, string>("J", "3C"));
    optable.insert(pair<string, string>("JEQ", "30"));
    optable.insert(pair<string, string>("JLT", "38"));
    optable.insert(pair<string, string>("JGT", "34"));
    optable.insert(pair<string, string>("LDA", "00"));
    optable.insert(pair<string, string>("LDX", "04"));
    optable.insert(pair<string, string>("LDL", "08"));
    optable.insert(pair<string, string>("RD", "D8"));
    optable.insert(pair<string, string>("WD", "DC"));
    optable.insert(pair<string, string>("LDCH", "50"));
    optable.insert(pair<string, string>("STX", "10"));
    optable.insert(pair<string, string>("TIX", "2C"));
    optable.insert(pair<string, string>("TD", "E0"));
    optable.insert(pair<string, string>("STCH", "54"));
    optable.insert(pair<string, string>("STL", "14"));
    optable.insert(pair<string, string>("RSUB", "4C"));
    optable.insert(pair<string, string>("STA", "0C"));
    optable.insert(pair<string, string>("JSUB", "48"));
    optable.insert(pair<string, string>("OR", "44"));
    optable.insert(pair<string, string>("STSW", "E8"));
}

// op_table
string opcode(string mnemonic)
{

    if (optable.find(mnemonic) == optable.end())
        return "-1";
    return optable[mnemonic];
}

// function to find the address of a label in the symbol table
string get_addr(string label_x)
{
    string label = "";
    string label_addr;
    int flag = 0;
    for (int l = 0; l < label_x.size(); l++)
    {
        if (label_x[l] == ',')
        {
            flag = 1;
            break;
        }
        label += label_x[l];
    }
    if (symtab.find(label) != symtab.end())
    {
        label_addr = symtab[label];
        if (flag)
        {
            label_addr = add(label_addr, "8000", 1);
        }
        return label_addr;
    }
    else
    {
        return "-1";
    }
}

void pass_1(string infile)
{
    // changing standard input to file
    ifstream in(infile);
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());

    // changing standard output to file
    ofstream out("intermediate_file.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    string str;
    instruction instruction;
    string loc, start_addr, cur_loc;

    // extracting statements instruction by instruction from the input file
    instruction = parser();
    // checking if the opcode is 'START'
    if (instruction.mnemonic == "START")
    {
        // Setting the start address to the operand if the start instruction
        start_addr = instruction.operand;
        // add this instruction to the intermediate file
        cout << start_addr << ' ' << setw(8) << left << instruction.label << setw(8) << left << instruction.mnemonic << instruction.operand << endl;
        // read the next instruction
        instruction = parser();
    }
    // if no start instruction is found set the default start address
    else
    {
        start_addr = "0000";
    }
    // set the location counter to the start address
    loc = start_addr;
    // loop through the file to add instructions to the intermediate file
    while (true)
    {
        // Exit the loop if the "END" instruction is reached
        if (instruction.mnemonic == "END")
        {
            break;
        }
        cur_loc = loc;
        // look for label in the instruction
        if (instruction.label != "")
        {
            // if label is found check if it is present in the symbol table

            // if the label is already in the symbol table print an error message
            if (symtab.find(instruction.label) != symtab.end())
            {
                cin.rdbuf(cinbuf);
                cout.rdbuf(coutbuf);
                cout << "Duplicate Symbol definition used" << endl;
                return;
            }
            // else add it to the symbol table
            else
            {
                symtab[instruction.label] = loc;
            }
        }
        // if the mnemonic is an opcode increase the loaction counter by 3
        if (opcode(instruction.mnemonic) != "-1")
        {
            loc = add(loc, "3", 0);
        }
        // increment the location counter by the operand value in case of "RESB"
        else if (instruction.mnemonic == "RESB")
        {
            int reserve = atoi(instruction.operand.c_str());
            string hexaReserve = decToHex(reserve);
            loc = add(loc, hexaReserve, 1);
        }
        // in case of "BYTE" opcode
        else if (instruction.mnemonic == "BYTE")
        {
            int bytes;
            string label2 = instruction.operand;
            char ch = label2[0];
            // in case of hex each byte can store 2 hex values
            if (ch == 'X')
            {
                if ((label2.size() - 3) % 2 == 0)
                {
                    bytes = (label2.size() - 3) / 2;
                }
                else
                {
                    bytes = ((label2.size() - 3) / 2) + 1;
                }
            }
            // in case of character no of bytes equals the no. of characters in the string
            else
            {

                bytes = (label2.size() - 3);
            }
            // increase location counter by the number of bytes calculated above
            loc = add(loc, to_string(bytes), 1);
        }
        // increment the location counter by 3 if "WORD" opcode is used
        else if (instruction.mnemonic == "WORD")
        {
            loc = add(loc, "3", 0);
        }
        // increment the location counter by 3 times the operand value in case of "RESW"
        else if (instruction.mnemonic == "RESW")
        {
            int reserve = 3 * atoi(instruction.operand.c_str());
            string hexaReserve = decToHex(reserve);
            loc = add(loc, hexaReserve, 1);
        }
        // otherwise print error message
        else
        {
            cin.rdbuf(cinbuf);
            cout.rdbuf(coutbuf);
            cout << "Invalid opcode used" << endl;
            return;
        }
        // add the instruction to intermediate file
        cout << cur_loc << ' ' << setw(8) << left << instruction.label << setw(8) << left << instruction.mnemonic << instruction.operand << endl;
        instruction = parser();
    }
    // Find the program length
    prog_length = decToHex(hexToDec(loc) - hexToDec(start_addr), 4);
    cout << loc << ' ' << setw(8) << left << instruction.label << setw(8) << left << instruction.mnemonic << instruction.operand << endl;

    // reset the standard input and output
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
}

void pass_2()
{
    // taking input from the intermediate file
    ifstream in("intermediate_file.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());

    // switching output to the output.txt file
    ofstream out("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    instruction instruction;
    string start_addr, object, len_buf;

    // taking instruction by instruction input from the intermediate_file using the inter_parser() function
    instruction = inter_parser();
    //Adding the header record to the object file if start instruction is present
    if (instruction.mnemonic == "START")
    {
        start_addr = instruction.operand;
        cout << "H" << setw(6) << left << instruction.label << "00" << start_addr << "00" << prog_length << endl;
        instruction = inter_parser();
    }
     //Adding the header record to the object file if start instruction is absent
    else
    {
        start_addr = "0000";

        cout << "H" << setw(6) << left << "PROG"
             << "00" << start_addr << "00" << prog_length << endl;
    }
    
    //initiating a text record
    t_record t_record;
    t_record.start = start_addr;
    t_record.length = 0;
    t_record.objectCode = "";
    // loop through the file to add instructions to the object file
    while (true)
    {
        // Exit the loop if the "END" instruction is reached
        if (instruction.mnemonic == "END")
        {
            break;
        }
        object = "";
        //in case of "RESB" and "RESW" we don't need to add them to the object file so print the pre-existing record if it exists and start a new record
        if (instruction.mnemonic == "RESB" || instruction.mnemonic == "RESW")
        {
            if (t_record.length != 0)
            {
                cout << "T"
                     << "00" << t_record.start << decToHex(t_record.length, 2) << t_record.objectCode << endl;
                t_record.length = 0;
                t_record.start = "";
                t_record.objectCode = "";
            }

            instruction = inter_parser();
            continue;
        }
        //if the opcode is present in the opcode table
        else if (opcode(instruction.mnemonic) != "-1")
        {   
            //add the opcode to the record
            object += opcode(instruction.mnemonic);
            if (instruction.operand != "")
            {   
                //if symbol is not find in the symbol table print error
                if (get_addr(instruction.operand) == "-1")
                {
                    cin.rdbuf(cinbuf);
                    cout.rdbuf(coutbuf);
                    cout << "Unidentified Symbol usage encountered" << endl;
                    return;
                }
                else
                {   //add the address of the symbol to the record
                    object += get_addr(instruction.operand);
                }
            }
            else
            //if no operand is present add zeroes
            {   
                object += "0000";
            }
        }
        //if "BYTE" opcode is present 
        else if (instruction.mnemonic == "BYTE")
        {
            // assemble into string and store as object
            if (instruction.operand[0] == 'C')
            {   
                //if character is present add the hexcode of the ascci code of each character to the record
                for (int i = 2; i < instruction.operand.size() - 1; i++)
                {
                    int ascii = instruction.operand[i];
                    object += (decToHex(ascii));
                }
            }
            else
            {   //if hex code is present add it to the record
                if (instruction.operand.size() % 2 == 0)
                    object += "0";
                for (int i = 2; i < instruction.operand.size() - 1; i++)
                {
                    object += (instruction.operand[i]);
                }
            }
        } 
        //if "WORD" opcode is present convert it to hex and add to record
        else if (instruction.mnemonic == "WORD")
        {

            object += decToHex(atoi(instruction.operand.c_str()), 6);
        }
        //if record length exceeds the max allowed size print the record and initialize a new text record
        if (t_record.length + (object.size() / 2) > T_RECORD_MAX)
        {
            cout << "T"
                 << "00" << t_record.start << decToHex(t_record.length, 2) << t_record.objectCode << endl;
            t_record.length = 0;
            t_record.start = "";
            t_record.objectCode = "";
        }
        //recalculate the length, object code and the start address of the record
        t_record.length += (object.size() / 2);
        t_record.objectCode += object;
        t_record.start = (t_record.start == "") ? instruction.address : t_record.start;
        instruction = inter_parser();
    }
    //print the text record if any remains
    if (t_record.length)
        cout << "T"
             << "00" << t_record.start << decToHex(t_record.length, 2) << t_record.objectCode << endl;
    string prog_start;
    
    //printing the end record
    if (instruction.operand == "")
    {
        prog_start = start_addr;
    }
    else if (get_addr(instruction.operand) != "-1")
    {
        prog_start = get_addr(instruction.operand);
    }
    else
    {
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
        cout << "Unidentified Symbol usage encountered" << endl;
        return;
    }
    cout << "E"
         << "00" << prog_start << endl;

    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
}

//printing the opcode and symbol tables
void print_tables()
{
    ofstream out("symbol_table.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    cout << setw(10) << left << "SYMBOL"
         << "|  " << setw(5) << left << "ADDRESS" << endl;

    for (auto i : symtab)
        cout << setw(10) << left << i.first << "|  " << setw(5) << left << i.second << endl;

    ofstream out2("optable.txt");
    cout.rdbuf(out2.rdbuf());

    cout << setw(10) << left << "Mnemonic"
         << "|  " << setw(5) << left << "Binary" << endl;

    for (auto i : optable)
        cout << setw(10) << left << i.first << "|  " << setw(5) << left << i.second << endl;

    cout.rdbuf(coutbuf);
}


int main(int argc, char **argv)
{
    // check that the input is provided in the proper format
    if (argc != 2)
    {
        cout << "Usage: ./a.out {source file}\n";
        return 0;
    }

    // run the  2-pass assembler
    string input = argv[1];
    init_optable();
    pass_1(input);
    print_tables();
    pass_2();
    return 0;
}