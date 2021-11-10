
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,k;
int l,r,t;
int h, w;

int arr[300001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pair<ll, ll> arr[100001];
    
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr, arr + n);
    pq.push(arr[0].second);
    
    for(int i=1;i<n;i++){
        if(pq.top() <= arr[i].first){
            pq.pop();
            pq.push(arr[i].second);
        }
        else{
            pq.push(arr[i].second);
        }
    }
    
    cout << pq.size();
    
    return 0;
}


// 아까의 강의실 배정이랑 비슷한 문제 인거 같다.. 풀어바야디
// 일단 아까 한 대로 똑같이 복기해서 코드를 완성하였다.

// 머야 long long만 바꾸니까 똑같은 문제였다..
// 신기하네..

// priority_queue 유형 익히기
