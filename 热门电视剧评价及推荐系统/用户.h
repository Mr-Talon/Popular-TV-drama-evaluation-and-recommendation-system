#pragma once
#include<string>
#include<iostream>
using namespace std;
const int N = 40;   //���Ӿ�������
const int MAXUSER = 10;    //�û�������

typedef struct estimate {
	string userName;  //�������۵��û�����
	int plot;     //�������
	int behavior;		//��Ա������
	int levelOfDirector;		//����ˮƽ
	int levelOfWriter;		//���ˮƽ
	int photographer;		//��Ӱ
	int music;			//����
	int art;		//����
	int effect;		//��Ч
	string overallEstimate;		//�ۺ�����
	double average ;   //��������
}Esitimate;

typedef struct infoOfTv
{
	string name;     //���Ӿ�����
	string type;    //���Ӿ�����
	string director;		//����
	string actor;    //����
	int number;    //����
	string intro;    //����
}InfoOfTv;

class user
{
private:
	string name;  //�û�����
	int userAttempt[N] = { 0 }; // ���ڴ���û�����ÿһ�����Ӿ�Ĳ�ѯ����

public:
	user();
	user(string name);
	string getName();
	int recommendTv(int*);		//�鿴ϵͳ�Ƽ��ĵ��Ӿ�
	void TopTenTv(Esitimate [N][MAXUSER], infoOfTv* tv);		//�鿴ǰʮ���Ӿ������Ϣ
	void TopTenTvByIndex(int, Esitimate[N][MAXUSER], infoOfTv*);   //����һ��ָ���ǰ10���Ӿ��������
	int searchTv(InfoOfTv*,int*);     //���յ��Ӿ����������Ӿ������Ϣ
	void esitimateTv(int,int,Esitimate[N][MAXUSER],infoOfTv*);			//���۸ĵ��Ӿ�
	void esitimateFromOtherUser(int,Esitimate [N][MAXUSER], infoOfTv* );			//�鿴�����û���������Ӿ������
	void rankIndex(int pos[N], double  averageOfTv[N]);   //ѡ������
};
