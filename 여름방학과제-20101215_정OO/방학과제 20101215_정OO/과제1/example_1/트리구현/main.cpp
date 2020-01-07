/*
     �ݿ��������б�
     ����: ����(Binary Tree) ���� - 1��(���ᱸ�� ����)
     �а�: Business & CSE
     �й�: 20101215
     �̸�: ������
*/

#include <iostream>
#include <math.h>
#include <string>
#include "binarytree.h"

using namespace std;

// 1. Visitor ����
const int INVEST = 0;      // ����
const int MAKE = 1;      // ����

const char StrToCh(const string D);

/* ���� ����Ʈ�� ���� ��� */
int GetBinaryCount(int Num){

	int i = 0;
	int Binary = 0;
	int Result = 0;

	// ���� = 2^0 + 2^1 + ... + 2^n;

	while (1)
	{
		Binary = (int)pow(2, (double)i);

		if ((Binary + Result) > Num)
			break;
		else
			Result += Binary;

		i++;
	}
	return Result;

}

/* ������ �� Ʈ�� ���� */
BinaryTree<int>* TreeCreate(Visit<int>* _pVisit, int _UserSize){

	// �½�Ʈ ����
	VisitNode<int>* nextVisit = _pVisit->GetHeadNode();
	VisitNode<int>* prevVisit = nextVisit;
	BinaryTree<int>* NewTree = new BinaryTree<int>();
	TreeNode<int>* NewNode, *TopNode = NULL;
	TreeNode<int>* NextNode;

	int Count = 1;
	int BinaryCount = GetBinaryCount(_UserSize);
	int GetSize = 0;
	int GetPosition = LEFT;  // �ʱ� ���� ����
	bool First = true;


	// ��Ʈ ����
	NewNode = NewTree->CreateNode(nextVisit->data);
	NewTree->SetRootNode(NewNode);
	NextNode = NewTree->GetRootNode();
	TopNode = NewTree->GetRootNode();

	// ��� ����
	nextVisit = nextVisit->link;
	while (nextVisit != NULL)
	{
		int Decision;
		GetSize = 0;
		TopNode = NewTree->GetRootNode();

		// ���� ���� ����
		if (Count < BinaryCount)
		{
			// ��ġ ����
			while (GetSize < nextVisit->height)
			{
				Decision = NONE;

				if (TopNode->LeftChild == NULL && TopNode->RightChild == NULL)
				{
					Decision = ALL;
				} // End of if

				if (Decision == NONE){

					if (TopNode->LeftChild != NULL && TopNode->RightChild == NULL)
					{
						Decision = LEFT;
					}

				} // End of if

				if (Decision == NONE){

					if (TopNode->LeftChild != NULL && TopNode->RightChild != NULL)
					{
						Decision = RIGHT;
					}

				} // End of if

				switch (Decision)
				{
				case LEFT:
					TopNode = TopNode->LeftChild;
					break;

				case RIGHT:
					TopNode = TopNode->RightChild;
					break;

				} // End of Switch

				GetSize++;
			} // End of While

		} // End of if(1/2)
		
		// ������ ���� ����
		else{
			
			// ��ġ ����
			while (GetSize < nextVisit->height)
			{
				Decision = NONE;

				if (TopNode->LeftChild == NULL && TopNode->RightChild == NULL)
				{
					Decision = ALL;
				} // End of if

				if (Decision == NONE)
				{
					if (TopNode->LeftChild != NULL && TopNode->RightChild != NULL)
						if ((GetSize + 1) == nextVisit->height)
							Decision = LEFT;
						else
							Decision = RIGHT;
				} // End of if

				// ����
				switch (Decision)
				{
				case LEFT:
					TopNode = TopNode->LeftChild;
					break;

				case RIGHT:
					TopNode = TopNode->RightChild;
					break;

				} // End of Switch

				GetSize++;
			} // End of While

		} // End of if(2/2)

		// ��尡 ������� ��
		if (TopNode == NULL)
		{
			NewNode = NewTree->CreateNode(nextVisit->data);
			NewTree->Insert(LEFT, TopNode, NewNode);
		}
		// ������ ������� �� ����
		else if (TopNode->LeftChild == NULL)
		{
			NewNode = NewTree->CreateNode(nextVisit->data);
			NewTree->Insert(LEFT, TopNode, NewNode);
		}
		// �������� ������� �� ����
		else if (TopNode->RightChild == NULL)
		{
			NewNode = NewTree->CreateNode(nextVisit->data);
			NewTree->Insert(RIGHT, TopNode, NewNode);
		}

		Count++;
		nextVisit = nextVisit->link;
	}

	return NewTree;
}

