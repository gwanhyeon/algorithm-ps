//
//  후보키.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/02.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int n){
    
    int ret = 0;
    
    while(n){
        // 첫번째 비트가 켜져 있는 경우
        if(n & 1){
            ret++;
        }
        n = n >> 1;
        
    }
    return ret;
}

bool comp(int a,int b){
    int x = countBits(a);
    int y = countBits(b);
    
    return x > y;
}
bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset){
    
    // rowsize => attribute 개수라고 생각하면된다.
    // attibute의 모든 경우를 구해준다
    for(int a=0; a<rowsize-1; a++){
        // a b c d(ab ac ad bc bd cd)
        for(int b=a+1; b<rowsize; b++){
            bool isCheck = true;
            // 모든 속성을 만들어낸다. 속성의 값들
            for(int k=0; k<colsize; k++){
                // k번째 비트만 켜지게 된다.
                // k가 0이면 첫번째 비트가 켜져있는지 확인
                if((subset & 1 << k) == 0){
                    // 속성을 사용하지 않으므로 continue;
                    continue;
                }
                if(relation[a][k] != relation[b][k]){
                    isCheck = false;
                    break;
                }
            }
            // 유일성을 만족하지 못할때 false 모두 같았을 경우
            if(isCheck == true){
                return false;
            }
        }
    }
    return true;
}
int main(void){
    vector<vector<string>> relation{{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    int answer = 0;
    int rowsize = relation.size();
    int colsize = relation.front().size();
    
    vector<int> candidates;
    
    // 0 은 공집합이므로 1부터 시작한다.
    for(int i=1; i< (1<<colsize); i++){
    
        // check() : i가 모든 튜플을 식별하는지 확인
        if(check(relation, rowsize, colsize, i)){
            // true일 경우 유일성을 만족시키는 경우
            candidates.push_back(i);
        }
    }
        
    sort(candidates.begin(), candidates.end(), comp);
    
    while(!candidates.empty()){
        int n = candidates.back();
        candidates.pop_back();
        answer++;
        
        for(vector<int>::iterator it = candidates.begin(); it != candidates.end();){
            
            // n&*it == n이나오면 모든값을 모함하고 있다는 뜻이다.
            // 최소성을 만족하지 못하는 조건 -> 지우기
            if((n & *it) == n){
                it = candidates.erase(it);
            }
            else {
                ++it;
            }
            
        }
        // 나머지 candidates항목중에서 해당 속성을 포함하고 있는 후보키들을 지워주어야한다.
    }
        
    
    cout << answer << '\n';

}


 
/*
int main(void){
    vector<vector<string>> v{{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    int ans = 0;
    bool check = false;
    for(int i=0; i<v.size(); i++){
        int cnt = 0;
        for(int j=0; j<v[i].size()-1; j++){
            if(v[j][i] == v[j+1][i]){
                cnt += 1;
            }
        }
        // 후보키
        if(cnt == 0){
            ans += 1;
            check = false;
            // 후보키 충족 완료
        }
        // 후보키가 아닐 경우
        else if(cnt > 0){
            check = true;
        }
        // 하나라도 같은 값이 있는 경우라면 체크가 된 값이면
        if(check == true){
            ans +=1;
            check = false;
        }

    }
    
    cout << ans << '\n';
    return 0;
}
*/
