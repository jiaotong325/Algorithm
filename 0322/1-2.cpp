#include<iostream>
#include<algorithm>
using namespace std;
#include<unordered_map>
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

    


    int modalNumber;//众数
    int MaxNum = 0;//最多数的数量

    unordered_map <int,int> map;//定义一个哈希表
    for (int i = 0;i<MaxSize;i++){
        map[arr[i]]++;//将数组中的元素作为哈希表的键，出现的次数作为值
        if(map[arr[i]]>MaxNum){
            MaxNum = map[arr[i]];
            modalNumber = arr[i];
        }

    }

    cout<<"众数是："<<modalNumber<<endl;


    cout<<"为便于观察到众数，将数组排序："<<endl;
    sort(arr,arr+MaxSize);
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}