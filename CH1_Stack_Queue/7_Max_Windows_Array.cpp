/*
2019-10.6
CH1 双端队列--生成窗口最大值数组
测试样例:
8 3
4 3 5 4 3 3 6 7

输出:
5 5 5 4 6 7
*/

#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

deque<int> dq;            // 注意:存元素下标而非元素值!
vector<int> arr;

int main()
{
	// freopen("in.txt", "r", stdin);
	int len, w, temp;     // len:数组长度,w:窗口大小,temp:当前输入值
	cin >> len >> w;
	for (int i = 0; i < len; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	
	for (int i = 0; i < len; i++)
	{                     // 若队尾元素小于当前元素,弹出队末元素直到队列为空
		while (!dq.empty() && arr[dq.back()] <= arr[i])  // <= !!
			dq.pop_back();
		dq.push_back(i);         // 这一步是对任意i都必须操作的(思考)

		if (i >= w-1)            // 窗口,从w-1下标开始,根据dq输出窗口最大值
		{
			int ind = dq.front();
			while (ind <= i - w)  // 避免队头元素位于窗口外!用if更好!因为每次只加入一个元素
			{
				dq.pop_front();
				ind = dq.front();
			}
			cout << arr[ind] << " ";
		}
	}
	return 0;
}