/* GetProcess
1. ���� �ܰ�(INVEST)
1-1. GetProcess(std::string D, int Type, int &pCount)
2. ���� �ܰ�(MAKE)
2-1. GetProcess(std::string D, int Type, int &pCount, Visit<int>* pVisit)
*/
void GetProcess(std::string D, int Type, int *pCount, Visit<int>* pVisit = NULL){

	bool First = false;			// ó������ �ľ�

	int EndIDX = D.length();
	int Height = 0;
	int Number = -1; // �ӽ� ���� ����

	string NumSt;
	string LevelSt;

	// ���� �ܰ�
	if (Type == MAKE)
	{
		if (pVisit->GetHeadNode() == NULL)
			First = true;
	}


	for (int StartIDX = 0; StartIDX < EndIDX; StartIDX++)
	{
		const char chData = StrToCh(D.substr(StartIDX, 1));

		// ������ ��
		if (isdigit(chData))
			NumSt.push_back(chData);

		// ���� �ľ�
		if (chData == '-')
			LevelSt.push_back(chData);

		// ������ ��
		if (chData == ' ' || (StartIDX + 1) == EndIDX)
		{
			switch (Type)
			{
			case INVEST:

				// ���� ����(���� �ľ� ����)
				if (!NumSt.empty())
				{
					NumSt.erase();
					*pCount = *pCount + 1;
				}
				break;

			case MAKE:

				// ���� ���� �Ǵ�
				if (!LevelSt.empty())
				{
					Height++;
					LevelSt.erase();
				}

				// ���� ����(���� �ľ� ����)
				if (!NumSt.empty())
				{
					Number = atoi(NumSt.c_str());
					NumSt.erase();

					if (Height == ROOT)
						pVisit->InsertNode(pVisit->CreateNode(ROOT, Number, Height)); // ��Ʈ��� ����

					else{

						if (((StartIDX + 1) == EndIDX) && Height == 1) // �������� ������ ��
						{
							pVisit->InsertNode(pVisit->CreateNode(NODE, Number, pVisit->GetHeight() - Height)); // �Ϲݳ�� ����
						}
						else
						{
							pVisit->InsertNode(pVisit->CreateNode(NODE, Number, Height)); // �Ϲݳ�� ����
						}
					} // End of if

					*pCount = *pCount + 1;
				}

				break;

			default:
				break;

			} // End of Switch

		} // End of if

	} // End of For

	// ù �Է��� ��
	if (First == true)
		pVisit->SetHeight(Height);

}

int main()
{
	int UserSize;
	int Count = 0;                  // ��� ��
	Visit<int>* pVisitor = new Visit<int>();   // Visitor ���
	BinaryTree<int>* Tree;

	cout << "��� ������ �Է��ϼ��� : ";
	cin >> UserSize;

	while (Count < UserSize)
	{
		int CurCount = 0;
		string UserData;
		std::getline(cin, UserData);

		GetProcess(UserData, INVEST, &CurCount); // 1. ����

		if ((Count + CurCount) > UserSize)
			cout << "��� ���� �ʰ�" << endl;
		else
		{
			Count += CurCount;
			CurCount = 0;
			GetProcess(UserData, MAKE, &CurCount, pVisitor); // 1. ����
		}
	}
	
	Tree = TreeCreate(pVisitor, UserSize);

	// �Ҹ� Visitor
	delete pVisitor;


	// VLR
	cout << "preorder     : ";
	Tree->Preorder(Tree->GetRootNode());
	cout << endl;

	// LVR
	cout << "inorder      : ";
	Tree->Inorder(Tree->GetRootNode());
	cout << endl;

	// LRV
	cout << "postorder    : ";
	Tree->Postorder(Tree->GetRootNode());
	cout << endl;

	// height ���� Traversal
	cout << "level order  : ";
	Tree->Levelorder(Tree->GetRootNode());
	cout << endl;

	delete Tree;

}

const char StrToCh(const string D){
	return D.at(0);
}