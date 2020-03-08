/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
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
	bool operator!= (const Queue & other)//find函数要求const
	{
		return !(*this == other);//*this != other可能导致递归，堆栈溢出。调用本身的==
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
int nSolution; //解的总数
int nCheck; //尝试总数
const int N = 4;

void DisplaySolution ( const vector<Queue> solu, int n ) 
{ //输出n*n的布局
   printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) 
   {
      for ( int j = 0; j < n; j++ )
      {
         printf ( ( j == solu[i].GetY() ) ? "█" : "[]" );
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
		if (/*solution.size() >= n || */queue.GetY() >= N)//Y越界
		{//回溯一行，列前进
			queue = solution.top();
			solution.pop();
			queue.MoveY();
		}

		vector<Queue> container = solution._Get_container();
		for ( ; queue.GetY() < N; )//遍历列
		{
			if (find(container.begin(), container.end(),queue) != container.end())
			{
				queue.MoveY();//冲突则前进
				nCheck++;
			}
			else
			{
				break;//位置合适
			}
		}
		if (queue.GetY() < N)
		{
			solution.push(queue);//放置当前皇后
			//下一个皇后，即下一行，列复位
			queue.ResetY();
			queue.MoveX();
			//统计
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




