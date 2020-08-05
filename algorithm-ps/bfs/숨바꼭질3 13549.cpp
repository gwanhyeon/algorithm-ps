//
//  숨바꼭질3 13549.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/05.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m = 0;

int check[100001];
int map[100001];
const int MAX = 100001;

int main(void){
    cin >> n >> m;
    queue<int> q;
    queue<int> next_q;
    memset(check,-1,sizeof(check));
    map[n] = 0;         //몇초의 시간을 저장하는 맵
    check[n] = 1;
    q.push(n);
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        // x * 2
        if(dx*2 < MAX && check[dx*2] == -1){
            check[dx*2] = 1;
            q.push(dx*2);
            map[dx*2] = map[dx];
        }
        // x-1
        if(dx-1 >= 0 && check[dx-1] == -1){
            check[dx-1] = 1;
            next_q.push(dx-1);
            map[dx-1] = map[dx] + 1;
        }
        // x+1
        if(dx+1 < MAX && check[dx+1] == -1){
            check[dx+1] = 1;
            next_q.push(dx+1);
            map[dx+1] = map[dx] + 1;
            
        }
        
        
        // 0초의 경우 1초의 경우 매번 경우가 달라져야하므로 새로운 큐를 생성해서 next_q로 처리한다.
        if(q.empty()){
            q = next_q;
            next_q = queue<int>();
        }
        
    }
    cout << map[m] << '\n';
    return 0;
}
