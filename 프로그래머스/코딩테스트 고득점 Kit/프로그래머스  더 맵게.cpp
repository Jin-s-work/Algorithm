


#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> >pq;
    // 오름 차순
    
    
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    // 혼자 거의 다 해봤는데 효율성 점수가 너무 낮아서 K 이상으로 만들 수 없는 경우만 참고
    // 그래도 혼자 해보면서 우선순위 큐에 조금 더 익숙해졌다.
    
    while(pq.size() != 1 && pq.top() < K){      // 한개가 되면 끝
        int now = pq.top();                     // 안그러면 계속 해서 seg 에러 난듯
        pq.pop();
        int next = pq.top();
        pq.pop();
        
        int num = now + (next * 2);
        pq.push(num);
        answer++;
    }
    
    // 위에 과정을 했는데도 안넘는게 있으면 -1을 리턴
    if(pq.top() < K)
        return -1;
    

    return answer;
}




// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>

// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer = 0;
    
//     priority_queue<int, vector<int>, greater<int>>pq(scoville.begin(), scoville.end());
//     // 오름차순을 위한 우선순위 큐
//     // 이런 식으로 하면 우선 순위 큐에 벡터가 들어감
    
//     while(pq.size() > 1 && pq.top() < K){
//         // 개수가 2개 이상 이어야 하고, 제일 작은 수가 K보다 작을때만 해준다.
        
//         int one = pq.top();
//         pq.pop();
//         int two = pq.top();
//         pq.pop();
        
//         pq.push(one + (two * 2));
//         answer++;
        
//     }

//     if(pq.top() < K)
//         answer = -1;
//     // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없을때
//     // 즉, 하나라도 작으면 -1로 바꾼다.
    
//     return answer;
// }













