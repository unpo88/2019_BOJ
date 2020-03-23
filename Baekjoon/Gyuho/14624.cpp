#include <iostream>
using namespace std;

void star(int a, int b)

{
	if (a == -1) return;
	for (int i = 0; i < a; i++)
		cout << " ";
	cout << "*";
	for (int i = 0; i < b; i++)
		cout << " ";
	cout << "*\n";
	star(a - 1, b + 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int mid = N / 2;
	if (N % 2 != 0) {
		for (int i = 0; i < N; i++)
			cout << "*";
		cout << "\n";
		for (int i = 0; i < mid; i++)
			cout << " ";
		cout << "*\n";

		star(mid - 1, 1);
	}
	else {
		cout << "I LOVE CBNU";
	}

	return 0;
}