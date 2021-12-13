#include <string>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>> &computers, int n){
    // 여기서 &로 참조를 해주어야 computers 자체를 변화시킬 수 있음
    if(!computers[n][n])
        return false;
    // nn이 이미 false일 경우 즉 지나갔을 경우 false로 탈출
    
    computers[n][n] = 0;
    // 즉 원래는 true이니까 일로 오기에 지나갔음을 표시해주기 위해 0으로 해준다.
    
    for(int i=0;i<computers.size();i++){
        if(computers[n][i])     // 아직 computers[n][i]가 true일 경우
            DFS(computers, i);  // computers에 대해서 i로 DFS 해준다.
    }
    return true;
    // 다 지나면 DFS를 true로
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(computers[i][i] && DFS(computers, i))
            answer++;
    }
    
    
    return answer;
}














#include <string>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& computers, int n){
    if(!computers[n][n])
        return false;       // 0일 경우 false
    
    computers[n][n] = 0;    // n,n을 0으로 해주고
    
    for(int i=0;i<computers.size();i++){
        if(computers[n][i])         // n,i가 1일때 DFS한다.
            DFS(computers, i);      // 즉 연결된 노드가 있다면 재귀한다.
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(computers[i][i] && DFS(computers, i))
            answer++;
    }
    // computers가 연결되어 있고, DFS가 true일때 네트워크를 늘려줌
    // 지나지 않을 경우 탐색한 후 answer를 증가시켜줌
    
    return answer;
}

// i와 j가 연결되어있으면 computers[i][j] == 1
// computers[i][i]는 항상 1

