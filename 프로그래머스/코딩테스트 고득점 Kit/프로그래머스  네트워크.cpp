#include <string>
#include <vector>

using namespace std;

bool check[201];

int DFS(vector<vector<int>> computers, vector<int>numbers, int n){
    check[n] = true;
    for(int i=0;i<numbers.size();i++){      // number의 개수만큼
        if(!check[i] && numbers[i] == 1)    // check가 true고 number가 1이면
            DFS(computers, computers[i], i);    // 안으로 들어가서 DFS
    }
    
    return 0;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++){
        if(!check[i]){      // check가 안들어간 곳일 경우
            DFS(computers, computers[i], i);    // 들어가고 answer를 늘림
            answer++;
        }
    }
    
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// bool DFS(vector<vector<int>> &computers, int n){
//     // &로 참조를 해서 computer자체를 바꾼다.
//     if(!computers[n][n])        // 처음 모든 computers[n][n]은 모두 1인 것을 이용
//         return false;
//     // [n][n]이 0일 경우 탈출한다.
    
//     computers[n][n] = 0;
//     // 아닐 경우 일로 오므로 0으로 해준다. (지나간 것을 표시)
    
//     for(int i=0;i<computers.size();i++){
//         if(computers[n][i])     // true일 경우 (즉 연결되어 있는 것이 있을 경우)
//             DFS(computers, i);  // DFS로 옮겨가준다.
//     }
    
//     return true;
//     // 다 지나면 true로 리턴한다.
    
// }

// int solution(int n, vector<vector<int>> computers) {
//     int answer = 0;
    
//     for(int i=0;i<computers.size();i++){
//         if(computers[i][i] && DFS(computers, i))
//             answer++;
//     }   // [i][i]에 대해 지나갔고, DFS를 모두 마치고 왔을 때 answer를 증가시켜준다.
        
//     // 계속 DFS로 파고들다가 끝나면 true로 나오면서 한 블럭을 한다.
//     // 보니까 이해는 가는데 실전에서 할 수 있을까.. 많이 풀어보자
    
    
//     return answer;
// }



// #include <string>
// #include <vector>

// using namespace std;

// bool DFS(vector<vector<int>> &computers, int n){
//     // 여기서 &로 참조를 해주어야 computers 자체를 변화시킬 수 있음
//     if(!computers[n][n])
//         return false;
//     // nn이 이미 false일 경우 즉 지나갔을 경우 false로 탈출
    
//     computers[n][n] = 0;
//     // 즉 원래는 true이니까 일로 오기에 지나갔음을 표시해주기 위해 0으로 해준다.
    
//     for(int i=0;i<computers.size();i++){
//         if(computers[n][i])     // 아직 computers[n][i]가 true일 경우
//             DFS(computers, i);  // computers에 대해서 i로 DFS 해준다.
//     }
//     return true;
//     // 다 지나면 DFS를 true로
// }

// int solution(int n, vector<vector<int>> computers) {
//     int answer = 0;
    
//     for(int i=0;i<n;i++){
//         if(computers[i][i] && DFS(computers, i))
//             answer++;
//     }
    
    
//     return answer;
// }

