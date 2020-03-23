#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> arr(21);
	for (int i = 1; i <= 20; i++)
		arr[i] = i;
	for (int i = 0; i < 10; i++) {
		int b, e;
		cin >> b >> e;
		reverse(arr.begin() + b, arr.begin() + e + 1);
	}
	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}