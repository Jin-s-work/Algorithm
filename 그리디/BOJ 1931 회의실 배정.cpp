
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;

vector<pair<int, int>>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }       // 끝나는 시간을 기준으로 빠른 것을 골라주어야 하므로 반대로 넣어서
            // 정렬을 편하게 해준다.
    
    sort(v.begin(), v.end());
    
    int num = 0;
    int end = 0;
    
    for(int i=0;i<v.size();i++){
        if(v[i].second < end)
            continue;           // 시작하는 부분이 저장되어있는 end보다 작을 경우 그냥 무시함
                                // 즉 그냥 재끼는 거임
        end = v[i].first;
        // 그러고 끝나는 부분을 end로 해주고
        
        num++;
        // 횟수 증가해줌
        
        // 제거된 경우 continue해주기 때문에 end에 갱신도 안되고 숫자도 안더해져서 괜춘
    }
    
    cout << num;
    
    
    return 0;
}

// 끝나는 시간을 기준으로 해서 빠른 순으로 고르고, 없애주면서 하는게 포인트..!

// 이런 방법을 어떻게 생각해내는지 신기하다.. 더 열심히 해야겠다...
