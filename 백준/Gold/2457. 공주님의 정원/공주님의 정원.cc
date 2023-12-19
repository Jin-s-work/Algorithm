#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>


using ll = long long;
using namespace std;
int l,m,r;
ll n,k;
int h,w;
int d;

vector<pair<int, int>> v;
int num = -1;
int tmp = 0;
int ans = 0;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        pair<int, int> start, last;
        
        cin >> start.first >> start.second;
        cin >> last.first >> last.second;
        
        v.push_back({start.first * 100 + start.second, last.first * 100 + last.second});
    }       // 숫자형식으로 넣어줌
    
    sort(v.begin(), v.end());
    // 하나씩 소트 해준다.
    
        
    for(int i=301;i<=1130 && num < n; i = tmp){     // i에 tmp을 넣어준다.
        bool check = false;     // 처음엔 false로 하고 num 증가시켜줌
        num++;
        
        for(int j=num;j<v.size();j++){      // num부터 v 크기만큼
            if(v[j].first > i)      // v의 시작 부분이 i보다 크면 멈춘다.
                break;
            if(tmp < v[j].second){      // tmp가 v에서 마지막 부분보다 작을경우
                tmp = v[j].second;      // 맞으므로 갱신해주고, num도 j로 check도 true로 해준다.
                num = j;
                check = true;
            }
        }
        
        if(check){      // check가 맞으면 횟수 증가
            ans++;
        }
        else{           // 아닐 경우 0을 출력해줌
            cout << "0" << '\n';
            return 0;
        }
        
    }
    
    cout << ans << '\n';
    
    return 0;
}


//