#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	char a[101];

	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		answer += int(a[i] - 64);
	}

	cout << answer << "\n";
	

	return 0;
}