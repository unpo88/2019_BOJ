#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	bool visited[31] = { false, };
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		visited[num] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!visited[i])
			cout << i << "\n";
	}

	return 0;
}