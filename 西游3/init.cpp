#include<bits/stdc++.h>
#include"game.h"

using namespace std;


void game::load_roleSkill() {
	roleSkill = new Skill[13];

	//1��3Ϊ��ɮ
	roleSkill[1].Name = "����֮��";
	roleSkill[1].Describe;
	roleSkill[1].Level = 1;
	roleSkill[1].Power = 20;
	roleSkill[1].CostMp = 10;

	roleSkill[2].Name = "�Ż�֮��";
	roleSkill[2].Describe;
	roleSkill[2].Level = 1;
	roleSkill[2].Power = 20;
	roleSkill[2].CostMp = 10;

	roleSkill[3].Name = "�ֻ�֮ӡ";
	roleSkill[3].Describe;
	roleSkill[3].Level = 1;
	roleSkill[3].Power = 20;
	roleSkill[3].CostMp = 10;

	//4��6Ϊ�����
	roleSkill[4].Name = "��ս���";
	roleSkill[4].Describe;
	roleSkill[4].Level = 1;
	roleSkill[4].Power;
	roleSkill[4].CostMp;

	roleSkill[5].Name = "�����";
	roleSkill[5].Describe;
	roleSkill[5].Level = 1;
	roleSkill[5].Power;
	roleSkill[5].CostMp;

	roleSkill[6].Name = "�����䷨";
	roleSkill[6].Describe;
	roleSkill[6].Level = 1;
	roleSkill[6].Power;
	roleSkill[6].CostMp;

	//7��9Ϊ��˽�
	roleSkill[7].Name = "����һ��";
	roleSkill[7].Describe;
	roleSkill[7].Level = 1;
	roleSkill[7].Power;
	roleSkill[7].CostMp;

	roleSkill[8].Name = "�ⵯ�Ĵ�";
	roleSkill[8].Describe;
	roleSkill[8].Level = 1;
	roleSkill[8].Power;
	roleSkill[8].CostMp;

	roleSkill[9].Name = "̩ɽѹ��";
	roleSkill[9].Describe;
	roleSkill[9].Level = 1;
	roleSkill[9].Power;
	roleSkill[9].CostMp;

	//10��12Ϊɳ����
	roleSkill[10].Name = "��ɳ����";
	roleSkill[10].Describe;
	roleSkill[10].Level = 1;
	roleSkill[10].Power;
	roleSkill[10].CostMp;

	roleSkill[11].Name = "������ɳ";
	roleSkill[11].Describe;
	roleSkill[11].Level = 1;
	roleSkill[11].Power;
	roleSkill[11].CostMp;

	roleSkill[12].Name = "�������";
	roleSkill[12].Describe;
	roleSkill[12].Level = 1;
	roleSkill[12].Power;
	roleSkill[12].CostMp;

}


void game::load_enemySkill() {
	enemySkill = new Skill[7];

	//1Ϊ�׹Ǿ�
	enemySkill[1].Name = "��ʬ����";
	enemySkill[1].Describe;
	enemySkill[1].Level = 1;
	enemySkill[1].Power = 10;
	enemySkill[1].CostMp = 0;

	//2Ϊ��ëʨ�Ӿ�
	enemySkill[2].Name = "ħ��֮ŭ";
	enemySkill[2].Describe;
	enemySkill[2].Level = 1;
	enemySkill[2].Power = 10;
	enemySkill[2].CostMp = 0;

	//3Ϊ�캢��
	enemySkill[3].Name = "��ζ���";
	enemySkill[3].Describe;
	enemySkill[3].Level = 1;
	enemySkill[3].Power = 10;
	enemySkill[3].CostMp;

	//4Ϊ���ȹ���
	enemySkill[4].Name = "����ƾ�";
	enemySkill[4].Describe;
	enemySkill[4].Level = 1;
	enemySkill[4].Power;
	enemySkill[4].CostMp;

	//5Ϊ��Ƥ���Ӿ�
	enemySkill[5].Name = "������";
	enemySkill[5].Describe;
	enemySkill[5].Level = 1;
	enemySkill[5].Power;
	enemySkill[5].CostMp;

	//6Ϊ���þ�
	enemySkill[6].Name = "��̬����";
	enemySkill[6].Describe;
	enemySkill[6].Level = 1;
	enemySkill[6].Power;
	enemySkill[6].CostMp;

}



