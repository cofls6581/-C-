#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector <int> isPrime[n]={1,};
    isPrime[0]=isPrime[1]=0;
    
    for(int i=2;i<sqrt(n);++i){
        if(isPrime[i]){
            for(int j=i+i;j<n;j+=i)
                isPrime[j]=0;
        }
    }
    
    for(int i=0;i<n;++i){
        if(isPrime[i]) answer++;
    }
    return answer;
}
