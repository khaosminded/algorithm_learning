#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//�ݹ�ɨ�������������
bool ScanTree(int nSum, int nDest, bool *pNull) {
	static int nChild;
	//��ȥ��ǰһ��ǰ����������
	cin >> (char&)nChild;
	//br���ڵݹ��ӽڵ�ļ�������bNull��ʾ�������Ƿ�Ϊ��
	bool br = false, bNull1 = false, bNull2 = false;
	//�������ֵʧ�ܣ���ýڵ��Ϊ��                     //���Ϊ�վͲ����� �ܻ��� �ܹؼ� ������մ���
	if (!(*pNull = ((bool)(cin >> nChild) == 0))) {
		//�ܺͼ��϶����ֵ�������ӽڵ�
		nSum += nChild;
		//�ж������ӽڵ��Ƿ��ܷ�����ȷ�Ľ��
		br = ScanTree(nSum, nDest, &bNull1) | ScanTree(nSum, nDest, &bNull2);
		//��������ӽڵ㶼Ϊ�գ��򱾽ڵ�ΪҶ�������Ƿ�ﵽĿ��ֵ
		if (bNull1 && bNull2) {
			br = (nSum == nDest);
		}
	}
	//����ڵ�Ϊ��ʱcin�Ĵ���״̬
	cin.clear();
	//��ȥ��ǰһ��ĩβ��������
	cin >> (char&)nChild;
	return br;
}
//������
int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	bool bNull;
	//����Ŀ��ֵ
	for (int nDest; cin >> nDest;) {
		//���ݽ�����yes��no
		cout << (ScanTree(0, nDest, &bNull) ? "yes" : "no") << endl;
	}
	return 0;
}
