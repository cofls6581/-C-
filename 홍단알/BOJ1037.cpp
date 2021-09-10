/*
	BOJ1037
	<약수>
	문제
	양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int totalN;
	cin >> totalN;
	int* div = new int[totalN];
	for (int i = 0; i < totalN; i++) 
		cin >> div[i];
	sort(div, div + totalN);
	cout << div[0] * div[totalN - 1];
	return 0;
}
