#include <iostream>
using namespace std;
const int horse_leg[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
bool judge[30][30];//judge[i][j]表示i,j是否可走
long long dp[30][30],termin_x,m,termin_y,horse_x,horse_y;
int main()
{
    cin>>termin_x>>termin_y>>horse_x>>horse_y;
    judge[horse_x][horse_y]=true;//走到终点
    for (int i=0;i<8;i++){
        int ban_x=horse_x+horse_leg[i][0];
        int ban_y=horse_y+horse_leg[i][1];
        if(ban_x>=0&&ban_x<=termin_x&&ban_y>=0&&ban_y<=termin_y){
            judge[ban_x][ban_y]=true;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<=termin_x;i++){
        for(int j=0;j<=termin_y;j++){
            if(judge[i][j]==false){
                if (i>0) {dp[i][j]+=dp[i-1][j];}
                if (j>0) {dp[i][j]+=dp[i][j-1];}}
    }}
    cout<<dp[termin_x][termin_y]<<endl;
    return 0;
}
