#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

typedef struct UserLog {
    int id;
    int timeAt;
} UserLog;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(0);
    }        
    vector<UserLog> listUserLogs;
    
    for (int i = 0; i < logs.length(); i++) {
        UserLog userLog;
        userLog.id = 
    }
}
int main() {

    return 0;
}