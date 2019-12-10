#include <iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
vector<vector<int>> result = {};
bool search(vector<int> candidates, vector <int> &v, int target) {
	int t = accumulate(v.begin(), v.end(), 0);
	if (t == target) {
		result.push_back(v);
		return true;
	}
	if (t > target) {
		return false;
	}
	
	for (int i = 0; i < candidates.size(); i++) {
		v.push_back(candidates[i]);
		search(candidates, v, target);
		v.pop_back();
	}

}

int main() {
	vector<int> c = {2,3,6,7};
	vector<int> v = {};
	search(c, v, 7);
	cout << "test";
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}