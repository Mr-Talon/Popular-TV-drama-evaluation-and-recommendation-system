#include"����Ա.h"
#include<fstream>
using namespace std;
int count1 = 30;

//ѡ������
void rankIndex(int pos[N], double  averageOfTv[N]) {
	//����  pos�ǵ��Ӿ��ַ����   averageOfTv�ǵ�ǰָ����������
	//�޷���ֵ
	int index;   //�ݴ���ֵ
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
			//����ƽ��ֵ�͵�ַ
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
	name = "δ����";
	password = "δ����";
}

manager::manager(string name, string password) :name(name), password(password) {
	cout << "����Աע��ɹ���" << endl;
	cout << endl;
}

bool manager::checkPassword(char* password) {
	//����  ����Ա���������
	// ����ֵ  �����Ƿ���ȷ��boolֵ
	//�ж����������Ƿ�һ��
	if (password == this->password) {
		return 1;
	}
	else
	{
		return 0;
	}
}

//���ӵ��Ӿ���Ϣ
void manager::Add(InfoOfTv* tv, Esitimate esitimateOfTv[N][MAXUSER],int* countOfTv){
	//���� tv���Ӿ�����  esitimateOfTv���۶�ά����   countOfTv���������Ӿ����
	//�޷���ֵ
	if (count1 != N)//�жϵ��Ӿ�������û�г���40
	{
		//tv�����Ӧλ�����ӵ��Ӿ���Ϣ
		cout << "��������Ӿ�����ơ����͡����ݡ����ݡ�����������" << endl;
		cout << "���ƣ�";
		cin >> tv[count1].name;
		cout << "���ͣ�";
		cin >> tv[count1].type;
		cout << "���ݣ�";
		cin >> tv[count1].director;
		cout << "���ݣ�";
		cin >> tv[count1].actor;
		cout << "������";
		cin >> tv[count1].number;
		while (cin.fail()) {//��ֹ�������
			cin.clear();
			cout << "����������������룡" << endl;
			cin.ignore(10000, '\n');
			cin >> tv[count1].number;
		}
		cout << "���飺";
		cin >> tv[count1].intro;
		//������Ϣ��ά�����Ӧλ�ó�ʼ����Ϣ
		for (int j = 0; j < MAXUSER; j++) {   //��ʼ���ṹ�����͵Ķ�ά�����ŵ��Ӿ����۵ĸ���ָ��
			esitimateOfTv[count1][j].userName = "δ����";
			esitimateOfTv[count1][j].plot = 0;
			esitimateOfTv[count1][j].behavior = 0;
			esitimateOfTv[count1][j].levelOfDirector = 0;
			esitimateOfTv[count1][j].levelOfWriter = 0;
			esitimateOfTv[count1][j].photographer = 0;
			esitimateOfTv[count1][j].music = 0;
			esitimateOfTv[count1][j].art = 0;
			esitimateOfTv[count1][j].effect = 0;
			esitimateOfTv[count1][j].overallEstimate = "δ����";
			esitimateOfTv[count1][j].average = 0;
		}
		count1++;   //���Ӿ�����++
		(*countOfTv)++;		//���������Ӿ�����++
		//Ϊ�½��ĵ��Ӿ��½�һ���ļ����ڴ洢�û��Ըõ��Ӿ������
		fstream newTv("C:\\Users\\16046\\Desktop\\���\\���ŵ��Ӿ����ۼ��Ƽ�ϵͳ\\���ŵ��Ӿ����ۼ��Ƽ�ϵͳ\\" + tv[count1].name + ".txt",fstream::out);
		if (!newTv) {
			cout << "���ܴ�������Ϣ�ļ�" << endl;
			return ;
		}
		newTv.close();
	}
	else  //���Ӿ���������40
	{
		cout << "���Ӿ���Ϣ�������޷���������Ϣ��";
	}
}

