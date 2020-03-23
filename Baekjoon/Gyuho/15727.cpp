#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int L;
	cin >> L;

	int cnt = L / 5;
	
	if (L % 5 != 0) {
		cnt++;
	}

	cout << cnt;
	return 0;
}