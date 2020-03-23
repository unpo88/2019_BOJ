#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	char map[11][11] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}