#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to validate if a given string represents a valid IP segment
bool isValidSegment(const string& segment) {
    if (segment.empty() || segment.size() > 3 || (segment[0] == '0' && segment.size() > 1))
        return false;
    int value = stoi(segment);
    return value >= 0 && value <= 255;
}

// Recursive function to generate all valid IP addresses
void generateIPAddresses(vector<string>& result, const string& givenString, int index, int count, string ipAddress) {
    // If we have processed all the digits and formed 4 segments
    if (index == givenString.size() && count == 4) {
        ipAddress.pop_back(); // Remove the last dot
        result.push_back(ipAddress); // Add the formed IP address to the result
        return;
    }

    // If we have processed all the digits but haven't formed 4 segments yet
    if (index == givenString.size() || count == 4)
        return;

    // Try adding 1 digit as a segment
    string segment1 = givenString.substr(index, 1);
    if (isValidSegment(segment1)) {
        generateIPAddresses(result, givenString, index + 1, count + 1, ipAddress + segment1 + '.');
    }

    // Try adding 2 digits as a segment
    if (index + 1 < givenString.size()) {
        string segment2 = givenString.substr(index, 2);
        if (isValidSegment(segment2)) {
            generateIPAddresses(result, givenString, index + 2, count + 1, ipAddress + segment2 + '.');
        }
    }

    // Try adding 3 digits as a segment
    if (index + 2 < givenString.size()) {
        string segment3 = givenString.substr(index, 3);
        if (isValidSegment(segment3)) {
            generateIPAddresses(result, givenString, index + 3, count + 1, ipAddress + segment3 + '.');
        }
    }
}

int main() {
    string givenString = "11211";
    vector<string> result;
    generateIPAddresses(result, givenString, 0, 0, "");
    if (result.empty()) {
        cout << "-1\n";
    }
    else {
        for (const string& ip : result) {
            cout << ip << "\n";
        }
    }
    return 0;
}
