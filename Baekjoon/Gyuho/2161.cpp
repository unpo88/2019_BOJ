#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		int first = q.front();
		cout << first << " ";
		q.pop();
		int second = q.front();
		q.pop();
		q.push(second);
	}

	int last = q.front();
	cout << last;
	return 0;
}