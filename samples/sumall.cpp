
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



int main()
{

	int* A = (int*)malloc(n * sizeof(int)); 

 	unsigned int seed = (unsigned int)time(NULL);
    randomArray(A, n, seed); 
    std::cout << "-->  ";
    print(A, n);
	//0 + 1 + ... + n=n*(n-1)/2 
    int s = sum(A, n); 
	std::cout << "==>  " << s << std::endl;

	free(A);

}

