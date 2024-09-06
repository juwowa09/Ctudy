#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    set<string> s;
    string line;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        s.insert(line);
    }

    for (int i = 0; i < M; i++) {
        getline(cin, line);
        string word;
        stringstream ss(line);

        while (getline(ss, word, ',')) {
            if (s.find(word) != s.end()) {
                s.erase(word);
            }
        }

        cout << s.size() << '\n';
    }

    return 0;
}
