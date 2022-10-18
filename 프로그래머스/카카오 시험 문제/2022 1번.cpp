#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int today_year = stoi(today.substr(0,4));
    int today_month = stoi(today.substr(5,2));
    int today_day = stoi(today.substr(8,2));

    map<string, int> mp;

    for(int i=0;i<terms.size();i++){
        
        string tmp_term = terms[i].substr(0,1);
        int number = stoi(terms[i].substr(2));
        mp[tmp_term] += number;

    }

    
    for(int i=0;i<privacies.size();i++){
        string dates = privacies[i].substr(0,10);
        string name = privacies[i].substr(11);

        int plus = mp[name];

        int year = stoi(dates.substr(0,4));
        int month = stoi(dates.substr(5,2));
        int day = stoi(dates.substr(8,2));
        if(month + plus > 12 && month + plus <= 24){
            year++;
            month -= 12;
        }
        else if(month + plus > 24 && month + plus <= 36){
            year += 2;
            month -= 24;
        }
        else if(month + plus > 36 && month + plus <= 48){
            year += 3;
            month -= 36;
        }
        else if(month + plus > 48 && month + plus <= 60){
            year += 4;
            month -= 48;
        }
        else if(month + plus > 60 && month + plus <= 72){
            year += 5;
            month -= 60;
        }
        else if(month + plus > 72 && month + plus <= 84){
            year += 6;
            month -= 72;
        }
        else if(month + plus > 84 && month + plus <= 96){
            year += 7;
            month -= 84;
        }
        else if(month + plus > 96 && month + plus <= 108){
            year += 8;
            month -= 96;
        }
        else if(month + plus > 108 && month + plus <= 120){
            year += 9;
            month -= 108;
        }
        month += plus;

        
        if(day - 1 == 0){
            day = 28;
            if(month - 1 == 0){
                month = 12;
                year--;
            }
            else
                month--;
        }
        else
            day--;

        if(today_year > year)
            answer.push_back(i+1);
        else if(today_year == year){
            if(today_month > month){
                answer.push_back(i+1);
            }
            else if(today_month == month){
                if(today_day > day)
                    answer.push_back(i+1);
            }
        }

    }

    
    
    
    return answer;
}

