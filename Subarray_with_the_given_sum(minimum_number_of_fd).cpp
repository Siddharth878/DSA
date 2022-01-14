#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        b[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void merge_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, i;
        int s;

        cin >> n;
        int arr[n];
        cin >> s;

        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        merge_sort(arr, 0, n - 1);

        i = 0;
        int j = 0;
        int sum = 0, start = -1, end = -1;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= s)
            {
                ans = 1;
                break;
            }
        }

        while (j < n && sum + arr[j] <= s)
        {
            sum += arr[j];
            j++;
        }

        if (sum == s)
        {

            ans = min(ans, (j - (i + 1)) + 1);
        }

        while (j < n)
        {
            sum += arr[j];

            if(sum>=s)
            {
                ans = min(j-(i)+1,ans);

            }

            while (sum > s)
            {
                sum -= arr[i];
                i++;

                if (sum >= s)
                {
                    start = i + 1;
                    end = j + 1;

                    ans = min(ans, end - start + 1);
                }
            }

            if (sum == s)
            {
                start = i + 1;
                end = j + 1;
                ans = min(end - start + 1, ans);
            }

            j++;
        }

        ans == INT_MAX ? cout << -1 << endl : cout << ans << endl;
    }

    return 0;
}
