#include <iostream>
#include <set>
#include <map>

using namespace std;

int N;
int arr[101];
set<int> setA, setB;


int main(){
    cin >> N;

    for (auto i = 1; i <= N; i++){
        cin >> arr[i];
        setA.insert(i);
        setB.insert(arr[i]);
    }

    while(setA != setB){

        set<int> setTempA;

        for (auto i : setA){
            if (setB.find(i) != setB.end()){
                setTempA.insert(i);
            }
        }

        setA = setTempA;

        set<int> setTempB;

        for (auto i : setA){
            setTempB.insert(arr[i]);
        }

        setB = setTempB;
    }

    cout << setB.size() << '\n';

    for(auto i : setB){
        cout << i << '\n';
        
    }
}
