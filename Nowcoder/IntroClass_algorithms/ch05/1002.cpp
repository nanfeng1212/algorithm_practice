#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    int times = T;
    while(times--)
    {
        priority_queue<int, vector<int>, less<int> >line1;
        priority_queue<int, vector<int>, greater<int> >line2;
        int order,N,getNum;
        scanf("%d%d", &order, &N);
        cout <<  order << " "<< (N + 1)/2 << "\n";
        int cnt = 0;
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &getNum);
            if(!line1.size() && !line2.size())
            {
                line1.push(getNum);
                if(i %2 == 1)
                {
                    cout << line1.top() << " ";   
                    cnt++;
                }
            }
            else if(!line2.size())
            {
                if(getNum < line1.top())
                {
                    line2.push(line1.top());
                    line1.pop();
                    line1.push(getNum);
                }
                else
                {
                    line2.push(getNum);
                }
                if(i %2 == 1)
                {
                    cout << (line1.top() + line2.top())/2 << " ";
                    cnt++;
                }   
            }
            else
            {
                if(line1.size() == line2.size())
                {
                    if(getNum > line2.top())
                    {
                        line1.push(line2.top());
                        line2.pop();
                        line2.push(getNum);
                    }
                    else
                    {
                        line1.push(getNum);
                    }
                    if(i %2 == 1)
                    {
                        cout << line1.top() << " ";
                        cnt++;
                    }
                }
                else if((line1.size() - line2.size()) == 1)
                {
                    if(getNum < line1.top())
                    {
                        line2.push(line1.top());
                        line1.pop();
                        line1.push(getNum);
                    }
                    else
                    {
                        line2.push(getNum);
                    }
                    if(i %2 == 1)
                    {
                        cout << (line1.top() + line2.top())/2 << " ";   
                        cnt++;
                    }
                }
            }
            if(cnt%10 == 0 && i %2 == 1)
            {
                cout << "\n";
            }
        }
        if(order != T && cnt%10 != 0)
        {
            cout << "\n";   
        }
    }
    return 0;
}