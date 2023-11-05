#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

bool cmp(const int a, const int b) {
    return a > b;
}
void marathonRanking(vector<long long> ranking, vector<int> scores)
{
    sort(ranking.begin(), ranking.end(), cmp);
    int n1 = ranking.size();
    int n2 = scores.size();

    vector<long long> cpRanking;
    vector<int> cpScores;

    for (int i = 0; i < n2; i++) {
        cpScores.push_back(scores[n2 - 1 - i]);
    }

    cpRanking.push_back(ranking[0]);
    for (int i = 1; i < n1; i++) {
        if (ranking[i] == ranking[i-1]) {
            continue;
        }
        else {
            cpRanking.push_back(ranking[i]);
        }
    }

    n1 = cpRanking.size();

    cout << "n1  = " << n1 << ", n2 = " << n2 << endl;
    int i = 0, j = 0, rank = 2;
    while(i < n1 && j < n2) {
        
        if (cpRanking[i] <= cpScores[j]) {
            rank--;
            ans.push_back(rank);
            //if (cpScores[j] != cpScores[j-1]) {
                rank++;
            //}
            j++;
        }
        else {
            i++;
            rank++;
        }
        
    }

    cout << "i = " << i << ", j = " << j << endl;
    rank = n1 + 1;
    while(j < n2) {
        ans.push_back(rank);
        j++;
    }
}

int main() {
    vector<long long> ranking;
    vector<int> scores;
    //ranking = {100, 100, 50, 40, 40, 20, 10}; scores = {5, 25, 50, 120};
    //ranking = {100, 90, 90, 80, 75, 60}; scores = {50, 65, 77, 90, 102};
    //ranking = {60,317,208,67,43,292,393,380,160,213}; scores = {264,287,318,370,900};
    ranking = {501,648,281,108,43,221,700,942,606,488,978,211,164,289,122};
    scores = {6,40,74,139,146,148,149,170,173,215,236,261,285,285,295,326,363,379,488,4930};
    marathonRanking(ranking, scores);
    
    cout << endl;
    int size = ans.size();
    for (int i = size - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}