//
//  2653이진수만들기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/15.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int n, int bit){
    cout << "n" << n;
    cout << "bit" << bit << '\n';
    // 길이가 n이 아니면
    if(!n){
        
        cnt++;
        return;
    }
    dfs(n-1, 1);
    if(bit == 1){
        dfs(n-1, 0);
    }
    
}
int main(void){
    int n;
    cin >> n;
    
    // bit 0, 1
    // 비트는 1부터 시작한다.
    dfs(n, 1);
    
    cout << cnt;
    
    return 0;
}
