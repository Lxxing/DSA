#ifndef _BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_
#define _BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_

#include <stack>

template <typename T, typename VST>//��������������㷨���ݹ�棩
void TravInR(BinTreeNodePtr node, VST& visit ) 
{ 
   if (NULL == node)
   {
	   return;//�ݹ��
   }
   TravInR(node->lChild,visit);
   visit(node->data);
   TravInR(node->rChild,visit);
}

//�ӵ�ǰ�ڵ����������ͨ·�Զ����²������룬ֱ��û�����֧�Ľڵ㣻
//��;�ڵ�ֱ����ջ��ջ��Ϣ��Ϊ��;�ڵ�������¼
template <typename T, typename VST> 
static void GoAlongLeftBranch(BinTreeNodePtr x, VST& visit, 
	std::stack<BinTreeNodePtr>& S ) 
{
   while ( x ) //��Ҷ�ڵ�
   {
      S.push (x); //��ǰ�ڵ���ջ
      x = x->lChild;  //�����֧����һ��
   }
}

template <typename T, typename VST>
void TravIn1(BinTreeNodePtr node, VST& visit ) 
{ 

    std::stack<BinTreeNodePtr> travQ;
	while (1)
	{
		GoAlongLeftBranch(node, visit,travQ);
		if (travQ.empty())
		{
			return;
		}
		node = travQ.top();
		travQ.pop();
		visit(node->data);
		node = node->rChild;//������ת�����������˴�����ҽڵ㵱��һ���ڵ���ջ��ջ��ȡ
	}
}

