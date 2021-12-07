

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    
    for(int i=0;i<land.size()-1;i++){
        land[i+1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i+1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i+1][2] += max(land[i][1], max(land[i][0], land[i][3]));
        land[i+1][3] += max(land[i][1], max(land[i][2], land[i][0]));
    }
    // 원래의 값에 더해주는 것이므로 = 를 쓰면 안댐
    
    answer = max(land[land.size()-1][0], max(land[land.size()-1][1], max(land[land.size()-1][2], land[land.size()-1][3])));
    
    
    return answer;
}

// 대충 보니까 DP인거 같다..
// 아주 쉬운 문제 였는데 안푼지 오래되서 안익숙하다 더 풀어보자













