/*
	BOJ2609
	<최대공약수와 최소공배수>
	문제
	두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int temp = -1;
	int a = x, b = y;
	while (temp != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	cout << a << '\n' << x * y / a;
}
