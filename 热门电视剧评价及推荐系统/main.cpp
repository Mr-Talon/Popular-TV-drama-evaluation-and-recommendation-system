#include<string>
#include<conio.h>
#include"管理员.h"
#include"用户.h"
using namespace std;

void menuOfStatus();      //身份选择菜单
void menuOfManager();   //管理员菜单
void menuOfRegister();   //用户登录注册菜单
void menuOfUser();   //用户菜单
void menuOftv();    //用户对于一个电视剧的选择

int main()
{
	/*
	注册管理员
	*/
	cout << "请输入管理员的姓名：";
	string name;
	cin >> name;
	cout << "请设置管理员的密码（6位）：";
	string password;
	cin >> password;
	while (password.length() != 6) {                //检测密码位数
		cout << "输入位数不正确，请重新输入！" << endl;
		cin >> password;
	}
	manager manager(name,password);         //创建管理员对象

	/*
	主函数中的变量
	*/
	int countOfUser = 0;   //用户个数
	int countOfTv = 0;     //电视剧个数
	int posOfDelete=N;    //管理员删除电视剧时电视剧在tv数组中的位置 ，用于调整用户偏好数组
	int choice1, choice2, choice3,choice4,choice5;    //对应1、2、3、4、级菜单的选项
	user* userPtr[MAXUSER];   //用户数组指针
	InfoOfTv tv[N];   //用于把文件中的数据存入内存
	Esitimate esitimateOfTv[N][MAXUSER];   //每一个电视剧的评价

	/*
	读取电视剧数据文件和电视剧评价文件
	*/
	//打开电视剧数据文件
	fstream docOfTv("../数据文件/三十部电视剧简介缩略版.txt");
	if (!docOfTv) {
		cout << "不能打开电视剧信息文件" << endl;
		return 0;
	}
	//将文件读入内存
	for (int i = 0; i < N; i++) {
		docOfTv >> tv[i].name;
		if (tv[i].name[0] == '\0') {
			break;
		}
		docOfTv >> tv[i].type;
		docOfTv >> tv[i].director;
		docOfTv >> tv[i].actor;
		docOfTv >> tv[i].number;
		docOfTv >> tv[i].intro;
		countOfTv++;
	}
	docOfTv.close();

	//打开电视剧评价文件
	ifstream esitimateList[N];  //每一个电视剧评价用一个文件存储  流对象存储在一个数组里  地址和电视剧在tv数组里的一样
	for (int k = 0; k < countOfTv; k++) {
		esitimateList[k].open("../数据文件/"+tv[k].name+".txt");  
		//fstream类只有在out方法下才可以创建文档   或者使用ofstream
		if (!esitimateList[k]) {
			cout << "不能打开评论信息文件" << endl;
			return 0;
		}
	}	
	//将电视剧评价信息读入内存
	for (int i = 0; i < countOfTv; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			esitimateList[i] >> esitimateOfTv[i][j].userName;
			esitimateList[i] >> esitimateOfTv[i][j].plot;
			esitimateList[i] >> esitimateOfTv[i][j].behavior;
			esitimateList[i] >> esitimateOfTv[i][j].levelOfDirector;
			esitimateList[i] >> esitimateOfTv[i][j].levelOfWriter;
			esitimateList[i] >> esitimateOfTv[i][j].photographer;
			esitimateList[i] >> esitimateOfTv[i][j].music;
			esitimateList[i] >> esitimateOfTv[i][j].art;
			esitimateList[i] >> esitimateOfTv[i][j].effect;
			esitimateList[i] >> esitimateOfTv[i][j].overallEstimate;
			esitimateList[i] >> esitimateOfTv[i][j].average;
		}
	}
	//为电视剧评价信息中暂时为空的数据赋予初值
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			if (esitimateOfTv[i][j].userName[0] == '\0') {
				//如果导入的评价信息为空  把相关评价设置为0
				esitimateOfTv[i][j].userName = "未输入";
				esitimateOfTv[i][j].plot = 0;
				esitimateOfTv[i][j].behavior = 0;
				esitimateOfTv[i][j].levelOfDirector = 0;
				esitimateOfTv[i][j].levelOfWriter = 0;
				esitimateOfTv[i][j].photographer = 0;
				esitimateOfTv[i][j].music = 0;
				esitimateOfTv[i][j].art = 0;
				esitimateOfTv[i][j].effect = 0;
				esitimateOfTv[i][j].overallEstimate = "未输入";
				esitimateOfTv[i][j].average = 0;
			}	
		}
	}
	for (int i = 0; i < countOfTv; i++) {
		esitimateList[i].close();
	}

	/*
	主函数菜单模块
	*/
	do
	{
		menuOfStatus();
		cin >> choice1;
		while (cin.fail()) {
			cin.clear();
			cout << "输入错误请重新输入！" << endl;
			cin.ignore(10000, '\n');
			cin >> choice1;
		}
		switch (choice1) {
		case 1: {   
			//身份选择是管理员
			
			//管理员身份需要先通过密码
			int time = 0;   //只有三次机会输入
			char c[7];    //存放管理员输入密码的临时数组
			do
			{
				int count = 0;     //防止输入过多
				if (time == 0) {
					cout << "请输入密码: " << endl;;
				}
				else
				{
					cout << endl << "密码错误，请再次输入密码！你还有"<<3-time<<"次机会: " << endl;
				}
				while (count < 6)
				{
					c[count] = getch();     //getch可以不显示输入的字符
					if (c[count] == '\r')     //回车键表示\r\n 
					{
						break;
					}
					cout << "*";
					count++;
				}
				c[6] = '\0';
				if (!manager.checkPassword(c)) {
					time++;
				}
				else    //密码正确跳出do while循环
				{
					break;
				}
			} while (time<3);
			if (time == 3) {   //3次错误直接退出程序
				return 0;
			}

			//管理员菜单
			do
			{
				menuOfManager();
				cin >> choice2;
				while (cin.fail()) {
					cin.clear();
					cout << "输入错误请重新输入！" << endl;
					cin.ignore(10000, '\n');
					cin >> choice2;
				}
				switch (choice2) {
				case 1:
					//增加电视剧信息
					manager.Add(tv,esitimateOfTv,&countOfTv);
					break;
				case 2:
					//修改电视剧信息
					manager.modify(tv);
					break;
				case 3:
					//删除电视剧信息
					manager.deletetv(tv,esitimateOfTv,&countOfTv,&posOfDelete);
					break;
				case 4:
					//按照名称返回电视剧信息
					manager.searchofmanager(tv);
					break;
				case 5:
					//查看所有电视剧的评价
					manager.esitimateFromuser(esitimateOfTv, tv);
					break;
				case 6:
					//按照排名分数段查看
					cout << "请输入需要分段排行的项目：" << endl;
					cout << "1、情节    2、演员表现力   3、导演水平   4、编剧水平   5、摄影   6、音乐   7、美术   8、特效		9、总体评价" << endl;
					int choiceOfManager;
					cin >> choiceOfManager;
					while ((choiceOfManager != 1 && choiceOfManager != 2 && choiceOfManager != 3 && choiceOfManager != 4 && choiceOfManager != 5 && choiceOfManager != 6 && choiceOfManager != 7 && choiceOfManager != 8 && choiceOfManager != 9)||cin.fail()) {
						cout << "输入错误，请重新输入" << endl;
						cin.clear();
						cin.ignore(10000, '\n');
						cin >> choiceOfManager;
					 }
					manager.rank(choiceOfManager,esitimateOfTv, tv);
					break;
				case 0:
					//返回
					break;
				default:
					cout << "输入选项错误！请重新输入" << endl;
					break;
				}
			} while (choice2);
			break;
		}
		case 2:
		//身份选择是普通用户
			do{
				menuOfRegister();   //显示登陆菜单
				cin >> choice5;
				while (cin.fail()) {
					cin.clear();
					cout << "输入错误请重新输入！" << endl;
					cin.ignore(10000, '\n');
					cin >> choice5;
				}
				switch (choice5){
				case 1: {
					//注册模块
					cout << "请输入用户名" << endl;
					string name;
					cin >> name;
					//查重模块
					int flag = 0;
					for (int i = 0; i < countOfUser; i++) {
						if (userPtr[i]->getName() == name) {
							cout << "用户名已被使用！" << endl;
							flag = -1;
						}
					}
					if (flag == 0) {
						userPtr[countOfUser] = new user(name);       //创建用户类
						countOfUser++;
					}
					break;
				}
				case 2: {
					//登陆模块
					cout << "请输入用户名：" << endl;
					string userName;
					cin >> userName;
					//在用户数组中搜索是否有该用户
					int flag = 0;   //用于显示用户是否在数组之中
					int pos;    //用于存储当前登录用户在用户类数组中的位置
					for (int i = 0; i < countOfUser; i++) {
						if (userName == userPtr[i]->getName()) {
							pos = i;
							flag = -1;
						}
					}
					if (flag != 0) {
						cout << "欢迎" << userPtr[pos]->getName() <<"!!!"<< endl;
					}
					else
					{
						//登录失败返回上一级菜单
						cout << "未检测到该用户！" << endl;
						break;
					}
					do {
						//登录成功显示以下菜单
						menuOfUser();
						cin >> choice3;
						while (cin.fail()) {
							cin.clear();
							cout << "输入错误请重新输入！" << endl;
							cin.ignore(10000, '\n');
							cin >> choice3;
						}
						switch (choice3) {
						case 1: {
							//系统推荐用户观看电视剧
							int max = userPtr[pos]->recommendTv(&posOfDelete);
							cout << "我们推荐您看《" << tv[max].name << "》哦~" << endl;
							break;
						}
						case 2:
							//返回前10名电视剧的基本信息
							userPtr[pos]->TopTenTv(esitimateOfTv, tv);
							break;
						case 3:
							//按照相关指标进行前10名电视剧的排行
							cout << "请输入您想检索的指标：" << endl;
							cout << "1、情节    2、演员表现力   3、导演水平   4、编剧水平   5、摄影   6、音乐   7、美术   8、特效" << endl;
							int choice;
							cin >> choice;
							while ((choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8)||cin.fail()) {
								cout << "输入错误，请重新输入！" << endl;
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> choice;
							}
							userPtr[pos]->TopTenTvByIndex(choice, esitimateOfTv, tv);
							break;
						case 4:
							//用户按照电视剧名称查找
							//调用用户类 searchTv方法
							int posOfThis;   //标记当前搜索的电视剧的位置
							if (userPtr[pos]->searchTv(tv,&posOfThis)) {
								//找到电视剧进入下一级菜单
								do{
									menuOftv();
									cin >> choice4;
									while (cin.fail()) {
										cin.clear();
										cout << "输入错误请重新输入！" << endl;
										cin.ignore(10000, '\n');
										cin >> choice4;
									}
									switch (choice4)
									{
									case 1:
										//观看电视剧
										cout << "观看成功！" << endl;
										cout <<endl<< "请问您想对本电视剧进行评价吗？（Y/N）" << endl;
										char esitimateOrNot;
										cin >> esitimateOrNot;
										if (esitimateOrNot == 'y' || esitimateOrNot == 'Y') {
											userPtr[pos]->esitimateTv(posOfThis,pos,esitimateOfTv,tv);
										}
										else if (esitimateOrNot == 'N' || esitimateOrNot == 'n') {
											break;
										}
										else
										{
											cout << "输入有误！" << endl;
										}
										break;
									case 2:
										//观看其他用户的评价
										userPtr[pos]->esitimateFromOtherUser(posOfThis, esitimateOfTv, tv);
										break;
									case 0:
										break;
									default:
										cout << "输入错误！请重新输入" << endl;
										break;
									}
								} while (choice4);
							}
							else
							{
								cout << "没有找到这个电视剧哦~" << endl;
								break;
							}
							break;
						case 0:
							//返回
							break;
						default:
							cout << "输入有误！请重新输入" << endl;
							break;
						}
					} while (choice3);
				}
					//登录模块以及登录后的所有菜单
					
				case 0:
					//返回
					break;
				default:
					cout << "输入选项错误！请重新输入" << endl;
					break;
				}
			} while (choice5);
		case 0:
			cout << "谢谢使用本程序！！！" << endl;
			break;
		default:
			cout << "输入选项错误！请重新输入" << endl;
			break;
		}
	} while (choice1);

	/*
	内存数据输出至外部文件
	方法就是把原来文件中的内容用trunc方法清空
	*/
	//将内存中的数据输出
	fstream newDocOfTv("../数据文件/三十部电视剧简介缩略版.txt", ios::out|ios::trunc);
	if (!newDocOfTv) {
		cout << "不能打开电视剧信息文件" << endl;
		return 0;
	}
	for (int i = 0; i < countOfTv; i++) {
		newDocOfTv << tv[i].name<< " ";
		newDocOfTv << tv[i].type << " ";
		newDocOfTv << tv[i].director << " ";
		newDocOfTv << tv[i].actor << " ";
		newDocOfTv << tv[i].number << " ";
		newDocOfTv << tv[i].intro << " ";
	}
	newDocOfTv.close();

	fstream newEsitimateList[N];  //每一个电视剧评价用一个文件存储  流对象存储在一个数组里  地址和电视剧在tv数组里的一样
	for (int k = 0; k < countOfTv; k++) {
		newEsitimateList[k].open("../数据文件/" + tv[k].name + ".txt", fstream::out|fstream::trunc);
		//fstream类只有在out方法下才可以创建文档   或者使用ofstream
		if (!newEsitimateList[k]) {
			cout << "不能打开评论信息文件" << endl;
			return 0;
		}
	}
	//将电视剧评价信息读入内存
	for (int i = 0; i < countOfTv; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			newEsitimateList[i] << esitimateOfTv[i][j].userName<<" ";
			newEsitimateList[i] << esitimateOfTv[i][j].plot << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].behavior << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].levelOfDirector << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].levelOfWriter << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].photographer << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].music << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].art << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].effect << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].overallEstimate << " ";
			newEsitimateList[i] << esitimateOfTv[i][j].average << " ";
		}
	}
	for (int i = 0; i < N; i++) {
		newEsitimateList[i].close();
	}
	return 0;
}

