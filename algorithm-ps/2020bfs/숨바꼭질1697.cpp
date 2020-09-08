//
//  숨바꼭질1697.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/04.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m = 0;

const int MAX = 100001;
int map[100001];
int check[100001];

int main(void){
    cin >> n >> m;
    queue<int> q;
    map[n] = 0;
    check[n] = 1;
    q.push(n);
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        
            if(dx-1 >= 0){
                if(check[dx-1] == 0){
                    q.push(dx-1);
                    check[dx-1] = 1;
                    map[dx-1] = map[dx] +1;
                }
            }
            
            if(dx+1 < MAX){
                if(check[dx+1] == 0){
                    q.push(dx+1);
                    check[dx+1] = 1;
                    map[dx+1] = map[dx] + 1;
                }
            }
            
            if(dx*2 < MAX){
                if(check[dx*2] == 0){
                    q.push(dx*2);
                    check[dx*2] = 1;
                    map[dx*2] = map[dx] + 1;
                }
            }
    }
    cout << map[m];
    return 0;
}
