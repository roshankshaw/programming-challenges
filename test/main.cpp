/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
void push_digits(int num,set<int>&dig)
{
    while(num>0)
    {
        int d=num%10;
        dig.insert(d);
        num=num/10;
    }
}
bool check_digits(int num,set<int>&dig)
{
    while(num>0)
    {
        int d=num%10;
        if(dig.find(d)!=dig.end())
            return 0;
        num=num/10;
    }
    return 1;
}
int main(int argc, char *a[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,num;
        cin>>n;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            a.push_back(num);
        }
        sort(a.begin(),a.end());
        long long int max_sum=0;
        for(int i=n-1;i>=0;i--)
        {
            set<int>dig;
            push_digits(a[i],dig);
            long long int sum=a[i];
            for(int j=n-1;j>=0;j--)
            {
                if(i==j)
                    continue;
                if(check_digits(a[j],dig))
                {
                    sum+=a[j];
                    push_digits(a[j],dig);
                }
            }
            if(sum>max_sum)
                max_sum=sum;
        }
        cout<<max_sum<<"\n";
    }
}
