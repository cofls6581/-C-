#include <string>
#include <vector>

using namespace std;

int rankN(int count) {
    switch(count){
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;   
        default:
            return 6;
    }
}
    
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count=0,nZero=0,temp;
    int maxN,minN;
    
    for(int i=0;i<lottos.size();++i){
        if(!lottos[i]) {
            nZero++; 
            continue;
        }
        for(int j=0;j<lottos.size();++j){
            if(lottos[i]==win_nums[j]) {
                count++; 
                break;
            }
        }
    }
    
    temp=nZero+count;
    maxN=rankN(temp);
    minN=rankN(count);
    
    answer.push_back(maxN);
    answer.push_back(minN);
    
    return answer;
}
