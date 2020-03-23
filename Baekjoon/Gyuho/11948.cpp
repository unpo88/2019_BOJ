#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> v(4);
	vector<int> v2(2);

	cin >> v[0] >> v[1] >> v[2] >> v[3];
	cin >> v2[0] >> v2[1];

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	cout << v[3] + v[2] + v[1] + v2[1];

}