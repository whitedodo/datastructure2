/*
	금오공과대학교
	과제 : 방학(Binary Search Tree) 과제5 - 3번
	학과 : Business & CSE
	학번 : 20101215
	이름 : 정원영
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
		cout << "문자열들을 입력하세요(마지막은 0) : ";

		std::getline(cin, Data);

		if (Data == "0"){
			cout << "종료합니다." << endl;
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

		// 끝에 도달했을 때
		if ((IDX + 1) == Length)
		{
			GetMax = BSTree->GetMax();
			// 갯수가 일치할 때
			if (Count == GetMax)
			{
				BSTree->SetMax(INITIAL);
				TreeNode<std::string>* tmpNode = BSTree->Search(BSTree->GetNode(), INITIAL, Count);
				D = tmpNode->Data;

				BSTree->Remove(BSTree->GetNode(), tmpNode->Data);
				tmpNode = BSTree->Create(D);
				BSTree->Insert(BSTree->GetNode(), tmpNode);
			}

			// 삭제와 추가 구현해보기
		}

		IDX++;
	}

	// NULL 여부 판단

	if (BSTree->GetNode() != NULL){
		BSTree->SetMax(GetMax); // GetMax 설정
		BSTree->PrintOut(BSTree->GetNode());
	}
	else
		cout << "데이터가 존재하지 않습니다." << endl;
}

const char StringToChar(std::string _Data, int index){
	string D = _Data.substr(index, 1);
	return D.at(0);
}
