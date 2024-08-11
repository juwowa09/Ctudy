#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1001;

int R, C;
char map[MAX][MAX];
queue<pair<int,int>> fires;
queue<pair<int,int>> jihun;
bool isVisited[MAX][MAX] = {0};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int answer = 10e7;

void input(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                jihun.push({i,j});
                isVisited[i][j] = true;
            }
            else if(map[i][j] == 'F'){
                fires.push({i,j});
            }
        }
    }
}

bool isWall(int r, int c){
    if(map[r][c] == '#') return true;
    return false;
}

bool isFire(int r, int c){
    if(map[r][c] == 'F') return true;
    return false;
}

bool isEXIT(int r, int c){
    if(r < 0 || c < 0 || r >= R || c >= C) return true;
    return false;
}

//방법 1. queue를 이용하여 구현하기
//방법 2. array를 이용하여 구현하기
void fire_spreadings(int r, int c){
    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(isWall(nr,nc) || isEXIT(nr,nc) || isFire(nr,nc)) continue;
        else if(map[nr][nc] == '.') {
            map[nr][nc] = 'F';
            fires.push({nr,nc});
        }
    }   
}

void fire_Turn(){
    int firesize = fires.size();
    for(int i = 0; i < firesize; i++){
        auto fire = fires.front();
        fires.pop();
        int x = fire.first;
        int y = fire.second;
        fire_spreadings(x,y);
    }
}

void jihun_Turn(int r, int c, int time){
    for(int i = 0; i < 4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(isEXIT(nx,ny)){
            //cout << "ESCAPE! -> " << nx << " : " << ny << "/ " << time << endl;
            answer = min(answer, time);
        }
        else if(isWall(nx,ny) || isFire(nx,ny) || isVisited[nx][ny]) continue;
        else{
            jihun.push({nx,ny});
            isVisited[nx][ny] = true;;
        }
    }
}

void print(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void sol(){ 
    int time = 0;
    int move_size = 0;
    while(!jihun.empty()){
        if(move_size == 0){
            move_size = jihun.size();
            fire_Turn();
            time++;
        }
        auto next_move = jihun.front();
        //cout << next_move.first << " : " << next_move.second << endl;
        jihun.pop();
        move_size -= 1;
        jihun_Turn(next_move.first, next_move.second, time);
    }

    if(answer == 10e7) cout << "IMPOSSIBLE" << endl;
    else cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    input();
    sol();

    return 0;
}