#pragma once
#include<bits/stdc++.h>
using namespace std;

class Place {//�ص���
public:
	string Name;
	string Describe;

	short comefirst;
	short npc_index;//�õ�NPC������
	short enemy_index;


	short connectnum;//���ӵص���
	short connect_place[7];//�������ӵص������
	bool enemy_life;//�õع����Ƿ���
};






struct {
	int choice;
	short current_palce;
};