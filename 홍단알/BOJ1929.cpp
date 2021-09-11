/*
	BOJ1929
	<소수 구하기>
	문제
	M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	bool* div = new bool[n + 1];
	for (int i = 2; i <= n; i++)
		div[i] = true;
	for (int i = 2; i * i <= n; i++) {
		if (div[i] == false) continue;
		for (int j = i + i; j <= n; j += i) {
			if (div[j] == false) continue;
			else div[j] = false;
		}
	}
	for (int i = m; i <= n; i++)
		if (div[i] == true) cout << i << '\n';
}
