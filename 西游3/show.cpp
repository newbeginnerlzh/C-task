#include<iostream>
#include<iomanip>
#include"Game.h"
using namespace std;



void game::show_eq() {
	int i;
	cout << "ȫ����Ʒ" << endl;
	for (i = 1; i <= 14; i++)
	{
		cout << i << "." << shore[i].Name << "  �۸�" << shore[i].Cost << endl;
	}
}

void game::show_eqdate(int i) {
	cout << shore[i].Describe << endl;
}

void game::show_bag() {
	int i;
	for (i = 1; i <= 14; i++)
	{
		cout << i << "." << shore[i].Name << "  ������" << role[record.current_role].Bag[i] << endl;
	}
}


void game::show_state() {
	cout << "��ǰ��������\t������" << role[record.current_role].Name << "\t�ȼ���" << role[record.current_role].Level << endl;
	cout << "������" << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "\t������" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
	cout << "������" << role[record.current_role].Attack << "\t������" << role[record.current_role].Defence << "\t�ٶȣ�" << role[record.current_role].Speed << "\t��Ǯ��" << role[record.current_role].Money << endl;
	cout << "��ǰ���ڵص㣺" << place[record.current_role].Name << endl;
	cout << "������" << endl;
	show_bag();
}

void game::show_myeq() {
	cout << "1.ͷ�� " << shore[role[record.current_role].MyEquipment_index[1]].Name << endl;
	cout << "2.�·� " << shore[role[record.current_role].MyEquipment_index[2]].Name << endl;
	cout << "3.���� " << shore[role[record.current_role].MyEquipment_index[3]].Name << endl;
}

bool game::show_enemy() {
	if (place[record.current_place].enemy_index == 0) {
		cout << "�˴��޹���" << endl;
		return false;
	}
	if (place[record.current_place].enemy_life == false) {
		cout << "�����Ѿ�������" << endl;
		return false;
	}
	cout << enemy[place[record.current_place].enemy_index].Name << endl;
	cout << enemy[place[record.current_place].enemy_index].Describe << endl;
	cout << "��������" << enemy[place[record.current_place].enemy_index].Attack << "  " << "����ֵ��" << enemy[place[record.current_place].enemy_index].HP << "  " << "�ٶȣ�" << enemy[place[record.current_place].enemy_index].Speed << endl;
	cout << "���ܣ�" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Name << endl;
	cout << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Describe << endl;
	cout << "��������" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power << endl;
	return true;
}

void game::show_roleskill() {
	int i;
	for (i = 1; i <= 3; i++) {
		cout << i << "." << roleSkill[role[record.current_role].skill_index[i]].Name << "  " << roleSkill[role[record.current_role].skill_index[i]].Describe << endl;
	}
}
