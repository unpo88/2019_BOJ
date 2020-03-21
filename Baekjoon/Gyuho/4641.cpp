#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		int num;
		int visited[201] = { 0, };
		for (int i = 0; i <= 15; i++) {
			cin >> num;

			if (num == -1) {
				return 0;
			}

			if (num == 0) {
				break;
			}

			visited[num]++;
			visited[num * 2]++;
		}

		int cnt = 0;
		for (int i = 1; i <= 200; i++) {
			if (visited[i] == 2) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}