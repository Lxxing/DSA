/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/



#include <iostream>
#include <time.h> 
#include <vector>
using namespace std;

int nSolution; //�������
int nCheck; //��������

void DisplaySolution ( int* solu, int n ) 
{ //���n*n�Ĳ���
   printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) 
   {
      for ( int j = 0; j < n; j++ )
      {
         printf ( ( j == solu[i] ) ? "��" : "[]" );
      }
      printf ( "\n" );
   }
   printf ( "--\n" );
}

bool CollideCheck ( int* s, int k )
{ 
   nCheck++;
   for ( int i = 0; i < k; i++ ) 
   {
      if ( s[k] == s[i] )         return true; //��
      if ( s[k] - s[i] == k - i ) return true; //�Խ���
      if ( s[k] - s[i] == i - k ) return true; //���Խ���
   }
   return false;
}

//���õ�k���ʺ�(��n��)
const int N = 4;
void Place4Queens_Recursive(int n, int k)
{

	static int solution[N];

	//�ݹ�����ʺ�����
	if (n <= k)
	{
		nSolution++;
		DisplaySolution(solution, N);
		return;
	}
	
	for (int line = 0; line < N; line++)//������
	{
		solution[k] = line;//�����з��õ���ǰ��
		if (!CollideCheck(solution, k))
	    {//ǰ���޳�ͻ����ݹ������һ��
			Place4Queens_Recursive(n,k + 1);
		}
	}
}

void main()
{
	Place4Queens_Recursive(N,0);
    printf ( "Queens, %d Solution(s), %dCheck(s)\n\a\a", nSolution, nCheck );
}



