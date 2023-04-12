//top-K问题，求数组前k大的元素
//c++ stl 中priority_queue为我们提供了优先队列的实现，其底层是堆排序
#include<iostream>
#include<ctime>
#include<queue>
#include<algorithm>
#define MaxSize 20
using namespace std;
int main(){
    //将数组arr中前k大的元素放入堆中
    int arr[MaxSize];
    srand((unsigned)time(NULL));
    cout<<"数组元素为："<<endl;
    for (int i = 0;i<MaxSize;i++){
        arr[i] = rand()%100;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"为方便测试，将数组排序后结果输出："<<endl;
    sort(arr,arr+MaxSize);
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k = 5;
    //定义最小堆，堆顶元素为最小元素
    priority_queue<int,vector<int>,greater<int>> q;
    //将前k个元素放入堆中
    for (int i = 0;i<k;i++){
        q.push(arr[i]);
    }
    //遍历数组，将大于堆顶元素的元素放入堆中
    for (int i = k;i<MaxSize;i++){
        if (arr[i]>q.top()){
            q.pop();
            q.push(arr[i]);
        }
    }
    //输出堆中元素
    cout<<"前"<<k<<"大的元素为："<<endl;
    while (!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout << endl;
    return 0;
}