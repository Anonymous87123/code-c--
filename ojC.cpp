#include<bits/stdc++.h>
#define int long long
using namespace std;
int cmp(vector<int>&a,vector<int>&b){//传倒过来的
    for(int i=a.size()-1;i>=0;--i){
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return -1;
    }
    return 0;
}
vector<int> multiply (vector<int>&a,vector<int>&b){//倒序的a,b（传绝对值）
    int n=a.size()+b.size();
    vector<int> res(n,0);
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            res[i+j]+=a[i]*b[j];
        }
    }
    for(int i=0;i<n-1;++i){
        while(res[i]>=10){
            res[i]-=10;
            res[i+1]++;
        }
    }
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}
vector<int> add(vector<int>&a,vector<int>&b){
    int n=max(a.size(),b.size())+3;
    vector<int>result(n,0);
    a.resize(n,0);b.resize(n,0);
    for(int i=0;i<n;i++)result[i]=a[i]+b[i];
    for(int i=0;i<n-1;i++){
        while(result[i]>=10){
            result[i]-=10;result[i+1]++;
        }
    }
    while(result.size()>1&&result.back()==0)result.pop_back();
    return result;
}
vector<int>sub(vector<int>&a,vector<int>&b){//a>b默认
    int n=max(a.size(),b.size())+3;//0到n
    a.resize(n,0);b.resize(n,0);
    vector<int>result(n,0);
    if(cmp(a,b)==0){
        while(result.size()>1&&result.back()==0)result.pop_back();
        return result;
    }else{
        for(int i=0;i<n;i++)result[i]=a[i]-b[i];
        for(int i=0;i<n-1;i++){
            while(result[i]<0){
                result[i]+=10;result[i+1]--;
            }
        }
    }
    while(result.size()>1&&result.back()==0)result.pop_back();
    return result;
}
vector<int> mul_int(vector<int>&a,int b){
    int temp=b/10;
    int n=a.size()+temp+3;
    vector<int>result(n,0);
    for(int i=0;i<a.size();i++){
        result[i]=a[i]*b;
    }for(int i=0;i<result.size()-1;i++){
        while(result[i]>=10){
            result[i]-=10;result[i+1]++;
        }
    }
    while(result.size()>1&&result.back()==0)result.pop_back();
    return result;
}
void print_mul(vector<int>&res){//res是倒序的
    string s="";
    for(int i=res.size()-1;i>=0;--i){
        s+=to_string(res[i]);
        if(i!=res.size()-1&&(i+1)%3==0){
            s+=",";
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
void print_quo(vector<int>&res){//res是正序的，且为正数，取最后3位数为小数点后的数
    string s="";
    for(int i=0;i<res.size()-3;i++){
        s+=to_string(res[i]);
    }s+=".";
    for(int i=res.size()-3;i<res.size();i++){
        s+=to_string(res[i]);
    }
    cout<<s<<endl;   
}
vector<int> add1(vector<int>&a){//a是正序的
    a.reverse();a.push_back(0);a.reverse();
    for(int i=a.size()-1;i>=1;--i){
        if(a[i]>10)a[i]-=10;a[i-1]++;
    }
    return a;
}
vector<int> quotient(vector<int>&a,vector<int>&b){
    vector<int>res=(a.size(),0);
    if(cmp(multiply(res,b),a)<1||cmp(multiply(add1(res),b),a)==1){
        return res;
    }else{
        res=add1(res);
    }
}
signed main(){
    string s1,op,s2;cin>>s1>>op>>s2;
    vector<int>num1,num2;bool neg1=false,neg2=false;
    if(op=="*"){
        for(int i=s1.size()-1;i>=0;i--){
            if(s1[i]>='0'&&s1[i]<='9')num1.push_back(s1[i]-'0');
            else if(s1[i]=='-')neg1=true;
        }
        for(int i=s2.size()-1;i>=0;i--){
            if(s2[i]>='0'&&s2[i]<='9')num2.push_back(s2[i]-'0');
            else if(s2[i]=='-')neg2=true;
        }
        if((neg1==true&&neg2==false)||(neg1==false&&neg2==true)){
            cout<<"-";print_mul(multiply(num1,num2));
        }else if((neg1==false&&neg2==false)||(neg1==true&&neg2==true)){
            print_mul(multiply(num1,num2));
        }
    }
    else if(op=='/'){
        for(int i=0;i<s1.size();i++){
            if(s1[i]>='0'&&s1[i]<='9')num1.push_back(s1[i]-'0');
            else if(s1[i]=='-')neg1=true;
        }
        num1.push_back(0);num1.push_back(0);num1.push_back(0);
        for(int i=0;i<s2.size();i++){
            if(s2[i]>='0'&&s2[i]<='9')num2.push_back(s2[i]-'0');
            else if(s2[i]=='-')neg2=true;
        }
        if((neg1==true&&neg2==false)||(neg1==false&&neg2==true)){
            cout<<"-";print_mul(qutient(num1,num2));
        }else if((neg1==false&&neg2==false)||(neg1==true&&neg2==true)){
            print_mul(qutient(num1,num2));
        }
    }
}