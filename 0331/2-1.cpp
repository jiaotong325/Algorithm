//��ά��������㷨�����е���

#include<iostream>
#include<ctime>
using namespace std;


#define M 15
#define N 15

//һά����Ķ��ֲ���
bool Binary_search(int* arr,int* n,int value);
//��ά������ֲ����㷨�����е���
bool Binary_search_s(int** arr,int* m,int* n,int value);

//��ά��������㷨�����е���,����λ��
bool find_in_matrix(int** arr,int* m,int* n,int value);


 



//���ֲ���
bool Binary_search(int* arr,int* n,int value){
    int low = 0;
    int high = N-1;
    int mid = 0;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==value){
            *n=mid;
            return true;
        }
        else if(arr[mid]>value){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return false;
}

bool Binary_search_s(int** arr,int* m,int* n,int value){
    for(int i=0;i<M;i++){
        //cout<<*((int*)arr + 3)<<endl;   //�Զ�ά������ʷ�ʽ�Ĳ���Ϥ
        if(Binary_search((int*)arr+M*i,n,value)){
            *m=i;
            return true;
        }
    }
    return false;
}



//����˼·�Ǵ����Ͻǿ�ʼ���ң��������value�����м�һ�����С��value�����м�һ
bool find_in_matrix(int** arr,int* m,int* n,int value){
    //��ά��������㷨�����е���
    int row = 0;//��,�ӵ�һ�����һ��Ԫ�ؿ�ʼ
    int col = N-1;
    while(row<M && col>=0){
        if(*((int*)arr+M*row+col)==value){
            *m=row;
            *n=col;
            return true;
        }
        
        else if(*((int*)arr+M*row+col)>value){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

/*
5   9   11  12  26
18  32  64  66  77
20  35  77  88  138
21  40  101 102 144

    1   2   4   8
    2   4   8   16 
    4   8   16  32
    8   16  32  64
*/