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

// control i
#define MAX 987654321
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int weight[31];
int arr[8];
bool check[31][30*500 + 1];

void DFS(int num, int res){
    if(num > n)
        return;
    
    if(check[num][res])
        return;
    // n보다 num이 크거나 이미 방문하였을 경우 리턴
    
    check[num][res] = true;
    DFS(num+1, res + weight[num]);
    DFS(num+1, res);
    DFS(num+1, abs(res-weight[num]));
    
    // 더해서 들어가거나 그냥 들어가거나 빼서 넣어주기
    // 받아진 weight에 대하여 num을 늘려주며 넣어준다.
}
// 최근에 이러한 더하고 빼는 DFS 식 문제를 많이 풀었는데도 제대로 못풀었다.. 더 열심히 하자

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }   // 추
    
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }   // 구슬
    
    // 먼가 DFS로 끝까지 파보는게 조을 거 같음.. 근데 구현어케하지
    
    DFS(0,0);
    for(int i=0;i<m;i++){
        if(arr[i] > 30*500)
            cout << "N ";
        else if(check[n][arr[i]])
            cout << "Y ";
        else
            cout <<  "N ";
    }
    
    
    
    return 0;
    
}
