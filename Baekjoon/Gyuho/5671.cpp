#include <iostream>
#include <cstdio>
using namespace std;

bool isCheck[5001] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 1; i <= 5000; i++) {
		int visited[10] = { false, };
		bool flag = true;

		int temp = i;
		while (temp) {
			visited[temp % 10]++;
			temp /= 10;
		}

		for (int i = 0; i < 10; i++) {
			if (visited[i] > 1) {
				flag = false;
			}
		}

		if (flag) {
			isCheck[i] = true;
		}
	}

	while (1) {
		int N, M;
		if (scanf("%d%d", &N, &M) == -1) break;
		
		int cnt = 0;
		for (int i = N; i <= M; i++) {
			if (isCheck[i]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}