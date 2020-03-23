#include <iostream>
using namespace std;

int q1, q2, q3, q4, ax, x, y, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		if (x == 0 || y == 0) { ax++; }
		else if (x > 0 && y > 0)
			q1++;
		else if (x < 0 && y>0)
			q2++;
		else if (x < 0 && y < 0)
			q3++;
		else if (x > 0 && y < 0)
			q4++;
	}
	cout << "Q1: " << q1 << '\n';
	cout << "Q2: " << q2 << '\n';
	cout << "Q3: " << q3 << '\n';
	cout << "Q4: " << q4 << '\n';
	cout << "AXIS: " << ax << '\n';


	return 0;
}