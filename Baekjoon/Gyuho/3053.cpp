#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int R;
	cin >> R;

	cout << fixed;
	cout.precision(6);

	cout << R * R * PI << "\n";

	cout << R * R * 2.0 << "\n";

	return 0;
}