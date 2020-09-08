//
//  진법변환.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/11.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
char arr[100];
int main(void){
    int num = 19;
    int jinsu = 16;
    //cin >> num >> jinsu;
    int cnt=0;
    while(num > 0){
        int tmp = num % jinsu;
        // 16진수까지 표현
        if(tmp >= 10 && tmp <= 15){
            arr[cnt] = (char)('A' + (tmp-10));        // tmp-10 문자로 바꾸어줌 'A'
        }else {
            arr[cnt] = (char)('0' + tmp);     // 문자열 변경
        }
        num /= jinsu;
        cnt++;
    }
    while(cnt >= 0){
        cout << arr[cnt];
        cnt--;
    }
    return 0;
}
