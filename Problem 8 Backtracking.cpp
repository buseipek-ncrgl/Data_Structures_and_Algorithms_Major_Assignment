#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PROBLEM 8: BACKTRACKING

void GetAllValidIpAddress(vector<string>& result, string givenString, int index,
    int count, string ipAddress) {

    if (givenString.size() == index && count == 4) {
        ipAddress.pop_back();
        result.push_back(ipAddress);
        return;
    }

    if (givenString.size() < index + 1)
        return;

    ipAddress = ipAddress + givenString.substr(index, 1) + '.';
    GetAllValidIpAddress(result, givenString, index + 1, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 2, ipAddress.end());
    if (givenString.size() < index + 2 || givenString[index] == '0')
        return;

    ipAddress = ipAddress + givenString.substr(index, 2) + '.';
    GetAllValidIpAddress(result, givenString, index + 2, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 3, ipAddress.end());
    if (givenString.size() < index + 3 || stoi(givenString.substr(index, 3)) > 255)
        return;

    ipAddress += givenString.substr(index, 3) + '.'; 
    GetAllValidIpAddress(result, givenString, index + 3, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 4, ipAddress.end());
}

int main() {
    string givenString = "11211";
    vector<string> result;
    GetAllValidIpAddress(result, givenString, 0, 0, "");
    if (result.empty()) {
        cout << "-1\n";
    }
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "\n";
        }
    }
    return 0;
}
