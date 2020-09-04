//
//  방금그곡.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/03.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    // 1. Input
    vector<string> musicinfos{"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    string m = "ABC";
    string answer = "";
    
    
    
    
    for(int i=0; i<musicinfos.size(); i++){
        //cout << musicinfos[i] << ' ';
        int song_time = 0;
        int start_h = 0;
        int start_m = 0;
        int end_h = 0;
        int end_m = 0;
        string song_title = "";
        string song_info = "";
        int cnt = 0;
        for(int j=0; j<musicinfos[i].size(); j++){
            /*
             1.음악 start, end 시간, 곡 제목, 곡 정보가 주어진다.
             2. : 가 존재하면 시간임, "," 가 존재하면 다음 continue;
             3. HH:MM -> 분으로 변경하여서 시작시간 - 끝나는 시간
             4. 실제 재생된곡과 해당 들은 멜로디분을 확인한다
             */
            if(musicinfos[i][j] == ','){
                cnt +=1;
                continue;
            }
            if(musicinfos[i][j] == ':'){
                int h = stoi(musicinfos[i].substr(j-2,2));
                int m = stoi(musicinfos[i].substr(j+1,2));
                // start time
                if(cnt == 0){
                    start_h += h * 60;
                    start_m += m;
                }
                // end time
                if(cnt == 1){
                    end_h += h * 60;
                    end_m += m;
                    song_time = (end_h + end_m) - (start_h + start_m);
                }
            // 대문자 인경우만
            }else{
                // 곡 제목
                if(cnt == 2){
                    song_title += musicinfos[i][j];
                }
                // 곡 정보
                if(cnt > 3){
                    song_info += musicinfos[i][j];
                }
            }
        }
        // 곡 정보 체크
        int song_info_cnt = 0;
        for(int k=0; k<song_time; k++){
            if(song_info.size() == song_info_cnt){
                song_info_cnt = 0;
            }
            if(song_info.size() < k+1){
                song_info += song_info[song_info_cnt];
                song_info_cnt++;
            }
        }
        if (song_info.find(m) != string::npos) {
            answer = song_title;
            break;
        }
    }
    cout << answer << '\n';
    
    
    return 0;
}
