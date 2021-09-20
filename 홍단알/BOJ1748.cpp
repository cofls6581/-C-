/*
	BOJ1748
	<수 이어 쓰기 1>
	문제
	1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int len = 0,temp=n;
	while (temp > 0) {
		temp /= 10;
		++len;
	}
	if (len == 1) {
		cout << n << '\n';
		return 0;
	}
	int ans = 0;
	for (int i = 1; i < len; i++) 
		ans += i * (9 * pow(10, i - 1));
	ans += len * (n - pow(10, len - 1)+1);
	cout << ans << '\n';
	return 0;
}
