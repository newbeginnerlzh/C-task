#pragma once
#include<bits/stdc++.h>
using namespace std;

class Place {//地点类
public:
	string Name;
	string Describe;

	short comefirst;
	short npc_index;//该地NPC的引索
	short enemy_index;


	short connectnum;//连接地点数
	short connect_place[7];//储存连接地点的引索
	bool enemy_life;//该地怪兽是否存活
};






struct {
	int choice;
	short current_palce;
};