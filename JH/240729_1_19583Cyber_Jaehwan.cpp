#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int s, e, q;
string ex;
string th, tm, id;
string input, line;


int main(){
    cin >> s >> e >> q;

    while (true){
        getline(cin, line);

        if(line.empty()) {
            break;
        }

        input += line + '\n'
    }

    stringstream ss(input);

    while(getline(ss, line)){
        size_t pos = line.find(':')
    }


}