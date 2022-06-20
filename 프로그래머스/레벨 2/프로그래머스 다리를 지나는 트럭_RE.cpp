#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int>q;
    int sum = 0;    // 다리에 있는 총 무게
    int idx = 0;    // 시간을 알려줌
    int num = 0;
    
    while(1){
        
        if(idx == truck_weights.size()){ // idx가 총 트럭의 사이즈와 같아 졌을때
            answer += bridge_length;     // 마지막에 지나는 게 남아있으므로 그만큼을 더해줌
            break;                       // 그리고 끝
        }
        
        answer++;
        
        num = truck_weights[idx];       // num은 트럭들을 지칭함
        
        if(q.size() == bridge_length){
            sum -= q.front();       // 제일 앞의 다 건넌 트럭 빼주기
            q.pop();
        }
        // q의 사이즈는 트럭이 있는 경우도 지칭 하지만 시간도 넣어주었기 때문에 다 건넌 경우도 의미
        // 0일 경우에도 진행 되지만 영향을 안주므로 신경 안써도 된다.
        
        if(sum + num <= weight){        // 다음 트럭이 건널 수 있을 때
            sum += num;                 // 다리의 무게를 늘려주고
            q.push(num);                // 큐에 다리에 있는 차를 넣어주고
            idx++;                      // 시간 증가
        }
        else{                           // 못 건넌다고 해도 0을 넣어 시간을 나타내줌
            q.push(0);                  // 허수지만 개수를 넣어 시간을 표시해주는 역할
        }
        
    }
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <queue>
// #include <stack>

// using namespace std;

// int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     int answer = 0;
    
//     int idx = 0;
//     int sum = 0;
//     queue<int>q;
    
//     while(1){
        
//         if(idx == truck_weights.size()){
//             answer += bridge_length;
//             break;      // 마지막일 경우 마지막 트럭이 지나는 시간을 더해준다.
//         }
        
//         answer++;
        
//         int num = truck_weights[idx];
        
//         if(q.size() == bridge_length){
//             sum -= q.front();
//             // 다 건넜으므로, 현재 다리에 있는 차들의 무게에서 뺀다.
//             // 차면 빼주는 것
//             q.pop();
//         }
//         // sum은 다리에 찬 무게를 의미한다.
        
//         if(sum + num <= weight){        // 다리의 무게보다 작을 경우
//             sum += num;
//             q.push(num);
//             idx++;
//             // 무게가 작을 경우에는 차량의 무게를 sum에 추가하고
//             // queue에도 넣어준다.
//             // 인덱스도 이동한다.
//         }
//         else{
//             q.push(0);
//             // 들어갈 수가 없다면 0을 넣어서 시간을 계산한다.
//         }
        
        
        
//     }
    
    
//     return answer;
// }
