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

	short Power;//�˺�
	short CostMp;//����
	short Level;//�ȼ�
};


class Equipment {
public:
	string Name;
	string Describe;
	short Location;	//����װ����λ�á�1-ͷ��2-��3-�֣�4-��
	short Cost;		//ֵ����Ǯ

	short AddAttack;	//���ӹ���
	short AddDefence;	//���ӷ���
	short AddHP;		//����Hp
	short AddMaxHP;	//����max HP
	short AddMP;		//����Mp
	short AddMaxMP;	//����max MP
	short AddSpeed;	//�����ٶ�
};


class Role {//����
public:
	//void operator =(Role player);

public:
	string Name;
	string Describe;

	short Attack;//�չ�ֵ
	short skill_index[4];//����

	short Money;//��ң�������װ��
	//short Goodsnum;
	short Bag[15];//��������¼ÿ��������Ӧװ��������
	//short Equipmentnum;
	short MyEquipment_index[5];//��ǰװ��

	short HP;//����ֵ
	short Max_Hp;//��ǰHP��ֵ
	short Defence;//����

	short MP;//����
	short Max_Mp;//��ǰMP��ֵ

	short Speed;//�ٶ�

	short Exp;//����ֵ
	short Level;//�ȼ�
	short place_index[15];
	short taskstatus[6];
};

class  Enemy{
public:
	string Name;
	string Describe;

	short Attack;//�չ�ֵ
	short skill_index;//����

	short HP;//����ֵ
	short Max_Hp;//��ǰHP��ֵ

	short Speed;//�ٶ�

	short Lose_Exp;//����ľ���ֵ
	short Lose_Money;//����Ľ��
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
	int taskstatus; //1.δ���� 2.weiwancheng1
	//Good goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

};