void menuOfStatus() {
	cout << "请问你的身份是？" << endl;
	cout << "**********1、管理员**********" << endl;
	cout << "**********2、用   户**********" << endl;
	cout << "**********0、退   出**********" << endl;
	cout << "请输入您的选项:" << endl;
}
void menuOfManager() {
	cout << endl;
	cout << "*****************1、增加电视剧*****************" << endl;
	cout << "**************2、修改电视剧信息***************" << endl;
	cout << "**************3、删除电视剧信息***************" << endl;
	cout << "**********4、按照名称返回电视剧信息**********" << endl;
	cout << "***********5、查看所有电视剧的评价************" << endl;
	cout << "************6、按照排名分数段查看*************" << endl;
	cout << "*******************0、返   回********************" << endl;
	cout << "请输入您的选项:" << endl;
}
void menuOfRegister() {
	cout << endl;
	cout << "********************1、注   册*******************" << endl;
	cout << "********************2、登   录*******************" << endl;
	cout << "********************0、返   回*******************" << endl;
	cout << "请输入您的选项：" << endl;
}
void menuOfUser() {
	cout << endl;
	cout << "********************1、查看系统推荐电视剧*********************" << endl;
	cout << "*****************2、查看前10名电视剧基本信息*****************" << endl;
	cout << "**********3、按照相关指标查询前10名电视剧基本信息**********" << endl;
	cout << "******************4、按照名称返回电视剧信息******************" << endl;
	cout << "****************************0、返    回***************************" << endl;
	cout << "请输入您的选项:" << endl;
}
void menuOftv() {
	cout << endl;
	cout << "****************1、观看该电视剧****************" << endl;
	cout << "**********2、查看其它用户对它的评价**********" << endl;
	cout << "********************0、返   回*******************" << endl;
	cout << "请输入您的选项:" << endl;
}