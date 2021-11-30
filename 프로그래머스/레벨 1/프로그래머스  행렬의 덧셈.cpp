#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int>v;
    
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[0].size();j++){
            v.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(v);
        v.clear();
    }
    // 각각 이런식으로 v를 각각 만들어서 answer에 줄대로 넣어주고 v를 clear한 후
    // 다시 입력받아서 행마다 넣어줌
    
    
    return answer;
}
