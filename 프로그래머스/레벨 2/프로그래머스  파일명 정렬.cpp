













#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool cmp(pair<string, pair<string, int>>a, pair<string, pair<string, int>> b){
    if(a.first == b.first){
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return stoi(a.second.first) < stoi(b.second.first);
    }
    else
        return a.first < b.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    string head = "";
    string number = "";
    bool headcheck = false;
    bool numbercheck = false;
    
    vector<pair<string, pair<string, int>>> v;
    
    for(int i=0;i<files.size();i++){
        pair<string, int> p;
        
        for(int j=0;j<files[i].size();j++){
            if(headcheck == false){
                if(files[i][j] >= '0' && files[i][j] <= '9'){
                    headcheck = true;
                    number += files[i][j];
                }
                else
                    head += tolower(files[i][j]);   // 아닐 경우 소문자로
                    
            }
            else if(headcheck && numbercheck == false){
                if(files[i][j] >= '0' && files[i][j] <= '9')
                    number += files[i][j];
                else
                    break;
            }
        }
        
        p = make_pair(number, i);
        v.push_back({head, p});
        head = "";
        number = "";
        headcheck = false;
        numbercheck = false;
        
        
    }
    
    stable_sort(v.begin(), v.end(), cmp);
    
    for(auto k : v)
        answer.push_back(files[k.second.second]);
    
    return answer;
}

