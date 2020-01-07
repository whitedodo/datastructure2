/*
	�ݿ��������б�
	���� : ����(Binary Search Tree) ����5 - 3��
	�а� : Business & CSE
	�й� : 20101215
	�̸� : ������
*/

#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

const char StringToChar(std::string _Data, int index);
void Parser(std::string _Data);
void main()
{
	while (1)
	{
		string Data;
		cout << "���ڿ����� �Է��ϼ���(�������� 0) : ";

		std::getline(cin, Data);

		if (Data == "0"){
			cout << "�����մϴ�." << endl;
			break;
		}
		else
		{
			Parser(Data);
		}
	}
}

void Parser(std::string _Data)
{
	BST<std::string>* BSTree = new BST<std::string>();
	TreeNode<std::string>* pNode = NULL;
	int Count = 0;
	int GetMax = -1;
	int IDX = 0;
	int Length = _Data.length();
	string D;

	BSTree->SetMax(INITIAL);

	while (IDX < Length)
	{
		char ch = StringToChar(_Data, IDX);

		if (ch == ' ')
		{
			pNode = BSTree->Create(D);
			BSTree->Insert(BSTree->GetNode(), pNode);
			Count++;

			D.erase();
		}

		if (ch != '0' && ch != ' ')
		{
			D.push_back(ch);
		}

		// ���� �������� ��
		if ((IDX + 1) == Length)
		{
			GetMax = BSTree->GetMax();
			// ������ ��ġ�� ��
			if (Count == GetMax)
			{
				BSTree->SetMax(INITIAL);
				TreeNode<std::string>* tmpNode = BSTree->Search(BSTree->GetNode(), INITIAL, Count);
				D = tmpNode->Data;

				BSTree->Remove(BSTree->GetNode(), tmpNode->Data);
				tmpNode = BSTree->Create(D);
				BSTree->Insert(BSTree->GetNode(), tmpNode);
			}

			// ������ �߰� �����غ���
		}

		IDX++;
	}

	// NULL ���� �Ǵ�

	if (BSTree->GetNode() != NULL){
		BSTree->SetMax(GetMax); // GetMax ����
		BSTree->PrintOut(BSTree->GetNode());
	}
	else
		cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
}

const char StringToChar(std::string _Data, int index){
	string D = _Data.substr(index, 1);
	return D.at(0);
}
