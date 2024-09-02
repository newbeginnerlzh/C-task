#pragma once
#include<bits/stdc++.h>
#include"skill.h"
#include"good.h"
//#include"task.h"
using namespace std;



class Skill {
public:
	string Name;
	string Describe;

	short Power;//伤害
	short CostMp;//耗蓝
	short Level;//等级
};


class Equipment {
public:
	string Name;
	string Describe;
	short Location;	//可以装备的位置。1-头，2-身，3-手，4-脚
	short Cost;		//值多少钱

	short AddAttack;	//增加攻击
	short AddDefence;	//增加防御
	short AddHP;		//增加Hp
	short AddMaxHP;	//增加max HP
	short AddMP;		//增加Mp
	short AddMaxMP;	//增加max MP
	short AddSpeed;	//增加速度
};


class Role {//主角
public:
	//void operator =(Role player);

public:
	string Name;
	string Describe;

	short Attack;//普攻值
	short skill_index[4];//技能

	short Money;//金币，用于买装备
	//short Goodsnum;
	short Bag[15];//背包，记录每个引索对应装备的数量
	//short Equipmentnum;
	short MyEquipment_index[5];//当前装备

	short HP;//生命值
	short Max_Hp;//当前HP阈值
	short Defence;//防御

	short MP;//蓝量
	short Max_Mp;//当前MP阈值

	short Speed;//速度

	short Exp;//经验值
	short Level;//等级
	short place_index[15];
	short taskstatus[6];
};

class  Enemy{
public:
	string Name;
	string Describe;

	short Attack;//普攻值
	short skill_index;//技能

	short HP;//生命值
	short Max_Hp;//当前HP阈值

	short Speed;//速度

	short Lose_Exp;//掉落的经验值
	short Lose_Money;//掉落的金币
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