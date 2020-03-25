#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int day;
	int month;
	int year;
};

Student s[101];

bool cmp(Student &a, Student &b) {
	return a.year != b.year ? a.year > b.year : a.month != b.month ? a.month > b.month : a.day > b.day;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].day >> s[i].month >> s[i].year;
	}

	sort(s, s + n, cmp);

	cout << s[0].name << "\n";
	cout << s[n-1].name << "\n";
	return 0;
}