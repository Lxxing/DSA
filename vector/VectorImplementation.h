/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#ifndef _VECTOR_IMPLEMENTAION__H_
#define _VECTOR_IMPLEMENTAION__H_

#include "LXUtil.h"
using namespace LXUtil;

namespace LX
{

template <typename T>
vector<T>::vector(int cap)
{
	_capacity = cap;
	_data = new T[cap];
	_size = 0;

}

template <typename T>
vector<T>::~vector()
{
	delete [] _data;
}

template <typename T>
Rank vector<T>::size() const
{
	return this->_size;
}

template <typename T>
bool vector<T>:: empty() const
{
	return !this->_size;
}

template <typename T>
T& vector<T>::at(Rank r)
{
	return _data[r];
}

template <typename T>
T& vector<T>::operator[] ( Rank r ) const
{
	return _data[r];
}

template <typename T>
void vector<T>::permute()
{
	for ( int i = _size; i > 0; i-- )
	{
      std::swap( _data[i - 1], _data[rand() % i] ); //[i - 1]与[0, i)中某一随机元素交换
	}
}
template <typename T>// 0<=r<=_size
Rank vector<T>::insert( Rank r, T const& e )
{
	expandCheck();
	for (int i = _size; i > r; i--)
	{
		_data[i] = _data[i - 1];//r（包含r）之后的数据往后移动
	}
	_data[r] = e;
	_size++;
	return r;
}

template <typename T>
Rank vector<T>::insert( T const& e )
{
	return insert(_size,e);
}

template <typename T>
void vector<T>::expandCheck()
{
	if (_capacity - _size <= 0)
	{
		_capacity <<= 1;
		
		T * newdata = new T[_capacity];
		memcpy(newdata,_data,_size * sizeof(T));
		delete [] _data;
		_data = newdata;
	}
}

template <typename T>
void vector<T>::shrinkCheck()
{
	if (_size << 2 < _capacity)//装载因子为25%(_size / _capacity <= 0.5整数不能直接比)
	{
		_capacity >>= 1;
		
		T * newdata = new T[_capacity];
		memcpy(newdata,_data,_size * sizeof(T));
		delete [] _data;
		_data = newdata;
	}

}
template <typename T>
T vector<T>::remove ( Rank r )
{
	T rnt = _data[r];
	remove(r,r + 1);
	return rnt;
}

template <typename T>
int vector<T>::remove ( Rank lo, Rank hi )
{
	int rnt = hi - lo;
	//[hi,_size)向前移动
	for (int i = hi; i < _size; ++i)
	{
		_data[lo++] = _data[i]; 
	}
	_size = lo;//lo = lo + (_size - hi)
	shrinkCheck();
	return rnt;
}

template <typename T>
int vector<T>::disordered() const
{
	int rnt = 0;

	for (int i = 0; i < _size; i++)
	{
		if (_data[i] > _data[i + 1])
		{
			rnt++;
		}
	}
	return rnt;
}


template <typename T>
Rank vector<T>::find ( T const& e ) const 
{ 
	return find ( e, 0, _size ); 
} 

template <typename T>//[lo,hi)
Rank vector<T>::find ( T const& e, Rank lo, Rank hi ) const 
{ 
	for (int i = lo; i < hi; i++)
	{
		if (e == _data[i])
		{
			return i;
		}
	}
	return -1;
} 

template <typename T>
int vector<T>::deduplicate()
{
	int rnt = 0;
	for (int i = 1; i < _size; )
	{
		T index = find ( _data[i], 0, i);
		if (-1 != index)
		{
			remove(i);
			rnt++;//记录删除个数
		}
		else
		{
			i++;
		}
		
	}
	return rnt;
}

template <typename T>
int vector<T>::uniquify()
{
	int rnt = _size;
	Rank ptrHead = 0;
	Rank ptrTailer = 1;

	for (; ptrTailer < _size; )
	{
		if (_data[ptrHead] == _data[ptrTailer])
		{
			ptrTailer++;
		}
		else
		{
			_data[ptrHead++] = _data[ptrTailer++]
		}
		
	}

	return rnt - _size;
}

template <typename T>
void vector<T>::sort()
{
	sort ( 0, _size );
}


template <typename T>
void vector<T>::sort ( Rank lo, Rank hi )
{
	//int casen = rand()%3;
	int casen = 3;
	switch (casen)
	{
		case 1:
			selectionSort(lo,hi);
			break;
		case 2:
			bubbleSort(lo,hi);
			break;
		case 3:
			mergeSort(lo,hi);
			break;
	}

}

template <typename T>
Rank vector<T>::search ( T const& e ) const
{
	return search ( e, 0, _size ); 

}

template <typename T>//有序区间[lo, hi)内，查找不大于e的最后一个节点的秩
Rank vector<T>::search (T const& e, Rank lo, Rank hi) const
{
	if (hi - lo < 1)
	{
		return -1;
	}
	//int casen = rand()%2;
	int casen = 1;
	switch (casen)
	{
		case 1:
			return binSearch(_data, e, lo, hi );
			break;
		case 2:
			//return fibSearch(_data, e, lo, hi );
			break;
	}
	return -1;
}    

template <typename T>//[lo,hi),hi-1为秩最大值
bool vector<T>::bubble ( Rank lo, Rank hi )
{
	bool sorted = true;
	for (; lo < hi - 1; )
	{
		if (_data[lo] > _data[lo + 1])//lo + 1取到最大秩
		{
			std::swap(_data[lo],_data[lo + 1]);
			sorted = false;
		}
		lo++;
	}
	return sorted;
}

template <typename T>
void vector<T>::bubbleSort ( Rank lo, Rank hi )
{
	while (!bubble(lo,hi--));
}

template <typename T>//[lo, hi]区间内最大者
Rank vector<T>::selectMax( Rank lo, Rank hi )
{
	Rank maxIndex = hi;
	while (lo < hi--)//逆序扫描。考虑重复数据，有重复数据时，选择后者。
	{
		if (_data[hi] > _data[maxIndex])
		{
			maxIndex = hi;
		}
	}
	return maxIndex;
}

template <typename T>
void vector<T>::selectionSort ( Rank lo, Rank hi )
{
	for (; lo < --hi; )
	{
		Rank max = selectMax(lo, hi);
		
		if (-1 != max)
		{
			std::swap(_data[hi],_data[max]);
		}
	}
}

template <typename T>
void vector<T>::merge ( Rank lo, Rank mid, Rank hi )
{
	//取出当前数组区间,currentArray[0,hi-lo) =_data[lo,hi)
	T * currentArray = _data + lo;
	int currentLength = hi - lo;
	Rank currentPointer = 0;
	//构造备份数组,从当前区间开始构造，前缀序列newHead[0,mid-lo) =_data[lo,mid)
	T * preHead = new T[mid - lo];
	int preLength = mid - lo;
	Rank prePointer = 0;
	memcpy(preHead,currentArray,(mid - lo) * sizeof(T));
	//取出后缀序列newHead[0,hi-mid) =_data[mid,hi)
	T * sucArray = _data + mid;
	int sucLength = hi-mid;
	Rank sucPointer = 0;

	while (( prePointer < preLength ) || ( sucPointer < sucLength ))//pre、suc序列有一个没有遍历完
	{
		if (( prePointer < preLength ) && //pre有数据，pre数组数据小或者suc编译完毕
			( !(sucPointer < sucLength) || (preHead[prePointer] <= sucArray[sucPointer]) ))
		{
			currentArray[currentPointer++] = preHead[prePointer++];
		}
		if (( sucPointer < sucLength ) && //suc有数据，suc数组数据小或者pre编译完毕
			( !(prePointer < preLength) || (sucArray[sucPointer] < preHead[prePointer]) ))
		{
			currentArray[currentPointer++] = sucArray[sucPointer++];
		}			
	}

	delete [] preHead;
}

template <typename T>//[lo,hi)
void vector<T>::mergeSort ( Rank lo, Rank hi )
{
	if (hi - lo < 2)
	{
		return;//递归基
	}
	
	int mid = (lo + hi ) >> 1;
	mergeSort(lo, mid);//[lo,mid)
	mergeSort(mid, hi);//[mid,hi)
	
	merge(lo,mid,hi);
}

template <typename T>//通过调整元素位置构造区间[lo, hi]的轴点，并返回其秩
Rank vector<T>::partition ( Rank lo, Rank hi )
{
	std::swap(_data[lo],_data[rand() % (hi - lo)]);//设置首元素为随机点
	T pivot = _data[lo];//轴点
	while (lo < hi)
	{
		while (lo < hi && pivot <= _data[hi])//轴点判断
		{
			hi--;//右序列左展
		}
		_data[lo] = _data[hi];//异于轴点，放入对应序列

		while (lo < hi && pivot >= _data[hi])
		{
			lo++;//左序列右展
		}
		_data[hi] = _data[lo];
	}

	_data[lo] = pivot;//轴点数据赋值

	return lo;
}


template <typename T> //关键码重复多的情况。交换少，
Rank vector<T>::partition1 ( Rank lo, Rank hi ) 
{
	std::swap(_data[lo],_data[rand() % (hi - lo)]);
	T pivot = _data[lo];

   while ( lo < hi ) 
   { //从向量的两端交替地向中间扫描
      while ( lo < hi )
      {
         if ( pivot < _elem[hi] )
         {
            hi--; //向左拓展右端子向量
         }
		 else //直至遇到不大于pivot者
         { 
         	_elem[lo++] = _elem[hi];
		    break;
		 }
      }
      while ( lo < hi )
      {
         if ( _elem[lo] < pivot )
         {
            lo++; //向右拓展左端子向量
         }  
         else //直至遇到不小于pivot者
         { 
             _elem[hi--] = _elem[lo];
		     break; 
		 }
      }
   } 
   //assert: lo == hi
   _elem[lo] = pivot; //将备份的轴点记录置于前、后子向量之间
   return lo; 
}


template <typename T>//[lo,hi)
void vector<T>::quickSort ( Rank lo, Rank hi )
{
	if (hi - lo < 2) return; //递归基

	Rank pivotRank = partition(lo, hi - 1);//[lo, hi - 1]
	quickSort(lo, pivotRank);//[lo,pivotRank)
	quickSort(pivotRank + 1, hi);//[pivotRank+1,hi)

}

template <typename T>//[lo,hi)
void vector<T>::heapSort ( Rank lo, Rank hi )
{

}


}



#endif //_VECTOR_IMPLEMENTAION__H_

