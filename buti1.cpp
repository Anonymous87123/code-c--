#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k;string S;
    while(cin>>k>>S){
        string s=S;
        for(char& c:s){
            c='a'+((c-'a'+k)%26);
        }
        string t="^#";
        for(char c:s){
            t+=c;t+="#";
        }
        t+="$";
        int n=t.size();
        vector<int>P(n,0);
        int C=0,R=0;
        int maxlen=0;int best=1e9;
        for(int i=1;i<n-1;++i){
            int mirror=2*C-i;
            if(i<R){
                P[i]=min(R-i,P[mirror]);
            }else P[i]=1;
            while(t[i+P[i]]==t[i-P[i]]){
                ++P[i];
            }
            if(i+P[i]>R){
                C=i;R=i+P[i];
            }
            int len=P[i]*2-1;
            int start=(i-P[i])/2;
            if(len>=2){
                if(len>maxlen){
                    maxlen=len;
                    best=start;
                }
                else if(len==maxlen&&start<best){
                    best=start;
                }
            }
        }
        if(maxlen>=2){
            cout<<best<<" "<<best+maxlen-1<<endl;
            cout<<s.substr(best,maxlen)<<endl;
        }else{
            cout<<"No solution!"<<endl;
        }
    }

}