#include <bits/stdc++.h>

using namespace std;

static const int MAX_ALPHABET = 123;
int flag[MAX_ALPHABET];
int scoreWords[15];
int maxScore = 0;
int ans = 0;

void createFlag(vector<string>& letters) {
    int len = letters.size();
    for (int i = 0; i < len; i++) {
        flag[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int x = letters[i][0];
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
    cout << "flag: ";
    for (int i = 97; i < MAX_ALPHABET; i++) {
        cout << flag[i] << ", ";
    }
    cout << endl;
}

void increaseChar(string word) {
    for (int i = 0; i < word.size(); i++) {
        flag[word[i]]++;
    }
}

bool isCanAdd(string word) {
    for (int i = 0; i < word.size(); i++) {
        if (flag[i] <= 0) return false;
    }
    return true;
}

void TRY(int i, int n, vector<string>& words) {
    maxScore = maxScore + scoreWords[i];
    decreaseChar(words[i]);
    cout << "maxScore: " << maxScore << endl;

    if (maxScore > ans) {
        ans = maxScore;
        cout << "ans: " << ans << endl;
        //cout << "maxScore: " << maxScore << endl;
    }
    i = i + 1;
    if (i < n && isCanAdd(words[i])) {
        TRY(i+1, n, words);
    }

    i = i - 1;
    increaseChar(words[i]);
    maxScore = maxScore - scoreWords[i];
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    return 0;
}

int main() {
    vector<string> words;
    vector<string> letters;
    vector<int> score;
    words = {"dog","cat","dad","good"}, letters = {"a","a","c","d","d","d","g","o","o"}, score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    int n = words.size();
    createFlag(letters);
    createScoreWords(words, score);
    TRY(0, n, words);
    return 0;
}