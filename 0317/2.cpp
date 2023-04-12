//请用递归方式实现堆排序
#include <iostream>
#include<ctime>
#define MaxSize 5
using namespace std;

//维护最大堆
void heapify(int arr[], int n, int i) {
    //i为当前节点
    int largest = i;
    int l =2*i+1;//左子结点
    int r =2*i+2;//右子结点
    if (l<n&&arr[l]>arr[largest])//当前节点与左子结点比较
        largest = l;
    if (r<n&&arr[r]>arr[largest])
        largest = r;
    if (largest != i) {//需要交换
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);//递归，维护下一层
    }
}

//递归堆排序
//过程是先建立最大堆，然后将堆顶元素与最后一个元素交换，然后维护最大堆
void heapSort(int* arr, int n) {
    for (int i=n/2-1;i>=0;i--){//n个元素，最后一个元素的父节点下标为(n-1)/2
        heapify(arr,n,i);
    }
    for (int i=n-1;i>0;i--) {//每次构成大顶堆，能找到一个最大值
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);//i--,排除此时最后一个最大元素
    }
}

int main(){
    int arr[MaxSize];
    srand((unsigned)time(NULL));
    cout<<"数组元素为："<<endl;
    for (int i = 0;i<MaxSize;i++){
        arr[i] = rand()%100;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //堆排序
    heapSort(arr,MaxSize);

    cout<<"排序后结果输出："<<endl;
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}