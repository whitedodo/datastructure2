/*
     �ݿ��������б�
     ����: ����(Binary Tree) ���� - 1��(�迭 ����)
     �а�: Business & CSE
     �й�: 20101215
     �̸�: ������
*/

#include <iostream>
#include <string>
#include "io.h"
#include "binarytree.h"

using namespace std;

int main()
{
	int Count = 0;
	int UserSize;	      // ��� ������ - ����ڰ� ����

	BinaryTree<int> Tree; // Ʈ�� ����
	string UserData;

	cout << "��� ������ �Է��ϼ��� : ";
	cin >> UserSize;

	// 1. ������ �Է�
	while (Count != UserSize)
	{
		string TmpData;
		std::getline(cin, TmpData);
		
		int CurCount = Tree.GetCount(TmpData);

		// (CurrentLevel + Count)�� ���� �ľ� (UserSize ��)
		if ((Count + CurCount) > UserSize)
			cout << "��� ���� �ʰ�" << endl;
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

	// Traversal ó��
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

	// �Ҹ��� ó��
	Tree.DestoryTree();
}

// String To Char(�ڷ��� ��ȯ)
const char StrToCh(std::string Data){
	return Data.at(0);
}