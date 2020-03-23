#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	struct tm *t;
	string s = "";
	time_t timer;
	timer = time(NULL);

	t = localtime(&timer);
	s += to_string(t->tm_year + 1900);
	s += "-";
	if (t->tm_mon + 1 < 10) {
		s += "0";
	}
	s += to_string(t->tm_mon + 1);
	s += "-";
	if (t->tm_mday + 1 < 10) {
		s += "0";
	}
	s += to_string(t->tm_mday);

	cout << s << endl;

	return 0;
}