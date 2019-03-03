// 1. 각각의 시험장에 총감독관은 오직 1명
// 2. 부감독관은 여러명
// 3. 시험장마다 응시생들을 모두 감시해야한다.
// 4. 감독관 수의 최소값

#include <iostream>
using namespace std;

const int MAX = 1000000;

int N; //교실 수

int A[MAX]; //교실 당 학생 수

int B, C; //총감독관, 부감독관

long long minSupervisor(void) {
	long long total = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B; //총감독관이 감시할 수 있는 학생 수만큼 빼고
		total++;
		//남은 학생들을 몇명의 부감독관이 감시해야하는가
		if (A[i] > 0)
			total += (A[i] % C == 0) ? (A[i] / C) : (A[i] / C + 1);
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> B >> C;
	
	cout << minSupervisor() << endl;

	return 0;
}