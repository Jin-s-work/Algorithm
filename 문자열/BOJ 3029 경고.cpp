
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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s[3], t[3];
    scanf("%2d:%2d:%2d", &s[0], &s[1], &s[2]);
    scanf("%2d:%2d:%2d", &t[0], &t[1], &t[2]);

    int st = s[0] * 3600 + s[1] * 60 + s[2];
    int tt = t[0] * 3600 + t[1] * 60 + t[2];
    
    int ans = 0;
    if(st < tt)
        ans = tt - st;
    else
        ans = 24*3600 + tt - st;
    // tt가 더 작은 경우에는 빼준 다음 24시간을 더해준다.
    
    printf("%02d:%02d:%02d", ans/3600, ans%3600 / 60, ans%60);
    // 시간 형태의 문자열 받는법
    // 이렇게 하지 않으면 그냥 문자열로 입력 받아서 인덱스로 해주어도 될 거 같긴 하다.
    
    return 0;

}

// 아직 문자열이 안 익숙하여 브론즈도 잘 안풀리므로 최대한 이번주에 많이 풀어보기..!
