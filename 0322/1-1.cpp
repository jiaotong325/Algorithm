#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
#define MaxSize 25
int main(){
    int arr[MaxSize];
    srand((unsigned)time(NULL));
    cout<<"数组元素为："<<endl;
    for (int i = 0;i<MaxSize;i++){
        arr[i] = rand()%20;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //将序列排序
    sort(arr,arr+MaxSize);
    cout<<"经排序后数组为："<<endl;
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //排序后相同数字都聚在一起
    int modalNumber=arr[0];//众数
    int currentNum = 0;
    int mostNum = 0;//最多数的数量
    for (int i = 0; i < MaxSize; i++){
        //特殊情况，i为最后一个元素索引
        currentNum++;
        if (arr[i] != arr[i + 1] || i==MaxSize-1){
            if(currentNum>mostNum){
                mostNum = currentNum;
                modalNumber=arr[i];
            }
            currentNum = 0;//下一个元素不同，归零
        }
    }
    cout << "众数是：" << modalNumber << endl;
    return 0;
}
