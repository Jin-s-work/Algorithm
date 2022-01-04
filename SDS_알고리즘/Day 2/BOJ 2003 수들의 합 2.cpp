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
int l,r,t;
int h;


vector<int>v;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = 0;
    
    // 나는 여기서 투 포인터라서 sort를 썼는데,
    // 생각해 보니 만약 처음 인덱스를 잡았을 경우, 오른쪽으로 갈 수록 더 커지게 되는 데 그 전에
    // 옮기면 그게 처음부터에서의 그나마 최소값..? 이라서 넘어가는게 맞다. 정렬은 안해도됨..
    // 정렬을 하는 경우 배열을 바꾸는 것으므로 안된다.
    
    while(1){
        
        if(sum >= m)
            sum = sum - v[i++];
        // m보다 sum이 클 경우에는 인덱스를 증가시키면서 밑에서 부터 합을 빼준다.
        else if(j == n)
            break;      // 여기에서 빼주어야 한다. 그 다음 경우에서 j를 더 늘리면 안되므로..
        else{
            sum = sum + v[j++];
            // 더 작을 경우에는 뒤의 인덱스를 증가시키면서 더해줌
        }

        if(sum == m)
            ans++;
        

    }
    
    cout << ans << '\n';
    
    
    return 0;

}


// 일반적인 투 포인터 이지만 유형을 더 풀어보자

//10 5
//1 2 3 4 2 5 3 1 1 2
