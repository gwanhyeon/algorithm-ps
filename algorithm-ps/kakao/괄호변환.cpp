//
//  괄호변환.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/30.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

// 올바른 문자열인지 체크하는 함수
bool isCheckString(string str, int *position){
    
    bool ret = true;
    int left = 0;
    int right = 0;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        
        if(str[i] == '('){
            left++;
            s.push(str[i]);
        }else {
            right++;
            if(s.empty()){
                ret = false;
            }else {
                s.pop();
            }
        }
        // 균형잡힌문자열(가장짧은 올바른 문자열) u의 위치
        if(left == right){
            *position = i+1;            // u의 위치
            return ret;
        }
    }
    return true;
}

int main(void){
    string p = "(()())()";
    int position;
    
    
   if(p == ""){
       return p;
   }
       
    // 균형잡힌 문자열, 올바른 문자열인지 체크
    bool check = isCheckString(p, &position);
    
    string u = p.substr(0,position);
    string v = p.substr(position, u.length() - position);
    string answer = "";
    if(check){
        return u + solution();
    }else {
        answer = '(' + solution() + ')';
    }
    
    for(int i=1; i<u.length()-1; i++){
        if(u[i] == ')'){
            answer += '(';
        }else {
            answer += ')';
        }
    }
        
    
    return answer;

}
