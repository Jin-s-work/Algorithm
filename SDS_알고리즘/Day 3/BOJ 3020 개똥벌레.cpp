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


int arr[500001];
int Min = 200001;
int Min_num;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> h;
    
    for(int i=0;i<n;i++){
        
        int a;
        cin >> a;
        
        if(i % 2 == 0){
            arr[0]++;
            arr[a]--;
        }   // 짝수면 밑에 있기에 cnt[0]을 증가시켜주고 a는 마이너스
        else{
            arr[h - a]++;
        }   // 홀수면 플러스 해주는게 밑에 부분을 +해주는 것이다.
            // 즉 종유석이 있으면 마이너스를 주고 아닐 경우 +를 주므로,
            // 반대편을 증가시킴으로서 원래 있던 부분이 더 작게 해주는 느낌(?)이다.
    }
    
    // arr[14]
    // 0  1  2  3  4  5
    // 7  1  2 -2 -1  -1
    
    
    
    int num = 0;
    for(int i=0;i<h;i++){
        num += arr[i];
        // num에 arr를 매번 더 해 나가면서
        
        // 처음에 arr[0]을 더해주면서 바닥에 있는 석순의 개수를 num에 더해준다.
        
        if(num < Min){      // Min보다 num이 작으면 Min을 갱신하고
            Min = num;
            Min_num = 1;    // 1부터 시작해준다.
        }
        else if(num == Min)     // num이 Min과 같을 경우는 Min_num을 거기서부터 증가시켜준다.
            Min_num++;
        
    }
    
    cout << Min << " " << Min_num << '\n';
    
    
    

    return 0;

}



