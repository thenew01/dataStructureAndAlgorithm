// dataStructureAndAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <sal.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;


#include "dfs.h"

//������

template <typename T>
class TreeNode
{
	//friend class BSTree;
public:
	TreeNode* lChild, *rChild;
	bool lEntered, rEntered;
	TreeNode* parent; //��Ӹ��׽ڵ㣬��Ȼɾ����ʱ���޷���ø��׽ڵ�
	T data;

};

template <typename T>
class BSTree
{
private:
	TreeNode<T>* tree;
	
	TreeNode<T>* search(TreeNode<T>* t, T x);
public:
	BSTree(){ tree = NULL; }
	~BSTree(){ delete tree; }

	TreeNode<T>* getRoot() {return tree; }
	TreeNode<T>* search(T x);	//�ݹ�����
	TreeNode<T>* iSearch(T x);	//ѭ������
	void deepFirstSearch_Recurse(TreeNode<T>* node);
	void deepFirstSearch_NonRecurse(TreeNode<T>* node);
	void insert(T x);
	void deleteNode(T& x);
};

template <typename T>
TreeNode<T>* 
BSTree<T>::search(T x)
{
	return search(tree, x);
}

template <typename T>
TreeNode<T>*
BSTree<T>::search(TreeNode<T>* t, T x)
{
	if( t == NULL ) return NULL;
	else if( x == t->data ) return t;
	else if( x < t->data ) return search(t->lChild, x);
	else if( x > t->data ) return search(t->rChild, x);
}

template <typename T>
TreeNode<T>*
BSTree<T>::iSearch(T x)
{
	bool bFound = false;
	TreeNode* t = tree;
	while( t && !bFound )
	{
		if( x == t->data ) bFound = true;
		else if( x < t->data ) t = t->lChild;
		else t = t->rChild;
	}
	if( bFound ) return t;
	else return NULL;
}
template <typename T>
void 
BSTree<T>::insert(T x)
{
	bool bFound = false;
	TreeNode<T>* temp, *p = tree;
	while( p && !bFound )
	{
		temp = p; //����p
		if( x == p->data ) bFound = true;
		else if( x < p->data ) p = p->lChild;
		else p = p->rChild;
	}

	if( !bFound )
	{
		p = new TreeNode<T>;
		p->lChild = p->rChild = NULL;
		p->lEntered = p->rEntered = false;
		p->data = x;
		if( tree )
		{
			if( x < temp->data ) 
			{
				temp->lChild = p;
				p->parent = temp;
			}			
			else
			{
				temp->rChild = p;
				p->parent = temp;
			}
		}
		else 
		{
			tree = p;
			p->parent = NULL;
			tree->parent = NULL;
		}
	}
}

template <typename T>
void 
BSTree<T>::deleteNode(T& x)
{
	bool bFound = false;
	TreeNode* temp, *p = tree;
	while( p && !bFound )
	{
		temp = p; 
		if( x == p->data ) bFound = true;
		else if(x < p->data ) p = p->lChild;
		else p = p->rChild;
	}

	if( bFound ) //�ҵ�ʱ�ǵ�ǰ�ڵ㣬��֪�����ڵ�
	{
		if( temp->lChild && temp->rChild ) //����������
		{
			//����ö������������д���
			/*temp->lChild->parent = temp->parent;
			temp->rChild->parent = temp->parent;
			temp->parent->lChild = temp->lChild;
			temp->parent->rChild = temp->rChild;
			delete temp;*/
		}
		else if( temp->lChild != NULL )
		{
			temp->lChild->parent = temp->parent;
			temp->parent->lChild = temp->lChild;
			temp->parent = NULL;
			delete temp;
		}
		else if(  temp->rChild != NULL )
		{
			temp->rChild->parent = temp->parent;
			temp->parent->rChild = temp->rChild;
			temp->parent = NULL;
			delete temp;
		}
		else 
		{				
			delete temp;
			temp = NULL; //��Ҷ�ӽڵ�
		}
	}
}

template <typename T>
void 
BSTree<T>::deepFirstSearch_Recurse(TreeNode<T>* node)
{
	if( node == NULL )
		return;

	if( node->lChild ) 
	{
		printf("parent->lChild(%d->%d)\r\n", node->data, node->lChild->data);
		deepFirstSearch_Recurse(node->lChild);
	}			

	if( node->rChild )
	{
		printf("parent->rChild(%d->%d)\r\n", node->data, node->rChild->data);
		deepFirstSearch_Recurse(node->rChild);
	}
}

stack<TreeNode<int>*> gStack;

template <typename T>
void 
BSTree<T>::deepFirstSearch_NonRecurse(TreeNode<T>* node)
{
	while(node)
	{
		if( node->lChild && !node->lEntered ) 
		{
			printf("parent->lChild(%d->%d)\r\n", node->data, node->lChild->data);
			node->lEntered = true;
			gStack.push(node);
			node = node->lChild;
			continue;
		}			

		if( node->rChild && !node->rEntered)
		{
			printf("parent->rChild(%d->%d)\r\n", node->data, node->rChild->data);
			node->rEntered = true;
			gStack.push(node);
			node = node->rChild;
			continue;
		}

		if( gStack.empty() )
			break;

		node = gStack.top();
		gStack.pop();
	}
}


#pragma warning(error: 6063)
int _tmain(int argc, _TCHAR* argv[])
{
	BSTree<int> tree;	
	for ( int i= 0;i<20;i++)
	{
		int data = rand() % 100;		
		tree.insert(data);
	}

	tree.deepFirstSearch_Recurse(tree.getRoot());

	printf( "%s");

	getchar();
	getchar();

	return 0;
}


