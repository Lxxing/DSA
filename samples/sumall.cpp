
#include <iostream>
using namespace std;

#include "LXUtil.h"
using namespace LXUtil;

int sum(int A[], int len)
{

	int ret = 0;

	for(unsigned int i = 0; i < len; i++)
	{
		sum += A[i];
	}

	return ret;

}

int sumRecursive(int A[],int len)
{

	int ret = 0;

	//µÝ¹é»ù£¬
	if(len = 0)
	{
		return A[0];
	}
	/*ret = A[len - 1];
	ret += sumRecursive(A,len - 1);
	return ret;*/

	return sumRecursive(A,len - 1) + A[len - 1];

}


int main()
{

	int* A = (int*)malloc(n * sizeof(int)); 

 	unsigned int seed = (unsigned int)time(NULL);
    randomArray(A, n, seed); 
    std::cout << "-->  ";
    print(A, n);
	//0 + 1 + ... + n=n*(n-1)/2 
    int s = sum(A, n); 
	std::cout << "µü´ú°æ±¾:  " << s << std::endl;

    s = sumRecursive(A, n); 
	std::cout << "µÝ¹é°æ±¾:  " << s << std::endl;
	

	free(A);

}

