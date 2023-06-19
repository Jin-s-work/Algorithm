#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using ll = long long;
using namespace std;
//int m,l;
//int n;
//int k,t;

vector<int>v;


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll maxtmp = 0;
    ll n,k,m,cnt=0;
    ll left = 0;
    ll right = 0, mid = 0;
    
    cin >> k >> n;
    
    
    for(int i=0;i<k;i++){
        cin >> m;
        v.push_back(m);     // vector에 값을 넣어주면서 maxtmp를 갱신해 나가면서 제일 큰 수를 maxtmp에 넣어준다.
        if(maxtmp < m)
            maxtmp = m;     // m이 max보다 더 크면 갱신해준다.
        }
        
    left = 1;           // 1~최대값 사이에서
    right = maxtmp;
    
    while(left <= right){       // left가 right보다 무조건 작을때
        int num = 0;            // 개수를 처음 선언해준다.
        mid = (left+right)/2;   // mid는 left와 right 중간
        
        for(int i=0;i<v.size();i++){
            num += v[i] / mid;  // 중간을 계속 나누어가면서 더해준다. 즉 총 필요한 합을 알기위해서 해준다.
        }
        
        if(num < n)  // 이 것이 아직 n보다 작으면 right를 mid보다 작게 논다.
            right = mid - 1;    // 왼쪽부분을 해본다
        else{       // 크거나 같은 경우에
            if(cnt < mid)       // cnt에 mid를 저장
                cnt = mid;      // cnt가 mid보다 작을 경우에는 mid를 또 작게 해준다.
            left = mid+1;       // 아닌 경우에는 left를 mid보다 크게 해준다.
        }
        
        
    }
    
    cout << cnt << '\n';
    
    return 0;
}
