#pragma once
#include<bits/stdc++.h>

using namespace std;

class Good {
public:
	void operator= (Good goods);

public:
	string Name;	//��Ʒ����
	string Describe;	//��Ʒ����
	short Location;	//����װ����λ�á�0-ͷ��1-��2-�֣�3-��
	short Cost;		//ֵ����Ǯ

	short AddAttack;	//���ӹ���
	short AddDefence;	//���ӷ���
	short AddHp;		//����Hp
	short AddMaxHp;	//����max HP
	short AddMp;		//����Mp
	short AddMaxMp;	//����max MP
	short AddSpeed;	//�����ٶ�
};