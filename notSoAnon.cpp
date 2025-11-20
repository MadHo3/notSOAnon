#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
            cout << data << endl;
        }
    }
    MyFile.close();
}
