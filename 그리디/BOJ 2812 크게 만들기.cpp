
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

vector<char>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    
    string st;
    cin >> st;
    
    for(int i=0;i<st.length();i++){
        while(k != 0 && !v.empty() && v.back() < st[i]){
            // k가 0이 아니고, v도 비어있지 않을 때 즉 처음에는 안함
            // 그러고 st[i]가 v의 마지막 보다 클 경우
            v.pop_back();
            k--;
            // v의 마지막을 없애주고
            // 하나 없앴으므로, k도 하나 줄인다.
        }
        v.push_back(st[i]);
        // st[i]는 계속 v에 넣어주면서 해본다.
    }
    
    while(k--){
        v.pop_back();
    }
    // k가 아직 안끝나면 v는 내림차순 순서일 것이기에
    // 맨 뒤에 부분을 없애면 된다.
    
    for(int i=0;i<v.size();i++)
        cout << v[i];
    // 그리고 출력
    
    return 0;
}


// 그냥 무식하게 string으로 하니까 답은 나오지만 출력 초과가 떴다..!

// 구글링해보니 deque로 하는 방법도 있었지만, 전에 풀었던 방법대로 벡터를 사용해서 해 보았다.
// k가 아직 남았을 경우 맨 뒤에 부분을 빼는 부분이 중요한 포인트 인거 같다..!

// if( && &&) 문에 있어서 런타임 에러가 뜨다가 또 순서를 바꾸어주니 맞게 되었다..
// 순서를 앞으로도 조심히 다뤄야 할 거 같다... 신기하네
