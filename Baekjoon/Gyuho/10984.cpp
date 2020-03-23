#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int test_case;
	cin >> test_case;

	cout << fixed;
	cout.precision(1);

	for (int i = 0; i < test_case; i++) {
		int N;
		cin >> N;

		int sumC = 0;
		double sumG = 0.0;

		for (int i = 0; i < N; i++) {
			int c;
			double g;
			cin >> c >> g;
			sumC += c;
			sumG += (c*g);
		}

		printf("%d %.1f\n", sumC, round(10 * sumG / sumC) / 10);
	}
	
	return 0;
}