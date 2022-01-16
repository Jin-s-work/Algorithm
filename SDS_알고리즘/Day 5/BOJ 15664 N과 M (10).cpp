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

int input[11];
int arr[11];
bool check[11];

void DFS(int num, int cnt){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    int tmp = 0;
    for(int i=cnt;i<n;i++){
        if(check[i] || tmp == input[i])
            continue;       // check가 방문 했거나, tmp가 input[i]와 같으면 넘어감
                            // 중복 방지
        check[i] = true;
        arr[num] = input[i];
        tmp = input[i];
        // i를 방문했다고 표시하고, arr[num]에 input[i]를 넣는다.
        // tmp에 input을 저장해놓음 ( 다음 번에 만약 같으면 피해주기 위해서 )
        DFS(num + 1, i+1);
        // i가 i+1 부터 시작하게 한다.
        // 정렬 해 놓았으므로 무조건 크게 하는 것 ( 그 전에 것들은 출력 안함 )
        check[i] = false;
        
        // 완전 탐색하는 backtracking 방법
    }
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    
    sort(input, input + n);
            
    DFS(0,0);
            
    

    return 0;

}



//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}

//
//
