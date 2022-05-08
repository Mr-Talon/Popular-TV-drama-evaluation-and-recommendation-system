#pragma once
#include<iostream>
#include<fstream>
#include"用户.h"

using namespace std;
class manager
{
private:
	string name;
	string password;
public:
	manager();
	manager(string name, string password);
	bool checkPassword(char* password);
	void Add(InfoOfTv*, Esitimate esitimateOfTv[N][MAXUSER],int*);//增加电视剧信息
	void modify(InfoOfTv*);//修改电视剧信息
	void deletetv(InfoOfTv*, Esitimate esitimateOfTv[N][MAXUSER], int*,int*);//删除电视剧信息
	void searchofmanager(InfoOfTv*);//按照名称返回电视剧信息
	void esitimateFromuser(Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv*);
	void rank(int,Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv*);//按照排名分数段查看
};
