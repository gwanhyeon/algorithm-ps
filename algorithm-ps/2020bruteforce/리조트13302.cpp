//
//  리조트13302.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/14.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int map[101];
int n,m = 0;
// 현재날짜랑 쿠폰을 세팅한다.
int dfs(int cur, int coupon){
    // termination condition
    // 여름방학일 경우 지나간다.
    if(cur >= n+1){
        return 0;
    }
    int ret = 1234567890;
    if(map[cur]){
        ret = min(ret,dfs(cur+1,coupon));
    }else {
        // 이용권을 1일 사용한다 가격 10000 쿠폰 X
        ret = min(ret, dfs(cur+1, coupon) + 10000);
        // 이용권을 3일 사용한다 가격 25000 쿠폰 1
        ret = min(ret, dfs(cur+3, coupon+1) +25000);
        // 이용권을 5일 사용한다 가격 37000 쿠폰 2
        ret = min(ret, dfs(cur+5, coupon+2) + 37000);
        // 쿠폰이 3장일 경우 이용권하루를 무료로 사용한다.
        if(coupon>=3){
            ret = min(ret,dfs(cur+1, coupon-3));
        }
    }
    return ret;
    
    // 리턴값: 리조트에 입장하기 위해서 지불해야 하는 비용의 최솟값
}
int main(void){
    
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        cin >> map[i];
        map[i] = 1;
    }
    
    cout << dfs(1,0);
    
    return 0;
}
