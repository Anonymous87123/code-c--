#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        const int N=n;
        double a[N];
        double sum=0;int count=0;
        if(n==0){cout<<sum<<" "<<count<<endl;continue;}
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
            if(5000<a[i]&&a[i]<=8000){sum+=(a[i]-5000)*0.03;count++;}
            else if(8000<a[i]&&a[i]<=17000)
            {
                sum+=3000*0.03+(a[i]-8000)*0.1;count++;
            }
            else if(17000<a[i]&&a[i]<=30000)
            {
                sum+=3000*0.03+9000*0.1+(a[i]-17000)*0.2;count++;
            }
            else if(30000<a[i]&&a[i]<=40000)
            {
                sum+=3000*0.03+9000*0.1+13000*0.2+(a[i]-30000)*0.25;count++;
            }
            else if(40000<a[i]&&a[i]<=60000)
            {
                sum+=3000*0.03+9000*0.1+13000*0.2+10000*0.25+(a[i]-40000)*0.3;count++;
            }
            else if(60000<a[i]&&a[i]<=85000)
            {
                sum+=3000*0.03+9000*0.1+13000*0.2+10000*0.25+20000*0.3+(a[i]-60000)*0.35;count++;
            }
            else if(a[i]>85000)
            {
                sum+=3000*0.03+9000*0.1+13000*0.2+10000*0.25+20000*0.3+25000*0.35+(a[i]-85000)*0.45;count++;
            }
        }
        cout<<sum<<" "<<count<<endl;
    }
}