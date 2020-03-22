#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int K;
	cin >> K;
	while (K--) {
		int P, M;
		cin >> P >> M;

		bool visited[501] = { false, };

		int cnt = 0;
		for (int i = 0; i < P; i++) {
			int num;
			cin >> num;
			if (visited[num]) {
				cnt++;
			}
			else {
				visited[num] = true;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}