template <typename T, typename VST>
void TravIn2 (BinTreeNodePtr node, VST& visit ) 
{ 
    std::stack<BinTreeNodePtr> travQ;
	while (1)
	{
	
		if(node)
   		{
      		travQ.push (node); //��ǰ�ڵ���ջ
      		node = node->lChild;  //�����֧����һ��
   		}
   		else if(!travQ.empty())//�Ѿ�����
   		{
			node = travQ.top();
			travQ.pop();//������Ƚڵ���ջ
			visit(node->data);
			node = node->rChild;
   		}
   		else
   		{
			return;//�˳�����
		}
	}
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::Succ()
{
	BinTreeNodePtr node = this;//��¼��̵���ʱ����,�����ʼ��Ϊ��ǰ�ڵ�
	//��ǰ�ڵ����Һ��ӣ�ֱ�Ӻ�̱ش�������������ת�����������������ͨ·�����·�����
	if (this->rChild)
	{
		node = this->rChild;
		while (HasLChild(*node))
		{
			node = node->lChild;//������С�ڵ�
		}
	}
	else////ֱ�Ӻ�������ڣ�����ĳ����,������ǰ�ڵ���������������е�������ȡ�
	{//���Ҳ�ͨ·�����ϣ��ҵ�������������ǰ����������ǰ��һ��
		while (IsRChild(*node))
		{
			node = node->parent;
		}
		node = node->parent;
	}
	return node;
}

template <typename T, typename VST>//ʡȥջ����O(1)�����ռ�
void TravIn3( BinTreeNodePtr node,VST& visit ) 
{ 
	bool backTrack = false; //ǰһ���Ƿ�մ����������ݡ���true�ǻ��ݣ�false�رձ�־
    while ( true )
    {
       if ( !backTrack && HasLChild ( *node ) ) //�����������Ҳ��Ǹոջ��ݣ���
       {
          node = node->lChild; //�������������
       }
       else//���򡪡�����������ոջ��ݣ��൱������������
       {
          visit ( node->data ); //���ʸýڵ�
          
          if ( HasRChild ( *node ) ) //�����������ǿ�
          { 
             node = node->rChild; //������������������
             backTrack = false; //���رջ��ݱ�־
          } 
          else //����������
          { 
             if ( ! ( node = node->Succ() ) )
             	break; //���ݣ����ִ�ĩ�ڵ�ʱ���˳����أ�
             //�������������	
             backTrack = true;
          }
       }
     }
       
}
template <typename T, typename VST>
void TravIn4( BinTreeNodePtr node,VST& visit ) 
{ 
	while (1)
	{
		if ( HasLChild ( *node) )
		{
			node = node->lChild;
		}
		else 
		{
  		    visit ( node->data );
  		    
  		    while ( !HasRChild ( *node ) ) //���ϵ������ҷ�֧��
  		    {
  			    if ( node = node->Succ() )//������ֱ�Ӻ��
  			    {
  			    	visit ( node->data ); //�����µĵ�ǰ�ڵ�
  			   	}
  			    else 
  			    {
  			    	return; //����û�к�̵�ĩ�ڵ㴦��ֱ���˳���
  			    }
  		    }
			node = node->rChild; //��ֱ�����ҷ�֧����ת��ǿյ�������

		}

	}

}

template <typename T, typename VST>
void TravPreR( BinTreeNodePtr node,VST& visit ) 
{ 
	if (NULL == node)
	{
		return;//�ݹ��
	}
	visit(node->data);
	TravPreR(node->lChild,visit);
	TravPreR(node->rChild,visit);

}

//�ӵ�ǰ�ڵ����������ͨ·�Զ����²������룬ֱ��û�����֧�Ľڵ㣻
//��;�ڵ���������������
template <typename T, typename VST> //Ԫ�����͡�������
static void VisitAlongLeftBranch(BinTreeNodePtr x, VST& visit, 
	stack<BinTreeNodePtr>& S ) 
{
   while ( x ) //��Ҷ�ڵ�
   {
      visit ( x->data ); //���ʵ�ǰ�ڵ�
      S.push ( x->rChild ); //�Һ�����ջ�ݴ棨���Ż���ͨ���жϣ�����յ��Һ�����ջ��
      x = x->lChild;  //�����֧����һ��
   }
}

template <typename T, typename VST>
void TravPre1(BinTreeNodePtr node, VST& visit ) 
{ 
	std::stack<BinTreeNodePtr> S;
	while (1)
	{
		VisitAlongLeftBranch(node, visit,S);
		if (S.empty())
		{
			return;
		}
		node = S.top();
		S.pop();
	}
}

template <typename T, typename VST>
void TravPre2( BinTreeNodePtr node,VST& visit ) 
{ 
   std::stack<BinTreeNodePtr> S; //����α��������𣬲���Ƕ���
   if (node ) S.push (node); //���ڵ���ջ
   while ( !S.empty() ) //��ջ���֮ǰ����ѭ��
   { 
      node = S.top(); 
      S.pop();
      visit ( node->data ); //���������ʵ�ǰ�ڵ�
      //��ǿպ��ӵ���ջ����Ϊ���Һ�����ջ˳�����ε�����
      if ( HasRChild ( *node ) ) 
      	S.push ( node->rChild ); 
      if ( HasLChild ( *node ) ) 
      	S.push ( node->lChild );
   }
}


template <typename T, typename VST>
void TravPostR( BinTreeNodePtr node,VST& visit ) 
{ 
	if (NULL == node)
	{
		return;//�ݹ��
	}

	TravPostR(node->lChild,visit);
	TravPostR(node->rChild,visit);
	visit(node->data);
}

template <typename T> //����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
static void HLVFL ( stack<BinTreeNodePtr> & S )
{ //��;�����ڵ�������ջ
    while ( BinTreeNodePtr x = S.top() ) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
    {
 	    if ( HasLChild ( *x ) ) 
 	    { //����������
            if ( HasRChild ( *x ) ) 
            	S.push ( x->rChild ); //�����Һ��ӣ�������ջ
 			S.push ( x->lChild ); //Ȼ���ת������
 		}
 		else
 		{
 			S.push ( x->rChild ); //�ҽڵ���ջ��Ȼ���ٴ�ѭ����ֱ���սڵ���ջ
 		}
 
    }
     
    S.pop(); //����֮ǰ������ջ���Ŀսڵ�
}

template <typename T, typename VST>
void TravPost1(BinTreeNodePtr node, VST& visit ) 
{ 
    std::stack<BinTreeNodePtr> travlQ;
    if ( node) travlQ.push ( node); //���ڵ���ջ
    while ( !travlQ.empty() )
    {
       if ( travlQ.top() != node->parent ) //��ջ���ǵ�ǰ�ڵ�֮�������Ϊ�����֣�
          HLVFL(travlQ ); //����������Ϊ��֮�����У��ҵ�HLVFL���൱�ڵݹ��������У�
       node = travlQ.top();
       travlQ.pop();
       visit ( node->data ); //����ջ������ǰһ�ڵ�֮��̣�
    }
}




#endif //_BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_


