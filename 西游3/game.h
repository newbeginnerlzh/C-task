#pragma once
#include<bits/stdc++.h>
#include"place.h"
#include"role.h"

using namespace std;

enum GAMESTATE {
	system_menu,		//�µĹ��£��ɵĻ��䣬�⽨����������
	playing_sys_menu,	//�洢���ȣ���ȡ���ȣ��뿪��Ϸ
	player_adven,		//���ð�գ���·����̸��������״̬����Ʒ������
	show_exits,			//�����ѡ��ȥ����
	talk_with_npc,		//�����ѡ���˭��̸
	attack_npc,			//�����ѡ�񹥻�˭
	watch_npc,			//�����ѡ��۲�˭
	//trading,			//�̵�
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
	void equip();//����װ��
	void disequip();//����װ��
	void add_value(int j);//װ����������ֵ
	void reduce_value(int k);//��װ�������ֵ
	void roleact(int i);
	void enemyact();
	void fight(bool n);


public:

	Role* role;//��Ϸ����������
	Skill* roleSkill;//��Ϸ�����ǵļ���

	Enemy* enemy;//��Ϸ�����й���
	Skill* enemySkill;//��Ϸ�й���ļ���

	Place* place;//��Ϸ�����еص�
	Equipment* shore;//��Ϸ��װ���̵�

	Npc* npc;

	struct Status {
		short current_role;//��ǰ����
		short current_place;//��ǰλ��
		short last_place;
		short previous_index;
		short status;
	}record;

};


int Labyrinth();
void show_surface();

void color(const unsigned short textColor);
