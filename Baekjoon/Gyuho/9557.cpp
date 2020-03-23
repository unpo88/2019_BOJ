#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		int index = -1;
		cin >> N;
		vector<string> word;

		string input;
		for (int j = 0; j < N; j++) {
			cin >> input;
			word.push_back(input);

			if ('a' <= input[0] && input[0] <= 'z')
				index = j;
		}

		if (index != -1) {
			for (int j = index + 1; j < word.size(); j++) {
				cout << word[j].c_str() << " ";
			}
			cout << word[index].c_str() << " ";
			for (int j = 0; j < index; j++) {
				cout << word[j].c_str() << " ";
			}
			cout << "\n";
		}
		else {
			for (int j = 0; j < word.size(); j++){
				cout << word[j].c_str() << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}