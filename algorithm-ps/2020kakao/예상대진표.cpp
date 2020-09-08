//
//  예상대진표.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/01.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n = 8;
    int a = 4;
    int b = 7;
    int left = 0;
    int right = 0;
    
    if(a > b){
        left = b;
        right = a;
        
    }else {
        left = a;
        right = b;
    }
    int answer = 1;     // 라운드 시작 1번 겨루는것이 초기화 값
    while(true){
        // 차이가 right - left가 되어야지 값이 왼쪽, 오른쪽에 있는값이므로
        if(left % 2 != 0 && right - left == 1){
            break;
        }
        left = (left + 1) / 2;          // 홀수일 경우
        right = (right + 1) / 2;        // 짝수일 경우
        answer+=1;
    }
    cout << answer << '\n';
    return 0;
}

/*
int main(void){
    
    int n = 8;
    int a = 4;
    int b = 7;
    vector<int> v;
    int round_size = n;
    bool isRound = false;
    int ans = 0;
    while(true){
        ans +=1;
        if(isRound == true){
            break;
        }
        for(int i=1; i<round_size; i++){
            // A와 B가 만나는 경우
            if(i == a && i+1 == b){
                isRound = true;
                break;
            }
            // A가 이기는 경우
            if(i == a || i+1 == a){
                v.push_back(a);
            }
            // B가 이기는 경우
            else if(i == b || i+1 == b){
                v.push_back(b);
            }else {
                // 나머지 경우 첫번쨰 참가자가 이길수도 있고, 이기지 않을수도 있음.
                v.push_back(i);
            }
        }
        round_size = v.size();
        v.clear();
    }
    cout << ans << '\n';
    
    
    
    
    return 0;
}
 */
