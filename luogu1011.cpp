//火车从始发站（称为第 1 站）开出，在始发站上车的人数为 a，然后到达第 2 站，在第 2 站有人上、下车，但上、下车的人数相同，因此在第 2 站开出时（即在到达第 3 站之前）车上的人数保持为 a 人。从第 3 站起（包括第 3 站）上、下车的人数有一定规律：上车的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，一直到终点站的前一站（第 n−1 站），都满足此规律。现给出的条件是：共有 n 个车站，始发站上车的人数为 a，最后一站下车的人数是 m（全部下车）。试问 x 站开出时车上的人数是多少？输入只有一行四个整数，分别表示始发站上车人数 a，车站数 n，终点站下车人数 m 和所求的站点编号 x。输出一行一个整数表示答案：从 x 站开出时车上的人数。
//本题知道的只有初始和末态，并不知道第二站上车人数所以不方便递推，所以我们用二分法从两个方向逼近，知道找到合适的第二站上车人数使得终点站下车人数等于m。
#include<iostream>
using namespace std;
int main()
{
    int n,x,m;
    int onbus[30]={0};
    int geton[30]={0};
    int getoff[30]={0};
    cin>>geton[1]>>n>>m>>x;
    int inf = 0, sup = m;
    while(inf<=sup){
        int guess = (inf+sup)/2;
        geton[2]=guess;
        getoff[2] = guess;
        onbus[1] = geton[1];
        for(int i=2;i<n;i++){
            geton[i+1] = geton[i] + geton[i-1];
            getoff[i+1] = geton [i];
            onbus[i] = onbus[i-1] + (geton[i] - getoff[i]);
        }
        if (onbus[n-1]==m){
            break;
        }
        else if(onbus[n-1]<m){
            inf = geton[2]+1;
        }
        else{
            sup = geton[2]-1;
        }
    }
    getoff[2] = geton[2];
    onbus[1] = geton[1];
    for(int i=2;i<n;i++){
        geton[i+1] = geton[i] + geton[i-1];
        getoff[i+1] = geton [i];
        onbus[i] = onbus[i-1] + (geton[i] - getoff[i]);
    }
    cout<<onbus[x]<<endl;
    return 0;
}