#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int answer = (B + C) < (A + D) ? (B + C) : (A + D);

	cout << answer;
	return 0;
}