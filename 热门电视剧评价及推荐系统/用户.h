#pragma once
#include<string>
#include<iostream>
using namespace std;
const int N = 40;   //电视剧最大个数
const int MAXUSER = 10;    //用户最大个数

typedef struct estimate {
	string userName;  //这条评论的用户名称
	int plot;     //情节评分
	int behavior;		//演员表现力
	int levelOfDirector;		//导演水平
	int levelOfWriter;		//编剧水平
	int photographer;		//摄影
	int music;			//音乐
	int art;		//美术
	int effect;		//特效
	string overallEstimate;		//综合评价
	double average ;   //整体评分
}Esitimate;

typedef struct infoOfTv
{
	string name;     //电视剧名字
	string type;    //电视剧类型
	string director;		//导演
	string actor;    //主演
	int number;    //集数
	string intro;    //剧情
}InfoOfTv;

class user
{
private:
	string name;  //用户名称
	int userAttempt[N] = { 0 }; // 用于存放用户对于每一个电视剧的查询次数

public:
	user();
	user(string name);
	string getName();
	int recommendTv(int*);		//查看系统推荐的电视剧
	void TopTenTv(Esitimate [N][MAXUSER], infoOfTv* tv);		//查看前十电视剧基本信息
	void TopTenTvByIndex(int, Esitimate[N][MAXUSER], infoOfTv*);   //按照一定指标对前10电视剧进行排名
	int searchTv(InfoOfTv*,int*);     //按照电视剧名搜索电视剧基本信息
	void esitimateTv(int,int,Esitimate[N][MAXUSER],infoOfTv*);			//评价改电视剧
	void esitimateFromOtherUser(int,Esitimate [N][MAXUSER], infoOfTv* );			//查看其它用户对这个电视剧的评价
	void rankIndex(int pos[N], double  averageOfTv[N]);   //选择法排序
};
