#include <iostream>
#include <ostream>
#include <string>

using namespace std;

const string maxInt = "2147483647";
const string minInt = "-2147483648";

bool isLessMaxInt(string value) {
    if (value.size() > maxInt.size()) return false;
    if (value.size() < maxInt.size()) return true;
    for (int i = 0; i < value.size(); i++) {
        int val = int(value[i]);
        int valMaxInt = int(maxInt[i]);
        if (val > valMaxInt) return false;
        else if (val < valMaxInt) return true;
    }
    return true;
}

bool isGreaterMinInt(string value) {
    if (value.size() > minInt.size()) return false;
    if (value.size() < minInt.size()) return true;
    for (int i = 1; i < value.size(); i++) {
        int val = int(value[i]);
        int valMinInt = int(minInt[i]);
        if (val > valMinInt) return false;
        else if (val < valMinInt) return true;
    }
    return true;
}

int strToInt (string str) {
    int intValue, result = 0;
    bool isNegative = false;
    if (str.size() == 0) return 0;
    int i = 0;
    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    }
    while (i < str.size()) {
        intValue = str[i] - '0';
        result = result * 10 + intValue;
        i++;
    }
    if (isNegative) {
        return 0 - result;
    }
    return result;
};

int reverse(int x) {
    string valueString = to_string(x);
    int len = valueString.size();
    if (len == 0) return 0;
    int i = len - 1;
    while(i >= 0) {
        if (valueString[i] !=  '0') break;
        i--;
    }
    string reverseString = "";
    while(i >= 1) {
        reverseString += valueString[i];
        i--;
    } 
    cout << "reverseString: " << reverseString << endl;
    if (valueString[0] == '-') {
        reverseString = "-" + reverseString;
        cout << "reverseString: " << reverseString << endl;
        if (!isGreaterMinInt(reverseString)) return 0;
        return strToInt(reverseString);
    }  
    else {
        reverseString =  reverseString + valueString[0];
        cout << "reverseString: " << reverseString << endl;
        if (!isLessMaxInt(reverseString)) return 0;
        return strToInt(reverseString);
    }
};

int main() {
    // int x = 123;
    // int x = 120;
    // int x = -123;
    // int x = 0;
    // int x = 1;
    // int x  = 1534236469;
    // int x = -2147483648;
    // int x = -1563847412;
    int x = -2147483412;
    // int x = 2147483647;
    
    
    // int valueMin = pow(2, 31) - 1;
    // int valueMax = 0 - pow(2, 31);
    // cout << "valueMin: " << valueMin << ", valueMax: " << valueMax << endl;
    cout << reverse(x) << endl;
    return 0;
}