#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void editData(string &base64Code)
{
    base64Code.erase(0, 20);
    base64Code.pop_back();
}

int main()
{
    string data;
    string address;
    cout << "Enter .Json file address:" << "\n";
    getline(cin, address);
    ifstream MyFile(address);
    if (!MyFile.is_open())
    {
        cout << "Cant't open file!" << endl;
        return 1;
    }
    while (getline(MyFile, data))
    {
        if (data.find("dataBase64") != string::npos)
        {
            editData(data);
            cout << data << endl;
        }
    }
    MyFile.close();
}
