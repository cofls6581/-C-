/*
	BOJ10866
	<덱>
	문제
	정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	int n, b;
	cin >> n;
	deque<int> d;

	while (n--) {
		cin >> a;
		if (a == "push_front") {
			cin >> b;
			d.push_front(b);
		}
		if (a == "push_back") {
			cin >> b;
			d.push_back(b);
		}
		if (a == "pop_front") {
			if (d.empty())
				cout << "-1\n";
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		if (a == "pop_back") {
			if (d.empty())
				cout << "-1\n";
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		if (a == "size") {
			cout << d.size() << '\n';
		}
		if (a == "empty") {
			cout << d.empty() << '\n';
		}
		if (a == "front") {
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.front() << '\n';
		}
		if (a == "back") {
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.back() << '\n';
		}
	}
}
