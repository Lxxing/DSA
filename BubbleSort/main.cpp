/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include <iostream>
#include <time.h> 

#include "LXUtil.h"
using namespace LXUtil;

#include "bubble.h"


/******************************************************************************************
 * 起泡排序测试程序
 ******************************************************************************************/
void main ( int argc, char* argv[] ) 
{
    int n = 20; //array length
    int a[10] = {5,4,1,0,4,6,2,8,9,7};
    int legth = sizeof(a) / sizeof(a[1]);
    printf("%d\n", legth);
    
    bubblesort(a, legth);
	print(a, legth);

    int* A = (int*)malloc(n * sizeof(int)); //allocate an array of size n
    unsigned int seed = (unsigned int)time(NULL); //A same seed is used here for comparison between different algorithms
    
    std::cout << "Bubblesort algorithm " << std::endl;
    randomArray(A, n, seed); 
    std::cout << "-->  ";
    print(A, n);
    bubblesort(A, n); 
	std::cout << "==>  ";
	print(A, n);
    
	std::cout << "Bubblesort algorithm A " << std::endl;
	shuffle(A, n);
	std::cout << "-->  "; 
	print(A, n);
    bubblesort<int>(A, n);
	std::cout << "==>  ";
	print(A, n);

	std::cout << "Bubblesort algorithm bubblesortA " << std::endl;
	shuffle(A, n);
	std::cout << "-->  "; 
	print(A, n);
	bubblesortA<int>(A, n);
	std::cout << "==>  "; 
	print(A, n);

	free(A);
}