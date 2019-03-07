// 	1일	2일	3일	4일	5일	6일	7일
// Ti	3	5	1	1	2	4	2
// Pi	10	20	10	20	15	40	200
// 1. 오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
// 2. 각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
// 3. 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
// 4. 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)
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