#pragma once
#include<bits/stdc++.h>
#include"skill.h"
#include"good.h"
#include"task.h"
using namespace std;


class Role {//����
public:
	void operator =(Role player);

public:
	string Name;
	string Describe;

	short Attack;//�չ�ֵ
	Skill Skills[4];//����

	short Money;//��ң�������װ��
	short Goodsnum;
	Good Goods[10];//��Ʒ�ֿ�
	short Equipmentnum;
	Good Equipment[5];//��ǰװ��

	short Hp;//����ֵ
	short Max_Hp;//��ǰHP��ֵ
	short Defence;//����

	short Mp;//����
	short Max_Mp;//��ǰMP��ֵ

	short Speed;//�ٶ�

	short Exp;//����ֵ
	short Level;//�ȼ�
	short place_index[15];
	short taskstatus[6];
};

class enemy {//���
public:
	void operator= (enemy npc);

public:

	string Name;
	string Describe;

	short Attack;//�չ�ֵ
	Skill skill;//����

	short Defence;
	short Hp;//����ֵ
	short Max_Hp;//��ǰHP��ֵ

	short Speed;//�ٶ�


};

enum GAMESTATE {
	system_menu,		//�µĹ��£��ɵĻ��䣬�⽨����������
	playing_sys_menu,	//�洢���ȣ���ȡ���ȣ��뿪��Ϸ
	player_adven,		//���ð�գ���·����̸��������״̬����Ʒ������
	show_exits,			//�����ѡ��ȥ����
	talk_with_npc,		//�����ѡ���˭��̸
	attack_npc,			//�����ѡ�񹥻�˭
	watch_npc,			//�����ѡ��۲�˭
	player_state,		//��Ҳ쿴״̬�����ܡ���Ʒ
	list_goods,			//�г���ӵ����Ʒ
	list_skills,		//�г���ӵ�еļ���
	list_quest,			//�鿴����
	use_goods,
	use_skill,
	fighting,			//ս����
	player_act,			//�ֵ�����ж�	
	list_free_item,		//�г�����ʰȡ����Ʒ
	pick_item,			//��ȡ��Ʒ
	check_equipment,	//���װ��
	unequip_,			//ж��װ��
	trading,			//����
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
	int taskstatus; //1.δ���� 2.weiwancheng1
	//Good goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

};