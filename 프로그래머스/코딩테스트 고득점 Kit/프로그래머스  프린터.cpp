#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // 이중포문을 쓰면 시간 복잡도가 늘어나니 우선순위 큐 사용
    // 애초에 변수부터가 우선순위다.
    queue<pair<int, int>> q;
    priority_queue<int>pq;
    
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        if(q.front().first == pq.top()){  // 즉 제일 우선순위가 큰 부분이 나왔을 경우
            if(q.front().second == location){   // 구하는 위치에 있을 경우
                return ++answer;        // 인덱스의 값이 0부터라 먼저 1을 더해줘야한다.
            }
            else{                       // 문제에서 요구하는 location은 아닌 경우
                answer++;
                q.pop();
                pq.pop();               // location이 아니더라도 제일 큰건 맞으니 넘어가기
            }
        }
        else{
            q.push(q.front());
            q.pop();                    // 작으므로 아직 아니니까 다음에 넣어다 줌
        }
        
    }
    
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> priorities, int location) {
//     int answer = 0;
        
//     queue<pair<int, int>>q;
//     priority_queue<int>pq;
    
//     for(int i=0;i<priorities.size();i++){
//         q.push({priorities[i], i});
//         pq.push(priorities[i]);
//     }
    
//     while(!q.empty()){
//         if(q.front().first == pq.top()){
//             if(q.front().second == location)
//                 return ++answer;        // location과 같을 경우 처음은 0이기에
//                                         // ++answer로 해주고 return
//             else{
//                 answer++;
//                 q.pop();
//                 pq.pop();
//             }
//         }
//         else{
//             q.push(q.front());
//             q.pop();            // q가 중요도가 큰 부분이 아닐 경우 제일 뒤로 넣어주고
//                                 // pop
//         }
        
//     }
    
//     // 어려워보이지만, 우선순위 큐를 이용하면 쉽게 할 수 있는 구조
    
//     return answer;
// }
