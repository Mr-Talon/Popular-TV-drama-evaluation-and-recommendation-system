#include"管理员.h"
#include<fstream>
using namespace std;
int count1 = 30;

//选择法排序
void rankIndex(int pos[N], double  averageOfTv[N]) {
	//参数  pos是电视剧地址数组   averageOfTv是当前指标数据数组
	//无返回值
	int index;   //暂存最值
	int i, k, temp1;
	double temp;
	for (k = 0; k < N - 1; k++) {
		index = k;
		for (i = k + 1; i < N; i++) {
			if (averageOfTv[i] > averageOfTv[index]) {
				index = i;
			}
		}
		if (index != k) {
			//交换平均值和地址
			temp = averageOfTv[index];
			averageOfTv[index] = averageOfTv[k];
			averageOfTv[k] = temp;
			temp1 = pos[index];
			pos[index] = pos[k];
			pos[k] = temp1;
		}
	}
}

manager::manager() {
	name = "未定义";
	password = "未定义";
}

manager::manager(string name, string password) :name(name), password(password) {
	cout << "管理员注册成功！" << endl;
	cout << endl;
}

bool manager::checkPassword(char* password) {
	//参数  管理员输入的密码
	// 返回值  密码是否正确的bool值
	//判断输入密码是否一致
	if (password == this->password) {
		return 1;
	}
	else
	{
		return 0;
	}
}

//增加电视剧信息
void manager::Add(InfoOfTv* tv, Esitimate esitimateOfTv[N][MAXUSER],int* countOfTv){
	//参数 tv电视剧数组  esitimateOfTv评价二维数组   countOfTv主函数电视剧个数
	//无返回值
	if (count1 != N)//判断电视剧总数有没有超过40
	{
		//tv数组对应位置增加电视剧信息
		cout << "请输入电视剧的名称、类型、导演、主演、集数、剧情" << endl;
		cout << "名称：";
		cin >> tv[count1].name;
		cout << "类型：";
		cin >> tv[count1].type;
		cout << "导演：";
		cin >> tv[count1].director;
		cout << "主演：";
		cin >> tv[count1].actor;
		cout << "集数：";
		cin >> tv[count1].number;
		while (cin.fail()) {//防止输入错误
			cin.clear();
			cout << "输入错误请重新输入！" << endl;
			cin.ignore(10000, '\n');
			cin >> tv[count1].number;
		}
		cout << "剧情：";
		cin >> tv[count1].intro;
		//评价信息二维数组对应位置初始化信息
		for (int j = 0; j < MAXUSER; j++) {   //初始化结构体类型的二维数组存放电视剧评价的各个指标
			esitimateOfTv[count1][j].userName = "未输入";
			esitimateOfTv[count1][j].plot = 0;
			esitimateOfTv[count1][j].behavior = 0;
			esitimateOfTv[count1][j].levelOfDirector = 0;
			esitimateOfTv[count1][j].levelOfWriter = 0;
			esitimateOfTv[count1][j].photographer = 0;
			esitimateOfTv[count1][j].music = 0;
			esitimateOfTv[count1][j].art = 0;
			esitimateOfTv[count1][j].effect = 0;
			esitimateOfTv[count1][j].overallEstimate = "未输入";
			esitimateOfTv[count1][j].average = 0;
		}
		count1++;   //电视剧数量++
		(*countOfTv)++;		//主函数电视剧数量++
		//为新建的电视剧新建一个文件用于存储用户对该电视剧的评价
		fstream newTv("C:\\Users\\16046\\Desktop\\编程\\热门电视剧评价及推荐系统\\热门电视剧评价及推荐系统\\" + tv[count1].name + ".txt",fstream::out);
		if (!newTv) {
			cout << "不能打开评论信息文件" << endl;
			return ;
		}
		newTv.close();
	}
	else  //电视剧数量超过40
	{
		cout << "电视剧信息已满，无法再增加信息！";
	}
}

