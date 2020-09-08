//
//  숨바꼭질3 13549(deck).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/05.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int map[100001];
int check[100001];
int n,m = 0;
const int MAX = 100001;
int main(void){
    
    deque<int> q;
    cin >> n >> m;
    
    memset(check,-1,sizeof(check));
    q.push_back(n);
    check[n] = 1;
    map[n] = 0;
    
    while(!q.empty()){
        int dx = q.front();
        q.pop_front();
        // 순간이동 *2
        if(dx*2 < MAX && check[dx*2] == -1){
            check[dx*2] = 1;
            q.push_front(dx*2);
            map[dx*2] = map[dx];
        }
        // X-1
        
        if(dx-1 >= 0 && check[dx-1] == -1){
            check[dx-1] = 1;
            q.push_back(dx-1);
            map[dx-1] = map[dx] + 1;
        }
        // X+1
        if(dx+1 < MAX && check[dx+1] == -1){
            check[dx+1] = 1;
            q.push_back(dx+1);
            map[dx+1] = map[dx] +1;
        }
    }
    cout << map[m] << '\n';
    return 0;
}
