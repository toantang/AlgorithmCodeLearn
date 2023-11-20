#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	vector<int> ans(size(queries));
	for(int i = 0; i < size(queries); i++){
		int x = queries[i][0], y = queries[i][1], r = queries[i][2];
		for(int j = 0; j < size(points); j++){
			if((x - points[j][0]) * (x - points[j][0]) + (y - points[j][1]) * (y - points[j][1]) <= r * r)    
				ans[i]++;
		}            
	}
	return ans;
}

int main() {
    vector<vector<int>> queries;
    vector<vector<int>> points;

    // points = {{1,3},{3,3},{5,3},{2,2}};
    // queries = {{2,3,1},{4,3,1},{1,1,2}};

    points = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    queries = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    
    vector<int> ans = countPoints(points, queries);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", ";
    }
    return 0;
}