#include <bits/stdc++.h>

using namespace std;

struct Character {
    int quantity;
    int score;
    char label;
    Character create(char label, int quantity, int score) {
        Character c;
        c.quantity = quantity;
        c.score = score;
        c.label = label;
        return c;
    }
    string toString() {
        string s = "";
        if (label != '~') s.push_back(label);
        return s + "(" + to_string(quantity) + ", " + to_string(score) + ")";
    }
    int totalScore() {
        return quantity * score;
    }
};

vector<Character> characters = {};
int ans = 0;
int f = 0;
int flag[15];
int scoreWords[15];
int totalRemaining = 0;
int totalScoreWords = 0;
int cnt = 0;

void createCharacter(vector<string>& words, vector<char>& letters, vector<int>& score) {
    for (int i = 0; i < 27; i++) {
        Character c;
        c = c.create('~', 0, 0);
        characters.push_back(c);
    }
    for (int i = 0; i < letters.size(); i++) {
        characters[letters[i] - 'a'].label = letters[i];
        characters[letters[i] - 'a'].quantity++;
    }

    for (int i = 0; i < characters.size(); i++) {
        characters[i].score = score[i];
    }

    // for (int i = 0; i < characters.size(); i++) {
    //     cout << characters[i].toString() << ", ";
    // }
    // cout << endl;
}

void createFlag(int n) {
    for (int i = 0; i < n; i++) {
        flag[i] = -1;
    }
}

void createScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < word.size(); j++) {
            scoreWords[i] += characters[word[j] - 'a'].score;
        }
    }
    for (int i = 0; i < words.size(); i++) {
        cout << scoreWords[i] << ", ";
        totalScoreWords += scoreWords[i];
    }
    cout << endl;
}

void calTotalRemaining() {
    for (int i = 0; i < characters.size(); i++) {
        totalRemaining += characters[i].totalScore();
    }
}

void decrease(string word) {
    for (int i = 0; i < word.size(); i++) {
        //Character c = characters[word[i] - 'a'];
        characters[word[i] - 'a'].quantity--;
        totalRemaining -= characters[word[i] - 'a'].score;
    }
}

void increase(string word) {
    for (int i = 0; i < word.size(); i++) {
        //Character c = characters[word[i] - 'a'];
        characters[word[i] - 'a'].quantity++;
        totalRemaining += characters[word[i] - 'a'].score;
    }
}

bool isCanAdd(string word) {
    vector<Character> temp = {};
    for (int i = 0; i < 27; i++) {
        Character c;
        c = c.create('~', 0, 0);
        temp.push_back(c);
    }
    for (int i = 0; i < word.size(); i++) {
        Character c;
        temp[word[i] - 'a'].label = word[i];
        temp[word[i] - 'a'].quantity++;
    }
    
    for (int i = 0; i < word.size(); i++) {
        Character c = characters[word[i] - 'a'];
        if (c.quantity <= 0 || c.quantity < temp[word[i] - 'a'].quantity) return false;
    }

    return true;
}

void TRY(int i, int n, vector<string>& words, vector<char>& letters, vector<int>& score) {
    f = f + scoreWords[i];
    totalScoreWords -= scoreWords[i];
    flag[i] = 1;
    decrease(words[i]);

    cout << "f: " << f << ", totalRemaining: " << totalRemaining << endl;
    cnt++;
    if (f > ans) {
        ans = f;
    }

    for (int j = 0; j < n; j++) {
        if (flag[j] < 0 && isCanAdd(words[j]) && f + totalScoreWords > ans) {
            TRY(j, n, words, letters, score);
        }
    }

    increase(words[i]);
    f = f - scoreWords[i];
    totalScoreWords += scoreWords[i];
    flag[i] = -1;
}

int main() {
    vector<string> words;
    vector<char> letters;
    vector<int> score;
    // words = {"dog","cat","dad","good"}, letters = {'a','a','c','d','d','d','g','o','o'}, score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    //words = {"leetcode"}, letters = {'l','e','t','c','o','d'}, score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    words = { "daeagfh","acchggghfg","feggd","fhdch","dbgadcchfg","b","db","fgchfe","baaedddc"}, letters = { 'a','a','a','a','a','a','a','b','b','b','b',
    'b','b','b','b','b','c','c','c','c','c','c','c','c','c','c','c','d','d','d','d','d','d','d','d','d','d','d','d','d','d','e','e','e','e','e','e','e',
    'e','e','e','f','f','f','f','f','f','f','f','f','f','f','f','f','f','g','g','g','g','g','g','g','g','g','g','g','g','h','h','h','h','h','h','h','h',
    'h','h','h','h','h'}, score = { 2,1,9,2,10,5,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //words = {"xxxz","ax","bx","cx"}, letters = {'z','a','b','c','x','x','x'}, score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    int n = words.size();
    createCharacter(words, letters, score);
    createFlag(n);
    createScoreWords(words, letters, score);
    calTotalRemaining();
    cout << "total remaining: " << totalRemaining << endl;
    for (int i = 0; i < n; i++) {
        if (flag[i] < 0 && isCanAdd(words[i])) {
            TRY(i, n, words, letters, score);
        }
    }
    cout << "cnt: " << cnt << endl;
    cout << "ans: " << ans << endl; 
}