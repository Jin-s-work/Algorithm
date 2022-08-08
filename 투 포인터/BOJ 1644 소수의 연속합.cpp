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

vector<int>v;
vector<bool>prime;


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    prime.resize(n+1, true);
    for(int i=2;i*i<=n;i++){
        if(!prime[i])       // 원래 false면 넘어감
            continue;
        for(int j=i*i;j<=n;j+=i)
            prime[j] = false;   // i씩을 더해줄때 즉 그냥 소수가 아닐 때 false
    }
    
    for(int i=2;i<=n;i++){      // 벡터를 넣어주는 크기도 제대로 고려하기
        if(prime[i])            // 왜냐면 위에서 i를 2부터 탐색해서 0,1도 들어갈 수 있다.
            v.push_back(i);
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    
    while(1){
        if(sum >= n){
            sum = sum - v[left++];
        }
        else if(right == v.size())      // 여기서는 right의 끝이 소수들의 size만큼
            break;                      // 소수 자체도 n+1까지 이므로 괜찮다.
        else{
            sum = sum + v[right++];
        }
        
        if(sum == n)
            ans++;
        
    }
    
    // 소수들에 대한 벡터를 만들어주어서 여기서 투 포인터를 적용한다는 생각이 하기 쉽지 않았는데
    // 풀고 나니 나중에는 이런 생각을 할 수 있을 것 같다.
    
    
    cout << ans;

    
    return 0;
    
}

