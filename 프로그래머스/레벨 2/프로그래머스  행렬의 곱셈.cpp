

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int n = arr1.size();
    int m = arr2[0].size();
    int l = arr1[0].size();
    // 안에서 움직이는 것은 가운데 만큼의 사이즈
    
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int k=0;k<l;k++){
                sum += arr1[i][k] * arr2[k][j];
            }
            v.push_back(sum);
            // 하나씩 받으며 한 행을 만든다.
        }
        answer.push_back(v);
        // 행렬의 행 전체를 answer에 넣어버리는 것
    }
    
    // i,j에서 더 곱해줘야 하므로 for문을 하나 더 만든다.
    
    return answer;
    
}













