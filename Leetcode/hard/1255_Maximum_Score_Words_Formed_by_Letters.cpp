#include <bits/stdc++.h>

using namespace std;

static const int MAX_ALPHABET = 123;
int flag[MAX_ALPHABET];
int sign[15];
int scoreWords[15];
int maxScore = 0;
int ans = 0;

void createSign(int n) {
    for (int i = 0; i < n; i++) {
        sign[i] = -1;
    }
}

void createFlag(vector<char>& letters) {
    int len = letters.size();
    for (int i = 0; i < len; i++) {
        flag[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int x = letters[i];
        flag[x] = flag[x] + 1;
    }
    cout << "flag: ";
    for (int i = 97; i < MAX_ALPHABET; i++) {
        cout << flag[i] << ", ";
    }
    cout << endl;
}

void createScoreWords(vector<string>& words, vector<int>& score) {
    int len = words.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            char x = words[i][j];
            scoreWords[i] += score[x - 97];
        }
    }
    cout << "score words: ";
    for (int i = 0; i < len; i++) {
        cout << scoreWords[i] << ", ";
    }
    cout << endl;
}

void decreaseChar(string word) {
    for (int i = 0; i < word.size(); i++) {
        flag[word[i]]--;
    }
    // cout << "flag: ";
    // for (int i = 97; i < MAX_ALPHABET; i++) {
    //     cout << flag[i] << ", ";
    // }
    // cout << endl;
}

void increaseChar(string word) {
    for (int i = 0; i < word.size(); i++) {
        flag[word[i]]++;
    }
}

bool isCanAdd(string word) {
    int temp[MAX_ALPHABET];
    for (int i = 97; i < MAX_ALPHABET; i++) {
        temp[i] = 0;
    }
    
    cout << endl;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i];
        temp[index] = temp[index] + 1;
    }

    // cout << "temp: ";
    // for (int i = 97; i < MAX_ALPHABET; i++) {
    //     cout << temp[i] << ", ";
    // }
    for (int i = 97; i < MAX_ALPHABET; i++) {
        if (temp[i] > flag[i]) return false;
    }
    
    return true;
}

bool isCanGo(vector<char>& letters) {
    for (int i = 97; i < MAX_ALPHABET; i++) {
        
    }
}
void TRY(int i, int n, vector<string>& words) {
    maxScore = maxScore + scoreWords[i];
    decreaseChar(words[i]);
    sign[i] = 1;
    cout << "flag: ";
    for (int i = 97; i < MAX_ALPHABET; i++) {
        cout << flag[i] << ", ";
    }
    cout << "maxScore: " << maxScore << endl;
    if (maxScore > ans) {
        ans = maxScore;
        //cout << "ans: " << ans << endl;
    }

    for (int j = 0; j < n; j++) {
        bool isCan = isCanAdd(words[j]);
        
        if (sign[j] < 0 && isCan) {
            TRY(j, n, words);
        }
    }
    
    sign[i] = -1;
    increaseChar(words[i]);
    maxScore = maxScore - scoreWords[i];
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    return 0;
}

int main() {
    vector<string> words;
    vector<char> letters;
    vector<int> score;
    //words = {"dog","cat","dad","good"}, letters = {'a','a','c','d','d','d','g','o','o'}, score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    //words = {"leetcode"}, letters = {"l","e","t","c","o","d"}, score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    words = { "daeagfh","acchggghfg","feggd","fhdch","dbgadcchfg","b","db","fgchfe","baaedddc"}, letters = { 'a','a','a','a','a','a','a','b','b','b','b',
    'b','b','b','b','b','c','c','c','c','c','c','c','c','c','c','c','d','d','d','d','d','d','d','d','d','d','d','d','d','d','e','e','e','e','e','e','e',
    'e','e','e','f','f','f','f','f','f','f','f','f','f','f','f','f','f','g','g','g','g','g','g','g','g','g','g','g','g','h','h','h','h','h','h','h','h',
    'h','h','h','h','h'}, score = { 2,1,9,2,10,5,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int n = words.size();
    createFlag(letters);
    createScoreWords(words, score);
    createSign(n);
    for (int i = 0; i < n; i++) {
        if (sign[i] < 0 && isCanAdd(words[i])) {
            TRY(i, n, words);
        }
    }
    
    cout << "ans: " << ans << endl;
    return 0;
}