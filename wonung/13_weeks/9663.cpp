#include <iostream>
using namespace std;

int map[15];
int n;
int result = 0;

bool check(int index, int cur_row)
{
    for (int i = 1; i <= index; i++)
    {
        if (map[index - i] == cur_row || map[index - i] == cur_row + i || map[index - i] == cur_row - i)
            return false;
    }
    return true;
}

void search_position(int index, int cur_row)
{
    if (index == n || cur_row == n)
        return;

    if (check(index, cur_row))
    {
        map[index] = cur_row;
        if (index == n - 1)
            result++;
        search_position(index + 1, 0);
        map[index] = 0;
    }
    search_position(index, cur_row + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    search_position(0, 0);
    cout << result;
}