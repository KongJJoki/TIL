#include <iostream>
#include <vector>
#include <stack>

int main()
{
	int nInputN{};
	int nNumberCursor{};
	int nResultLength{};
	bool bValid{};
	std::stack<int> stcInput{};
	std::vector<int> vecInput{};
	std::vector<char> vecResult{};

	bValid = true;
	nNumberCursor = 1; // 숫자 1 부터 넣기 시작
	stcInput.push(0); // 처음부터 top봐야하는데 없으면 에러나니까 0 넣어주기

	std::cin >> nInputN;


	for (int i = 0; i < nInputN; i++)
	{
		int nTmp{};
		std::cin >> nTmp;
		
		if(stcInput.top() < nTmp) // 스택의 맨 위 수가 입력받은 수보다 작은 경우
		{
			while (stcInput.top() < nTmp) // 스택의 맨 위 수가 입력받은 수보다 작으면 같아질때까지 + 해야함
			{
				stcInput.push(nNumberCursor);
				nNumberCursor++; // 1 2 3 4 ... 순서로 넣어야하니까 숫자 넣고 다음 숫자로 가기위해서 ++ 하기
				vecResult.push_back('+');
				nResultLength++;
			}
		}

		if (stcInput.top() == nTmp) // 맨 위가 원하는 수랑 같으면 바로 pop
		{
			stcInput.pop();
			vecResult.push_back('-');
			nResultLength++;
		}
		else //top 이 원하는 수보다 큰 경우 -> 오름차순으로 넣기 때문에 이미 내가 원하는 수는 들어갔다가 - 로 나왔음 그래서 못함
		{
			bValid = false;
			break;
		}
	}

	if (bValid == false)
	{
		std::cout << "NO";
	}
	else
	{
		for (int i = 0; i < nResultLength; i++)
		{
			std::cout << vecResult[i] << '\n';
		}
	}
}