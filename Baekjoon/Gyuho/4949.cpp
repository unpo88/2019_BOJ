#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		string s;
		getline(cin, s);

		stack<char> st;

		if (s.length() == 1 && s[0] == '.') {
			break;
		}

		bool flag = true;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') {
				st.push('(');
			}
			else if (s[j] == '[') {
				st.push('[');
			}
			else if (s[j] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (s[j] == ')') {
				if (!st.empty() && st.top() == '('){
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag && st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	
	return 0;
}