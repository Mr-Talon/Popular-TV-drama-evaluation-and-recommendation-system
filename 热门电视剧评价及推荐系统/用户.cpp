#include"�û�.h"
using namespace std;

//ѡ������
void user::rankIndex(int pos[N],double  averageOfTv[N]) {
	//����  pos�ǵ��Ӿ��ַ����   averageOfTv�ǵ�ǰָ����������
	//�޷���ֵ  ֱ�Ӹ����������
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
user::user() {
	name = "δ����";
}
user::user(string na) :name(na){
	cout << "�û��Ѿ�ע��ɹ�����" << endl;
}
string user::getName() {
	return name;
}
int user::recommendTv(int* posOfDelete) {
	//���� ����Ա����ɾ�����Ӿ� ������ɾ���ĵ��Ӿ��λ��  ���ڵ�����ǰ�û�ƫ���б�
	//����ֵ�ǵ�ֵַ 
	int max=0; //�û�ƫ������ֵ���ĵ��Ӿ�ĵ�ַ
	//������ǰ�û�ƫ������
	if (*posOfDelete != N) {
		for (int k = *posOfDelete; k<N-1; k++) {
			userAttempt[k] = userAttempt[k + 1];
		}
		userAttempt[N-1] = 0;
	}
	//Ѱ��ƫ�������е����ֵ
	for (int i = 0; i < N; i++) {
		if (userAttempt[i] > userAttempt[max]) {
			max = i;
		}
	}
	return max;
}

void user::TopTenTv(Esitimate esitimateOfTv[N][MAXUSER], infoOfTv*tv  ) {
	//����   esitimateOfTv�ǵ��Ӿ����۶�ά����     tv�ǵ��Ӿ���Ϣ����
	//����ֵ   �޷���ֵ
	//�������Ӿ�ƽ��������
	double averageOfTv[N];
	int pos[N];
	double sum = 0.00;
	//����ÿ�����Ӿ��ƽ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MAXUSER; j++) {
			sum += esitimateOfTv[i][j].average;
		}
		averageOfTv[i] = sum / MAXUSER;
		pos[i] = i;
		sum = 0.00;
	}
	rankIndex(pos, averageOfTv);   //����
	for (int i = 0; i < 10; i++) {
		cout << "��" << i +1<< "��:" << endl;
		cout << "����:" << tv[pos[i]].name << endl;
		cout << "����:" << tv[pos[i]].type << endl;
		cout << "����:" << tv[pos[i]].director << endl;
		cout << "����:" << tv[pos[i]].actor << endl;
		cout << "����:" << tv[pos[i]].number << endl;
		cout << "���:" << tv[pos[i]].intro << endl<<endl;
	}
}

void user::TopTenTvByIndex(int choice, Esitimate esitimateOfTv[N][MAXUSER], infoOfTv* tv) {
	//����  choice��ָ��      esitimateOfTv���۶�ά����   tv���Ӿ�����
	//�޷���ֵ
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
			cout << "��" << i + 1 << "��:" << endl;
			cout << "����:" << tv[pos[i]].name << endl;
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
		cout << "��" << i + 1 << "��:" << endl;
		cout << "����:" << tv[pos[i]].name << endl;
	}
	}
}

