#include<iostream>
#include<algorithm>
using namespace std;
#include<unordered_map>
#define MaxSize 25



int main(){
    int arr[MaxSize];
    srand((unsigned)time(NULL));
    cout<<"����Ԫ��Ϊ��"<<endl;
    for (int i = 0;i<MaxSize;i++){
        arr[i] = rand()%20;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    


    int modalNumber;//����
    int MaxNum = 0;//�����������

    unordered_map <int,int> map;//����һ����ϣ��
    for (int i = 0;i<MaxSize;i++){
        map[arr[i]]++;//�������е�Ԫ����Ϊ��ϣ��ļ������ֵĴ�����Ϊֵ
        if(map[arr[i]]>MaxNum){
            MaxNum = map[arr[i]];
            modalNumber = arr[i];
        }

    }

    cout<<"�����ǣ�"<<modalNumber<<endl;


    cout<<"Ϊ���ڹ۲쵽����������������"<<endl;
    sort(arr,arr+MaxSize);
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}