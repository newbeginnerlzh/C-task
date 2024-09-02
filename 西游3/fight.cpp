#include<iostream>
#include"game.h"

using namespace std;

void game::buy() {
	cout << "�����е��ʽ�" << role[record.current_role].Money << endl;
	int i;
	cout << "��Ҫ�����װ����ţ�" << endl;
	cin >> i;
	if (role[record.current_role].Money >= shore[i].Cost)
	{
		role[record.current_role].Money = role[record.current_role].Money - shore[i].Cost;
		role[record.current_role].Bag[i]++;
		cout << "�ѹ��룬��ǰ��������Ϊ��" << role[record.current_role].Bag[i] << endl;
	}
	else {
		cout << "����" << endl;
	}
}

void game::sell() {
	cout << "�����е��ʽ�" << role[record.current_role].Money << endl;
	int i;
	cout << "��Ҫ���۵�װ����ţ�" << endl;
	cin >> i;
	if (role[record.current_role].Bag[i] == 0)
	{
		cout << "û�и���Ʒ" << endl;
	}
	else {
		role[record.current_role].Bag[i]--;
		role[record.current_role].Money = role[record.current_role].Money + shore[i].Cost;
		cout << "�ѳ��ۣ���ǰ��������Ϊ��" << role[record.current_role].Bag[i] << endl;
	}
}


void game::equip() {
	int j;
	int input;
	cout << "Ҫװ����λ�ã�1.ͷ  2.��  3.��" << endl;
	cin >> j;
	if (j == 1)
	{
		cout << "Ҫװ������Ʒ��ţ�" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "װ��λ�ô���" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "������û�и���Ʒ" << endl;
		}
		else {
			role[record.current_role].Bag[input]--;
			role[record.current_role].MyEquipment_index[j] = input;
			add_value(j);
		}
	}
	else if (j == 2)
	{
		cout << "Ҫװ������Ʒ��ţ�" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "װ��λ�ô���" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "������û�и���Ʒ" << endl;
		}
		else {
			role[record.current_role].Bag[input]--;
			role[record.current_role].MyEquipment_index[j] = input;
			add_value(j);
		}
	}
	else if (j == 3) {
		cout << "Ҫװ������Ʒ��ţ�" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "װ��λ�ô���" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "������û�и���Ʒ" << endl;
		}
		else {
			role[record.current_role].Bag[input]--;
			role[record.current_role].MyEquipment_index[j] = input;
			add_value(j);
		}
	}
}


void game::add_value(int j) {
	role[record.current_role].Attack = role[record.current_role].Attack + shore[role[record.current_role].MyEquipment_index[j]].AddAttack;
	role[record.current_role].Defence = role[record.current_role].Defence + shore[role[record.current_role].MyEquipment_index[j]].AddDefence;
	role[record.current_role].HP = role[record.current_role].HP + shore[role[record.current_role].MyEquipment_index[j]].AddHP;
	role[record.current_role].Max_Hp = role[record.current_role].Max_Hp + shore[role[record.current_role].MyEquipment_index[j]].AddMaxHP;
	role[record.current_role].MP = role[record.current_role].MP + shore[role[record.current_role].MyEquipment_index[j]].AddMP;
	role[record.current_role].Max_Mp = role[record.current_role].Max_Mp + shore[role[record.current_role].MyEquipment_index[j]].AddMaxMP;
}

void game::disequip() {
	cout << "ѡ��Ҫ���µ�װ��" << endl;
	int k;
	cin >> k;
	if (role[record.current_role].MyEquipment_index[k] == 0) {
		cout << "��װ������" << endl;
	}
	else {
		reduce_value(k);
		role[record.current_role].Bag[role[record.current_role].MyEquipment_index[k]]++;
		role[record.current_role].MyEquipment_index[k] = 0;

	}
}

void game::reduce_value(int k) {
	role[record.current_role].Attack = role[record.current_role].Attack - shore[role[record.current_role].MyEquipment_index[k]].AddAttack;
	role[record.current_role].Defence = role[record.current_role].Defence - shore[role[record.current_role].MyEquipment_index[k]].AddDefence;
	role[record.current_role].HP = role[record.current_role].HP - shore[role[record.current_role].MyEquipment_index[k]].AddHP;
	role[record.current_role].Max_Hp = role[record.current_role].Max_Hp - shore[role[record.current_role].MyEquipment_index[k]].AddMaxHP;
	role[record.current_role].MP = role[record.current_role].MP - shore[role[record.current_role].MyEquipment_index[k]].AddMP;
	role[record.current_role].Max_Mp = role[record.current_role].Max_Mp - shore[role[record.current_role].MyEquipment_index[k]].AddMaxMP;
}


