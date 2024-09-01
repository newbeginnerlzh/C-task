#pragma once
#include<bits/stdc++.h>

using namespace std;

class Good {
public:
	void operator= (Good goods);

public:
	string Name;	//物品名称
	string Describe;	//物品描述
	short Location;	//可以装备的位置。0-头，1-身，2-手，3-脚
	short Cost;		//值多少钱

	short AddAttack;	//增加攻击
	short AddDefence;	//增加防御
	short AddHp;		//增加Hp
	short AddMaxHp;	//增加max HP
	short AddMp;		//增加Mp
	short AddMaxMp;	//增加max MP
	short AddSpeed;	//增加速度
};