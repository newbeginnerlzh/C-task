#pragma once
#include<bits/stdc++.h>
#include"place.h"
#include"role.h"

using namespace std;

enum GAMESTATE {
	system_menu,		//新的故事，旧的回忆，封建归隐，关于
	playing_sys_menu,	//存储进度，读取进度，离开游戏
	player_adven,		//玩家冒险：赶路，交谈，攻击，状态，物品，进度
	show_exits,			//让玩家选择去哪里
	talk_with_npc,		//让玩家选择和谁交谈
	attack_npc,			//让玩家选择攻击谁
	watch_npc,			//让玩家选择观察谁
	//trading,			//商店
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

class game {
public:
	void load_shore();
	void load_roleSkill();
	void load_enemy();
	void load_enemySkill();
	void game_init();
	void game_begin();
	void init_place();
	void init_show();
	void init_role();
	void init_npc();
	void select_talk(int num);
	void task_status(int num);

	void show_menu();
	void show_state();
	void show_eq();
	void show_eqdate(int i);
	void show_bag();
	void show_myeq();
	bool show_enemy();
	void show_roleskill();

	//void move();
	void buy();
	void sell();
	void equip();//配置装备
	void disequip();//脱下装备
	void add_value(int j);//装备后增加数值
	void reduce_value(int k);//脱装后减少数值
	void roleact(int i);
	void enemyact();
	void fight(bool n);


public:

	Role* role;//游戏中所有主角
	Skill* roleSkill;//游戏中主角的技能

	Enemy* enemy;//游戏中所有怪物
	Skill* enemySkill;//游戏中怪物的技能

	Place* place;//游戏中所有地点
	Equipment* shore;//游戏中装备商店

	Npc* npc;

	struct Status {
		short current_role;//当前主角
		short current_place;//当前位置
		short last_place;
		short previous_index;
		short status;
	}record;

};


int Labyrinth();
void show_surface();

void color(const unsigned short textColor);
