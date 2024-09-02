#include<iostream>
#include<iomanip>
#include"Game.h"
using namespace std;



void game::show_eq() {
	int i;
	cout << "全部商品" << endl;
	for (i = 1; i <= 14; i++)
	{
		cout << i << "." << shore[i].Name << "  价格" << shore[i].Cost << endl;
	}
}

void game::show_eqdate(int i) {
	cout << shore[i].Describe << endl;
}

void game::show_bag() {
	int i;
	for (i = 1; i <= 14; i++)
	{
		cout << i << "." << shore[i].Name << "  数量：" << role[record.current_role].Bag[i] << endl;
	}
}


void game::show_state() {
	cout << "当前人物属性\t姓名：" << role[record.current_role].Name << "\t等级：" << role[record.current_role].Level << endl;
	cout << "生命：" << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "\t蓝量：" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
	cout << "攻击：" << role[record.current_role].Attack << "\t防御：" << role[record.current_role].Defence << "\t速度：" << role[record.current_role].Speed << "\t金钱：" << role[record.current_role].Money << endl;
	cout << "当前所在地点：" << place[record.current_role].Name << endl;
	cout << "背包：" << endl;
	show_bag();
}

void game::show_myeq() {
	cout << "1.头饰 " << shore[role[record.current_role].MyEquipment_index[1]].Name << endl;
	cout << "2.衣服 " << shore[role[record.current_role].MyEquipment_index[2]].Name << endl;
	cout << "3.武器 " << shore[role[record.current_role].MyEquipment_index[3]].Name << endl;
}

bool game::show_enemy() {
	if (place[record.current_place].enemy_index == 0) {
		cout << "此处无怪物" << endl;
		return false;
	}
	if (place[record.current_place].enemy_life == false) {
		cout << "怪物已经被击败" << endl;
		return false;
	}
	cout << enemy[place[record.current_place].enemy_index].Name << endl;
	cout << enemy[place[record.current_place].enemy_index].Describe << endl;
	cout << "攻击力：" << enemy[place[record.current_place].enemy_index].Attack << "  " << "生命值：" << enemy[place[record.current_place].enemy_index].HP << "  " << "速度：" << enemy[place[record.current_place].enemy_index].Speed << endl;
	cout << "技能：" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Name << endl;
	cout << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Describe << endl;
	cout << "攻击力：" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power << endl;
	return true;
}

void game::show_roleskill() {
	int i;
	for (i = 1; i <= 3; i++) {
		cout << i << "." << roleSkill[role[record.current_role].skill_index[i]].Name << "  " << roleSkill[role[record.current_role].skill_index[i]].Describe << endl;
	}
}
