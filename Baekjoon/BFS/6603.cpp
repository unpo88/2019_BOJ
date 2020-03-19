#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		int k;
		cin >> k;

		if (k == 0) {
			return 0;
		}

		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}

		vector<int> v2;
		for (int i = 0; i < k - 6; i++) {
			v2.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			v2.push_back(1);
		}

		vector<vector<int>> ans;

		do {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (v2[i] == 1) {
					current.push_back(v[i]);
				}
			}
			ans.push_back(current);
		} while (next_permutation(v2.begin(), v2.end()));
		sort(ans.begin(), ans.end());

		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
	}

	return 0;
}