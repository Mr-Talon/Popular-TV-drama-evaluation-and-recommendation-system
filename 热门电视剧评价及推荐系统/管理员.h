#pragma once
#include<iostream>
#include<fstream>
#include"�û�.h"

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
	void Add(InfoOfTv*, Esitimate esitimateOfTv[N][MAXUSER],int*);//���ӵ��Ӿ���Ϣ
	void modify(InfoOfTv*);//�޸ĵ��Ӿ���Ϣ
	void deletetv(InfoOfTv*, Esitimate esitimateOfTv[N][MAXUSER], int*,int*);//ɾ�����Ӿ���Ϣ
	void searchofmanager(InfoOfTv*);//�������Ʒ��ص��Ӿ���Ϣ
	void esitimateFromuser(Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv*);
	void rank(int,Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv*);//�������������β鿴
};
