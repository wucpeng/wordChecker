#include<iostream>
#include "NameChecker.h"
#include "StringChecker.h"
#include "ConfigReader.h"
#include <string>
using namespace std;

int main(int argc, char** argv) {
    //TODO 测试1: NameChecker Trie
    std::string strKeyWordFile = "../config/keyword.txt";
	if (!CNameChecker::Init(strKeyWordFile.c_str())){
        cout << "Load keyword.txt error" << endl;
		return -1;
	}

    string name1 = "你是谁 管理员";
    CNameChecker::ReplaceString(name1);
    cout << "name1="<< name1 << endl;

    //TODO 测试2: StringChecker
    std::string strKeyWordCsv = "../config/keyword.csv";
    CConfigReader reader;
    if (!reader.init(strKeyWordCsv)) {
        cout << "Load keyword.csv error" << endl;
		return -1;
    }

    StringChecker stringChecker;
    stringChecker.Reset();
    int nRow = reader.rowCount();
    for(int i = 0; i < nRow; ++i) {
        int j = 1;
        string txt;
        READER_STR(txt);
        stringChecker.AddPattern(txt.c_str());
    }
    stringChecker.Build();
    string name21 = "你是谁 管理员";
    bool isChange = stringChecker.Replace( name21 );
    cout << "name21="<< name21 << endl;
    cout << "isChange="<< isChange << endl;

    return 0;
}