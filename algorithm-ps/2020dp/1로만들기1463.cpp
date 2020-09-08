//
//  1로만들기1463.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/15.
//  Copyright © 2020 kgh. All rights reserved.
//

/*
 
 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

 X가 3으로 나누어 떨어지면, 3으로 나눈다.
 X가 2로 나누어 떨어지면, 2로 나눈다.
 1을 뺀다.
 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
 
 
 TOP DOWN방식

 */

#include <stdio.h>
#include <iostream>
using namespace std;

int memo[1000001];

int dp(int n){
    
    
    if(n == 1){
        return 0;
    }
    
    if(memo[n] > 0){
        return memo[n];
    }
    memo[n] = dp(n-1) + 1;
    if(n % 3 == 0){
        int temp = dp(n/3) + 1;
        if(memo[n] > temp){
            memo[n] = temp;
        }
    }
    if(n % 2 == 0){
        int temp = dp(n/2) + 1;
        if(memo[n] > temp){
            memo[n] = temp;
        }
    }
    return memo[n];
}

int main(void){
    // top down
    int n;
    cin >> n;
    
    int res = dp(n);
    cout << res << '\n';
    return 0;
}
