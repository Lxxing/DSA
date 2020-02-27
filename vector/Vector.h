/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#ifndef _LX_VECTOR__H_
#define _LX_VECTOR__H_


namespace LX
{
typedef int Rank;
#define DEFAULT_CAPACITY 5//后面不能带；不然编译错误

template <typename T>
class vector
{

public:
	vector(int cap = DEFAULT_CAPACITY);
	~vector();

	Rank size() const;
	bool empty() const;
	T& at(Rank r);
    T& operator[] ( Rank r ) const; //重载下标操作符
	
	void permute();//（变换）随机置乱向量

	Rank insert( Rank r, T const& e ); //将e作为秩为r元素插入
    Rank insert( T const& e ); //默认作为末元素插入

	T remove ( Rank r ); //删除秩为r的元素
	int remove ( Rank lo, Rank hi ); //删除秩在区间[lo, hi)之内的元素

	int disordered() const; //判断向量是否已排序

	Rank find(T const& e) const; //无序向量整体查找
    Rank find ( T const& e, Rank lo, Rank hi ) const; //无序向量区间查找
    int deduplicate(); //无序去重
    void sort ( Rank lo, Rank hi ); //对[lo, hi)排序
    void sort() ; //整体排序

	Rank search ( T const& e ) const; //有序向量整体查找
    Rank search ( T const& e, Rank lo, Rank hi ) const; //有序向量区间查找
   
    int uniquify(); //有序去重
private:
    void expandCheck();//扩容检查,空间不足时扩容
    void shrinkCheck(); //装填因子过小时压缩

	bool bubble ( Rank lo, Rank hi ); //扫描交换
    void bubbleSort ( Rank lo, Rank hi ); //起泡排序算法

	Rank selectMax( Rank lo, Rank hi ); //选取最大元素
    void selectionSort ( Rank lo, Rank hi ); //选择排序算法

	void merge ( Rank lo, Rank mid, Rank hi ); //归并算法
    void mergeSort ( Rank lo, Rank hi ); //归并排序算法

	Rank partition ( Rank lo, Rank hi ); //轴点构造算法
    Rank partition1 ( Rank lo, Rank hi);//关键码重复多的情况。交换少，
    void quickSort ( Rank lo, Rank hi ); //快速排序算法
    void heapSort ( Rank lo, Rank hi ); //堆排序
    
private:
	T * _data;
	int _size;
	int _capacity;

};

}

#include "VectorImplementation.h"

#endif //_LX_VECTOR__H_

