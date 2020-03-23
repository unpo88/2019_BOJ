#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int V, E;
		cin >> V >> E;
		cout << 2 - V + E << "\n";
	}

	return 0;
}