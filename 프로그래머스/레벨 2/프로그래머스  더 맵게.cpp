














#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>>pq(scoville.begin(), scoville.end());
    // 오름차순으로 우선순위큐를 만든다.
    
    // 음식이 2개 이상이고, 제일 안 매운 음식이 K보다 작을 때까지 한다.
    while(pq.size() > 1 && pq.top() < K){
        int one = pq.top();
        pq.pop();
        
        int two = pq.top();
        pq.pop();
        
        pq.push(one + (two * 2));
        answer++;
    }
    
    // 다 하고, 제일 안 매운 음식이 K보다 작을 경우 -1 리턴
    if(pq.top() < K)
        return -1;
    
    
    return answer;
}
