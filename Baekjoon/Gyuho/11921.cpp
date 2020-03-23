#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	int sum = 0;

	cin >> N;
	cout << N << "\n";
	while (N--) {
		int M;
		cin >> M;
		sum += M;
	} 

	cout << sum;
}