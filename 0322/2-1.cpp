#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
#define MaxSize 24

int main(){
    int arr[MaxSize];
    srand((unsigned)time(NULL));
    cout<<"����Ԫ��Ϊ��"<<endl;
    for (int i = 0;i<MaxSize;i++){
        arr[i] = rand()%20;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sort(arr,arr+MaxSize);

    cout<<"���з�Ϊ�����֣�"<<endl;
    cout << "s1:";
    for (int i = 0; i < MaxSize / 2; i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
    cout << "s2:";
    for (int i = MaxSize / 2; i < MaxSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
