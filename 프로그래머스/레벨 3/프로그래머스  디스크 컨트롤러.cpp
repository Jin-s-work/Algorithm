

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 문제를 풀떄 소요시간이 짧은 것부터 처리하면 된다.
    // 큐에 작업 시간이 현재 걸리는 시간보다 작을 경우 큐에 작업들을 넣어주고
    // 작업이 있을 경우에는 소요시간이 적은 순으로 pop한다.
    
    sort(jobs.begin(), jobs.end());
    // 먼저 jobs도 정렬해야한다.
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // pair로 내림차순으로 우선순위 큐를 만들어줌
    // 우선 순위큐를 이런식으로 만들면 알아서 내림차순으로 정리해준다.
    
    int idx = 0;
    int t = 0;
    
    while(idx < jobs.size() || !pq.empty()){
        // 인덱스가 총 jobs의 크기 보다 작거나 pq가 존재 할때
        if(idx < jobs.size() && t >= jobs[idx][0]){
            pq.push({jobs[idx][1], jobs[idx][0]});
            // 끝난시간, 시작 시간을 넣어준다.
            idx++;
            continue;
        // 인덱스가 jobs의 크기보다 작고, 시간이 jobs에서 처음 시작보다 클 경우
        // idx를 증가시키고 밑을 생략한다.
        }
        
        // 위의 경우가 아닐 경우
        if(!pq.empty()){
            t += pq.top().first;
            answer += t - pq.top().second;
            pq.pop();
            // 비어있지 않을때, 시간에 완료된 시간을 더해주고,
        // answer에 (끝난 시간 - 시작시간)을 해서 그만큼 기다린 시간을 더해준다.
        }
        else{
            t = jobs[idx][0];
            // 비어있을 경우 처음의 시간을 처음 시작한 위치로 넣어주고 시작
        }
    }
    
    // 즉, 처음에 jobs[0][0]을 t에 저장해주고,
    // 그 다음에 t가 이제 위의 조건에 충족하므로, pq에 끝나는 시간, 시작 시간을 넣어주고
    // idx를 옮긴다.
    // 그러면서 이제 모든 시간들을 pq에 넣고, 내림차순으로 정렬이 되어있으면
    // t에 .first를 더하고 .second를 빼며 시간을 answer에 더해준다.
    // 그 answer를 나누면 끝
    
    
    return answer / jobs.size();
    // 크기만큼 나누어야 한다.
}













