//为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 n 张地毯，编号从 1 到 n。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
//本题的注意点是如果枚举100000*100000个点，内存占用较大，因此需要优化。因此我们可以在每一次铺地毯时将涵盖的所有点的值进行一次更新。而不是创建二维数组并索引元素后自增。
#include <iostream>
using namespace std;
const int N=100000;
int main() 
{
    int n;
    int carpet_x[N],carpet_y[N],length[N],width[N];
    int result = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> carpet_x[i]>>carpet_y[i]>>length[i]>>width[i];
    }
    int x,y;
    cin >> x>>y;
	for(int i=1;i<=n;i++){
        if(x>=carpet_x[i]&&x<=carpet_x[i]+length[i]&&y>=carpet_y[i]&&y<=carpet_y[i]+width[i]){
            result=i;
        }
    }
    cout << result << endl;
    return 0;
}