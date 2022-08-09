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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;
      

int arr[4001][4];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    
    vector<int>v1;
    vector<int>v2;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v1.push_back(arr[i][0] + arr[j][1]);
            v2.push_back(arr[i][2] + arr[j][3]);
        }
    }
    // 이런 식으로 arr에 대해서 두 가지 경우를 각각의 벡터에 넣어준다.
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    ll ans = 0;
    for(int i=0;i<v1.size();i++){
        ll upp = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        ll loww = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        // int 형으로 넣기 위해서는 마지막에 v2.begin()을 빼주어야 한다.
        // 위의 bound 함수는 v2안에서 -v1[i] 값의 이상과 이하가 나타나는 가장 작은 iterator를 구해준다.
        // 즉 -v1[i]에 가장 근접한 인덱스를 반환해준다.
        
        // 이 함수들을 쓰면 이분탐색을 여러번 해야하는 수고로움을 덜고, 개수의 차이를 더해주어
        // 탐색으로 낭비되는 시간을 줄여준다.
        
        ans += (upp - loww);
        // v1과 v2의 합을 돌면서 합의 배열중 더해서 0이 되는 곳을 찾아 그 개수만큼 더해준다.
        
        // 즉, -v1[i] 이상인 값이 처음 나오는 인덱스를, 하나는 -v1[i] 이하인 값이 처음 나오는 인덱스를
        // 구하면, 이 차를 통하여 배열의 합이 0인 것들의 개수를 구할 수가 있다.
        
        // 0-v1의 크기만큼 하여 모두 더하면 그게 답이다.
        
    }
    
    cout << ans;
    
    
    return 0;
    
}

