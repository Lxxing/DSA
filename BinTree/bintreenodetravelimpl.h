#ifndef _BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_
#define _BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_

#include <stack>

template <typename T, typename VST>//二叉树中序遍历算法（递归版）
void TravInR(BinTreeNodePtr node, VST& visit ) 
{ 
   if (NULL == node)
   {
	   return;//递归基
   }
   TravInR(node->lChild,visit);
   visit(node->data);
   TravInR(node->rChild,visit);
}

//从当前节点出发，沿左通路自顶向下不断深入，直至没有左分支的节点；
//沿途节点直接入栈。栈信息即为沿途节点的逆序记录
template <typename T, typename VST> 
static void GoAlongLeftBranch(BinTreeNodePtr x, VST& visit, 
	std::stack<BinTreeNodePtr>& S ) 
{
   while ( x ) //至叶节点
   {
      S.push (x); //当前节点入栈
      x = x->lChild;  //沿左分支深入一层
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
		node = node->rChild;//遍历完转向右子树。此处会把右节点当做一个节点入栈出栈读取
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
      		travQ.push (node); //当前节点入栈
      		node = node->lChild;  //沿左分支深入一层
   		}
   		else if(!travQ.empty())//已经到底
   		{
			node = travQ.top();
			travQ.pop();//最低祖先节点退栈
			visit(node->data);
			node = node->rChild;
   		}
   		else
   		{
			return;//退出条件
		}
	}
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::Succ()
{
	BinTreeNodePtr node = this;//记录后继的临时变量,必须初始化为当前节点
	//当前节点有右孩子，直接后继必存在于右子树，转入右子树再沿最左侧通路向左下方深入
	if (this->rChild)
	{
		node = this->rChild;
		while (HasLChild(*node))
		{
			node = node->lChild;//靠左最小节点
		}
	}
	else////直接后继若存在，必是某祖先,“将当前节点包含于其左子树中的最低祖先”
	{//沿右侧通路向左上，找到子树根，不能前进再向右上前进一步
		while (IsRChild(*node))
		{
			node = node->parent;
		}
		node = node->parent;
	}
	return node;
}

template <typename T, typename VST>//省去栈，仅O(1)辅助空间
void TravIn3( BinTreeNodePtr node,VST& visit ) 
{ 
	bool backTrack = false; //前一步是否刚从右子树回溯——true是回溯，false关闭标志
    while ( true )
    {
       if ( !backTrack && HasLChild ( *node ) ) //若有左子树且不是刚刚回溯，则
       {
          node = node->lChild; //深入遍历左子树
       }
       else//否则——无左子树或刚刚回溯（相当于无左子树）
       {
          visit ( node->data ); //访问该节点
          
          if ( HasRChild ( *node ) ) //若其右子树非空
          { 
             node = node->rChild; //深入右子树继续遍历
             backTrack = false; //并关闭回溯标志
          } 
          else //若右子树空
          { 
             if ( ! ( node = node->Succ() ) )
             	break; //回溯（含抵达末节点时的退出返回）
             //左子树遍历完毕	
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
  		    
  		    while ( !HasRChild ( *node ) ) //不断地在无右分支处
  		    {
  			    if ( node = node->Succ() )//回溯至直接后继
  			    {
  			    	visit ( node->data ); //访问新的当前节点
  			   	}
  			    else 
  			    {
  			    	return; //（在没有后继的末节点处，直接退出）
  			    }
  		    }
			node = node->rChild; //（直至有右分支处）转向非空的右子树

		}

	}

}

template <typename T, typename VST>
void TravPreR( BinTreeNodePtr node,VST& visit ) 
{ 
	if (NULL == node)
	{
		return;//递归基
	}
	visit(node->data);
	TravPreR(node->lChild,visit);
	TravPreR(node->rChild,visit);

}

//从当前节点出发，沿左通路自顶向下不断深入，直至没有左分支的节点；
//沿途节点遇到后立即访问
template <typename T, typename VST> //元素类型、操作器
static void VisitAlongLeftBranch(BinTreeNodePtr x, VST& visit, 
	stack<BinTreeNodePtr>& S ) 
{
   while ( x ) //至叶节点
   {
      visit ( x->data ); //访问当前节点
      S.push ( x->rChild ); //右孩子入栈暂存（可优化：通过判断，避免空的右孩子入栈）
      x = x->lChild;  //沿左分支深入一层
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
   std::stack<BinTreeNodePtr> S; //跟层次遍历的区别，层次是队列
   if (node ) S.push (node); //根节点入栈
   while ( !S.empty() ) //在栈变空之前反复循环
   { 
      node = S.top(); 
      S.pop();
      visit ( node->data ); //弹出并访问当前节点
      //其非空孩子的入栈次序为先右后左。入栈顺序与层次的区别
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
		return;//递归基
	}

	TravPostR(node->lChild,visit);
	TravPostR(node->rChild,visit);
	visit(node->data);
}

template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void HLVFL ( stack<BinTreeNodePtr> & S )
{ //沿途所遇节点依次入栈
    while ( BinTreeNodePtr x = S.top() ) //自顶而下，反复检查当前节点（即栈顶）
    {
 	    if ( HasLChild ( *x ) ) 
 	    { //尽可能向左
            if ( HasRChild ( *x ) ) 
            	S.push ( x->rChild ); //若有右孩子，优先入栈
 			S.push ( x->lChild ); //然后才转至左孩子
 		}
 		else
 		{
 			S.push ( x->rChild ); //右节点入栈，然后再次循环，直到空节点入栈
 		}
 
    }
     
    S.pop(); //返回之前，弹出栈顶的空节点
}

template <typename T, typename VST>
void TravPost1(BinTreeNodePtr node, VST& visit ) 
{ 
    std::stack<BinTreeNodePtr> travlQ;
    if ( node) travlQ.push ( node); //根节点入栈
    while ( !travlQ.empty() )
    {
       if ( travlQ.top() != node->parent ) //若栈顶非当前节点之父（则必为其右兄）
          HLVFL(travlQ ); //在以其右兄为根之子树中，找到HLVFL（相当于递归深入其中）
       node = travlQ.top();
       travlQ.pop();
       visit ( node->data ); //弹出栈顶（即前一节点之后继）
    }
}




#endif //_BIN_TREE_NODE_TRAVEL_IMPLEMENTATION__H_


