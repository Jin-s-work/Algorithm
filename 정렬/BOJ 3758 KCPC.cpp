#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>
#include <sstream>

// control i
const int INF = 1000000000;
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;
      

int arr[101][101];
struct student{
    int id, score, num, times;
}s[101];
// 구조체를 이용하여 정렬을 사용해주면 정렬할 때 복잡한 벡터보다 훨씬 간편한 것 같다..
// 왜쓰는지 몰랐는데 이제야 이해

bool cmp(student a, student b){
    if(a.score == b.score){
        if(a.num == b.num)      // 같은 경우에 시간이 짧은게 앞으로
            return a.times < b.times;
        return a.num < b.num;   // 아닌 경우 제출 횟수가 적을 수록 앞으로
    }
    return a.score > b.score;   // 아닌 경우 점수가 높을 수록 앞으로
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        cin >> n >> k >> t >> m;
        // 팀 개수, 문제 개수, 내 팀 ID, 로그 엔트리의 수
        
        int ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(s, 0, sizeof(s));
        
        for(int i=0;i<n;i++){
            s[i].id = i + 1;
        }
        // s에서의 id는 순서대로 지정해줌
        
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[a][b] = max(arr[a][b], c);
            // arr에는 ID, 번호를 하고 획득한 점수를 저장해주는데 더 높을 수록 갱신하므로 이런 형태
            s[a-1].num++;
            s[a-1].times = i;
            // 시간을 i로 해주고, 문제 개수를 늘려준다.
            // 팀 ID, 문제 번호, 획득한 점수
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                s[i-1].score += arr[i][j];
            }
            // i는 팀의개수, j는 문제의 개수만큼 해서
            // 번호에 따른 i번째 학생의 점수를 arr[i][j]를 더해준다.
            // 위에서 arr[i][j]는 팀이 문제에 관하여 받은 최고 점수
        }
        
        sort(s, s+n, cmp);
        
        for(int i=0;i<n;i++){
            if(s[i].id == t)
                ans = i + 1;
            // id 전체를 조사하여서 ID와 id가 같을 경우 (즉 내 팀의 인덱스에 관하여)
            // 위치인 i에서 1더한 i + 1을 ans에 넣어준다.
        }
        
        cout << ans << '\n';
    }
    // 최종 점수가 같을 때 제출한 횟수가 적을 수록 순위 높
    // 최종 점수, 제출 횟수가 같으면 마지막 제출 시간이 빠를수록 순위 높다
    
   
    // 이게 실버 3..?
    
    
    return 0;
    
}
