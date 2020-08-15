//
//  2*N타일링(2)11727.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/15.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int memo[1001];


// https://jaemin8852.tistory.com/158

int dp(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 3;
    }
    if(memo[n] > 0){
        return memo[n];
    }else {
        memo[n] = (dp(n-1) + dp(n-2) * 2) % 10007;
    }
    return memo[n];
}
int main(void){
    int n;
    cin >> n;
    cout << dp(n) << '\n';
    return 0;
}
