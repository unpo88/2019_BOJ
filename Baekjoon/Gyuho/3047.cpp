#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> v;

	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	char a[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		if (a[i] == 'A')	cout << v[0] << " ";
		if (a[i] == 'B')	cout << v[1] << " ";
		if (a[i] == 'C')	cout << v[2] << " ";
	}

	return 0;
}