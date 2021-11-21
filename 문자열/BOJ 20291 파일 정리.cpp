
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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    vector<pair<string, int>>v;
    vector<string>tmp;
    
    for(int i=0;i<n;i++){
        string st;
        cin >> st;
        
        int idx = st.find(".");
        
        st.erase(0, idx + 1);
        tmp.push_back(st);
    }
    
    sort(tmp.begin(), tmp.end());

    int num = 0;
    string str = tmp[0];
    for(int i=0;i<tmp.size();i++){
        if(str == tmp[i])
            num++;
        else if(str != tmp[i]){
            v.push_back({str, num});
            str = tmp[i];
            num = 1;
        }
        // 위에서 정렬을 해주었으므로,
        // str 에다가 달라진 tmp[i]의 값을 다시 넣어주고 계속 확인해본다.
            
    }
        
    v.push_back({str, num});
    // 맨 마지막에 개수가 안 담기었을 경우도 마저 넣어주기
    
    
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    
    
    
    return 0;

}


// 문자열 혼자 했는데 답이 나와서 굉장히 뿌듯했는데 시간 초과가 나왔다.

// 확장자 개수가 최대 5만개이므로 O(nlogn)을 사용하여야 한다고 한다.
// char를 하는 내 방식보다는 확실히 string으르 사용하여 빠를 거 같긴 한데 제대로는 잘 모르겠다.
