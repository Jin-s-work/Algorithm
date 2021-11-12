
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
    
    cin >> n >> m;
    
    string st[1001];
    string ans;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    
    for(int i=0;i<m;i++){
        int alp[26] = {0};
        int Max = 0;
        int Maxidx = 0;
        
        for(int j=0;j<n;j++){
            alp[st[j][i] - 'A']++;      // i는 문자열의 크기만큼 각 문자열마다 해서 해줌
            // 여기서는 첫번째 글자에 대해서 ++해보고, 그 다음은 다음 글자,, 이런 식으로 넘어간다.
            // st[j][i]이기 때문에
            
            // A를 뺌으로서 알파벳에 맞는 인덱스를 더해줌
            // 즉 알파벳마다 횟수를 더해줌
            // 적혀있는 모든 문자열에 대하여
        }
        
        // 따라서 여기서도 각 글자의 i번째 부분에 대해서 찾아보는 것이다.
        for(int j=0;j<26;j++){
            if(Max < alp[j]){       // 가장 큰 값을 결과 문자열로 저장한다.
                Max = alp[j];
                Maxidx = j;
                // 제일 많이 나온 알파벳을 Max에 넣고, 그때의 알바펫을 Maxidx에 넣어준다.
            }
        }
        
        sum += n - Max;         // 각각의 값과 달랐던 횟수들을 sum에 더해준다.
        ans += Maxidx + 'A';
        // 다시 알파벳을 더해서 알파벳에 맞춰줌
        
        // 이런식으로 i번째 부분에 대해서 글자를 찾아, 쌓아가면서 새로운 s를 만드는 것
        // 여기서의 s는 가장 많은 것을 넣는 것이다.
    }
    
    cout << ans << '\n' << sum;
    
    
    return 0;
}

// 문제가 이해가 잘 가지 않아 풀이를 봤는데도 너무 복잡하고 그렇네....



