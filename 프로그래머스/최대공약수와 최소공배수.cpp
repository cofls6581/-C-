#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a=n; int b=m;
    while(b!=0){
		int c= a%b;
		a= b;
		b=c;
	}
    answer.push_back(a);
    int l=n*m/a;
    answer.push_back(l);
    return answer;
}
