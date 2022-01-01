using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long total=0;
    
    for(int i=1;i<=count;++i){
        total+=i*price;
    }
    
    if(total<money)
        answer=0;
    else
        answer=total-money;
    
    return answer;
}