//�޸ĵ��Ӿ���Ϣ
void manager::modify(InfoOfTv* tv)
{
	//���� tv���Ӿ�����
	//�޷���ֵ
	cout << "��������Ҫ�޸ĵĵ��Ӿ����ƣ�" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //������ʾ���Ӿ������Ƿ�������֮��
	int pos;    //���ڴ洢��ǰ���Ӿ��ڵ��Ӿ������Ϣ�����е�λ��
	for (int i = 0; i < N; i++) {    //����
		if (nameOfTv == tv[i].name) {
			pos = i;
			flag = -1;
		}
		if (flag == -1) {   //�ҵ���Ϣ�˳�forѭ��
			break;
		}
	}
	if (flag != 0) {
		//�ҵ��˾ͷ��ػ�����Ϣ
		cout << endl;
		cout << "��" << tv[pos].name << "���Ļ�����Ϣ�ǣ�" << endl;
		cout << "����:" << tv[pos].name << endl;
		cout << "����:" << tv[pos].type << endl;
		cout << "����:" << tv[pos].director << endl;
		cout << "����:" << tv[pos].actor << endl;
		cout << "����:" << tv[pos].number << endl;
		cout << "���:" << tv[pos].intro << endl;
		//������ƫ�������и�������Ӿ��1
	}
	int a;
	cout << "����������Ҫ�޸ĵ�����" << endl;
	cout << "1 ������   2 ������    3�� ����   4������    5������    6����� " << endl;
	cout << "���������ѡ��";
	cin >> a;
	while (cin.fail()||(a!=1&&a!=2&& a != 3 && a != 4 && a != 5 && a != 6) ) {
		cin.clear();
		cout << "����������������룡" << endl;
		cin.ignore(10000, '\n');
		cin >> a;
	}
	//�ж���������
	if (a == 1)
	{
		cout << "���ƣ�" << endl;
		cin >> tv[pos].name;
	}
	if (a == 2)
	{
		cout << "���ͣ�" << endl;
		cin >> tv[pos].type;
	}
	if (a == 3)
	{
		cout << "���ݣ�" << endl;
		cin >> tv[pos].director;
	}
	if (a == 4)
	{
		cout << "���ݣ�" << endl;
		cin >> tv[pos].actor;
	}
	if (a == 5)
	{
		cout << "������" << endl;
		cin >> tv[pos].number;
		while (cin.fail()) {
			cin.clear();
			cout << "����������������룡" << endl;
			cin.ignore(10000, '\n');
			cin >> tv[pos].number;
		}
	}
	if (a == 6)
	{
		cout << "��飺" << endl;
		cin >> tv[pos].intro;
	}
	cout << "���ѳɹ��޸���Ϣ��";
}

//ɾ�����Ӿ���Ϣ
void manager::deletetv(InfoOfTv* tv, Esitimate esitimateOfTv[N][MAXUSER], int* countOfTv,int* posOfDelete)
{
	//����  tv���Ӿ�����  esitimateOfTv���۶�ά����  countOfTv���������Ӿ����   posOfDeleteɾ��λ��
	//�޷���ֵ
	cout << "����������Ҫɾ���ĵ��Ӿ�" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //������ʾ���Ӿ������Ƿ�������֮��
	int pos;    //���ڴ洢��ǰ���Ӿ��ڵ��Ӿ������Ϣ�����е�λ��
	for (int i = 0; i < N; i++)
	{    //����
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
		//Ӳ���� ��Ӧ��ɾ���ĵ��Ӿ����۵�txt�ļ�ҲҪ��ɾ��
		string nameOfFile = "C:\\Users\\16046\\Desktop\\���\\���ŵ��Ӿ����ۼ��Ƽ�ϵͳ\\���ŵ��Ӿ����ۼ��Ƽ�ϵͳ\\" + tv[pos].name + ".txt";
		remove(nameOfFile.c_str());

		//�ڴ��� �ú���ĸ���֮ǰ��
		for (i = pos; i < N-1; i++)
		{
			tv[i] = tv[i + 1];
			for (int j = 0; j < MAXUSER; j++) {
				esitimateOfTv[i][j] = esitimateOfTv[i + 1][j];
			}
			//�û���������ҲҪ����ɾ��
		}
		*posOfDelete = pos;
		count1--;
		(*countOfTv)--;  //���������Ӿ�����--
		cout << "ɾ�����Ӿ�ɹ���";
	}
	else
	{
		cout << "û�иõ��Ӿ���Ϣ��";
	}
}

