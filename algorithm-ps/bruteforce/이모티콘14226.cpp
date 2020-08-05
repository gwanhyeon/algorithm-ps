//
//  이모티콘14226.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/05.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int cnt = 0;
int check[1001][1001];

int main(void){
    int target = 0;
    cin >> target;
    
    memset(check,-1,sizeof(check));
    queue<pair<int,int>> q;
    q.push({1,0});          // 1: S 0: C
    
    check[1][0] = 0;
    
    while(!q.empty()){
        int s,c;
        s = q.front().first;
        c = q.front().second;
        q.pop();
        
        // 복사(s,c) => (s,s)
        if(check[s][s] == -1){
            check[s][s] = check[s][c] + 1;
            q.push({s,s});
        }
        // 붙여넣기(s,c) => (s+c, c)    target값 이하까지만
        if(s+c <= target && check[s+c][c] == -1){
            check[s+c][c] = check[s][c] +1;
            q.push({s+c,c});
            
        }
        // 화면에 있는 이모티콘중 하나 삭제 (s,c) => (s-1,c)   0이상의 값만
        if(s-1 >= 0 && check[s-1][c]) {
            check[s-1][c] = check[s][c] +1;
            q.push({s-1,c});
        }
    }
    
    int ans = -1;
    
    for(int i=0; i<=target; i++){
        // 값이 있는 경우
        if(check[target][i] != -1){
            if(ans == -1 || ans > check[target][i]){
                ans = check[target][i];
            }
        }
    }
    cout<< ans << '\n';
    
    return 0;
}
