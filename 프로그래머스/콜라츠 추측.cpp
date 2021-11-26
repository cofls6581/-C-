#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long tmp=(long long)num;
    while(tmp!=1){
        if(answer==500)
            return -1;
        if(tmp%2==0)
            tmp/=2;
        else 
            tmp=tmp*3+1;
        answer++;
    }
    return answer;
}
