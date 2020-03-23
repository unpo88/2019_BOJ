#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int factorial(int num) {
	if (num == 0)	return 1;

	int result = 1;

	for (int i = num; i >= 1; i--) {
		result *= i;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << factorial(N) / (factorial(K) * factorial(N - K));

	return 0;
}