//
//  소수찾기1978.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[101];

// 소수 판별 함수
bool primeNumber(int n){
    
    // 2 미만은 소수 성립하지 않음
    if(n < 2){
        return false;
    }
    
    // 루트 i 까지만 진행해도 된다. 그이유는 n루트의 값 이상일수 없기때문에.
    
    for(int i=2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    // 위조건에 만족하지않으면 소수가 맞음.
    return true;
    
    
}
int main(void){
    /*
    int t = 0;
    int cnt = 0;
    cin >> t;
    
    for(int i=0; i<t; i++){
        
        cin >> arr[i];
        bool res = primeNumber(arr[i]);
        
        // res값이 소수 일경우 값을 1 개 늘려준다.
        if(res == true){
            cnt += 1;
        }
    }
    cout << cnt;
     */
    
    
    int cnt=2;
    int a[100];
    for(int i=0; i<10; i++){
        a[cnt++] = i;
        cout << "cnt" << cnt;
        cout << "i" << i;
        
    }
    
    return 0;
    
}