//修改电视剧信息
void manager::modify(InfoOfTv* tv)
{
	//参数 tv电视剧数组
	//无返回值
	cout << "请输入想要修改的电视剧名称：" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //用于显示电视剧名称是否在数组之中
	int pos;    //用于存储当前电视剧在电视剧基本信息数组中的位置
	for (int i = 0; i < N; i++) {    //查找
		if (nameOfTv == tv[i].name) {
			pos = i;
			flag = -1;
		}
		if (flag == -1) {   //找到信息退出for循环
			break;
		}
	}
	if (flag != 0) {
		//找到了就返回基本信息
		cout << endl;
		cout << "《" << tv[pos].name << "》的基本信息是：" << endl;
		cout << "名称:" << tv[pos].name << endl;
		cout << "类型:" << tv[pos].type << endl;
		cout << "导演:" << tv[pos].director << endl;
		cout << "主演:" << tv[pos].actor << endl;
		cout << "集数:" << tv[pos].number << endl;
		cout << "简介:" << tv[pos].intro << endl;
		//并且在偏好数组中给这个电视剧加1
	}
	int a;
	cout << "请输入你想要修改的内容" << endl;
	cout << "1 、名称   2 、类型    3、 导演   4、主演    5、集数    6、简介 " << endl;
	cout << "请输入你的选择";
	cin >> a;
	while (cin.fail()||(a!=1&&a!=2&& a != 3 && a != 4 && a != 5 && a != 6) ) {
		cin.clear();
		cout << "输入错误请重新输入！" << endl;
		cin.ignore(10000, '\n');
		cin >> a;
	}
	//判断输入内容
	if (a == 1)
	{
		cout << "名称：" << endl;
		cin >> tv[pos].name;
	}
	if (a == 2)
	{
		cout << "类型：" << endl;
		cin >> tv[pos].type;
	}
	if (a == 3)
	{
		cout << "导演：" << endl;
		cin >> tv[pos].director;
	}
	if (a == 4)
	{
		cout << "主演：" << endl;
		cin >> tv[pos].actor;
	}
	if (a == 5)
	{
		cout << "集数：" << endl;
		cin >> tv[pos].number;
		while (cin.fail()) {
			cin.clear();
			cout << "输入错误请重新输入！" << endl;
			cin.ignore(10000, '\n');
			cin >> tv[pos].number;
		}
	}
	if (a == 6)
	{
		cout << "简介：" << endl;
		cin >> tv[pos].intro;
	}
	cout << "你已成功修改信息！";
}

//删除电视剧信息
void manager::deletetv(InfoOfTv* tv, Esitimate esitimateOfTv[N][MAXUSER], int* countOfTv,int* posOfDelete)
{
	//参数  tv电视剧数组  esitimateOfTv评价二维数组  countOfTv主函数电视剧个数   posOfDelete删除位置
	//无返回值
	cout << "请输入你想要删除的电视剧" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //用于显示电视剧名称是否在数组之中
	int pos;    //用于存储当前电视剧在电视剧基本信息数组中的位置
	for (int i = 0; i < N; i++)
	{    //查找
		if (nameOfTv == tv[i].name) {
			pos = i;
			flag = -1;
		}
		if (flag == -1) {
			break;
		}
	}
	if (flag != 0) {
		int i;
		//硬盘中 相应被删除的电视剧评价的txt文件也要被删除
		string nameOfFile = "C:\\Users\\16046\\Desktop\\编程\\热门电视剧评价及推荐系统\\热门电视剧评价及推荐系统\\" + tv[pos].name + ".txt";
		remove(nameOfFile.c_str());

		//内存中 用后面的覆盖之前的
		for (i = pos; i < N-1; i++)
		{
			tv[i] = tv[i + 1];
			for (int j = 0; j < MAXUSER; j++) {
				esitimateOfTv[i][j] = esitimateOfTv[i + 1][j];
			}
			//用户倾向数组也要进行删除
		}
		*posOfDelete = pos;
		count1--;
		(*countOfTv)--;  //主函数电视剧数量--
		cout << "删除电视剧成功！";
	}
	else
	{
		cout << "没有该电视剧信息！";
	}
}

