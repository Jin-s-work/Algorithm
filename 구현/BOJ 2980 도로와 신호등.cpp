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
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int d[101], r[101], g[101];
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> d[i] >> r[i] >> g[i];
    }
    
    // 1 2 3 3 3 4 5 6 7 8 9 10
    // x x d d x x d d
    
    int t = 1;
    for(int i=1;i<=l;i++){              // i는 위치
        for(int j=0;j<n;j++){
            if(i == d[j] && r[j] > t % (r[j] + g[j])){  // 위치가 신호등의 위치이고, 아직 빨간불일때
                t += r[j] - t % (r[j] + g[j]);    // ( t % r[j] + g[j]) 가 포인트
            }   // 원래 t가 움직인 시간에 빨간불때문에 기다린 시간 더하기 (이 부분이 핵심인 것 같다.)
        }
        t++;
    }
    
    
    cout << t-1;
    // 처음에 1초부터 했으므로 줄여주기
        
    
    return 0;

}



