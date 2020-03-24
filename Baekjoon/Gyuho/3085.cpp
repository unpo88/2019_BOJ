#include <iostream>
#include <algorithm>
using namespace std;

int N;

char map[51][51];

int check() {
	int result = 1;

	for (int i = 0; i < N; i++) {
		int temp = 1;
		for (int j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j]) {
				temp++;
			}
			else {
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	for (int i = 0; i < N; i++) {
		int temp = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] == map[j + 1][i]) {
				temp++;
			}
			else {
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	return result;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(map[i][j], map[i][j + 1]);
			result = max(result, check());
			swap(map[i][j], map[i][j + 1]);

			swap(map[j][i], map[j + 1][i]);
			result = max(result, check());
			swap(map[j][i], map[j + 1][i]);
		}
	}

	cout << result << "\n";
}