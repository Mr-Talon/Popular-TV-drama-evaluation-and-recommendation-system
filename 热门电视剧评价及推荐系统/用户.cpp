#include"用户.h"
using namespace std;

//选择法排序
void user::rankIndex(int pos[N],double  averageOfTv[N]) {
	//参数  pos是电视剧地址数组   averageOfTv是当前指标数据数组
	//无返回值  直接更改相关数组
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
user::user() {
	name = "未定义";
}
user::user(string na) :name(na){
	cout << "用户已经注册成功！！" << endl;
}
string user::getName() {
	return name;
}
int user::recommendTv(int* posOfDelete) {
	//参数 管理员可能删除电视剧 参数是删除的电视剧的位置  用于调整当前用户偏好列表
	//返回值是地址值 
	int max=0; //用户偏好中数值最大的电视剧的地址
	//调整当前用户偏好数组
	if (*posOfDelete != N) {
		for (int k = *posOfDelete; k<N-1; k++) {
			userAttempt[k] = userAttempt[k + 1];
		}
		userAttempt[N-1] = 0;
	}
	//寻找偏好数组中的最大值
	for (int i = 0; i < N; i++) {
		if (userAttempt[i] > userAttempt[max]) {
			max = i;
		}
	}
	return max;
}

void user::TopTenTv(Esitimate esitimateOfTv[N][MAXUSER], infoOfTv*tv  ) {
	//参数   esitimateOfTv是电视剧评价二维数组     tv是电视剧信息数组
	//返回值   无返回值
	//构建电视剧平均分数组
	double averageOfTv[N];
	int pos[N];
	double sum = 0.00;
	//计算每个电视剧的平均分
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			sum += esitimateOfTv[i][j].average;
		}
		averageOfTv[i] = sum / MAXUSER;
		pos[i] = i;
		sum = 0.00;
	}
	rankIndex(pos, averageOfTv);   //排序
	for (int i = 0; i < 10; i++) {
		cout << "第" << i +1<< "名:" << endl;
		cout << "名称:" << tv[pos[i]].name << endl;
		cout << "类型:" << tv[pos[i]].type << endl;
		cout << "导演:" << tv[pos[i]].director << endl;
		cout << "主演:" << tv[pos[i]].actor << endl;
		cout << "集数:" << tv[pos[i]].number << endl;
		cout << "简介:" << tv[pos[i]].intro << endl<<endl;
	}
}

void user::TopTenTvByIndex(int choice, Esitimate esitimateOfTv[N][MAXUSER], infoOfTv* tv) {
	//参数  choice是指标      esitimateOfTv评价二维数组   tv电视剧数组
	//无返回值
	double averageOfTv[N];
	int pos[N];
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
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
		for (int i = 0; i < 10; i++) {
			cout << "第" << i + 1 << "名:" << endl;
			cout << "名称:" << tv[pos[i]].name << endl;
		}
	}
	else {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			sum += esitimateOfTv[i][j].effect;
		}
		averageOfTv[i] = sum / MAXUSER;
		pos[i] = i;
		sum = 0.00;
	}
	rankIndex(pos, averageOfTv);
	for (int i = 0; i < 10; i++) {
		cout << "第" << i + 1 << "名:" << endl;
		cout << "名称:" << tv[pos[i]].name << endl;
	}
	}
}

int user::searchTv(InfoOfTv* tv,int* posOfThis) {
	//参数  电视剧数组指针
	//返回值  找到返回1   没找到返回0 用于做条件判断
	cout << "请输入想要寻找的电视剧名称：" << endl;
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
		cout <<"《"<< tv[pos].name << "》的基本信息是：" << endl;
		cout << "名称:" << tv[pos].name << endl;
		cout << "类型:" << tv[pos].type << endl;
		cout << "导演:" << tv[pos].director << endl;
		cout << "主演:" << tv[pos].actor << endl;
		cout << "集数:" << tv[pos].number << endl;
		cout << "简介:" << tv[pos].intro << endl;
		//并且在偏好数组中给这个电视剧加1
		userAttempt[pos]++;
		*posOfThis = pos;
		return 1;
	}
	else
	{
		return 0;
	}
}

