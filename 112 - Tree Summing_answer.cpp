#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//递归扫描输入的整棵树
bool ScanTree(int nSum, int nDest, bool *pNull) {
	static int nChild;
	//略去当前一级前导的左括号
	cin >> (char&)nChild;
	//br用于递归子节点的计算结果，bNull表示左右子是否为空
	bool br = false, bNull1 = false, bNull2 = false;
	//如果读入值失败，则该节点必为空                     //如果为空就不操作 很机智 很关键 不用验空串了
	if (!(*pNull = ((bool)(cin >> nChild) == 0))) {
		//总和加上读入的值，遍例子节点
		nSum += nChild;
		//判断两个子节点是否能返回正确的结果
		br = ScanTree(nSum, nDest, &bNull1) | ScanTree(nSum, nDest, &bNull2);
		//如果两个子节点都为空，则本节点为叶，检验是否达到目标值
		if (bNull1 && bNull2) {
			br = (nSum == nDest);
		}
	}
	//清除节点为空时cin的错误状态
	cin.clear();
	//略去当前一级末尾的右括号
	cin >> (char&)nChild;
	return br;
}
//主函数
int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	bool bNull;
	//输入目标值
	for (int nDest; cin >> nDest;) {
		//根据结果输出yes或no
		cout << (ScanTree(0, nDest, &bNull) ? "yes" : "no") << endl;
	}
	return 0;
}
