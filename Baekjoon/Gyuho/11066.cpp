#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		cout << 2 * M - N << " " << M - (2 * M - N) << "\n";
	}

	return 0;
}