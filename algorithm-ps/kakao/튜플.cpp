//
//  튜플.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/27.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
int main(void){
    
    vector<int> answer;
    
    //string a[100001];
    vector<string> a;
    unordered_set<string> res;
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string temp = "";
    int cnt = 0;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == '{' || s[i] == '}' || s[i] == ','){
            a.push_back(temp);
            temp = "";
            continue;
        }else {
            temp += s[i];
            if(s[i+1] != '{' && s[i+1] != '}' && s[i+1] != ',' ){
                continue;
            }else {
                res.insert(temp);
               // a[i].append(temp);
                //temp = "";
                cnt +=1;
            }
        }
    }
    //cout << a[a.size()] << '\n';
    
    
    
//    for(int i=start; i<a.size(); i++){
//        cout << a[i] << '\n';
//    }
    // std::set의 요소 출력.
//    for (unordered_set<string>::iterator it=res.begin(); it!=res.end(); ++it){
    
    
//        answer.push_back(stoi(*it));
//    }
//    for(int i=0; i<answer.size(); i++){
//        cout << answer[i];
//    }
    return 0;
}
