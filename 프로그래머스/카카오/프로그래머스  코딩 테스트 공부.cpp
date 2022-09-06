#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 200;
const int INF = 987654321;

int MaxAlp = 0;
int MaxCop = 0;
int dp[201][201];
// alp, cop

int find(int alp, int cop, vector<vector<int>>& problems){
    if(MaxAlp <= alp && MaxCop <= cop)
        return 0;
    // 만약 alp, cop가 Max이하일 경우 즉 같을 경우에 리턴한다.
    
    int& ans = dp[alp][cop];
    // 그때 그때의 dp에 관해 ans에 저장해준다.
    
    if(ans != -1)
        return ans;
    
    ans = INF;
    ans = min(ans, find(min(MaxAlp, alp + 1), cop, problems) + 1);
    ans = min(ans, find(alp, min(MaxCop, cop + 1), problems) + 1);
    // 1. Alp 중 제일 큰 Alp와 alp + 1중 작은 것을 찾아서 넣는다.
    // 여기의 리턴 값에 +1 한 값과 ans를 비교하여 작은 것을 넣어줌
    
    // 2. Cop의 경우에도 마찬가지로 제일 큰 cop과 cop+1 중 작은 것을 넣고, find를 한 후
    // 여기의 리턴 값에 +1 한 값과 ans를 비교하여 ans에 넣어줌
    
    // 즉 alp, cop를 한번에 하는 것이 아니라 각각 해서 제일 작은 ans를 갱신해준다.
    
    for(vector<int> problem : problems){
        if(alp < problem[0] || cop < problem[1]){
            continue;
        }
        // 하나라도 problem보다 작으면 지나간다.
        
        ans = min(ans, find(min(MaxAlp, alp + problem[2]), min(MaxCop, cop + problem[3]), problems) + problem[4]);
    }
    
    return ans;
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    // problems : 문제 푸는데 필요한 알고력, 코딩력, 풀었을 때 증가하는 알고력, 코딩력, 푸는 시간

    memset(dp, -1, sizeof(dp));
    
    for(vector<int> problem : problems){
        MaxAlp = max(MaxAlp, problem[0]);
        MaxCop = max(MaxCop, problem[1]);
    }
    // problems에 대해서 각각 최대의 alp, cop를 비교하면서
    // 각각 제일 큰 값을 찾아낸다.
    
    
    return find(alp, cop, problems);
}















