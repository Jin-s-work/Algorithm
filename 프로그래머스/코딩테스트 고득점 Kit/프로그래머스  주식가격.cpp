

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    
    // 이중 포문으로 하면 무조건 시간 초과가 날 줄 알았는데 여기서는 시간이 무제한인거 같기도 하다
    // 하지만 큐로 풀어보는 것이 좀 더 공부에 좋을 거 같아 큐로 품
    
    queue<int>q;
    
    for(int i=0;i<prices.size();i++){
        q.push(prices[i]);
    }
    
    int idx = 0;
    while(!q.empty()){
        
        int num = q.front();
        q.pop();
        idx++;
        // 하나씩 위치 옮기기
        int cnt = 0;
        for(int i=idx;i<prices.size();i++){   // idx는 이미 옮겨졌으므로 idx+1부터 가능
            if(num <= prices[i])
                cnt++;              // 다음께 이상이면 하나 증가시켜줌
            else{
                cnt++;              // 아니어도 시간은 지나므로 하나 증가시키고 끝
                break;
            }                       // 맨 마지막 경우에는 어차피 prices.size()와 같아서
        }                           // cnt가 안더해지고 0으로 끝난다.
        answer.push_back(cnt);
        
    }
    
    
    return answer;
}
















