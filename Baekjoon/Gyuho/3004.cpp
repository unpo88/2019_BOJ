#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	cout << (N / 2 + 1) * (N - N / 2 + 1);

	return 0;
}