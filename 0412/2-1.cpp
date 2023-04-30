// �������Է���һ��m*n�����дӡ�1,1������m,n���ĺ���С��һ��·��
#include <iostream>
#include <ctime>
using namespace std;
#define M 5
#define N 5

// ���㲢��ӡ·��
int minPathSum(int** arr, int m,int n,int i,int j){
    // ��ӡ�±�
    // cout<<"["<<i<<","<<j<<"]"<<"->";
    // �ݹ����
    if(i==m-1&&j==n-1){
        return arr[i][j];
    }
    // �ݹ�
    if(i==m-1){
        return arr[i][j]+minPathSum(arr,m,n,i,j+1);
    }
    if(j==n-1){
        return arr[i][j]+minPathSum(arr,m,n,i+1,j);
    }
    int right = minPathSum(arr,m,n,i,j+1);
    int down = minPathSum(arr,m,n,i+1,j);
    return arr[i][j]+min(minPathSum(arr,m,n,i+1,j),minPathSum(arr,m,n,i,j+1));
}

int dpMin(int** arr, int m,int n){
    // �ȴ���ͬ�ߴ��dp����
    int** dp = new int*[m];
    for(int i=0;i<m;i++){
        dp[i]=new int[n];
    }
    // ��ʼ��dp����
    dp[0][0]=arr[0][0];
    for(int i=1;i<m;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    for(int j=1;j<n;j++){
        dp[0][j]=dp[0][j-1]+arr[0][j];
    }
    // ����
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
    }
    // ��ӡdp����
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    */
    // ���ؽ��
    return dp[m-1][n-1];
}



int main(){
    int arr[M][N];
    srand((unsigned)time(NULL));
    cout<<"����Ԫ��Ϊ��"<<endl;
   // ���������ά����
   for(int i=0;i<M;i++){
       for(int j =0;j<N;j++){
           arr[i][j]=rand()%10;
           cout<<arr[i][j]<<"\t";
       }
       cout<<endl;
   }
    return 0;
}