void game::load_enemy() {
	enemy = new Enemy[7];

	enemy[1].Name = "�׹Ǿ�";
	enemy[1].Describe;
	enemy[1].Attack = 5;
	enemy[1].skill_index = 1;
	enemy[1].HP = 50;
	enemy[1].Max_Hp = 50;
	enemy[1].Speed = 3;
	enemy[1].Lose_Exp = 200;
	enemy[1].Lose_Money = 200;

	enemy[2].Name = "��ëʨ�Ӿ�";
	enemy[2].Describe;
	enemy[2].Attack = 5;
	enemy[2].skill_index = 2;
	enemy[2].HP = 50;
	enemy[2].Max_Hp = 50;
	enemy[2].Speed = 3;
	enemy[2].Lose_Exp = 200;
	enemy[2].Lose_Money = 200;

	enemy[3].Name = "�캢��";
	enemy[3].Describe;
	enemy[3].Attack = 5;
	enemy[3].skill_index = 3;
	enemy[3].HP = 50;
	enemy[3].Max_Hp = 50;
	enemy[3].Speed = 3;
	enemy[3].Lose_Exp = 200;
	enemy[3].Lose_Money = 200;

	enemy[4].Name = "���ȹ���";
	enemy[4].Describe;
	enemy[4].Attack;
	enemy[4].skill_index = 4;
	enemy[4].HP;
	enemy[4].Max_Hp = 50;
	enemy[4].Speed;
	enemy[4].Lose_Exp;
	enemy[4].Lose_Money;

	enemy[5].Name = "��Ƥ���Ӿ�";
	enemy[5].Describe;
	enemy[5].Attack;
	enemy[5].skill_index = 5;
	enemy[5].HP;
	enemy[5].Max_Hp = 50;
	enemy[5].Speed;
	enemy[5].Lose_Exp;
	enemy[5].Lose_Money;

	enemy[6].Name = "���þ�";
	enemy[6].Describe;
	enemy[6].Attack;
	enemy[6].skill_index = 6;
	enemy[6].HP;
	enemy[6].Max_Hp = 50;
	enemy[6].Speed;
	enemy[6].Lose_Exp;
	enemy[6].Lose_Money;
}


