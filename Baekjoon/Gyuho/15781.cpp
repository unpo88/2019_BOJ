#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		answer = max(answer, num);
	}

	int answer2 = 0;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		answer2 = max(answer2, num);
	}

	cout << answer + answer2;
	return 0;
}