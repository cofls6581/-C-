/*
	BOJ1978
	<소수 찾기>
	문제
	주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int k;
	while (n != 0) {
		bool ans = true;
		cin >> k;
		if (k == 1) ans = false;
		for (int i = 2; i * i <= k; i++)
			if (k % i == 0) ans = false;
		if (ans == true) cnt++;
		n--;
	}
	cout << cnt;
}
