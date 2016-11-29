#include"invertTable.h"
#include "../libs/cppjieba/Jieba.hpp"
#include "../libs/cppjieba/KeywordExtractor.hpp"

vector<vector<invertNode>> invertTable::docToNode(vector<int> docId, vector<string> str){

	CHashAlgo tokenHash(HASHSIZE);						//hash��ʵ��
	vector<string>::iterator iter_token;
	vector<invertNode>::iterator iter_node;
	
	vector<invertNode> invertNodeVector;
	invertNode initNode;
	invertNodeVector.push_back(initNode);
		
	vector<vector<invertNode>>tempInvertNode ;//ÿһ���ڵ㴦�Ķ���
	vector<invertNode> initTempInvertNode;
	initTempInvertNode.push_back(initNode);
	tempInvertNode.push_back(initTempInvertNode);
	
	vector<invertNode>nodeVectorReal;
	
	vector<string>cutTextResult;

	int index = 0;
	string tokenStr;
	int tokenPos = 0;
	
	for (int i = 0; i < docId.size(); i++){
		bool flag = false;
		
		cutTextResult.clear();				//������е�Ԫ�ظ������Ƕ���vector��˵�������ͷ��ڴ�
		vector<string>().swap(cutTextResult);//�ͷ��ڴ�

	    cutTextResult = textToToken(docId[i], str[i]);

 		int perPos = 0;

		for (iter_token = cutTextResult.begin(); iter_token < cutTextResult.end(); iter_token++){
		
			index = iter_token - cutTextResult.begin();
		
			perPos = index + 1;
			
			if (tokenHash.GetHashTablePos(iter_token->c_str()) == -1){

				tokenHash.SetHashTable(iter_token->c_str());
				tokenStr = *iter_token;
				token.push_back(tokenStr);
				
				cout << "token "<< (token.size()-1) <<"is "<< token[token.size()-1]<< endl;
				
				invertNode nodeObj;
				nodeObj.tokenFreq++;
				nodeObj.createInvertNode(docId[i], nodeObj.tokenFreq, perPos);

				
				for(int k = 0;k< token.size();k++){
					if(*iter_token == token[k])
						tokenPos = k;
				}
				
				invertList.push_back(invertNodeVector);
				
				invertList[tokenPos].push_back(nodeObj);
								
			}
			else{				
				//����һ��token��Ӧ������vector
				//���ֵ�token��token�б����ŵڼ�λ������λ�ö�Ӧ��vector���в���
				for(int k = 0;k< token.size();k++){
					if(*iter_token == token[k]){
						tokenPos = k;
					}
				}
								
				nodeVectorReal = invertList[tokenPos];
				
				for(int m = 0;m < nodeVectorReal.size();m++){
					if (nodeVectorReal[m].docId == docId[i]&&(!(tokenHash.GetHashTablePos(iter_token->c_str()) == -1))){									
								
						flag = true;              
												
						invertList[tokenPos][m].docId = docId[i];
						invertList[tokenPos][m].docId = nodeVectorReal[m].tokenFreq;
						invertList[tokenPos][m].refNode(docId[i],nodeVectorReal[m].tokenFreq,perPos);
												
					}
				}
				if (!flag){
					invertNode nodeObj;
					nodeObj.tokenFreq++;
					nodeObj.createInvertNode(docId[i], nodeObj.tokenFreq, perPos);
					for(int k = 0;k< token.size();k++){
						if(*iter_token == token[k]){
							tokenPos = k;
						}
					}
					invertList[tokenPos].push_back(nodeObj);
				}
			}			
		}
	}
	return invertList;
}


vector<string> invertTable::textToToken(int docId, string str){



	const char* const DICT_PATH = "../libs/jieba.dict.utf8";
	const char* const HMM_PATH = "../libs/hmm_model.utf8";
	const char* const USER_DICT_PATH = "../libs/user.dict.utf8";
	const char* const IDF_PATH = "../libs/idf.utf8";
	const char* const STOP_WORD_PATH = "../libs/stop_words.utf8";


	cppjieba::Jieba jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH);
	vector<string> tokenResult;


	jieba.Cut(str, tokenResult, true);
	vector <string> ::iterator iter_word = tokenResult.begin();
	for (; iter_word != tokenResult.end(); iter_word++){
		cout << *iter_word << endl;

	}

	return  tokenResult;


}

vector<string>invertTable::getToken(){
	return token;
}

vector<string>invertTable::split(const string &s, const string &seperator){
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;
 
	while(i != s.size()){
	//�ҵ��ַ������׸������ڷָ�������ĸ��
	int flag = 0;
	while(i != s.size() && flag == 0){
		flag = 1;
		for(string_size x = 0; x < seperator.size(); ++x)
			if(s[i] == seperator[x]){
			++i;			  
			flag = 0;
			break;
		}
	}
    
	//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
	flag = 0;
	string_size j = i;
	while(j != s.size() && flag == 0){
		for(string_size x = 0; x < seperator.size(); ++x)
		if(s[j] == seperator[x]){
			flag = 1;
			break;
		}
		if(flag == 0) 
		++j;
	}
	if(i != j){
		result.push_back(s.substr(i, j-i));
		i = j;    
	}  
	}
	return result;
}



