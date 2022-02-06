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
    
    vector<int>A;
    vector<int>C;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A.push_back(arr[i][0] + arr[j][1]);
            C.push_back(arr[i][2] + arr[j][3]);
        }
    }
    
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    ll num = 0;
    
    for(int i=0;i<A.size();i++){
        ll upp = upper_bound(C.begin(), C.end(), -A[i]) - C.begin();
        ll loww = lower_bound(C.begin(), C.end(), -A[i]) - C.begin();
        // 마지막에 C.begin()을 빼야 int형으로 넣을 수가 있다.
        // C 안에서 -A[i]의 값의 이상과 이하가 나타나는 가장 작은 iterator를 저장해줌
        // 즉 -A[i]에 제일 근접한 인덱스를 반환한다.
        
        // upperbound와 lowerbound를 사용하면
        // 앞의 배열에서 -100을 찾았을 경우, 그 뒤에서 100을 찾았을때 개수를 늘려주는데
        // 100인 값이 10개 인 경우, 이분탐색을 10번이나 해야 하지만,
        // 위를 사용하면 개수의 차이를 더해주어서 탐색으로 낭비되는 시간을 줄여준다.
        
        num += (upp - loww);
        // A와 C의 합을 돌면서 합의 배열중 더해서 0이되는 곳을 찾아 그 개수만큼 더해 준다.
        
    }

    cout << num << '\n';
    
    
    return 0;

}

