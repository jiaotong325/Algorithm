#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
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

    //����������
    sort(arr,arr+MaxSize);
    cout<<"�����������Ϊ��"<<endl;
    for (int i = 0;i<MaxSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //�������ͬ���ֶ�����һ��
    int modalNumber=arr[0];//����
    int currentNum = 0;
    int mostNum = 0;//�����������
    for (int i = 0; i < MaxSize; i++){
        //���������iΪ���һ��Ԫ������
        currentNum++;
        if (arr[i] != arr[i + 1] || i==MaxSize-1){
            if(currentNum>mostNum){
                mostNum = currentNum;
                modalNumber=arr[i];
            }
            currentNum = 0;//��һ��Ԫ�ز�ͬ������
        }
    }
    cout << "�����ǣ�" << modalNumber << endl;
    return 0;
}
