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

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
ll l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    
    cin >> n;
    vector<ll>v1(n);

    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    
    cin >> m;
    vector<ll>v2(m);
    for(int i=0;i<m;i++){
        cin >> v2[i];
    }
    
    vector<ll>a;
    vector<ll>b;
    
    for(int i=0;i<n;i++){
        ll sum = v1[i];
        a.push_back(sum);
        // 처음의 sum을 a벡터에 저장해놓고
        
        for(int j=i+1;j<n;j++){
            sum += v1[j];
            a.push_back(sum);
        }
        // 그 다음부터 계속 넣어서 a에 넣어준다.
        // 각각의 sum들을
        
    }
    
    for(int i=0;i<m;i++){
        ll sum = v2[i];
        b.push_back(sum);
        // 처음의 sum을 b벡터에 저장해놓고
        
        for(int j=i+1;j<m;j++){
            sum += v2[j];
            b.push_back(sum);
        }
        // 그 다음부터 계속 넣어서 b에 넣어준다.
        // 각각의 sum들을
        
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // 이분탐색을 하기 위해 둘을 모두 sort해준다.
    ll ans = 0;
    
    for(int i=0;i<a.size();i++){
        
        int low = lower_bound(b.begin(), b.end(), t - a[i]) - b.begin();
        int high = upper_bound(b.begin(), b.end(), t - a[i]) - b.begin();
        // a의 원소를 하나씩 탐색하며 t와의 차이의 값이 b 중에서 몇개 존재 하는 지 찾는다.
        // 즉 a의 원소를 통하여 b의 개수 최대와 b의 개수 최소의 차이를 ans에 넣는 것
        // t - a[i]로 하여 나머지 b가 들어가는 부분
        
        // 사실 여기서 b.begin()은 어차피 없어지기에 안빼주어도 답이 나오긴 한다.
        // b.begin()을 빼주어야 값이 나오기는 하지만..
        
        ans += (high - low);
        
    }
    
    cout << ans;
    
    
    return 0;

}


// 굳이 upper, lower_bound를 쓰지 않아도 그냥 배열에 표시하는 식으로 하여
// 풀어도 답이 나올 수가 있다..
