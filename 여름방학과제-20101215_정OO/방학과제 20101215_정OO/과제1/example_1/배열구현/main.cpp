/*
     금오공과대학교
     과제: 방학(Binary Tree) 과제 - 1번(배열 구현)
     학과: Business & CSE
     학번: 20101215
     이름: 정원영
*/

#include <iostream>
#include <string>
#include "io.h"
#include "binarytree.h"

using namespace std;

int main()
{
	int Count = 0;
	int UserSize;	      // 노드 사이즈 - 사용자가 지정

	BinaryTree<int> Tree; // 트리 생성
	string UserData;

	cout << "노드 개수를 입력하세요 : ";
	cin >> UserSize;

	// 1. 데이터 입력
	while (Count != UserSize)
	{
		string TmpData;
		std::getline(cin, TmpData);
		
		int CurCount = Tree.GetCount(TmpData);

		// (CurrentLevel + Count)로 범위 파악 (UserSize 비교)
		if ((Count + CurCount) > UserSize)
			cout << "노드 갯수 초과" << endl;
		else
		{
			TmpData.append("\n");
			UserData.append(TmpData);
			Count += CurCount;
		}

	} // End of while
	
	// 2. Binary Tree
	Tree.SetMaxSize(UserSize);
	Tree.SetData(UserData);

	// Traversal 처리
	cout << "preorder    : ";
	Tree.Preorder(1);
	cout << endl;

	cout << "inorder     : ";
	Tree.Inorder(1);
	cout << endl;

	cout << "postorder   : ";
	Tree.Postorder(1);
	cout << endl;

	cout << "level order : ";
	Tree.Levelorder(1);
	cout << endl;

	// 소멸자 처리
	Tree.DestoryTree();
}

// String To Char(자료형 변환)
const char StrToCh(std::string Data){
	return Data.at(0);
}