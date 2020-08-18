//
//  123더하기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/16.
//  Copyright © 2020 kgh. All rights reserved.
//

/*
 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

 1+1+1+1
 1+1+2
 1+2+1
 2+1+1
 2+2
 1+3
 3+1
 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
 */
#include <stdio.h>
#include <iostream>
using namespace std;
int memo[11];

int dp(int n){
    if(n == 0){
        return 1;
    }
    if(memo[n] > 0){
        return memo[n];
    }
    if(n-1 >= 0){
        memo[n] += dp(n-1);
    }
    if(n-2 >= 0){
        memo[n] += dp(n-2);
    }
    if(n-3 >= 0){
        memo[n] += dp(n-3);
    }
    return memo[n];
}
int main(void){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int res = dp(n);
        cout << res << '\n';
    }
    return 0;
}
