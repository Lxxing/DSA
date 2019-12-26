#ifndef _LX_LIST__H_
#define _LX_LIST__H_

#include "ListNode.h"

//˫���б���ADT
template <typename T>
class List
{
public:
	List();
	~List();

	Rank size() const;//�����ģ
	bool empty() const;//���ж�
	T& operator [] (Rank r) const;//Ѱ�ȷ��ʣ�O(n)
	ListNodePtr first() const; //�׽ڵ�
	ListNodePtr last() const;    //β���
	bool valid(ListNodePtr p) const;	//�ڵ��Ƿ���Ч
	int disordered() const;     //�ж��б��Ƿ�����
	ListNodePtr find(T const & e) const;    //�����������
	ListNodePtr find(T const &e, int n, ListNodePtr p) const;    //���������������
	ListNodePtr search(T const & e) const;   //�������
	ListNodePtr search(T const &e,int n,ListNodePtr p) const;//�����������
	ListNodePtr selectMax(ListNodePtr p,int n) const;    //p�ڵ���n-1����������
	ListNodePtr selectMax() const;    //�����������

	ListNodePtr insertAsFirst(T const &e);//e��Ϊ�׽ڵ����
	ListNodePtr insertAsLast(T const &e);//e��Ϊβ�ڵ����
	ListNodePtr insertBefore(ListNodePtr p,T const &e);//e��Ϊpǰ������
	ListNodePtr insertAfter(ListNodePtr p,T const &e);//e��Ϊp��̲���
	T remove(ListNodePtr p);//ɾ���ڵ�p������ɾ���ڵ�
	void merge(List<T> &l);//ȫ�б�鲢
	void sort(ListNodePtr p,int n);//�б���������
	void sort();//�б�ȫ����
	int deduplicate();//����ȥ��
	int uniqufy();//����ȥ��
	void reverse();//��ת�б�

	//����
	void tranvers(void (*) (T&));
	template <typename VST>
	void tranvers(VST& vst);//����
protected:
	void merge ( ListNodePtr&, int, List<T>&, ListNodePtr, int ); //�鲢
	void selectionSort ( ListNodePtr p, int n );		//ѡ�����򣬴�p��ʼ��n���ڵ�
private:
	ListNodePtr _header;
	ListNodePtr _tailer;
	int _size;

};


#include "ListImplementation.h"


#endif //_LX_LIST__H_
