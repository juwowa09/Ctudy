#include <iostream>
#include <map>
#include <iomanip> // setprecision과 fixed를 사용하기 위해 필요

using namespace std;

void percolatedown(int *arr, int index, int len)
{ // 자식 왼쪽 존재 x
    if (index * 2 + 1 > len)
        return;
    int max;
    if (index * 2 + 2 > len)
        max = 1;
    else // 자식 오른쪽
        max = arr[2 * index + 1] < arr[2 * index + 2] ? 1 : 0;
    if (max && arr[index] > arr[2 * index + 1])
    {
        int temp = arr[index];
        arr[index] = arr[2 * index + 1];
        arr[2 * index + 1] = temp;
        percolatedown(arr, index * 2 + 1, len);
    }
    else if (!max && index * 2 + 2 <= len && arr[index] > arr[2 * index + 2])
    {
        int temp = arr[index];
        arr[index] = arr[2 * index + 2];
        arr[2 * index + 2] = temp;
        percolatedown(arr, index * 2 + 2, len);
    }
}

void buildheap(int *arr, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        percolatedown(arr, i, len);
    }
}
int pop(int *arr, int len)
{
    int temp = arr[0];
    arr[0] = arr[len];
    len -= 1;
    percolatedown(arr, 0, len);
    return temp;
}

void percolateup(int *arr, int pos, int n)
{
    if (pos == 0)
        return;
    if (arr[pos] < arr[(pos - 1) / 2])
    {
        int temp = arr[(pos - 1) / 2];
        arr[(pos - 1) / 2] = arr[pos];
        arr[pos] = temp;
        percolateup(arr, (pos - 1) / 2, n);
    }
}

void push(int *arr, int len, int n)
{
    arr[len] = n;
    percolateup(arr, len, n);
}

int *top(int *arr)
{
    return &arr[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, nsquare;
    cin >> n;
    nsquare = n * n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        push(arr, i, k);
    }
    for (int i = 0; i < nsquare - n; i++)
    {
        cin >> k;
        push(arr, n, k);
        pop(arr, n);
    }
    cout << arr[0];
}

// #include <iostream>

// using namespace std;

// void percolatedown(int *arr, int index, int len)
// { // 자식 왼쪽 존재 x
//     if (index * 2 + 1 > len)
//         return;
//     int max;
//     if (index * 2 + 2 > len)
//         max = 1;
//     else // 자식 오른쪽
//         max = arr[2 * index + 1] > arr[2 * index + 2] ? 1 : 0;
//     if (max && arr[index] < arr[2 * index + 1])
//     {
//         int temp = arr[index];
//         arr[index] = arr[2 * index + 1];
//         arr[2 * index + 1] = temp;
//         percolatedown(arr, index * 2 + 1, len);
//     }
//     else if (!max && index * 2 + 2 <= len && arr[index] < arr[2 * index + 2])
//     {
//         int temp = arr[index];
//         arr[index] = arr[2 * index + 2];
//         arr[2 * index + 2] = temp;
//         percolatedown(arr, index * 2 + 2, len);
//     }
// }

// void buildheap(int *arr, int len)
// {
//     for (int i = len / 2; i >= 0; i--)
//     {
//         percolatedown(arr, i, len);
//     }
// }

// int pop(int *arr, int *len)
// {
//     int temp = arr[0];
//     arr[0] = arr[*len];
//     *len -= 1;
//     percolatedown(arr, 0, *len);
//     return temp;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, k, nsquare;
//     cin >> n;
//     nsquare = n * n;
//     int *arr = new int[nsquare];
//     for (int i = 0; i < nsquare; i++)
//     {
//         cin >> k;
//         arr[i] = k;
//     }
//     nsquare -= 1;
//     buildheap(arr, nsquare);
//     for (int i = 0; i < n - 1; i++)
//     {
//         pop(arr, &nsquare);
//     }
//     cout << pop(arr, &nsquare);
// }