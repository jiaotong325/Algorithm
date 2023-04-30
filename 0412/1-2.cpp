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


int WheatherCircle(int left, int right, int top, int bottom);



int main(){
    // 先定义边界
    int left = -1, right = N, top = -1, bottom = N;
    // 从左下角开始打印
    int i = N-1, j = 0;

    while(1){
        // 从底部由左向右打印
        while(j<right){
            cout << arr[i][j] << " ";
            j++;
        }
        bottom--;
        i--;
        j--;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // 在右边由下向上打印
        while(i>top){
            cout << arr[i][j] << " ";
            i--;
        }
        right--;
        j--;
        i++;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // 在上面由右向左打印
        while(j>left){
            cout << arr[i][j] << " ";
            j--;
        }
        top++;
        i++;
        j++;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // 在左边由上向下打印
        while(i<bottom){
            cout << arr[i][j] << " ";
            i++;
        }
        left++;
        j++;
        i--;
        if(!WheatherCircle(left, right, top, bottom)) break;

    }
    return 0;
}


int WheatherCircle(int left, int right, int top, int bottom){
    if(left == right || top == bottom) return 0;
    else return 1;
}