//按照名称返回电视剧信息
void manager::searchofmanager(InfoOfTv* tv)
{
	//参数  tv电视剧数组
	//无返回值
	cout << "请输入想要查找的电视剧名称：" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //用于显示电视剧名称是否在数组之中
	int pos;    //用于存储当前电视剧在电视剧基本信息数组中的位置
	for (int i = 0; i < N; i++) {    //查找
		if (nameOfTv == tv[i].name) {
			pos = i;
			flag = -1;
		}
		if (flag == -1) {
			break;
		}
	}
	if (flag != 0) {
		//找到了就返回基本信息
		cout << endl;
		cout << "《" << tv[pos].name << "》的基本信息是：" << endl;
		cout << "名称:" << tv[pos].name << endl;
		cout << "类型:" << tv[pos].type << endl;
		cout << "导演:" << tv[pos].director << endl;
		cout << "主演:" << tv[pos].actor << endl;
		cout << "集数:" << tv[pos].number << endl;
		cout << "简介:" << tv[pos].intro << endl;
		//并且在偏好数组中给这个电视剧加1
	}
	else
	{
		cout << "没有该电视剧信息哦~";
	}
}

//查看所有电视剧评价
void manager::esitimateFromuser(Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv* tv)
{
	//参数  esitimateOfTv评价二维数组    tv电视剧数组
	//无返回值
	int i;
	cout << "用户对电视剧的评价是：" << endl;
	for (int j = 0; j < N; j++)   //输出电视剧评价的二维数组
	{
		if (tv[j].name[0]== '\0')
		{
			continue;
		}
		cout << "《" << tv[j].name << "》:" << endl;
		for (i = 0; i < MAXUSER; i++)
		{

			if (esitimateOfTv[j][i].userName == "未输入")
			{
				continue;
			}
			else
			{
				cout << esitimateOfTv[j][i].userName << ":  " << esitimateOfTv[j][i].overallEstimate << "     ta的总体评价是：" << esitimateOfTv[j][i].average << endl;
			}
		}
		cout << endl;
	}
}

//输出特定指标的排序
void outputByLevel(int pos[N], InfoOfTv* tv) {
	//参数  pos临时电视剧地址数组   tv电视剧数组
	//无返回值
	cout << "请输入需要查看的分数段：" << endl;
	cout << "1、1~10名		2、11~20名		3、21~30名		4、31~40名" << endl;
	int choice,level;
	cin >> choice;
	while ((choice != 1 && choice != 2 && choice != 3 && choice != 4) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >>choice;
	}
	//保证输入正确
	if (choice == 1) {
		level = 10;
	}
	else if (choice == 2) {
		level = 20;
	}
	else if (choice == 3) {
		level = 30;
	}
	else
	{
		level = 40;
	}
	for (int i = level-10; i < level; i++) {
		cout << "第" << i + 1 << "名:" << endl;
		cout << "名称:" << tv[pos[i]].name << endl;
	}
}

//按照排名分数段查看
void manager::rank(int choice,Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv* tv)
{
	// 参数  choice 指标变量     esitimateOfTv评价二维数组    tv电视剧数组
	//无返回值
	double averageOfTv[N];   //存放特定指标的平均分
	int pos[N];  //临时存放电视剧位置的数组，用于排序
	double sum = 0.00;
	if (choice == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].plot;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].behavior;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].levelOfDirector;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 4) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].levelOfWriter;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].photographer;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 6) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].music;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if (choice == 7) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].art;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else if(choice==8){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].effect;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
	else
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < MAXUSER; j++) {
				sum += esitimateOfTv[i][j].average;
			}
			averageOfTv[i] = sum / MAXUSER;
			pos[i] = i;
			sum = 0.00;
		}
		rankIndex(pos, averageOfTv);
		outputByLevel(pos, tv);
	}
}

