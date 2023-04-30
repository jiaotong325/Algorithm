// 打印旋转矩阵
#include <iostream>
using namespace std;
#define N 5

int arr[N][N] = {
    {13,12,11,10,9},
    {14,23,22,21,8},
    {15,24,25,20,7},
    {16,17,18,19,6},
    {1, 2, 3, 4, 5}
};
// 初始化数组全部为0
int visited[N][N] = {0};

//标记行进方向：右上左下
int direction[4]={0,1,2,3};


int main(){
    int k = 0;//用于记录“碰壁”次数
    // 从左下角开始逆时针打印
    int i = N-1, j = 0;
    while(k < 4){
        cout << arr[i][j] << " ";
        // 标记当前位置已经访问
        visited[i][j] = 1;
        // 根据方向数组的值，判断下一步的位置
        switch(direction[k]%4){
            case 0://右
                // 如果下一步的位置已经访问过或过界，那么就改变方向
                if(visited[i][j+1] != 0 || j+1 >= N){
                    k++;
                    i--;
                }
                else{  //未访问过或未过界，那么就继续前进
                    j++;
                }
                break;
            case 1://上
                if(visited[i-1][j] != 0 || i-1 < 0){
                    k++;
                    j--;
                }
                else{
                    i--;
                }
                break;
            case 2://左
                if(visited[i][j-1] != 0 || j-1 < 0){
                    k++;
                    i++;
                }
                else{
                    j--;
                }
                break;
            case 3://下
                if(visited[i+1][j] != 0 || i+1 >= N){
                    k++;
                    j++;
                }
                else{
                    i++;
                }
                break;
        }
    }
    return 0;
}