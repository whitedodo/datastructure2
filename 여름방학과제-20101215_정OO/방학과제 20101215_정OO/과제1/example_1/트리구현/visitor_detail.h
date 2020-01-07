#ifndef _VISITOR_DETAIL_H_
#define _VISITOR_DETAIL_H_

#include "binarytree.h"

using namespace std;

template <class T>
void Visit<T>::SetHeight(int height){
	MaxHeight = height;
}

template <class T>
int Visit<T>::GetHeight(){
	return MaxHeight;
}

template <class T>
VisitNode<T>* Visit<T>::CreateNode(int Type, T Element, int height){

	VisitNode<T>* pNode = new VisitNode<T>();
	pNode->type = Type;
	pNode->data = Element;
	pNode->height = height;
	pNode->link = NULL;

	return pNode;
}

template <class T>
void Visit<T>::InsertNode(VisitNode<T>* pNode){

	if (TopNode != NULL){
		TopNode->link = pNode;
		TopNode = TopNode->link;
	}
	else
	{
		TopNode = pNode;
		HeadNode = TopNode;
	}
}

template <class T>
VisitNode<T>* Visit<T>::GetTopNode(){
	return TopNode;
}

template <class T>
VisitNode<T>* Visit<T>::GetHeadNode(){
	return HeadNode;
}


template <class T>
Visit<T>::Visit(){
	HeadNode = NULL;
	TopNode = NULL;
}

template <class T>
Visit<T>::~Visit(){

	VisitNode<T>* prevNode;

	while (TopNode != NULL)
	{
		prevNode = TopNode;
		TopNode = TopNode->link;
		delete prevNode;
	}

}

#endif