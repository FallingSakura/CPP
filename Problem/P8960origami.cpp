#include<bits/stdc++.h>
using namespace std;
long long T;
long long n, k;
char s[75];
bool b[75];
bool flag; // true => Up, false => Down
int main()
{
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> n >> k;
        for(long long i = 1; i <= n; i++)
        {
            cin >> s[i];
            b[i] = (s[i] == '1'); // bool 表达式
        }
        long long l = 1, r = pow(2, n) - 1; // 初始左右边界
        long long i = 1;
        flag = false; // 第一道折痕一定是谷折
        while(l <= r) // 从第二次折开始遍历
        {
            i++; // 第i-1次折叠
            long long mid = (l + r) >> 1;
            if(k < mid) // 处理左半部分
            {
                r = mid - 1;
                flag = !b[i - 1];
            }
            else if(k > mid) // 处理右半部分
            {
                l = mid + 1;
                flag = b[i - 1];
            }
            else // 如果 (k == mid) 说明到达了目标位置，可以输出了
            {
                if(flag)
                {
                    cout << "Up";
                }
                else
                {
                    cout << "Down";
                }
                cout << endl;
                break;
            }
        } 
    }
    return 0;
}