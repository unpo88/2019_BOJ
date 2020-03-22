#include <iostream>
using namespace std;

int score[201][4] = { 0, };
int visited[201] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> score[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int k = 0; k < N; k++) {
				if (score[j][i] == score[k][i] && j != k) {
					cnt = 1;
					break;
				}
			}
			if (!cnt) {
				visited[j] += score[j][i];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << visited[i] << "\n";
	}
	return 0;
}