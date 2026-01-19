#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> add(vector<int>& num1, vector<int>& num2) {
    int n=max(num1.size(), num2.size())+1;
    vector<int> result(n,0);
    num1.resize(n,0);
    num2.resize(n,0);
    for(int i=0;i<n;++i) {
        result[i]=num1[i]+num2[i];
    }
    for(int i=0;i<n;++i) {
        if(result[i]>=10) {
            result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    while(result.size()>1&&result.back()==0)result.pop_back();
    return result;
}
vector<int> multiply(vector<int>& num1, vector<int>& num2) {
    int n=num1.size()+num2.size();
    vector<int> result(n,0);
    for(int i=0;i<num1.size();++i) {
        for(int j=0;j<num2.size();++j) {
            result[i+j]+=num1[i]*num2[j];
        }
    }
    for(int i=0;i<n;++i) {
        if(result[i]>=10) {
            result[i+1]+=result[i]/10;
            result[i] %= 10;
        }
    }
    while(result.size()>1&&result.back()==0)result.pop_back();
    return result;
}
vector<int> multiply_int(vector<int> num, int x) {
    for(int i=0;i<num.size();++i) {
        num[i]*=x;
    }
    for(int i=0;i<num.size();++i) {
        if(num[i]>=10) {
            if(i+1==num.size()) num.push_back(0);
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
    }
    return num;
}
vector<int> divide_int(vector<int> num, int x) {
    vector<int> res;
    int rem=0;
    for(int i=num.size()-1;i>=0;--i) {
        rem=rem*10+num[i];
        res.push_back(rem/x);
        rem%=x;
    }
    reverse(res.begin(),res.end());
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}
void print(vector<int> num) {
    for(int i=num.size()-1; i>=0;--i) {
        cout<<num[i];
    }
    cout<<endl;
}
main() {
    int n;
    cin>>n; 
    if(n==0) {
        cout<<1<<endl;
        return 0;
    }
    vector<int> catalan = {1};
    for(int i=1; i<=n;++i) {
        vector<int> temp = multiply_int(catalan, 4*i - 2);
        catalan = divide_int(temp, i + 1);
    } 
    print(catalan);
}