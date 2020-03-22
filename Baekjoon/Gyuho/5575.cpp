#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int sh, sm, ss, eh, em, es;
		cin >> sh >> sm >> ss >> eh >> em >> es;
		if (es - ss < 0) { em -= 1, es = 60 + es - ss; }
		else { es = es - ss; }
		if (em - sm < 0) { eh -= 1, em = 60 + em - sm; }
		else { em = em - sm; }
		eh = eh - sh;
		cout << eh << " " << em << " " << es << '\n';
	}

	return 0;
}