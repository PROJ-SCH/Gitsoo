#ifndef INVERTTABLE_H_
#define INVERTTABLE_H_

#include"invertNode.h"
#include"CHashAlgo.h"
class invertTable{
public:
	vector<string> textToToken(int docId,string str);		//���һƪ���·ִ�
	vector<vector<invertNode>> docToNode(vector<int> docId,vector<string> str);
	vector<string> getToken();								//��ȡtoken
	vector<string> split(const string &s, const string &seperator);
private:
	vector<string> token;									//��ŵ��ű��token
	vector<vector<invertNode>> invertList;					//��� ÿһ��token��Ӧvector��vector���ݶ����±���Ƚ���һһ��Ӧ��ϵ
	vector<vector<invertNode>> invertListVec;

};
#endif