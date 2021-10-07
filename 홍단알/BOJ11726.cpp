/*
	BOJ11726
	<2×n 타일링>
	문제
	2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> v(n + 1);
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i <= n; ++i) 
		v[i] = (v[i - 1] + v[i - 2])%10007;
	cout << v[n];
	return 0;
}
