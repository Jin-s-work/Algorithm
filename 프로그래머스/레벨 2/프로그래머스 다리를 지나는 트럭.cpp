#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int idx = 0;
    int sum = 0;
    queue<int>q;
    
    while(1){
        
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;      // 마지막일 경우 마지막 트럭이 지나는 시간을 더해준다.
        }
        
        answer++;
        
        int num = truck_weights[idx];
        
        if(q.size() == bridge_length){
            sum -= q.front();
            // 다 건넜으므로, 현재 다리에 있는 차들의 무게에서 뺀다.
            // 차면 빼주는 것
            q.pop();
        }
        // sum은 다리에 찬 무게를 의미한다.
        
        if(sum + num <= weight){        // 다리의 무게보다 작을 경우
            sum += num;
            q.push(num);
            idx++;
            // 무게가 작을 경우에는 차량의 무게를 sum에 추가하고
            // queue에도 넣어준다.
            // 인덱스도 이동한다.
        }
        else{
            q.push(0);
            // 들어갈 수가 없다면 0을 넣어서 시간을 계산한다.
        }
        
        
        
    }
    
    
    return answer;
}
