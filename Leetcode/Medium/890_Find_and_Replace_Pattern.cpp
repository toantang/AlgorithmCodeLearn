/// Passed
#include <bits/stdc++.h>

using namespace std;

bool isMapped(string word, string pattern) {
    int a[300];
    for (int i = 0; i < 300; i++) {
        a[i] = -1;
    }
    int len = word.size();
    for (int i = 0; i < len; i++) {
        char w = word[i];
        char p = pattern[i];
        if (a[w] == -1) {
            a[w] = p;
        }
        else {
            if (a[w] != p) {
                return false;
            }
        }
        for (int j = 0; j < 300; j++) {
            if (a[j] == a[w] && w != j) return false;
        }
    }
    return true;
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> v = {};
    int len = words.size();
    for (int i = 0; i < len; i++) {
        string word = words[i];
        if (isMapped(word, pattern)) {
            v.push_back(word);
        }
    }
    return v;
}

int main() {
    vector<string> words;
    string pattern = "";
    //words = {"abc","deq","mee","aqq","dkd","ccc"}, pattern = "abb";
    words = {"a","b","c"}, pattern = "a";
    vector<string> v = findAndReplacePattern(words, pattern);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    return 0;
}