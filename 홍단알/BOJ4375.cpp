/*
	BOJ4375
	<1>
	문제
	2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main () {
	int N;

	while (cin>>N) {
		int ans = 1;
		int count = 1;
		while (1) {
				if (ans % N == 0)
					break;
				ans = ((ans * 10) + 1) % N;
				count++;
		}
		cout << count << '\n';
	}
	return 0;
}
