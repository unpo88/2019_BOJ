#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int cnt[10] = { 0, };
	int N;

	cin >> N;

	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	cout << cnt[N];


	return 0;
}