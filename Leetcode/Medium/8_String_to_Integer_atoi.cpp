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
    return false;
}

int strToInt (string str) {
    int intValue, result = 0;
    bool isNegative = false;
    if (str.size() == 0) return 0;
    int i = 0;
    if (str[0] == '-') 
        isNegative = true;
        i = 1;
    }
    while(i < str.size()) {
        if (str[i] != '0') break;
        i++;
    }
    cout << "i: " << i << endl;
    while (i < str.size()) {
        intValue = str[i] - '0';
        result = result * 10 + intValue;
        i++;`
    }
    cout << "result: " << result << endl;
    if (isNegative) {
        return 0 - result;
    }
    return result;
};

int myAtoi(string s) {
    string numString = "";
    bool isAddingNumber = false;
    int i = 0;
    while(i < s.size()) {
        if (s[i] != ' ') break;;
        i++;
    }

    while(i < s.size()) {
        // cout << "s[" << i << "]: " << s[i] << endl;
        if (s[i] < 48 || s[i] > 57) {
            if (i == s.size() - 1) break;
            if (isAddingNumber) break;
            if (s[i] != '+' && s[i] != '-') break;
            if (s[i + 1] < 48 || s[i + 1] > 57) break;
        }
        if (s[i] != '+') {
            isAddingNumber = true;
            numString += s[i];
        }
        i++;
    }
    
    if (numString.size() == 0) return 0;

    string numStringNoZero = "";
    int k = 0;
    if (numString[0] == '-') {
        numStringNoZero = '-';
        k = 1;
    }
    while(k < numString.size()) {
        if (numString[k] != '0') break;
        k++;
    }

    while(k < numString.size()) {
        numStringNoZero += numString[k];
        k++;
    }

    if (numStringNoZero[0] == '-') {
        cout << "numStringNoZero: " << numStringNoZero << endl;
        if (!isGreaterMinInt(numStringNoZero)) return -2147483648;
        return strToInt(numStringNoZero);
    }  
    else {
        if (!isLessMaxInt(numStringNoZero)) return 2147483647;
        return strToInt(numStringNoZero);
    }
}

int main() {
    string s;
    s = "words and 987";
    // s = "   24496-42-67bn";
    s = "   -42";
    // s = "3.14159";
    s = "00000-42a1234";
    s = "  0000000000012345678";
    s = "-2147483648";
    cout << myAtoi(s) << endl;;
    return 0;
}