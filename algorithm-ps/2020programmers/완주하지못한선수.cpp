//
//  완주하지못한선수.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/04.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main(void){
    
    vector<string> participant;
    vector<string> completion;
    // [leo, kiki, eden]    [eden, kiki]    leo
    
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");
    
    completion.push_back("eden");
    completion.push_back("kiki");
    map<string,int> m;
    for(int i=0; i<completion.size(); i++){
        // 완주자 없는 경우
        if(m.find(completion[i]) == m.end()){
            m.insert(make_pair(completion[i], 1));
        }
        // 완주자 있는 경우
        else {
            // 완주자 수 카운팅
            m[completion[i]]++;
        }
    }
    
    string answer = "";
    for(int i=0; i<participant.size(); i++){
        // 완주자와 참가자 명단에서 못찾았을 경우
        if(m.find(participant[i]) == m.end()){
            answer = participant[i];        // 못찾은 사람이 정답
            break;
        }
        // 동명이인일 경우 값을 하나씩 줄였을때 0보다 작으면 그 사람이 완주자, 동명이인 체크해주기
        else {
            m[participant[i]]--;
            if(m[participant[i]] < 0){
                answer = participant[i];
                break;
            }
        }
    }
    
    
    
    return 0;
}
