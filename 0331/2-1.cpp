//二维矩阵查找算法，行列递增

#include<iostream>
#include<ctime>
using namespace std;


#define M 15
#define N 15

//一维数组的二分查找
bool Binary_search(int* arr,int* n,int value);
//二维矩阵二分查找算法，行列递增
bool Binary_search_s(int** arr,int* m,int* n,int value);

//二维矩阵查找算法，行列递增,返回位置
bool find_in_matrix(int** arr,int* m,int* n,int value);

int main(){
    int arr[M][N];
    srand((unsigned)time(NULL));
    cout<<"数组元素为："<<endl;
   
    arr[0][0]=rand()%3;
    cout<<arr[0][0]<<"\t";
    //构造随机行列递增二维数组
    for(int i=0;i<M;i++){
        for(int j =0;j<N;j++){

            if(i==0){
                if(j==0){
                    continue;
                }
                else{
                    arr[i][j]=arr[i][j-1]+rand() % 2 + 1;//生成1-3的随机数
                    cout<<arr[i][j]<<"\t";
                    continue;
                }
            }
            if(j==0){
                arr[i][j]=arr[i-1][j]+rand()%2+1;
                cout<<arr[i][j]<<"\t";
                continue;
            }
  
            arr[i][j]=max(arr[i][j-1],arr[i-1][j])+rand()%2+1;
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
    int value = rand()%10;
    cout<<"The random key is:"<<value<<endl;
    int m =-1;
    int n =-1;

    if(Binary_search_s((int**)arr,&m,&n,value)){
        cout<<"arr["<<m<<"]["<<n<<"]="<<value<<endl;
    }
    else{
        cout<<"Not found "<<value<<"!"<<endl;
    }
    return 0;
}

//二分查找
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
        //cout<<*((int*)arr + 3)<<endl;   //对二维数组访问方式的不熟悉
        if(Binary_search((int*)arr+M*i,n,value)){
            *m=i;
            return true;
        }
    }
    return false;
}



//总体思路是从右上角开始查找，如果大于value，则列减一，如果小于value，则行加一
bool find_in_matrix(int** arr,int* m,int* n,int value){
    //二维矩阵查找算法，行列递增
    int row = 0;//行,从第一行最后一个元素开始
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