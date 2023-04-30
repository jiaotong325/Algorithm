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
    int i = N-1, j = 0;
    while(k < 4){
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