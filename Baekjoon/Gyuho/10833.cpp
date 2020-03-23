#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	int student, apple;
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> student >> apple;
		sum += apple%student;
	}
	cout << sum << '\n';

	
	return 0;
}