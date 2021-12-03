

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int ranking(int n){
    if(n == 6)
        return 1;
    else if(n == 5)
        return 2;
    else if(n == 4)
        return 3;
    else if(n == 3)
        return 4;
    else if(n == 2)
        return 5;
    else if(n == 1 || n == 0)
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int same = 0;
    int zero = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0)
            zero++;
        
        for(int j=0;j<win_nums.size();j++){
            if(lottos[i] == win_nums[j])
                same++;
        }
    }
    
    for(int i=1;i<=6;i++){
        if(zero == i){
                answer.push_back(ranking(same));
                answer.push_back(ranking(same+i));
        }
    }
    
    if(zero == 0){
        answer.push_back(ranking(same));
        answer.push_back(ranking(same));
    }
    
    
    sort(answer.begin(), answer.end());
    
    
    return answer;
}

// 혼자 어찌어찌 해보는 중..
// 끙끙 풀었는데 처음에 이상하게 생각해서 필요도 없는 예외 케이스를 제거 하였다..
// 효율성이 없어서 쉽게 푼거 같은데 그런 것도 했으면 먼가 애매 했을 듯..
// 쓸데 없이 생각 더 했다가 이상해졌군