int user::searchTv(InfoOfTv* tv,int* posOfThis) {
	//����  ���Ӿ�����ָ��
	//����ֵ  �ҵ�����1   û�ҵ�����0 �����������ж�
	cout << "��������ҪѰ�ҵĵ��Ӿ����ƣ�" << endl;
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
		cout <<"��"<< tv[pos].name << "���Ļ�����Ϣ�ǣ�" << endl;
		cout << "����:" << tv[pos].name << endl;
		cout << "����:" << tv[pos].type << endl;
		cout << "����:" << tv[pos].director << endl;
		cout << "����:" << tv[pos].actor << endl;
		cout << "����:" << tv[pos].number << endl;
		cout << "���:" << tv[pos].intro << endl;
		//������ƫ�������и�������Ӿ��1
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
	//����  posOfThis�ǵ�ǰ���۵ĵ��Ӿ��ļ������е�λ��   posOfUser�ǵ�ǰ�û���λ�� esitimateList���ļ�����   tv�ǵ��Ӿ������Ϣ����
	//�޷���ֵ
	esitimateOfTv[posOfThis][posOfUser].userName = this->getName();
	cout << "�����һ�²�ͬ�������"+tv[posOfThis].name+"����֣�0-10��~��" << endl;
	cout << "��ڣ�" ;
	cin >> esitimateOfTv[posOfThis][posOfUser].plot;
	while ((esitimateOfTv[posOfThis][posOfUser].plot != 0 && esitimateOfTv[posOfThis][posOfUser].plot != 1 && esitimateOfTv[posOfThis][posOfUser].plot != 2 && esitimateOfTv[posOfThis][posOfUser].plot != 3 && esitimateOfTv[posOfThis][posOfUser].plot != 4 && esitimateOfTv[posOfThis][posOfUser].plot != 5 && esitimateOfTv[posOfThis][posOfUser].plot != 6 && esitimateOfTv[posOfThis][posOfUser].plot != 7 && esitimateOfTv[posOfThis][posOfUser].plot != 8 && esitimateOfTv[posOfThis][posOfUser].plot != 9 && esitimateOfTv[posOfThis][posOfUser].plot != 10)||cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].plot;
	}
	cout << endl;
	
	cout << "��Ա��������";
	cin >> esitimateOfTv[posOfThis][posOfUser].behavior;
	while ((esitimateOfTv[posOfThis][posOfUser].behavior != 0 && esitimateOfTv[posOfThis][posOfUser].behavior != 1 && esitimateOfTv[posOfThis][posOfUser].behavior != 2 && esitimateOfTv[posOfThis][posOfUser].behavior != 3 && esitimateOfTv[posOfThis][posOfUser].behavior != 4 && esitimateOfTv[posOfThis][posOfUser].behavior != 5 && esitimateOfTv[posOfThis][posOfUser].behavior != 6 && esitimateOfTv[posOfThis][posOfUser].behavior != 7 && esitimateOfTv[posOfThis][posOfUser].behavior != 8 && esitimateOfTv[posOfThis][posOfUser].behavior != 9 && esitimateOfTv[posOfThis][posOfUser].behavior != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].behavior;
	}
	cout << endl;
	
	cout << "����ˮƽ��";
	cin >> esitimateOfTv[posOfThis][posOfUser].levelOfDirector;
	while ((esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 0 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 1 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 2 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 3 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 4 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 5 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 6 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 7 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 8 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 9 && esitimateOfTv[posOfThis][posOfUser].levelOfDirector != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].levelOfDirector;
	}
	cout << endl;
	
	cout << "���ˮƽ��";
	cin >> esitimateOfTv[posOfThis][posOfUser].levelOfWriter;
	while ((esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 0 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 1 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 2 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 3 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 4 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 5 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 6 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 7 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 8 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 9 && esitimateOfTv[posOfThis][posOfUser].levelOfWriter != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].levelOfWriter;
	 }
	cout << endl;
	
	cout << "��Ӱ��" ;
	cin >> esitimateOfTv[posOfThis][posOfUser].photographer;
	while ((esitimateOfTv[posOfThis][posOfUser].photographer != 0 && esitimateOfTv[posOfThis][posOfUser].photographer != 1 && esitimateOfTv[posOfThis][posOfUser].photographer != 2 && esitimateOfTv[posOfThis][posOfUser].photographer != 3 && esitimateOfTv[posOfThis][posOfUser].photographer != 4 && esitimateOfTv[posOfThis][posOfUser].photographer != 5 && esitimateOfTv[posOfThis][posOfUser].photographer != 6 && esitimateOfTv[posOfThis][posOfUser].photographer != 7 && esitimateOfTv[posOfThis][posOfUser].photographer != 8 && esitimateOfTv[posOfThis][posOfUser].photographer != 9 && esitimateOfTv[posOfThis][posOfUser].photographer != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].photographer;
	 }
	cout << endl;
	
	cout << "���֣�";
	cin >> esitimateOfTv[posOfThis][posOfUser].music;
	while ((esitimateOfTv[posOfThis][posOfUser].music != 0 && esitimateOfTv[posOfThis][posOfUser].music != 1 && esitimateOfTv[posOfThis][posOfUser].music != 2 && esitimateOfTv[posOfThis][posOfUser].music != 3 && esitimateOfTv[posOfThis][posOfUser].music != 4 && esitimateOfTv[posOfThis][posOfUser].music != 5 && esitimateOfTv[posOfThis][posOfUser].music != 6 && esitimateOfTv[posOfThis][posOfUser].music != 7 && esitimateOfTv[posOfThis][posOfUser].music != 8 && esitimateOfTv[posOfThis][posOfUser].music != 9 && esitimateOfTv[posOfThis][posOfUser].music != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].music;
	}
	cout << endl;
	
	cout << "������";
	cin >> esitimateOfTv[posOfThis][posOfUser].art;
	while ((esitimateOfTv[posOfThis][posOfUser].art != 0 && esitimateOfTv[posOfThis][posOfUser].art != 1 && esitimateOfTv[posOfThis][posOfUser].art != 2 && esitimateOfTv[posOfThis][posOfUser].art != 3 && esitimateOfTv[posOfThis][posOfUser].art != 4 && esitimateOfTv[posOfThis][posOfUser].art != 5 && esitimateOfTv[posOfThis][posOfUser].art != 6 && esitimateOfTv[posOfThis][posOfUser].art != 7 && esitimateOfTv[posOfThis][posOfUser].art != 8 && esitimateOfTv[posOfThis][posOfUser].art != 9 && esitimateOfTv[posOfThis][posOfUser].art != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].art;
	}
	cout << endl;
	
	cout << "��Ч��";
	cin >> esitimateOfTv[posOfThis][posOfUser].effect;
	while ((esitimateOfTv[posOfThis][posOfUser].effect != 0 && esitimateOfTv[posOfThis][posOfUser].effect != 1 && esitimateOfTv[posOfThis][posOfUser].effect != 2 && esitimateOfTv[posOfThis][posOfUser].effect != 3 && esitimateOfTv[posOfThis][posOfUser].effect != 4 && esitimateOfTv[posOfThis][posOfUser].effect != 5 && esitimateOfTv[posOfThis][posOfUser].effect != 6 && esitimateOfTv[posOfThis][posOfUser].effect != 7 && esitimateOfTv[posOfThis][posOfUser].effect != 8 && esitimateOfTv[posOfThis][posOfUser].effect != 9 && esitimateOfTv[posOfThis][posOfUser].effect != 10) || cin.fail()) {
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> esitimateOfTv[posOfThis][posOfUser].effect;
	 }
	cout << endl;
	
	cout << "�㻹����дд����Ŷ~" << endl;
	cin >> esitimateOfTv[posOfThis][posOfUser].overallEstimate;
	cout << endl;
	esitimateOfTv[posOfThis][posOfUser].average = (esitimateOfTv[posOfThis][posOfUser].plot + esitimateOfTv[posOfThis][posOfUser].behavior + esitimateOfTv[posOfThis][posOfUser].levelOfDirector + esitimateOfTv[posOfThis][posOfUser].levelOfWriter + esitimateOfTv[posOfThis][posOfUser].photographer + esitimateOfTv[posOfThis][posOfUser].art + esitimateOfTv[posOfThis][posOfUser].music + esitimateOfTv[posOfThis][posOfUser].effect) / 8;
}

void user::esitimateFromOtherUser(int posOfThis,Esitimate esitimateOfTv[N][MAXUSER], infoOfTv* tv) {
	//����  posOfThis�ǵ�ǰ���۵ĵ��Ӿ��ļ������е�λ��    esitimateList���ļ�����   tv�ǵ��Ӿ������Ϣ����
	//�޷���ֵ
	cout << "�����û��ԡ�" + tv[posOfThis].name + "���������ǣ�" << endl;
	for (int i = 0; i < MAXUSER; i++) {
		if (esitimateOfTv[posOfThis][i].userName == "δ����") {
			continue;
		}
		cout << esitimateOfTv[posOfThis][i].userName << ":  " << esitimateOfTv[posOfThis][i].overallEstimate << "     ta�����������ǣ�" << esitimateOfTv[posOfThis][i].average << endl;
	}
}