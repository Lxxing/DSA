/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include <iostream>

#include "bubble.h"

/******************************************************************************************
 * 起泡排序测试程序
 ******************************************************************************************/
void main ( int argc, char* argv[] ) {
   int n = 0; //array length
   int a[10] = {2,4,1,0,4,6,5,8,9,7};
   int array[] = { 1,2,3,4,5,6 };
   int len = sizeof(array) / sizeof(array[1]);
   printf("%d\n", len);
   int legth = sizeof(a) / sizeof(a[1]);
   printf("%d\n", len);
   bubblesort(a, 10);

   for (size_t i = 0; i < 10; i++)
   {
	   std::cout << a[i] << "\t";
   }

}