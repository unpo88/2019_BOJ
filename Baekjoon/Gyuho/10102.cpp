#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int V;
	cin >> V;

	char score;
	int cnt = 0;
	for (int i = 0; i < V; i++) {
		cin >> score;
		if (score == 'A') {
			cnt++;
		}
		else if(score == 'B') {
			cnt--;
		}
	}

	if (cnt > 0) {
		cout << "A";
	}
	else if (cnt == 0) {
		cout << "Tie";
	}
	else {
		cout << "B";
	}

	return 0;
}