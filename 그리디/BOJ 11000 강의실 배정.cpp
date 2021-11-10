
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



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    pair<int, int> arr[200001];
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    // 시작과 끝나는 위치를 각각 받아줌
    
    sort(arr, arr + n);
    // 시작순서대로 오름차순 정렬
    
    pq.push(arr[0].second);
    // 가장 먼저 끝나는 부분을 먼저 우선순위 큐에 넣어준다.
    
    for(int i=1;i<n;i++){
        if(pq.top() <= arr[i].first){
            pq.pop();
            pq.push(arr[i].second);
        }   // 다음 부분의 시작시간이 끝나는 시간 이상일 경우 원래의 pq를 pop하고 다음 끝나는 시간을 넣어준다.
        else
            pq.push(arr[i].second);
    }       // 아닐 경우 pop하지 않고, 다음 끝나는 시간을 넣어준다.
    
    // 또한 priority_queue 이므로, 정의한 대로 push해도 greater<int> 즉 내림차순으로 되어,
    // 먼저 끝나는 arr[i].second가 먼저 나와서 다음 것과 비교하게 된다.
    
    cout << pq.size();
    // 개수는 즉 각각의 방의 size이다.
    
    return 0;
}