void user::esitimateTv(int posOfThis,int posOfUser,Esitimate esitimateOfTv[N][MAXUSER],infoOfTv* tv) {
	//参数  posOfThis是当前评价的电视剧文件数组中的位置   posOfUser是当前用户的位置 esitimateList是文件数组   tv是电视剧基本信息数组
	//无返回值
	esitimateOfTv[posOfThis][posOfUser].userName = this->getName();
	cout << "请根据一下不同层面给《"+tv[posOfThis].name+"》打分（0-10分~）" << endl;
	cout << "情节：" ;
	cin >> esitimateOfTv[posOfThis][posOfUser].plot;
	while ((esitimateOfTv[posOfThis][posOfUser].plot != 0 && esitimateOfTv[posOfThis][posOfUser].plot != 1 && esitimateOfTv[posOfThis][posOfUser].plot != 2 && esitimateOfTv[posOfThis][posOfUser].plot != 3 && esitimateOfTv[posOfThis][posOfUser].plot != 4 && esitimateOfTv[posOfThis][posOfUser].plot != 5 && esitimateOfTv[posOfThis][posOfUser].plot != 6 && esitimateOfTv[posOfThis][posOfUser].plot != 7 && esitimateOfTv[posOfThis][posOfUser].plot != 8 && esitimateOfTv[posOfThis][posOfUser].plot != 9 && esitimateOfTv[posOfThis][posOfUser].plot != 10)||cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].plot;
	}
	cout << endl;
	
	cout << "演员表现力：";
	cin >> esitimateOfTv[posOfThis][posOfUser].behavior;
	while ((esitimateOfTv[posOfThis][posOfUser].behavior != 0 && esitimateOfTv[posOfThis][posOfUser].behavior != 1 && esitimateOfTv[posOfThis][posOfUser].behavior != 2 && esitimateOfTv[posOfThis][posOfUser].behavior != 3 && esitimateOfTv[posOfThis][posOfUser].behavior != 4 && esitimateOfTv[posOfThis][posOfUser].behavior != 5 && esitimateOfTv[posOfThis][posOfUser].behavior != 6 && esitimateOfTv[posOfThis][posOfUser].behavior != 7 && esitimateOfTv[posOfThis][posOfUser].behavior != 8 && esitimateOfTv[posOfThis][posOfUser].behavior != 9 && esitimateOfTv[posOfThis][posOfUser].behavior != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].behavior;
	}
	cout << endl;
	
	cout << "导演水平：";
	cin >> esitimateOfTv[posOfThis][posOfUser].levelOfDirector;
	while ((esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 0 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 1 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 2 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 3 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 4 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 5 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 6 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 7 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 8 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 9 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].levelOfDirector;
	}
	cout << endl;
	
	cout << "编剧水平：";
	cin >> esitimateOfTv[posOfThis][posOfUser].levelOfWriter;
	while ((esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 0 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 1 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 2 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 3 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 4 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 5 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 6 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 7 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 8 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 9 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].levelOfWriter;
	 }
	cout << endl;
	
	cout << "摄影：" ;
	cin >> esitimateOfTv[posOfThis][posOfUser].photographer;
	while ((esitimateOfTv[posOfThis][posOfUser].photographer != 0 && esitimateOfTv[posOfThis][posOfUser].photographer != 1 && esitimateOfTv[posOfThis][posOfUser].photographer != 2 && esitimateOfTv[posOfThis][posOfUser].photographer != 3 && esitimateOfTv[posOfThis][posOfUser].photographer != 4 && esitimateOfTv[posOfThis][posOfUser].photographer != 5 && esitimateOfTv[posOfThis][posOfUser].photographer != 6 && esitimateOfTv[posOfThis][posOfUser].photographer != 7 && esitimateOfTv[posOfThis][posOfUser].photographer != 8 && esitimateOfTv[posOfThis][posOfUser].photographer != 9 && esitimateOfTv[posOfThis][posOfUser].photographer != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].photographer;
	 }
	cout << endl;
	
	cout << "音乐：";
	cin >> esitimateOfTv[posOfThis][posOfUser].music;
	while ((esitimateOfTv[posOfThis][posOfUser].music != 0 && esitimateOfTv[posOfThis][posOfUser].music != 1 && esitimateOfTv[posOfThis][posOfUser].music != 2 && esitimateOfTv[posOfThis][posOfUser].music != 3 && esitimateOfTv[posOfThis][posOfUser].music != 4 && esitimateOfTv[posOfThis][posOfUser].music != 5 && esitimateOfTv[posOfThis][posOfUser].music != 6 && esitimateOfTv[posOfThis][posOfUser].music != 7 && esitimateOfTv[posOfThis][posOfUser].music != 8 && esitimateOfTv[posOfThis][posOfUser].music != 9 && esitimateOfTv[posOfThis][posOfUser].music != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].music;
	}
	cout << endl;
	
	cout << "美术：";
	cin >> esitimateOfTv[posOfThis][posOfUser].art;
	while ((esitimateOfTv[posOfThis][posOfUser].art != 0 && esitimateOfTv[posOfThis][posOfUser].art != 1 && esitimateOfTv[posOfThis][posOfUser].art != 2 && esitimateOfTv[posOfThis][posOfUser].art != 3 && esitimateOfTv[posOfThis][posOfUser].art != 4 && esitimateOfTv[posOfThis][posOfUser].art != 5 && esitimateOfTv[posOfThis][posOfUser].art != 6 && esitimateOfTv[posOfThis][posOfUser].art != 7 && esitimateOfTv[posOfThis][posOfUser].art != 8 && esitimateOfTv[posOfThis][posOfUser].art != 9 && esitimateOfTv[posOfThis][posOfUser].art != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].art;
	}
	cout << endl;
	
	cout << "特效：";
	cin >> esitimateOfTv[posOfThis][posOfUser].effect;
	while ((esitimateOfTv[posOfThis][posOfUser].effect != 0 && esitimateOfTv[posOfThis][posOfUser].effect != 1 && esitimateOfTv[posOfThis][posOfUser].effect != 2 && esitimateOfTv[posOfThis][posOfUser].effect != 3 && esitimateOfTv[posOfThis][posOfUser].effect != 4 && esitimateOfTv[posOfThis][posOfUser].effect != 5 && esitimateOfTv[posOfThis][posOfUser].effect != 6 && esitimateOfTv[posOfThis][posOfUser].effect != 7 && esitimateOfTv[posOfThis][posOfUser].effect != 8 && esitimateOfTv[posOfThis][posOfUser].effect != 9 && esitimateOfTv[posOfThis][posOfUser].effect != 10) || cin.fail()) {
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].effect;
	 }
	cout << endl;
	
	cout << "你还可以写写评论哦~" << endl;
	cin >> esitimateOfTv[posOfThis][posOfUser].overallEstimate;
	cout << endl;
	esitimateOfTv[posOfThis][posOfUser].average = (esitimateOfTv[posOfThis][posOfUser].plot + esitimateOfTv[posOfThis][posOfUser].behavior + esitimateOfTv[posOfThis][posOfUser].levelOfDirector + esitimateOfTv[posOfThis][posOfUser].levelOfWriter + esitimateOfTv[posOfThis][posOfUser].photographer + esitimateOfTv[posOfThis][posOfUser].art + esitimateOfTv[posOfThis][posOfUser].music + esitimateOfTv[posOfThis][posOfUser].effect) / 8;
}

void user::esitimateFromOtherUser(int posOfThis,Esitimate esitimateOfTv[N][MAXUSER], infoOfTv* tv) {
	//参数  posOfThis是当前评价的电视剧文件数组中的位置    esitimateList是文件数组   tv是电视剧基本信息数组
	//无返回值
	cout << "其他用户对《" + tv[posOfThis].name + "》的评价是：" << endl;
	for (int i = 0; i < MAXUSER; i++) {
		if (esitimateOfTv[posOfThis][i].userName == "未输入") {
			continue;
		}
		cout << esitimateOfTv[posOfThis][i].userName << ":  " << esitimateOfTv[posOfThis][i].overallEstimate << "     ta的总体评价是：" << esitimateOfTv[posOfThis][i].average << endl;
	}
}