#pragma once
#include<bits/stdc++.h>
#include"skill.h"
#include"good.h"
#include"task.h"
using namespace std;


class Role {//主角
public:
	void operator =(Role player);

public:
	string Name;
	string Describe;

	short Attack;//普攻值
	Skill Skills[4];//技能

	short Money;//金币，用于买装备
	short Goodsnum;
	Good Goods[10];//物品仓库
	short Equipmentnum;
	Good Equipment[5];//当前装备

	short Hp;//生命值
	short Max_Hp;//当前HP阈值
	short Defence;//护盾

	short Mp;//蓝量
	short Max_Mp;//当前MP阈值

	short Speed;//速度

	short Exp;//经验值
	short Level;//等级
	short place_index[15];
	short taskstatus[6];
};

class enemy {//配角
public:
	void operator= (enemy npc);

public:

	string Name;
	string Describe;

	short Attack;//普攻值
	Skill skill;//技能

	short Defence;
	short Hp;//生命值
	short Max_Hp;//当前HP阈值

	short Speed;//速度


};

enum GAMESTATE {
	system_menu,		//新的故事，旧的回忆，封建归隐，关于
	playing_sys_menu,	//存储进度，读取进度，离开游戏
	player_adven,		//玩家冒险：赶路，交谈，攻击，状态，物品，进度
	show_exits,			//让玩家选择去哪里
	talk_with_npc,		//让玩家选择和谁交谈
	attack_npc,			//让玩家选择攻击谁
	watch_npc,			//让玩家选择观察谁
	player_state,		//玩家察看状态、技能、物品
	list_goods,			//列出所拥有物品
	list_skills,		//列出所拥有的技能
	list_quest,			//查看任务
	use_goods,
	use_skill,
	fighting,			//战斗中
	player_act,			//轮到玩家行动	
	list_free_item,		//列出可以拾取的物品
	pick_item,			//捡取物品
	check_equipment,	//检查装备
	unequip_,			//卸除装备
	trading,			//交易
	buy_goods,
	sell_goods
};



class Npc {
public:
	//Npc(int num);


public:
	string name;
	string describe;
	int talk;
	int goodId;
	int goodNum;
	string task;
	string tdescribe;
	int tasknum;
	int taskstatus; //1.未接受 2.weiwancheng1
	//Good goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

};