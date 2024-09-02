#include<iostream>
#include"game.h"

using namespace std;

void game::buy() {
	cout << "您现有的资金：" << role[record.current_role].Money << endl;
	int i;
	cout << "需要购买的装备编号：" << endl;
	cin >> i;
	if (role[record.current_role].Money >= shore[i].Cost)
	{
		role[record.current_role].Money = role[record.current_role].Money - shore[i].Cost;
		role[record.current_role].Bag[i]++;
		cout << "已购入，当前所持数量为：" << role[record.current_role].Bag[i] << endl;
	}
	else {
		cout << "金额不足" << endl;
	}
}

void game::sell() {
	cout << "您现有的资金：" << role[record.current_role].Money << endl;
	int i;
	cout << "需要出售的装备编号：" << endl;
	cin >> i;
	if (role[record.current_role].Bag[i] == 0)
	{
		cout << "没有该物品" << endl;
	}
	else {
		role[record.current_role].Bag[i]--;
		role[record.current_role].Money = role[record.current_role].Money + shore[i].Cost;
		cout << "已出售，当前所持数量为：" << role[record.current_role].Bag[i] << endl;
	}
}


void game::equip() {
	int j;
	int input;
	cout << "要装备的位置：1.头  2.身  3.手" << endl;
	cin >> j;
	if (j == 1)
	{
		cout << "要装备的物品编号：" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "装备位置错误" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "背包中没有该物品" << endl;
		}
		else {
			role[record.current_role].Bag[input]--;
			role[record.current_role].MyEquipment_index[j] = input;
			add_value(j);
		}
	}
	else if (j == 2)
	{
		cout << "要装备的物品编号：" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "装备位置错误" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "背包中没有该物品" << endl;
		}
		else {
			role[record.current_role].Bag[input]--;
			role[record.current_role].MyEquipment_index[j] = input;
			add_value(j);
		}
	}
	else if (j == 3) {
		cout << "要装备的物品编号：" << endl;
		cin >> input;
		if (shore[input].Location != j) {
			cout << "装备位置错误" << endl;
		}
		else if (role[record.current_role].Bag[input] == 0) {
			cout << "背包中没有该物品" << endl;
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
	cout << "选择要脱下的装备" << endl;
	int k;
	cin >> k;
	if (role[record.current_role].MyEquipment_index[k] == 0) {
		cout << "无装备可脱" << endl;
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
		cout << "对手受到" << role[record.current_role].Attack << "点伤害" << endl;
	}
	else if (i == 2) {
		show_roleskill();
		cout << "请选择需要使用的技能" << endl;
		int j;
		cin >> j;
		if (role[record.current_role].MP < roleSkill[role[record.current_role].skill_index[j]].CostMp) {//蓝不够
			cout << "蓝量不够，无法使用技能" << endl;
			return;
		}
		enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].HP - roleSkill[role[record.current_role].skill_index[j]].Power;
		role[record.current_role].MP = role[record.current_role].MP - roleSkill[role[record.current_role].skill_index[j]].CostMp;
		cout << "对手受到" << roleSkill[role[record.current_role].skill_index[j]].Power << "点伤害" << endl;
		cout << "您消耗" << roleSkill[role[record.current_role].skill_index[j]].CostMp << "点蓝量" << endl;
	}
}



void game::enemyact() {
	int p = 30;
	srand((unsigned)time(NULL));
	int r = rand() % 100;
	if (r < p) {//使用技能
		//cout<< enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power<<" " << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence) << endl;
		role[record.current_role].HP = role[record.current_role].HP - enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence);
		cout << "对手使用技能" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Name << endl;
		cout << "您受到" << enemySkill[enemy[place[record.current_place].enemy_index].skill_index].Power * (1 - role[record.current_role].Defence) << "点伤害" << endl;
	}
	else {//使用普攻
		role[record.current_role].HP = role[record.current_role].HP - enemy[place[record.current_place].enemy_index].Attack * (1 - role[record.current_role].Defence);
		cout << "您受到" << enemy[place[record.current_place].enemy_index].Attack * (1 - role[record.current_role].Defence) << "点普攻伤害" << endl;
	}
}


void game::fight(bool n) {
	if (n == false) {
		return;
	}
	cout << "1.开战  2.退出" << endl;
	int i, j, k;
	cin >> i;
	if (i == 1) {
		while (true) {
			cout << "你的当前状态： " << "生命值 " << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "  " << "蓝量" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
			cout << "1.普攻  2.使用技能  3.使用药品  4.逃跑" << endl;
			cin >> j;
			if (j == 1 || j == 2) {
				roleact(j);
				enemyact();
			}
			else if (j == 3) {
				cout << "1.使用生命之水  2.使用蓝色之水" << endl;
				cin >> k;
				if (k == 1) {
					if (role[record.current_role].Bag[13] == 0) {
						cout << "无生命之水" << endl;
					}
					else {
						role[record.current_role].Bag[13]--;
						role[record.current_role].HP = role[record.current_role].HP + shore[13].AddHP;
						if (role[record.current_role].HP > role[record.current_role].Max_Hp) {//不能超过阈值
							role[record.current_role].HP = role[record.current_role].Max_Hp;
						}
					}
				}
				else if (k == 2) {
					if (role[record.current_role].Bag[14] == 0) {
						cout << "无蓝色之水" << endl;
					}
					else {
						role[record.current_role].Bag[14]--;
						role[record.current_role].MP = role[record.current_role].MP + shore[14].AddMP;
						if (role[record.current_role].MP > role[record.current_role].Max_Mp) {//不能超过阈值
							role[record.current_role].MP = role[record.current_role].Max_Mp;
						}
					}
				}
			}
			else if (j == 4) {
				if (role[record.current_role].Speed > enemy[place[record.current_place].enemy_index].Speed) {
					cout << "逃跑成功" << endl;
					role[record.current_role].HP = role[record.current_role].Max_Hp;//主角生命回满
					role[record.current_role].MP = role[record.current_role].Max_Mp;//主角蓝条回满
					enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].Max_Hp;//怪物生命回满
					record.current_place = record.last_place;//回到上一地点
					break;
				}
			}

			if (enemy[place[record.current_place].enemy_index].HP <= 0) {
				cout << "战斗胜利！" << endl;
				role[record.current_role].HP = role[record.current_role].Max_Hp;//主角生命回满
				role[record.current_role].MP = role[record.current_role].Max_Mp;//主角蓝条回满
				role[record.current_role].Exp = role[record.current_role].Exp + enemy[place[record.current_place].enemy_index].Lose_Exp;
				role[record.current_role].Money = role[record.current_role].Money + enemy[place[record.current_place].enemy_index].Lose_Money;
				place[record.current_place].enemy_life = false;
				break;
			}
			if (role[record.current_role].HP <= 0) {
				cout << "战斗失败，回到上一地点" << endl;
				role[record.current_role].HP = role[record.current_role].Max_Hp;//主角生命回满
				role[record.current_role].MP = role[record.current_role].Max_Mp;//主角蓝条回满
				enemy[place[record.current_place].enemy_index].HP = enemy[place[record.current_place].enemy_index].Max_Hp;//怪物生命回满
				record.current_place = record.last_place;//回到上一地点
				break;
			}
		}
		record.status = system_menu;
	}
	else if (i == 2) {
		record.status = system_menu;
	}
}
