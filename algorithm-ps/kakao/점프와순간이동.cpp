//
//  점프와순간이동.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/31.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(void){
    int n=5;
    
    int ans = 0;
    //0이 될때까지 나누어준다.
    while(n!=0){
        
        // 순간이동의 경우
        if(n % 2 == 0 ){
            n = n / 2;      // 순간이동
                            // 배터리 소모는 없음
        }
        // 점프의 경우
        else {
            n = n -1;       // 점프
            ans +=1;        // 배터리소모
        }
    }
    
    
    
    return 0;
}

/*
int main(void){
    int MAX = 100000001;
    int map[MAX];
    int check[MAX];
    int N = 5;
    queue<int> q;
    memset(map,0,sizeof(map));
    memset(check,0,sizeof(check));
    map[0] = 0;
    check[0] = 1;
    q.push(0);
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        if(dx*2 < MAX){
            if(check[dx*2] == 0){
                q.push(dx*2);
                check[dx*2] = 1;
                map[dx*2] = map[dx];
            }
        }
        if(dx+1 < MAX){
            if(check[dx+1] == 0){
                q.push(dx+1);
                check[dx+1] = 1;
                map[dx+1] = map[dx] + 1;
            }
        }
    }
    
    cout << map[N] << '\n';
    return 0;
}
*/

