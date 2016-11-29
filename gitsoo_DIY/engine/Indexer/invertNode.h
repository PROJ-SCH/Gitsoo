#ifndef INVERTNODE_H_
#define INVERTNODE_H_

#include"util.h"
#define MAXPOSSIZE 10

class invertNode{
public:
	int docId;				//�ĵ����
	int tokenFreq;			//�ĵ�Ƶ��
	vector<int> pos;		//�ĵ����ֵ�λ��	

	invertNode()
	{
		docId = 0;
		tokenFreq = 0;
		vector<int>pos(MAXPOSSIZE,0);//����pos��ʼ��
		
	}
	void createInvertNode(int _docId, int _tokenFreq, int _perPos)//vector������  ͬΪvectorֱ��=����
	{
		docId =  _docId;
		tokenFreq = _tokenFreq;
		pos.push_back(_perPos);
	
	}
	void refNode(int _docId, int _tokenFreq, int _perPos){
		docId =  _docId;
		tokenFreq = _tokenFreq;
		pos.push_back(_perPos);
	
	}


};


#endif