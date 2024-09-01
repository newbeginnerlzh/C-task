#pragma once
#include<bits/stdc++.h>
#include"place.h"
#include"role.h"

using namespace std;





class game {
public:
	void game_init();
	void game_begin();
	void init_place();
	void init_show();
	void init_role();
	void init_npc();
	void select_talk(int num);
	void task_status(int num);

public:
	Place* place;
	Role* role;
	Npc* npc;

};


int Labyrinth();
void show_surface();

void color(const unsigned short textColor);
