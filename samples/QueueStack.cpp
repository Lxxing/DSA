/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/



#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

class Queue
{
public:
	Queue(int x,int y):x(x),y(y){}
	bool operator== (const Queue & other)
	{
		return (this->x == other.x) ||
				(this->y == other.y) ||
				((this->x + this->y) == (other.x + other.y)) ||
				((this->x - this->y) == (other.x - other.y));
	}
	bool operator!= (const Queue & other)//find����Ҫ��const
	{
		return !(*this == other);//*this != other���ܵ��µݹ飬��ջ��������ñ����==
	}
	void MoveY() { this->y++; }
	int GetY() { return this->y; }
	int GetY() const { return this->y; }
	void MoveX() { this->x++; }
	int GetX() { return this->x; }
	void ResetX() { this->x = 0; }
	void ResetY() { this->y = 0; }
private:
	int x;
	int y;

};
int nSolution; //�������
int nCheck; //��������
const int N = 4;

void DisplaySolution ( const vector<Queue> solu, int n ) 
{ //���n*n�Ĳ���
   printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) 
   {
      for ( int j = 0; j < n; j++ )
      {
         printf ( ( j == solu[i].GetY() ) ? "��" : "[]" );
      }
      printf ( "\n" );
   }
   printf ( "--\n" );
}

void Place4Queens_Stack(int n)
{
	Queue queue(0,0);
	stack<Queue,vector<Queue> > solution;

	while (queue.GetX() > 0 || queue.GetY() < N)
	{
		if (/*solution.size() >= n || */queue.GetY() >= N)//YԽ��
		{//����һ�У���ǰ��
			queue = solution.top();
			solution.pop();
			queue.MoveY();
		}

		vector<Queue> container = solution._Get_container();
		for ( ; queue.GetY() < N; )//������
		{
			if (find(container.begin(), container.end(),queue) != container.end())
			{
				queue.MoveY();//��ͻ��ǰ��
				nCheck++;
			}
			else
			{
				break;//λ�ú���
			}
		}
		if (queue.GetY() < N)
		{
			solution.push(queue);//���õ�ǰ�ʺ�
			//��һ���ʺ󣬼���һ�У��и�λ
			queue.ResetY();
			queue.MoveX();
			//ͳ��
			if (solution.size() >= N)
			{
				nSolution++;
				DisplaySolution(solution._Get_container(),N);
			}
		}
	}
}

void main()
{
	Place4Queens_Stack(N);
    printf ( "Queens, %d Solution(s), %dCheck(s)\n\a\a", nSolution, nCheck );
}




