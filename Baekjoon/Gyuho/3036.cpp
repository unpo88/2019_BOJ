#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int ring[101];

	for (int i = 0; i < N; i++) {
		cin >> ring[i];
	}

	int g;
	for (int i = 1; i < N; i++) {
		if (ring[0] > ring[i]) {
			g = gcd(ring[0], ring[i]);
		}
		else
		{
			g = gcd(ring[i], ring[0]);
		}
		cout << ring[0] / g << "/" << ring[i] / g << "\n";;
	}

	return 0;
}