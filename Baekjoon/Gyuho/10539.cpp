#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int A[101] = { 0, };
	int B[101] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		B[i] = B[i] * i;
		A[i] = B[i] - B[i - 1];
	}

	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}

	return 0;
}