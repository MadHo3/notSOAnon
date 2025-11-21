#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This function seprate base64Code
void editData(string &base64Code) {
  base64Code.erase(0, 17);
  base64Code.pop_back();
  base64Code.pop_back();
}
// This function decode base64

void decodeBase64(string &code) {
  string word = "";
  string main64 =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  vector<char> arr;

  // شمارش '='
  int padding = 0;
  if (!code.empty() && code.back() == '=')
    padding++;
  if (code.size() > 1 && code[code.size() - 2] == '=')
    padding++;

  // ساختن 6-bit ها
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '=')
      break;

    int index64 = main64.find(code[i]);
    if (index64 != string::npos) {
      bitset<6> base2_6(index64);
      string base2_6char = base2_6.to_string();
      for (char c : base2_6char)
        arr.push_back(c);
    }
  }

  // حذف بیت‌های padding (کمترین تغییر)
  if (padding == 1 && arr.size() >= 2)
    arr.resize(arr.size() - 2);
  else if (padding == 2 && arr.size() >= 4)
    arr.resize(arr.size() - 4);

  // تبدیل 8 بیت به کاراکتر — با چک برای جلوگیری از کرش
  for (int i = 0; i + 7 < arr.size(); i += 8) {
    string wholeByte = "";
    for (int j = 0; j < 8; j++)
      wholeByte += arr[i + j];

    bitset<8> bit(wholeByte);
    char character = static_cast<char>(bit.to_ulong());

    word += character;
  }

  cout << "Text : " << word << "\n";
}
int main() {
  // Define variables
  string data;
  string address;
  cout << "Enter .Json file address:" << "\n";
  getline(cin, address);
  // Open .Json file
  ifstream MyFile(address);

  if (!MyFile.is_open()) {
    cout << "Cant't open file!" << endl;
    return 1;
  }
  // Read whole file
  while (getline(MyFile, data)) {
    if (data.find("dataBase64") != string::npos) {
      editData(data);
      cout << data << endl;
      decodeBase64(data);
    }
  }
  // Close .Json file
  MyFile.close();
}
