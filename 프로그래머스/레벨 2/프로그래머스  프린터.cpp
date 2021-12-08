

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
        
    queue<pair<int, int>>q;
    priority_queue<int>pq;
    
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        if(q.front().first == pq.top()){
            if(q.front().second == location)
                return ++answer;        // location과 같을 경우 처음은 0이기에
                                        // ++answer로 해주고 return
            else{
                answer++;
                q.pop();
                pq.pop();
            }
        }
        else{
            q.push(q.front());
            q.pop();            // q가 중요도가 큰 부분이 아닐 경우 제일 뒤로 넣어주고
                                // pop
        }
        
    }
    
    // 어려워보이지만, 우선순위 큐를 이용하면 쉽게 할 수 있는 구조
    
    return answer;
}


//
//queue<pair<int, int>>q;
//    priority_queue<int>pq;
//    int n = priorities.size();
//
//    for(int i=0;i<n;i++){
//        q.push(make_pair(i, priorities[i]));    // index와 값들을 q에
//        pq.push(priorities[i]);                 // 값들을 pq에
//    }
//
//    while(!q.empty()){
//        if(q.front().second == pq.top()){ // q의 맨 앞의 값과 pq의 top과 같을떄
//            if(q.front().first == location){    // index와 location과 같을떄
//                return ++answer;
//            }
//            else{       // location과 번호가 다를 경우
//                answer++;
//                q.pop();
//                pq.pop();
//            }
//        }
//        else{      // top과 second가 다를 떄 즉 맨 뒤로 넣어준다고 생각하면 됨
//            q.push(q.front());  // 앞에꺼를 빼서 넣어줌
//            q.pop();    // 그러고 제거
//        }
//
//    }
//








