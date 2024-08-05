#include <iostream>
#include <string>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

int N, M;
set<string> keywords;
vector<string> blogs;

void input(){
    cin >> N >> M;
    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        keywords.insert(tmp);
    }

    for(int i = 0; i < M; i++){
        cin >> tmp;
        blogs.push_back(tmp);
    }
}

void sol(){
    for(int i = 0; i < M; i++){
        string tmp = "";
        string blog = blogs[i];
        for(int i = 0; i < int(blog.size()); i++){
            if(blog[i] == ','){
                keywords.erase(tmp);
                tmp = "";
            }
            else{
                tmp += blog[i];
            }
        }
        keywords.erase(tmp);
        cout << keywords.size() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    sol();
    return 0;
}