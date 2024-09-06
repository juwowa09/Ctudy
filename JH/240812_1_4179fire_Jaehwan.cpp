#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int R, C;

vector<string> lines(1000);

int J_y, J_x;
int ans = 1e9;

void dfs(int _y, int _x, int _walk);
void fire(int _y, int _x, queue<pair<int, int>>& _q);

int main(){


    cin >> R >> C;

    cin.ignore();

    for(auto i = 0; i < R; i++){
        getline(cin, lines[i]);
        for(auto j = 0; j < C; j++){
            if(lines[i][j] == 'J'){
                J_y = i;
                J_x = j;
            }
        }
    }

    dfs(J_y, J_x, 0);


    if (ans == 1e9) cout << "IMPOSSIBLE";
    else cout << ans;
    
}

void dfs(int _y, int _x, int _walk){
    if (_y < 0 || _y >= R){
        ans = min(ans, _walk); return;
    }

    
    else if(_x < 0 || _x >= C){
        ans = min(ans, _walk); return;
    }


    queue<pair<int, int>> q;

    for(auto i = 0; i < R; i++){
        for(auto j = 0; j < C; j++){
            if(lines[i][j] == 'F'){
                fire(i, j, q);
            }
        }
    }

    if(lines[_y][_x] != '.') return;

    lines[_y][_x] = 'X';

    dfs(_y, _x + 1, _walk + 1);
    dfs(_y, _x - 1, _walk + 1);
    dfs(_y + 1, _x, _walk + 1);
    dfs(_y - 1, _x, _walk + 1);

    lines[_y][_x] = '.';

    while(!q.empty()){
        lines[q.front().first][q.front().second] = '.';
        q.pop();
    }
 
}

void fire(int _y, int _x, queue<pair<int, int>>& _q){
    if(_x + 1 < C && lines[_y][_x + 1] == '.'){
        lines[_y][_x + 1] = 'F';
        _q.push({_y, _x + 1});
    }
    if(_x - 1 >= 0 && lines[_y][_x - 1] == '.'){
        lines[_y][_x - 1] = 'F';
        _q.push({_y, _x - 1});
    }
    if(_y + 1 < R && lines[_y + 1][_x] == '.'){
        lines[_y + 1][_x] = 'F';
        _q.push({_y + 1, _x});
    }
    if(_y - 1 >= 0 && lines[_y - 1][_x] == '.'){
        lines[_y - 1][_x] = 'F';
        _q.push({_y - 1, _x});
    }
    
}