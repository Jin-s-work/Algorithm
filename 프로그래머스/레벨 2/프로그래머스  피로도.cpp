

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    // 다른 방법도 있겠지만 조합으로 다 확인 해도 될듯..?
    
    vector<int>v;
    for(int i=0;i<dungeons.size();i++){
        v.push_back(i);
    }
    do{
        int num = k;
        int cnt = 0;
        
        for(int i=0;i<v.size();i++){
            int first = dungeons[v[i]][0];
            int second = dungeons[v[i]][1];
            // permutationd으로 돌아감에 따라 하나씩 해줌
            
            if(num < first)
                continue;
            
            num -= second;
            cnt++;
            
        }
        answer = max(answer, cnt);
        
    }while(next_permutation(v.begin(), v.end()));
    
    
    
    return answer;
}













