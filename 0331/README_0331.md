1. 调研学习Voronoi图及相关算法，并给出至少一个应用。







2. 前面已经学习在一维序列中某元素的查找算法，现若查找是在一个二维矩阵中进行，并且矩阵中行列均为升序排列，请给出相应查找算法并进行分析。

法一：暴力求解方法，序列从始到末遍历寻找。

法二：利用二分查找的思想，将二维数组arr\[m]\[n]分割为m个一维数组，在每个数组中实现二分查找;未查找到则在下一个数组中查找。

```cpp
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
```



法三：由于该序列的行列升序特性可知，待查找元素value小于当前元素时，需要向右或下继续查找；待查找元素value大于当前元素时，需要向左或上继续查找。
而我们若从右上角开始查找，则可以规避一半问题，当前元素如果大于value，则向左查找，如果小于value，向下查找。不需要向右和上方查找的原因是二维数组最初从右上角开始查找。

```cpp
int main(){
	.....
        

    if(find_in_matrix((int**)arr,&m,&n,value)){
        cout<<"arr["<<m<<"]["<<n<<"]="<<value<<endl;
    }
    else{
        cout<<"Not found "<<value<<"!"<<endl;
    }


    return 0;
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
```

运行结果如下：

![image-20230412014019889](C:\Users\liqi\AppData\Roaming\Typora\typora-user-images\image-20230412014019889.png)



法四：四分