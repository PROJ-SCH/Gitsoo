#pragma once
#ifndef SOLVEDATA_H_
#define SOLVEDATA_H_
#include"MysqlCon.h"
#include"invertNode.h"

class SolveData
{
public:
	SolveData(){}
	SolveData(char *service, char *USER, char *passwd, char *dbname, int port)
	{
		_mc.ConnectDB(service, USER, passwd, dbname, port);
	}
	// �������ݿ�
	void ConnectMysql(char *service, char *USER, char *passwd, char *dbname, int port)
	{
		_mc.ConnectDB(service, USER, passwd, dbname, port);
	}
	~SolveData() { }
	vector<invertNode>  selFromInvtable(char* token);//�ӵ��ű�ȡ��token��item
	void GetData_Solve();//�����ݿ⽫update=1����ȡ�������ҽ�update��0������data
	int tableCount(char *table);// ���������ж�����
	void SaveData(char* token, vector<invertNode> item);	//�������ݵ����ݿ�
	vector<int> getDocID() { return _docID; }
	vector<string> getText() { return _text; }
protected:
	vector<invertNode> charToVector(char *p, int n);// ��char*���vector 
	// ���л��������ݿ� 
	void inserthelp(const vector<invertNode>& a1, char* token);
	void updatehelp(const vector<invertNode>& a1, char* token);
	vector<invertNode> Merge50(const vector<invertNode> &a, const vector<invertNode>& b);// �鲢�㷨���ҳ���ƵΪǰ50���Ĵ� 

	void Comparison(char*token, const vector<invertNode>&a);// �ȶ�,����
	void buildTo50(vector<invertNode>&item);// ����±���vector����Ķ�������50������docID = 0��tokenFreq = 0��index = 0������
private:
	MysqlCon _mc;
	MYSQL_RES *buffres;
	vector<int> _docID;
	vector<string> _text;
	//MYSQL_ROW buffcol;
};


#endif
