#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//定义long long为ll
ll prime[40005], ans[40005], x, xx, cnt, flag;
int main()
{//求解40000以内的素数（埃氏筛）
    for (ll i = 1; i <= 40000; i++)//40000的平方大于1e9
        prime[i] = 1; x = 2;//初始化数组中所有数为1
    while (x <= 40000)
    {
        for (ll j = 2; j*x <= 40000; j++)
        {
            if (prime[x] == 1)//2为素数
            {
                prime[j*x] = 0;//素数的倍数即非素数初始化为0
            }
        }
        x++;
    }
    //判断素数
    ll T, m;
    cin >> T;
    while (T--)//使得输出全部结束后不会换行
    {
        ll ans[40005] = { 0 };//或者memset(ans,0,sizeof(ll));
        cnt = 0;
        cin >> xx;
        x = xx;//防止xx的原始输入值变化
        for (ll i = 2; i <= floor(sqrt(xx)) + 1; i++)//floor(sqrt(xx))+1一定小于40000
        {
            if (x == 1) break;//如果x=1，说明循环结束，立刻终止循环，防止其继续存入数组
            if (x <= 40000 && prime[x] == 1)//如果x是40000内的素数
            {
                ans[++cnt] = x;//或者cnt=cnt+1;ans[cnt]=x;
                               //将x存入数组ans中，此时ans[1]=x
                break;//退出for循环
            }
            //如果x不是40000内的素数
            if (prime[i] == 1 && x%i == 0)//如果i是素数因子
            {
                while (x%i == 0) x /= i;//让x一直除i，直到i不是x的素数因子为止
                                        //注意：x如果是40000内的非素数，其经历多次while循环的结果必为1
                                        //如果x=1,就会继续循环到上面存入数组，产生干扰（上面埃氏筛没有将1筛选成非素数）
                ans[++cnt] = i;//或者cnt=cnt+1;ans[cnt]=i;
                               //将x的素数因子i按从小到大的顺序存入数组ans中
            }
        }//for循环结束
         //如果循环后x>40000，则剩下的这个x一定是素数
         //反证法：如果剩下的x不是素数，则其必定被小于40000的素数因子循环掉
        if (x>40000) ans[++cnt] = x;//或者cnt=cnt+1;ans[cnt]=x;
        if (cnt == 1 && ans[1] == xx) cout << "isprime" << endl;
        else cout << "noprime" << endl;
        for (ll i = 1; i <= cnt; i++)
        {
            if (i == cnt) cout << ans[i];
            else cout << ans[i] << " ";
        }
        if (T != 0) cout << endl;
    }
    return 0;
}