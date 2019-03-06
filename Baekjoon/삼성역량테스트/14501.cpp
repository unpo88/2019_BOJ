#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[2][16];

int DFS(int idx) {
	if (input[0][idx] + idx > N + 1) return 0;

	int result = input[1][idx];
	int sum = 0;
	for (int i = idx + input[0][idx]; i <= N; i++) {
		sum = max(sum, DFS(i));
	}

	return result + sum;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> input[0][i] >> input[1][i];
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, DFS(i));
	}

	cout << answer << endl;

	return 0;
}