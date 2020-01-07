/*
금오공과대학교
과제: 방학(Binary Tree) 과제5 - 2번(계산식)
학과: Business & CSE
학번: 20101215
이름: 정원영
*/

#include <iostream>
#include <istream>
#include <string>
#include <math.h>
#include "tree.h"
#include "stack.h"

using namespace std;

int eval(char *post);
void postfix(char *dst, char *src);
int is_legal(char *postfix);
int precedence(int op);
bool is_operator(int op);
char* blankToChar(char* dest);
char* createBlankChar(int size);
int is_quit(char* dest);

int main()
{
	int result;

	while (1)
	{
		char *exp = createBlankChar(256);
		char Infix[256];
		cout << "계산식을 입력하세요 (종료는 quit) : ";

		cin.clear();
		cin.getline(Infix, 256);

		if (is_quit(Infix))
			break;

		postfix(exp, blankToChar(Infix));

		if (!is_legal(exp))
		{
			cout << "정상적인 표현이 아닙니다." << endl;
			continue;
		}
		else
		{
			cout << "--- 후위 계산식은 : " << exp << endl;
			result = eval(exp);
			cout << "---- 결과는 " << result << endl;
		}
	}
	return 0;

}

char* createBlankChar(int size){

	char* exp = new char[size];

	for (int i = 0; i < size; i++)
		exp[i] = NULL;

	return exp;
}

int is_quit(char* dest){

	int idx = 0;

	const int q = 0;
	const int u = 1;
	const int i = 2;
	const int t = 3;
	const int quit = 4;

	bool check = true;

	while (*dest){

		switch (idx)
		{
		case q:
			if (*dest != 'q')
				check = false;
			break;

		case u:
			if (*dest != 'u')
				check = false;
			break;

		case i:
			if (*dest != 'i')
				check = false;
			break;

		case t:
			if (*dest != 't')
				check = false;
			break;

		default:
			if (idx > t)
				check = false;
			break;
		}

		idx++;
		*dest++;
	}

	if (idx != quit)
		check = false;

	return check;

}

char* blankToChar(char* dest){

	char* pDest = new char[256];
	int i = 0;
	while (i < 256)
	{
		pDest[i++] = ' ';
	}

	i = 0;
	while (*dest)
	{
		if (*dest != ' ')
			pDest[i++] = *dest;

		*dest++;
	}

	return pDest;
}

bool is_operator(int op)
{
	bool result = false;

	if (op == '+' || op == '-')
		result = true;
	if (op == '*' || op == '^')
		result = true;
	if (op == '/' || op == '^')
		result = true;
	if (op == '%')
		result = true;

	return result;
}

int precedence(int op)
{
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	else return 4;
}

int is_legal(char *postfix)
{
	int result = 0;

	if (*postfix == NULL)
		return 0;

	while (*postfix)
	{
		while (*postfix == ' ')
			postfix++;

		if (is_operator(*postfix))
			result--;
		else
		{
			if (*postfix != '~')
				result++;

			while (*postfix != ' ')
				postfix++;
		} // End of if

		if (result < 1) break;
		postfix++;
	}

	return (result == 1);
}

void postfix(char *dst, char *src)
{
	Stack<char> *PostStack = new Stack<char>();
	Stack<char> *MinusStack = new Stack<char>();

	while (*src)
	{
		if (*src == '(')
		{
			PostStack->push(*src);
			src++;
		}
		else if (*src == ')')
		{
			while (PostStack->get_stack_top() != '(')
			{
				*dst++ = PostStack->pop();
				*dst++ = ' ';
			}
			PostStack->pop();
			src++;
		}
		else if (is_operator(*src))
		{
			while (!PostStack->is_stack_empty() && precedence(PostStack->get_stack_top()) >= precedence(*src))
			{
				*dst++ = PostStack->pop();
				*dst++ = ' ';
			}

			if (*src == '-' && src[1] == '-')
				MinusStack->push('~');
			else
				PostStack->push(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');

			if (!MinusStack->is_stack_empty())
			{
				*dst++ = ' ';
				*dst++ = MinusStack->pop();
			}

			*dst++ = ' ';
		}
		else
			src++;
	}

	while (!PostStack->is_stack_empty())
	{
		*dst++ = PostStack->pop();
		*dst++ = ' ';
	}
	dst--;
	*dst = 0;
}

int eval(char *post)
{
	int left, right, result;

	Tree<std::string>* pTree = new Tree<std::string>();
	Stack<int> *PostStack = new Stack<int>();

	while (*post)
	{
		if (*post >= '0' && *post <= '9')
		{
			result = 0;
			do
			{
				result = result * 10 + *post - '0';
				post++;
			} while (*post >= '0' && *post <= '9');

			PostStack->push(result);
		}
		else if (*post == '+')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = right + left;
			PostStack->push(result);
			pTree->Make(left, right, result, '+');

			post++;
		}
		else if (*post == '*')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = right * left;
			PostStack->push(result);
			pTree->Make(left, right, result, '*');

			post++;
		}
		else if (*post == '-')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = left - right;
			PostStack->push(result);
			pTree->Make(left, right, result, '-');

			post++;
		}
		else if (*post == '/')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = left / right;
			PostStack->push(result);
			pTree->Make(left, right, result, '/');
		}
		else if (*post == '^')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = (int)pow((double)left, (double)right);
			PostStack->push(result);
			pTree->Make(left, right, result, '^');

			post++;
		}
		else if (*post == '%')
		{
			right = PostStack->pop();
			left = PostStack->pop();

			result = left % right;
			PostStack->push(result);
			pTree->Make(left, right, result, '%');

			post++;
		}
		else if (*post == '~')
		{
			left = PostStack->pop();
			right = NULL;

			PostStack->push((-1) * left);
			pTree->Make(left, NULL, NULL, '~');

			post++;
		}
		else
			post++;

	} // End of if

	// 초기 라인스타일
	pTree->PrintOut(pTree->GetTree());

	result = PostStack->pop();

	return result;

}


