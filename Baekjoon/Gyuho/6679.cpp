#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int ret_ten, ret_twe, ret_hex;
	for (int i = 1000; i <= 9999; i++) {
		ret_ten = 0, ret_twe = 0, ret_hex = 0;

		for (int n = i; n > 0; n /= 10) {
			ret_ten += n % 10;
		}

		for (int n = i; n > 0; n /= 12) {
			ret_twe += n % 12;
		}

		for (int n = i; n > 0; n /= 16) {
			ret_hex += n % 16;
		}

		if (ret_ten == ret_twe && ret_twe == ret_hex) {
			cout << i << "\n";
		}
	}

	return 0;
}