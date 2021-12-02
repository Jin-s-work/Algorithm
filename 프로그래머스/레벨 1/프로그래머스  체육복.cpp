#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int>v(n+1);
    // 그냥 n으로 하면 안되고 여유롭게 한개 더 해주어야한다.
    
    for(int k:lost)
        v[k]--;
    // lost일 경우 작게 해줌
    
    for(int k:reserve)
        v[k]++;
    
    for(int i=1;i<=n;i++){
        if(v[i] < 0){    // 만약 음수인 경우 필요하므로 주변을 찾아줌
            if(v[i-1] == 1){
                v[i]++;
                v[i-1]--;   // 빌려줬으므로 내려줌
            }
            else if(v[i+1] == 1){
                v[i]++;
                v[i+1]--;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(v[i] >= 0)
            answer++;
    }
    // 처음에 혼자 풀 경우의 풀이와 제일 유사하다.
    
    return answer;
}

// 예전의 풀이는 너무 복잡하고 별로인 것 같아서 새로운 풀이로 대체한다.
// 학생의 수와 맞게 벡터를 설정하여서 lost는 -1로 reserve는 +1로 하여
// 확인하며 증가 더하는 방식으로 한다.












