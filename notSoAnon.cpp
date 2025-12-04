#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

// This function seprate base64Code
void editData(string &base64Code)
{
    base64Code.erase(0, 17);
    base64Code.pop_back();
    base64Code.pop_back();
}
// This function decode base64
void decodeBase64(string &code)
{
    string word = "";
    string main64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    vector<char> arr;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '=')
            break;
        int index64 = main64.find(code[i]);
        if (index64 != string::npos)
        {
            bitset<6> base2_6(index64);
            string base2_6char = base2_6.to_string();
            for (int index = 0; index < base2_6char.length(); index++)
            {
                arr.push_back(base2_6char[index]);
            }
        }
    }
    for (int i = 0; i + 7 < arr.size(); i += 8)
    {
        string wholeByte = "";
        for (int j = 0; j < 8; j++)
        {
            wholeByte += arr[i + j];
        }

        bitset<8> bit(wholeByte);
        unsigned long asciiCode = bit.to_ulong();
        char character = static_cast<char>(asciiCode);

        word += character;
    }
    cout << "Text : " << word << "\n";
}

int main()
{
    // Define variables
    string data;
    string address;
    cout << "Enter .Json file address:" << "\n";
    getline(cin, address);
    // Open .Json file
    ifstream MyFile(address);

    if (!MyFile.is_open())
    {
        cout << "Cant't open file!" << endl;
        return 1;
    }
    // Read whole file
    while (getline(MyFile, data))
    {
        if (data.find("dataBase64") != string::npos)
        {
            editData(data);
            cout << data << endl;
            decodeBase64(data);
        }
    }
    // Close .Json file
    MyFile.close();
}