//�������Ʒ��ص��Ӿ���Ϣ
void manager::searchofmanager(InfoOfTv* tv)
{
	//����  tv���Ӿ�����
	//�޷���ֵ
	cout << "��������Ҫ���ҵĵ��Ӿ����ƣ�" << endl;
	string nameOfTv;
	cin >> nameOfTv;
	int flag = 0;   //������ʾ���Ӿ������Ƿ�������֮��
	int pos;    //���ڴ洢��ǰ���Ӿ��ڵ��Ӿ������Ϣ�����е�λ��
	for (int i = 0; i < N; i++) {    //����
		if (nameOfTv == tv[i].name) {
			pos = i;
			flag = -1;
		}
		if (flag == -1) {
			break;
		}
	}
	if (flag != 0) {
		//�ҵ��˾ͷ��ػ�����Ϣ
		cout << endl;
		cout << "��" << tv[pos].name << "���Ļ�����Ϣ�ǣ�" << endl;
		cout << "����:" << tv[pos].name << endl;
		cout << "����:" << tv[pos].type << endl;
		cout << "����:" << tv[pos].director << endl;
		cout << "����:" << tv[pos].actor << endl;
		cout << "����:" << tv[pos].number << endl;
		cout << "���:" << tv[pos].intro << endl;
		//������ƫ�������и�������Ӿ��1
	}
	else
	{
		cout << "û�иõ��Ӿ���ϢŶ~";
	}
}

//�鿴���е��Ӿ�����
void manager::esitimateFromuser(Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv* tv)
{
	//����  esitimateOfTv���۶�ά����    tv���Ӿ�����
	//�޷���ֵ
	int i;
	cout << "�û��Ե��Ӿ�������ǣ�" << endl;
	for (int j = 0; j < N; j++)   //������Ӿ����۵Ķ�ά����
	{
		if (tv[j].name[0]== '\0')
		{
			continue;
		}
		cout << "��" << tv[j].name << "��:" << endl;
		for (i = 0; i < MAXUSER; i++)
		{

			if (esitimateOfTv[j][i].userName == "δ����")
			{
				continue;
			}
			else
			{
				cout << esitimateOfTv[j][i].userName << ":  " << esitimateOfTv[j][i].overallEstimate << "     ta�����������ǣ�" << esitimateOfTv[j][i].average << endl;
			}
		}
		cout << endl;
	}
}

//����ض�ָ�������
void outputByLevel(int pos[N], InfoOfTv* tv) {
	//����  pos��ʱ���Ӿ��ַ����   tv���Ӿ�����
	//�޷���ֵ
	cout << "��������Ҫ�鿴�ķ����Σ�" << endl;
	cout << "1��1~10��		2��11~20��		3��21~30��		4��31~40��" << endl;
	int choice,level;
	cin >> choice;
	while ((choice != 1 && choice != 2 && choice != 3 && choice != 4) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >>choice;
	}
	//��֤������ȷ
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
		cout << "��" << i + 1 << "��:" << endl;
		cout << "����:" << tv[pos[i]].name << endl;
	}
}

//�������������β鿴
void manager::rank(int choice,Esitimate esitimateOfTv[N][MAXUSER], InfoOfTv* tv)
{
	// ����  choice ָ�����     esitimateOfTv���۶�ά����    tv���Ӿ�����
	//�޷���ֵ
	double averageOfTv[N];   //����ض�ָ���ƽ����
	int pos[N];  //��ʱ��ŵ��Ӿ�λ�õ����飬��������
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

