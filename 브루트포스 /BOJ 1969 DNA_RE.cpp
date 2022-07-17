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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    string st[1001];
    string ans;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    
    for(int i=0;i<m;i++){       // 길이를 맞추어주기 위해 m
        int alp[26] = {0};
        int Max = 0;
        int Maxidx = 0;
        
        for(int j=0;j<n;j++){
            alp[st[j][i] - 'A']++;
        }   // 첫번째 글자들에 대해 더해줌
        
        for(int j=0;j<26;j++){
            if(Max < alp[j]){
                Max = alp[j];
                Maxidx = j;
            }
        }
        // 가장 많이 나온 알파벳을 더해줌
        // 그 인덱스의 위치도 저장해논다.
        
        sum += n - Max;
        // 각각의 값들과 달랐던 횟수를 sum에 더해줌
        // (총 DNA 개수 - 최대로 나온 개수) 이르모 다른 것들의 개수를 세주는 것
        
        ans += Maxidx + 'A';
        // 알파벳으로 고쳐서 넣어줌
    }
    
    
    cout << ans << '\n' << sum;
    
    
    return 0;

}
