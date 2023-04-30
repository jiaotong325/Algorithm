
1. �������Դ�ӡ��ת����
![image_1](./image_1.png)

���ӣ����Ƶģ�ͬѧ�ǻ�����˼�����ʵ��˳ʱ����ת����90&deg;���Լ����ʵ�֡�֮�����δ�ӡ���󣨴����Ͻ��شζԽ��߷����ӡ�����½ǣ���
![image_21](./image_2.png)

* ����һ����˳����������ȴ�ĳ��λ�����ұ������������֮�����ϱ������̶���������......ֱ������Ԫ�ض���������ȫ�������Ҫ��һ�������ͬ�ȴ�С�ľ����¼ÿ��Ԫ���Ƿ񱻷��ʡ�

```c++
// ��ӡ��ת����
#include <iostream>
using namespace std;
#define N 5
int arr[N][N] = {
    {13,12,11,10,9},
    {14,23,22,21,8},
    {15,24,25,20,7},
    {16,17,18,19,6},
    {1, 2, 3, 4, 5}
};
// ��ʼ������ȫ��Ϊ0
int visited[N][N] = {0};
//����н�������������
int direction[4]={0,1,2,3};

int main(){
    int k = 0;//���ڼ�¼�����ڡ�����
    // �����½ǿ�ʼ��ʱ���ӡ
    // �����￪ʼȡ������СԪ��λ�ã����������½�Ϊ��
    int i = N-1, j = 0;
    while(k < 4){
        // ��ӡ��ǰλ��
        cout << arr[i][j] << " ";
        // ��ǵ�ǰλ���Ѿ�����
        visited[i][j] = 1;
        // ���ݷ��������ֵ���ж���һ����λ��
        switch(direction[k]%4){
            case 0://��
                // �����һ����λ���Ѿ����ʹ�����磬��ô�͸ı䷽��
                if(visited[i][j+1] != 0 || j+1 >= N){
                    k++;
                    i--;
                }
                else{  //δ���ʹ���δ���磬��ô�ͼ���ǰ��
                    j++;
                }
                break;
            case 1://��
                if(visited[i-1][j] != 0 || i-1 < 0){
                    k++;
                    j--;
                }
                else{
                    i--;
                }
                break;
            case 2://��
                if(visited[i][j-1] != 0 || j-1 < 0){
                    k++;
                    i++;
                }
                else{
                    j--;
                }
                break;
            case 3://��
                if(visited[i+1][j] != 0 || i+1 >= N){
                    k++;
                    j++;
                }
                else{
                    i++;
                }
                break;
        }
    }
    return 0;
}
```

* ��������ÿ�α���һ�л�һ�У���������ϵ�Ԫ���޳��������¶���߽磬ֱ���ĸ��߽������߽��غϣ������غϣ�������������±���һ�л�һ�С�

```c++
// ��ӡ��ת����
#include <iostream>
using namespace std;
#define N 5
int arr[N][N] = {
    {13,12,11,10,9},
    {14,23,22,21,8},
    {15,24,25,20,7},
    {16,17,18,19,6},
    {1, 2, 3, 4, 5}
};
int WheatherCircle(int left, int right, int top, int bottom);

int main(){
    // �ȶ���߽�
    int left = -1, right = N, top = -1, bottom = N;
    // �����½ǿ�ʼ��ӡ
    int i = N-1, j = 0;

    while(1){
        // �ӵײ��������Ҵ�ӡ
        while(j<right){
            cout << arr[i][j] << " ";
            j++;
        }
        bottom--;
        i--;
        j--;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // ���ұ��������ϴ�ӡ
        while(i>top){
            cout << arr[i][j] << " ";
            i--;
        }
        right--;
        j--;
        i++;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // ���������������ӡ
        while(j>left){
            cout << arr[i][j] << " ";
            j--;
        }
        top++;
        i++;
        j++;
        if(!WheatherCircle(left, right, top, bottom)) break;

        // ������������´�ӡ
        while(i<bottom){
            cout << arr[i][j] << " ";
            i++;
        }
        left++;
        j++;
        i--;
        if(!WheatherCircle(left, right, top, bottom)) break;
    }
    return 0;
}

int WheatherCircle(int left, int right, int top, int bottom){
    if(left == right || top == bottom) return 0;
    else return 1;
}
```










2. �������Է���һ��m*n�����дӡ�1,1������m,n���ĺ���С��һ��·����

* ����һ���������뵽�ľ��Ƕ�̬�滮��dp\[i]\[j]��ʾ��(0, 0)��(i, j)����С����ͣ����ھ����е�ÿ��Ԫ�أ������Ԫ��Ҫô�����Ԫ�������ƶ���Ҫô���Ϸ�Ԫ�����ƣ���ô״̬ת�Ʒ���Ϊ
  $$
  dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j]
  $$
  �������״̬ת�Ʒ������ǿ���ȷ�������Ե��Ԫ��ֵ��

$$
dp[0][j]=dp[0][j-1]+arr[0][j]
$$

$$
dp[i][0]=dp[i-1][0]+arr[i][0]
$$

```cpp
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
```

* ��������ʹ�õݹ�ķ�ʽ�������\[x]\[y]��\[m]\[n]����С·�����Ǽ��� min{\[x+1]\[y]��\[x]\[y+1]} ��С·����

�������£�

```cpp
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
```