void game::roleact(int i) {
	if (i == 1) {
		enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].HP - role[record.current_role].Attack;
		cout << "�����ܵ�" << role[record.current_role].Attack << "���˺�" << endl;
	}
	else if (i == 2) {
		show_roleskill();
		cout << "��ѡ����Ҫʹ�õļ���" << endl;
		int j;
		cin >> j;
		if (role[record.current_role].MP < roleSkill[role[record.current_role].skill_index[j]].CostMp) {//������
			cout << "�����������޷�ʹ�ü���" << endl;
			return;
		}
		enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].HP - roleSkill[role[record.current_role].skill_index[j]].Power;
		role[record.current_role].MP = role[record.current_role].MP - roleSkill[role[record.current_role].skill_index[j]].CostMp;
		cout << "�����ܵ�" << roleSkill[role[record.current_role].skill_index[j]].Power << "���˺�" << endl;
		cout << "������" << roleSkill[role[record.current_role].skill_index[j]].CostMp << "������" << endl;
	}
}



void game::enemyact() {
	int p = 30;
	srand((unsigned)time(NULL));
	int r = rand() % 100;
	if (r < p) {//ʹ�ü���
		//cout<< enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power<<" " << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence) << endl;
		role[record.current_role].HP = role[record.current_role].HP - enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence);
		cout << "����ʹ�ü���" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Name << endl;
		cout << "���ܵ�" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence) << "���˺�" << endl;
	}
	else {//ʹ���չ�
		role[record.current_role].HP = role[record.current_role].HP - enemy[place[record.current_place].enemy_index].Attack * (1 - role[record.current_role].Defence);
		cout << "���ܵ�" << enemy[place[record.current_place].enemy_index].Attack * (1 - role[record.current_role].Defence) << "���չ��˺�" << endl;
	}
}


void game::fight(bool n) {
	if (n == false) {
		return;
	}
	cout << "1.��ս  2.�˳�" << endl;
	int i, j, k;
	cin >> i;
	if (i == 1) {
		while (true) {
			cout << "��ĵ�ǰ״̬�� " << "����ֵ " << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "  " << "����" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
			cout << "1.�չ�  2.ʹ�ü���  3.ʹ��ҩƷ  4.����" << endl;
			cin >> j;
			if (j == 1 || j == 2) {
				roleact(j);
				enemyact();
			}
			else if (j == 3) {
				cout << "1.ʹ������֮ˮ  2.ʹ����ɫ֮ˮ" << endl;
				cin >> k;
				if (k == 1) {
					if (role[record.current_role].Bag[13] == 0) {
						cout << "������֮ˮ" << endl;
					}
					else {
						role[record.current_role].Bag[13]--;
						role[record.current_role].HP = role[record.current_role].HP + shore[13].AddHP;
						if (role[record.current_role].HP > role[record.current_role].Max_Hp) {//���ܳ�����ֵ
							role[record.current_role].HP = role[record.current_role].Max_Hp;
						}
					}
				}
				else if (k == 2) {
					if (role[record.current_role].Bag[14] == 0) {
						cout << "����ɫ֮ˮ" << endl;
					}
					else {
						role[record.current_role].Bag[14]--;
						role[record.current_role].MP = role[record.current_role].MP + shore[14].AddMP;
						if (role[record.current_role].MP > role[record.current_role].Max_Mp) {//���ܳ�����ֵ
							role[record.current_role].MP = role[record.current_role].Max_Mp;
						}
					}
				}
			}
			else if (j == 4) {
				if (role[record.current_role].Speed > enemy[place[record.current_place].enemy_index].Speed) {
					cout << "���ܳɹ�" << endl;
					role[record.current_role].HP = role[record.current_role].Max_Hp;//������������
					role[record.current_role].MP = role[record.current_role].Max_Mp;//������������
					enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].Max_Hp;//������������
					record.current_place = record.last_place;//�ص���һ�ص�
					break;
				}
			}

			if (enemy[place[record.current_place].enemy_index].HP <= 0) {
				cout << "ս��ʤ����" << endl;
				role[record.current_role].HP = role[record.current_role].Max_Hp;//������������
				role[record.current_role].MP = role[record.current_role].Max_Mp;//������������
				role[record.current_role].Exp = role[record.current_role].Exp + enemy[place[record.current_place].enemy_index].Lose_Exp;
				role[record.current_role].Money = role[record.current_role].Money + enemy[place[record.current_place].enemy_index].Lose_Money;
				place[record.current_place].enemy_life = false;
				break;
			}
			if (role[record.current_role].HP <= 0) {
				cout << "ս��ʧ�ܣ��ص���һ�ص�" << endl;
				role[record.current_role].HP = role[record.current_role].Max_Hp;//������������
				role[record.current_role].MP = role[record.current_role].Max_Mp;//������������
				enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].Max_Hp;//������������
				record.current_place = record.last_place;//�ص���һ�ص�
				break;
			}
		}
		record.status = system_menu;
	}
	else if (i == 2) {
		record.status = system_menu;
	}
}