void game::load_shore() {
	shore = new Equipment[15];

	//1��3��ͷ��
	shore[1].Name = "ʹ�����";
	shore[1].Describe;
	shore[1].Location = 1;
	shore[1].Cost = 10;
	shore[1].AddAttack = 0;
	shore[1].AddDefence = 0;
	shore[1].AddHP = 0;
	shore[1].AddMaxHP = 0;
	shore[1].AddMP = 5;
	shore[1].AddMaxMP = 20;
	shore[1].AddSpeed = 0;

	shore[2].Name = "��ѧ֮ñ";
	shore[2].Describe;
	shore[2].Location = 1;
	shore[2].Cost = 10;
	shore[2].AddAttack = 0;
	shore[2].AddDefence = 0;
	shore[2].AddHP = 0;
	shore[2].AddMaxHP = 0;
	shore[2].AddMP = 5;
	shore[2].AddMaxMP = 20;
	shore[2].AddSpeed = 0;

	shore[3].Name = "��������";
	shore[3].Describe;
	shore[3].Location = 1;
	shore[3].Cost = 10;
	shore[3].AddAttack = 0;
	shore[3].AddDefence = 0;
	shore[3].AddHP = 0;
	shore[3].AddMaxHP = 0;
	shore[3].AddMP = 5;
	shore[3].AddMaxMP = 20;
	shore[3].AddSpeed = 0;

	//4��6���·�
	shore[4].Name = "�Ƽ�֮��";
	shore[4].Describe;
	shore[4].Location = 2;
	shore[4].Cost = 10;
	shore[4].AddAttack = 0;
	shore[4].AddDefence = 0.1;
	shore[4].AddHP = 100;
	shore[4].AddMaxHP = 200;
	shore[4].AddMP = 0;
	shore[4].AddMaxMP = 0;
	shore[4].AddSpeed = 0;

	shore[5].Name = "����֮��";
	shore[5].Describe;
	shore[5].Location = 2;
	shore[5].Cost = 10;
	shore[5].AddAttack = 0;
	shore[5].AddDefence = 0.1;
	shore[5].AddHP = 100;
	shore[5].AddMaxHP = 200;
	shore[5].AddMP = 0;
	shore[5].AddMaxMP = 0;
	shore[5].AddSpeed = 0;

	shore[6].Name = "������װ";
	shore[6].Describe;
	shore[6].Location = 2;
	shore[6].Cost = 10;
	shore[6].AddAttack = 0;
	shore[6].AddDefence = 0.1;
	shore[6].AddHP = 100;
	shore[6].AddMaxHP = 200;
	shore[6].AddMP = 0;
	shore[6].AddMaxMP = 0;
	shore[6].AddSpeed = 0;

	//7��9������
	shore[7].Name = "�޾�ս��";
	shore[7].Describe;
	shore[7].Location = 3;
	shore[7].Cost = 10;
	shore[7].AddAttack = 10;
	shore[7].AddDefence = 0;
	shore[7].AddHP = 0;
	shore[7].AddMaxHP = 0;
	shore[7].AddMP = 0;
	shore[7].AddMaxMP = 0;
	shore[7].AddSpeed = 0;

	shore[8].Name = "Ӱ��";
	shore[8].Describe;
	shore[8].Location = 3;
	shore[8].Cost = 10;
	shore[8].AddAttack = 20;
	shore[8].AddDefence = 0;
	shore[8].AddHP = 0;
	shore[8].AddMaxHP = 0;
	shore[8].AddMP = 0;
	shore[8].AddMaxMP = 0;
	shore[8].AddSpeed = 0;

	shore[9].Name = "����ս��";
	shore[9].Describe;
	shore[9].Location = 3;
	shore[9].Cost = 10;
	shore[9].AddAttack = 30;
	shore[9].AddDefence = 0;
	shore[9].AddHP = 0;
	shore[9].AddMaxHP = 0;
	shore[9].AddMP = 0;
	shore[9].AddMaxMP = 0;
	shore[9].AddSpeed = 0;

	//10��12��Ь��
	shore[10].Name = "�ط�֮ѥ";
	shore[10].Describe;
	shore[10].Location = 4;
	shore[10].Cost = 10;
	shore[10].AddAttack = 0;
	shore[10].AddDefence = 0;
	shore[10].AddHP = 0;
	shore[10].AddMaxHP = 0;
	shore[10].AddMP = 0;
	shore[10].AddMaxMP = 0;
	shore[10].AddSpeed = 5;

	shore[11].Name = "����սѥ";
	shore[11].Describe;
	shore[11].Location = 4;
	shore[11].Cost = 10;
	shore[11].AddAttack = 0;
	shore[11].AddDefence = 0;
	shore[11].AddHP = 0;
	shore[11].AddMaxHP = 0;
	shore[11].AddMP = 0;
	shore[11].AddMaxMP = 0;
	shore[11].AddSpeed = 5;

	shore[12].Name = "Ӱ��֮��";
	shore[12].Describe;
	shore[12].Location = 4;
	shore[12].Cost = 10;
	shore[12].AddAttack = 0;
	shore[12].AddDefence = 0;
	shore[12].AddHP = 0;
	shore[12].AddMaxHP = 0;
	shore[12].AddMP = 0;
	shore[12].AddMaxMP = 0;
	shore[12].AddSpeed = 5;

	shore[13].Name = "����֮ˮ";
	shore[13].Describe = "������100������ֵ";
	shore[13].Location = 0;
	shore[13].Cost = 10;
	shore[13].AddAttack = 0;
	shore[13].AddDefence = 0;
	shore[13].AddHP = 100;
	shore[13].AddMaxHP = 0;
	shore[13].AddMP = 0;
	shore[13].AddMaxMP = 0;
	shore[13].AddSpeed = 0;

	shore[14].Name = "��ɫ֮ˮ";
	shore[14].Describe;
	shore[14].Location = 0;
	shore[14].Cost = 10;
	shore[14].AddAttack = 0;
	shore[14].AddDefence = 0;
	shore[14].AddHP = 0;
	shore[14].AddMaxHP = 0;
	shore[14].AddMP = 10;
	shore[14].AddMaxMP = 0;
	shore[14].AddSpeed = 0;
}