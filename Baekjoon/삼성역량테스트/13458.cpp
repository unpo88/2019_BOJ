// 1. ������ �����忡 �Ѱ������� ���� 1��
// 2. �ΰ������� ������
// 3. �����帶�� ���û����� ��� �����ؾ��Ѵ�.
// 4. ������ ���� �ּҰ�

#include <iostream>
using namespace std;

const int MAX = 1000000;

int N; //���� ��

int A[MAX]; //���� �� �л� ��

int B, C; //�Ѱ�����, �ΰ�����

long long minSupervisor(void) {
	long long total = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B; //�Ѱ������� ������ �� �ִ� �л� ����ŭ ����
		total++;
		//���� �л����� ����� �ΰ������� �����ؾ��ϴ°�
		if (A[i] > 0)
			total += (A[i] % C == 0) ? (A[i] / C) : (A[i] / C + 1);
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> B >> C;
	
	cout << minSupervisor() << endl;

	return 0;
}