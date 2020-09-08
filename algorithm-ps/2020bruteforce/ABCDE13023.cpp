//
//  ABCDE13023.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/31.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int n[2001][2001];
int m[2001];

int main(void){
    int a,b;
    cin >> a >> b;
    
    for(int i=0; i<b; i++){
        int c,d = 0;
        cin >> c >> d;
        n[c][d] = 1;
    }
    
    int cnt = 0;
    for(int i=0; i<b; i++){
        if(n[i][i+1] == 1){
            cnt +=1;
        }
    }
    
    if(cnt == b){
        cout << "1" << '\n';
    }else {
        cout << "0" << '\n';
    }
    
    return 0;
}
