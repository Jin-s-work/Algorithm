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

int arr[3000001];
deque<int> dq;
int ans = 0;
int num = 0;
int kind[3001];
int c, d;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> d >> k >> c;
    // 접시 수 - 초밥 개수 - 연속해서 먹는 접시 수 - 쿠폰 번호
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<k;i++){
        dq.push_back(arr[i]);
        // 덱에 스시들을 넣는다.
        
        kind[arr[i]]++;
        // arr에 관해서 증가시켜줌
        
        if(kind[arr[i]] == 1)
            num++;
        // 증가해서 1일 경우 num을 증가시켜 준다.
        
        ans = max(ans, num);
    }
    // 연속해서 먹는 k개를 덱에 넣고 센다.
    
    for(int i=0;i<n-1;i++)
    {
        dq.pop_front();
        kind[arr[i]]--;
        // 맨 앞 스시를 빼고, 줄여준다.
        
        if(kind[arr[i]] == 0)
            num--;
        // 0이 되면 다시 num을 줄여준다.
        // (즉 해당 스시가 덱에 없을 경우 num을 뺀다.
        
        dq.push_back(arr[(i+k) % n]);
        kind[arr[(i + k) % n]]++;
        // 원형이므로 이런 식으로 다시 넣는다.
        
        if(kind[arr[(i + k) % n]] == 1)
            num++;
        // 1이 되면 다시 num을 증가시켜줌
        
        if(kind[c] == 0)
            ans = max(ans, num+1);
        else
            ans = max(ans, num);
        // 쿠폰 스시가 덱에 없으면 1을 증가시켜서 비교하고 아니면 그냥 비교
        
    }
    
    cout << ans;
    

    return 0;

}


