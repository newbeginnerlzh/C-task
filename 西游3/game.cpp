#include"game.h"
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void color(const unsigned short textColor)      //自定义函根据参数改变颜色 
{
	if (textColor >= 0 && textColor <= 15)     //参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
	else   //默认的字体颜色是白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}





void game::game_init() {



	string background;
	color(2);
	cout << "故事背景" << endl;
	color(6);
	background = "1";// "灵根孕育源流生，心性修持大道生。盘古开天辟地之后，天地清浊分明，日月星辰逐渐显现，四象五行各司其职，天地间的万物因而生发。随着时间的推移，山川河岳自成其势，草木鸟兽依序而生，天地之气孕育万物，灵根随之而出。神兽仙禽、奇花异草在这初生的世界中各展其能，天地间弥漫着无尽的灵气与生机，宇宙万象从此展开。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");

	color(2);
	cout << "故事背景" << endl;
	color(6);
	background = "1";// "在这初开的天地中，万物有灵，皆可修炼。灵根者，受天地精华之养，体天地造化之力，故能通灵成道，修持大道。修行者或依山而居，或隐于深林，吸日月精华，参悟天地法则，求得长生不老、超凡入圣之道。然而，修行之路并非平坦，因果业力、欲望执念如影随形，唯有心性坚定者，方能超脱俗世，步入大道。正邪相生相克，万物在对立中演化平衡，修炼者需经历磨难，历经生死考验，方能得道成仙。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");

	color(2);
	cout << "故事背景" << endl;
	color(6);
	background = "1";// "欲究天地玄妙，解悟万物本源，还须细读《西游释厄传》。在九九八十一难中，唐僧师徒四人的心性修持与大道追寻，道尽了天地之大美，阐释了人生的无穷奥义。修行者唯有守心如一，方能窥见天地真理，步入永恒光明。这正是天地初开，灵根孕育，大道生成的无限循环与升华。欲知造化会元功，须看西游释厄传";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	color(5);
	cout << "请选择你想要使用的角色：" << endl;

	color(9);
	cout << "1.唐僧\t2.孙悟空\t3.猪八戒\t4.沙和尚" << endl;
	cin >> record.current_role;
	color(7);
	while (record.current_role < 1 || record.current_role>4) {
		cout << "没有此选项，请选择正确选项。" << endl;
		cin >> record.current_role;
	}

	record.current_place = record.current_role;
	//init_show();


}

void game::game_begin() {
	record.status = 0;
	while (true) {
		int choice = 0;
		switch (record.status) {
		case system_menu:		//新的故事，旧的回忆，封建归隐，关于
			show_surface();
			cout << endl << endl;
			cout << "1.开始游戏\t2.退出游戏" << endl;
			cin >> choice;
			while (choice < 1 || choice>2) {
				cout << "请输入正确选项。" << endl;
				cin >> choice;
			}
			if (choice == 1) {
				init_place();
				init_role();
				init_npc();
				
				load_shore();
				load_roleSkill();
				load_enemy();
				load_enemySkill();
				system("cls");
				game_init();
				record.status = player_adven;

			}
			else {
				record.status = 20;
			}
			break;
		case playing_sys_menu:
			break;
		case player_adven:
			system("cls");
			init_show();
			cout << "1.交谈	2.观察	3.攻击	4.拾取	5.赶路	6.状态	7.退出并存档	8.地图  9.商店" << endl;
			cin >> choice;
			while (choice < 1 || choice>8) {
				cout << "请输入正确选项。" << endl;
				cin >> choice;
			}
			if (choice == 1) {
				if (place[record.current_place].npc_index == 0) {
					color(4);
					cout << "这里没有人可以交谈。" << endl;
					color(7);
					system("pause");
					record.status = player_adven;
				}
				else {
					color(13);
					cout << "你可以和" << npc[place[record.current_place].npc_index].name << "交谈" << endl;
					record.status = talk_with_npc;
					color(7);
				}

			}
			else if (choice == 2) {

				record.status = watch_npc;
			}
			else if (choice == 3) {
				record.status = attack_npc;
			}
			else if (choice == 4) {

			}

			else if (choice == 5) {
				record.status = show_exits;
			}
			else if (choice == 6) {
				record.status = player_state;
			}
			else if (choice == 7) {
				record.status = 20;
			}
			else if (choice == 8) {
				color(6);
				cout << "                 ———— * ————————————*——————————                    --———*————" << endl;
				cout << "               /    高峪村        狮驼岭     \\                  /   隐雾山    \\ " << endl;
				cout << "              /                               \\                /               \\ " << endl;
				cout << "             *                                  *—————————————*                 * 终点：雷音寺" << endl;
				cout << "起始地-----白虎岭                           火焰山       盘丝洞              /" << endl;
				cout << "              \\                              /                 \\              /" << endl;
				cout << "               \\                            /                   \\            /" << endl;
				cout << "                 *——————————————————*———————                     ———————*———" << endl;
				cout << "              号山枯松涧         翠云山                              天竺国" << endl;
				system("pause");
				color(7);
			}
			else if (choice == 9) {
				record.status = trading;
			}

			break;
		case show_exits:
			cout << "当前位置位于：" << place[record.current_place].Name << endl;
			cout << "你可以去到：" << endl;
			int i;
			for (i = 1; i <= place[record.current_place].connectnum; i++) {
				cout << i << "." << place[place[record.current_place].connect_place[i]].Name << endl;
			}
			cout << i << ".退出" << endl;
			cin >> choice;
			while (choice<1 || choice>i) {
				cout << "请输入正确的选项。" << endl;
				cin >> choice;
			}
			if ((place[record.current_place].connect_place[choice] == 12 || place[record.current_place].connect_place[choice] == 13) && npc[4].taskstatus != 3) {
				cout << "你找不到去往此地的路" << endl;
				system("pause");

			}
			else if (place[record.current_place].connect_place[choice] == 10) {
				if (true) {  //你拥有芭蕉扇
					record.current_place = place[record.current_place].connect_place[choice];
				}
				else {
					cout << "此处的三昧真火使得你无法前往，需要拥有芭蕉扇才可以通过。" << endl;
					system("pause");
				}
			}
			else if (choice == i) {
				record.status = player_adven;
			}
			else
				record.current_place = place[record.current_place].connect_place[choice];
			system("cls");
			record.status = player_adven;


			break;
		case talk_with_npc:
			cout << "你是否选择与之交谈？" << endl;
			cout << "1.是\t2.否" << endl;
			cin >> choice;
			while (choice < 1 || choice>2) {
				cout << "请输入正确选项。" << endl;
				cin >> choice;
			}
			system("cls");

			if (choice == 1)
				select_talk(place[record.current_place].npc_index);
			system("pause");
			record.status = player_adven;
			break;
		case attack_npc:
			fight(show_enemy());
			system("pause");
			system("cls");
			record.status = player_adven;
			break;

		case player_state:
			while (true) {
				cout << "1.人物属性  2.背包及装备  3.退出" << endl;
				cin >> i;
				if (i == 1) {
					show_state();
				}
				else if (i == 2) {
					while (true) {
						system("cls");
						show_bag();
						show_myeq();
						cout << "1.配置装备  2.脱下装备  3.退出" << endl;
						cin >> i;
						if (i == 1) {
							equip();
						}
						else if (i == 2) {
							disequip();
						}
						else if (i == 3) {
							break;
						}
						system("pause");
					}
				}
				else if (i == 3) {
					record.status = player_adven;
					break;
				}
				system("pause");
				system("cls");
			}
			system("cls");
			record.status = player_adven;
			break;

		case watch_npc:
			break;


		case trading:
			int input;
			while (true) {
				system("cls");
				show_eq();
				cout << "1.查看详细信息  2.查看背包  3.购买  4.出售  5.退出" << endl;
				cin >> i;
				if (i == 1) {
					cout << "请输入要查询的装备" << endl;
					cin >> input;
					show_eqdate(input);
				}
				else if (i == 2) {
					show_bag();
				}
				else if (i == 3) {
					buy();
				}
				else if (i == 4) {
					sell();
				}
				else if (i == 5) {
					break;
				}
				system("pause");
			}
			system("cls");
			record.status = player_adven;
			break;


			if (record.status == 20) {
				cout << "请问你是否要保存游戏进度?" << endl;
				cin >> choice;
				while (choice < 1 || choice>8) {
					cout << "请输入正确选项。" << endl;
					cin >> choice;
				}
				if (choice == 1) {
					string end = "正在保存并退出游戏...";
					for (int i = 0; i < end.length(); i++) {
						Sleep(10);
						cout << end[i];
					}
					break;
				}
				else {
					string end = "正在退出游戏...";
					for (int i = 0; i < end.length(); i++) {
						Sleep(10);
						cout << end[i];
					}
					cout << endl;
					break;
				}
			}
		}
	}
}

void game::init_show() {
	color(6);
	if (role[record.current_role].place_index[record.current_place] == 1) {
		role[record.current_role].place_index[record.current_place] = 0;
		cout << "欢迎你来到" << place[record.current_place].Name << endl;
		for (int i = 0; i < place[record.current_place].Describe.length(); i++) {
			//Sleep(10);
			cout << place[record.current_place].Describe[i];
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	color(3);
	cout << "当前人物属性\t姓名：";
	color(9);
	cout << role[record.current_role].Name;
	color(3);
	cout << "\t等级：" << role[record.current_role].Exp << endl;
	cout << "生命：" << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "\t蓝量：" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
	cout << "攻击：" << role[record.current_role].Attack << "\t防御：" << role[record.current_role].Defence << "\t速度：" << role[record.current_role].Speed << "\t金钱：" << role[record.current_role].Money << endl;
	cout << "当前所在地点：";
	color(6);
	cout << place[record.current_place].Name << endl;
	color(7);
}

void game::init_role() {
	role = new Role[5];

	role[2].Name = "孙悟空";
	role[2].Describe = "你是天地孕育的灵猴，拜师于菩提祖师，习得神通。却因生性顽劣，大闹天庭，闯下弥天大祸。受观音菩萨和如来佛祖点化，前往西天造化自我。";
	role[2].Attack;//普攻值
	for (int i = 1, j = 4; i <= 3, j <= 6; i++, j++)
	{
		role[2].skill_index[i] = j;
	}
	role[2].Money;//金币，用于买装备
	for (int i = 0; i < 15; i++)
	{
		role[2].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[2].MyEquipment_index[i] = 0;
	}
	role[2].HP;//生命值
	role[2].Max_Hp;//当前HP阈值
	role[2].Defence;//护盾
	role[2].MP;//蓝量
	role[2].Max_Mp;//当前MP阈值
	role[2].Speed;//速度
	role[2].Exp;//经验值
	role[2].Level;//等级
	for (int i = 1; i <= 14; i++) {
		role[2].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[2].taskstatus[i] = 1;
	}

	role[3].Name = "猪八戒";
	role[3].Describe = "你本是天上的天蓬元帅，威风凛凛，相貌堂堂。却因醉酒后调戏了嫦娥，被贬下凡，以猪的样子示人，为重回天上，弥补自己犯下的过错，你踏上了前往西天取经的道路。";
	role[3].Attack;//普攻值
	for (int i = 1, j = 7; i <= 3, j <= 9; i++, j++)
	{
		role[3].skill_index[i] = j;
	}
	role[3].Money;//金币，用于买装备
	for (int i = 0; i < 15; i++)
	{
		role[3].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[3].MyEquipment_index[i] = 0;
	}
	role[3].HP;//生命值
	role[3].Max_Hp;//当前HP阈值
	role[3].Defence;//护盾
	role[3].MP;//蓝量
	role[3].Max_Mp;//当前MP阈值
	role[3].Speed;//速度
	role[3].Exp;//经验值
	role[3].Level;//等级
	for (int i = 1; i <= 14; i++) {
		role[3].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[3].taskstatus[i] = 1;
	}

	role[4].Name = "沙和尚";
	role[4].Describe = "幼年的你得遇真人，修得三千功德圆满，被玉帝亲封为卷帘大将。却因为在蟠桃会上失手打翻了琉璃盏，被贬下流沙河，以人为食。经观音菩萨点化，欲皈依佛门，前往西天取经。";
	for (int i = 1, j = 10; i <= 3, j <= 12; i++, j++)
	{
		role[4].skill_index[i] = j;
	}
	role[4].Money;//金币，用于买装备
	for (int i = 0; i < 15; i++)
	{
		role[4].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[4].MyEquipment_index[i] = 0;
	}
	role[4].HP;//生命值
	role[4].Max_Hp;//当前HP阈值
	role[4].Defence;//护盾
	role[4].MP;//蓝量
	role[4].Max_Mp;//当前MP阈值
	role[4].Speed;//速度
	role[4].Exp;//经验值
	role[4].Level;//等级
	for (int i = 1; i <= 14; i++) {
		role[4].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[4].taskstatus[i] = 1;
	}

	role[1].Name = "唐僧";
	role[1].Describe = "你生长于东土大唐，是如来佛祖的二弟子金蝉子转世。现如今百姓饱经磨砺苦难，民不聊生。受唐太宗之命，亦是为实现自我的宗教信仰和使命，也为了救赎自己前世的过错，你毅然决然地踏上前往西天取经的道路，以普度众生。";
	role[1].Attack = 10;//普攻值
	
	for (int i = 1, j = 1; i <= 3, j <= 3; i++, j++)
	{
		role[1].skill_index[i] = j;
	}
	role[1].Money = 100;//金币，用于买装备
	for (int i = 0; i < 15; i++)
	{
		role[1].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[1].MyEquipment_index[i] = 0;
	}
	role[1].HP = 100;//生命值
	role[1].Max_Hp = 100;//当前HP阈值
	role[1].Defence = 0.2;//护盾
	role[1].MP = 20;//蓝量
	role[1].Max_Mp = 50;//当前MP阈值
	role[1].Speed = 10;//速度
	role[1].Exp = 0; //经验值
	role[1].Level = 1;//等级


	for (int i = 1; i <= 14; i++) {
		role[1].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[1].taskstatus[i] = 1;
	}
}

void game::init_npc() {
	npc = new Npc[6];
	npc[1].name = "土地公";
	npc[1].goodId = 20;
	npc[1].task = "让白虎岭恢复如初";
	npc[1].tdescribe = "打败白骨精";
	npc[1].tasknum = 1;
	npc[1].taskstatus = 1;

	npc[2].name = "小翠的父亲";
	npc[2].goodId = 20;
	npc[2].task = "解救小翠";
	npc[2].tdescribe = "打败青毛狮子精，将小翠拯救出来。";
	npc[2].tasknum = 2;
	npc[2].taskstatus = 1;

	npc[3].name = "小翠";
	npc[3].goodId = 20;
	npc[3].tasknum = 0;

	npc[4].name = "蜘蛛精";
	npc[4].goodId = 20;
	npc[4].task = "走出迷宫";
	npc[4].tdescribe = "打败青毛狮子精，将小翠拯救出来。";
	npc[4].tasknum = 3;
	npc[4].taskstatus = 1;

	npc[5].name = "如来佛祖";
	npc[5].goodId = 20;
	npc[5].task = "符合佛教的四圣谛和八正道";
	npc[5].tdescribe = "无";
	npc[5].tasknum = 4;
	npc[5].taskstatus = 1;
}

void game::init_place() {
	place = new Place[15];
	place[1].Name = "长安";
	place[1].Describe = "长安城气势恢宏，城墙高耸延绵，守卫森严。城内街道纵横交错，集市繁华，商贾云集，行人如织，店铺鳞次栉比，货物琳琅满目，尽显繁荣昌盛。宫殿楼阁巍峨壮丽，红墙黄瓦在阳光下熠熠生辉，花木扶疏，池水清澈，处处散发着皇家气派与威严。长安四季分明，春花秋实，年年充满生机，作为大唐的政治、经济、文化中心，这座千年古城展现出无与伦比的富庶与辉煌。";
	place[1].comefirst = 1;
	place[1].npc_index = 0;
	place[1].enemy_index = 0;
	place[1].connectnum = 1;
	place[1].connect_place[1] = 5;
	place[2].Name = "五指山";
	place[2].Describe = "五指山巍峨险峻，宛如五根巨大的手指直指苍穹，山体光滑如玉，显得苍凉而荒芜。整座山常年笼罩在阴云之下，周围环境阴森恐怖，天空昏暗无光，只有风声凄厉地呼啸，仿佛在诉说着被镇压在此的孙悟空的无奈与悲怆。山脚下荒无人烟，寂静得令人窒息，五指山不仅象征着自然的险恶，更是如来佛祖镇压孙悟空的威严所在，提醒着世人天道的不可违抗。";
	place[2].comefirst = 1;
	place[2].npc_index = 0;
	place[2].enemy_index = 0;
	place[2].connectnum = 1;
	place[2].connect_place[1] = 5;
	place[3].Name = "高老庄";
	place[3].Describe = "高老庄坐落在一片广袤的田园中，周围环绕着翠绿的山丘和丰饶的田野，村道蜿蜒，炊烟袅袅，洋溢着田园牧歌般的宁静气息。村中房屋错落有致，农田里作物茁壮生长，牛羊悠闲地踱步，村民们过着朴实安宁的生活。村中央的高家大院占地广阔，青砖黛瓦，院落整洁，门前石狮威严，彰显着主人的显赫地位。无论春夏秋冬，高老庄都展现出一派秀丽祥和的自然风光。";
	place[3].comefirst = 1;
	place[3].npc_index = 0;
	place[3].enemy_index = 0;
	place[3].connectnum = 1;
	place[3].connect_place[1] = 5;
	place[4].Name = "流沙河";
	place[4].Describe = "流沙河位于荒凉的西域，河水湍急而浑浊，水面上常年笼罩着一层薄薄的雾气，显得阴森恐怖。河岸两旁荒芜寂静，杂草丛生，怪石嶙峋，仿佛很久没有人迹踏足。河水中不时泛起诡异的波纹，隐隐透出一股令人不寒而栗的气息。流沙河水底深不见底，水中蕴藏着无数危险，沙悟净曾在此作乱，令人闻之色变。这片区域荒凉、神秘，仿佛与世隔绝，是一个让人望而生畏的地方。";
	place[4].npc_index = 0;
	place[4].comefirst = 1;
	place[4].enemy_index = 0;
	place[4].connectnum = 1;
	place[4].connect_place[1] = 5;
	place[5].Name = "白虎岭";
	place[5].Describe = "经过了漫长的路程，你来到了白虎岭，这里地势险峻，山岭连绵起伏，覆盖着稀疏的草木，显得荒凉而孤寂。山中常年被浓密的白雾笼罩，仿佛永远处在一种朦胧的阴影之中，使人无法看清前方的道路。路旁的枯树扭曲丛生，像是怪兽的爪牙，令人不寒而栗。岩石嶙峋不平，山路崎岖难行，每一步都充满了危险。空气中弥漫着一股森冷的寒意，仿佛隐含着无数潜伏的危机。偶尔传来的猛兽咆哮声，更让人感到这片山岭充满了未知的恐怖。四周寂静得诡异，只有风穿过枯树的声音，仿佛在低声诉说着这片土地上的危险与凶险。";
	place[5].comefirst = 1;
	place[5].npc_index = 1;
	place[5].enemy_index = 1;
	place[5].connectnum = 6;
	place[5].connect_place[1] = 1;
	place[5].connect_place[2] = 2;
	place[5].connect_place[3] = 3;
	place[5].connect_place[4] = 4;
	place[5].connect_place[5] = 6;
	place[5].connect_place[6] = 8;

	place[6].Name = "一条蜿蜒的山路";
	place[6].Describe = "这里偏僻无比，只有一户人家在此居住。";
	place[6].comefirst = 1;
	place[6].npc_index = 2;
	place[6].enemy_index = 0;
	place[6].connectnum = 2;
	place[6].connect_place[1] = 5;
	place[6].connect_place[2] = 7;

	place[7].Name = "狮子山谷";
	place[7].Describe = "四周群山环绕，山石嶙峋，植被稀疏，透出几分荒芜与冷寂。山谷中常年笼罩着一股诡异的雾气，空气中弥漫着一股潮湿而腐朽的气味，令人感到压抑不安。谷底的洞穴深邃幽暗，洞口被藤蔓杂草掩映，散发着阴冷的气息。洞内隐隐传出野兽的低吼声，回荡在空旷的山谷中，显得格外恐怖。整个地方充满了危险与神秘，仿佛是大自然中隐藏的凶险之地。";
	place[7].comefirst = 1;
	place[7].npc_index = 3;
	place[7].enemy_index = 2;
	place[7].connectnum = 2;
	place[7].connect_place[1] = 6;
	place[7].connect_place[2] = 10;

	place[8].Name = "火云洞";
	place[8].Describe = "门前，见有一座石碣，上镌八个大字，乃是“号山枯松涧火云洞”。那壁厢一群小妖，在那里轮枪舞剑的跳风顽耍。";
	place[8].comefirst = 1;
	place[8].npc_index = 0;
	place[8].enemy_index = 3;
	place[8].connectnum = 2;
	place[8].connect_place[1] = 5;
	place[8].connect_place[2] = 9;

	place[9].Name = "芭蕉洞";
	place[9].Describe = "芭蕉洞外，被茂密的芭蕉树环绕，这些芭蕉树不同于凡间的植物，它们高大挺拔，叶子宽大如扇，仿佛能遮天蔽日。洞口或许隐藏在这片芭蕉林之中，不为凡人所见，只有得道高人或有缘者才能寻得其踪。";
	place[9].comefirst = 1;
	place[9].npc_index = 0;
	place[9].enemy_index = 4;
	place[9].connectnum = 2;
	place[9].connect_place[1] = 8;
	place[9].connect_place[2] = 10;

	place[10].Name = "火焰山";
	place[10].Describe = "四周寸草不生，一片焦土，整座山都被烈火焚烧，烟雾缭绕，热浪滚滚。山上的岩石呈现出红色、橙色和黑色，仿佛被熔岩覆盖。阳光照射下来，整座山犹如熊熊燃烧的火焰，令人望而生畏 ";
	place[10].comefirst = 1;
	place[10].npc_index = 0;
	place[10].enemy_index = 0;
	place[10].connectnum = 3;
	place[10].connect_place[1] = 7;
	place[10].connect_place[2] = 9;
	place[10].connect_place[3] = 11;

	place[11].Name = "盘丝洞";
	place[11].Describe = "只见，峦头高耸接云烟，地脉遥长通海岳。门近石桥，九曲九湾流水顾；园栽桃李，千株千颗斗穠华。藤薜挂悬三五树，芝兰香散万千花。远观洞府欺蓬岛，近睹山林压太华。正是妖仙寻隐处，更无邻舍独成家。";
	place[11].comefirst = 1;
	place[11].npc_index = 4;
	place[11].enemy_index = 0;
	place[11].connectnum = 3;
	place[11].connect_place[1] = 10;
	place[11].connect_place[2] = 12;
	place[11].connect_place[3] = 13;

	place[12].Name = "隐雾山";
	place[12].Describe = "此处为隐雾山。山真好山，细看色班班。顶上云飘荡，崖前树影寒。飞禽淅沥，走兽凶顽。林内松千干，峦头竹几竿。吼叫是苍狼夺食，咆哮是饿虎争餐。野猿长啸寻鲜果，麋鹿攀花上翠岚。风洒洒，水潺潺，时闻幽鸟语间关。几处藤萝牵又扯，满溪瑶草杂香兰。磷磷怪石，削削峰岩。狐狢成群走，猴猿作队顽。行客正愁多险峻，奈何古道又湾还。 ";
	place[12].comefirst = 1;
	place[12].npc_index = 0;
	place[12].enemy_index = 5;
	place[12].connectnum = 2;
	place[12].connect_place[1] = 11;
	place[12].connect_place[2] = 14;

	place[13].Name = "天竺国";
	place[13].Describe = "天竺国，这里是一个繁荣富庶的王国，国王虔诚信佛，百姓安居乐业。这里环境优美，山清水秀，宫殿巍峨壮丽，充满了中亚风情的典雅气息。 ";
	place[13].comefirst = 1;
	place[13].npc_index = 0;
	place[13].enemy_index = 6;
	place[13].connectnum = 1;
	place[13].connect_place[1] = 11;
	place[13].connect_place[2] = 14;

	place[14].Name = "雷音寺";
	place[14].Describe = "天竺国，这里是一个繁荣富庶的王国，国王虔诚信佛，百姓安居乐业。这里环境优美，山清水秀，宫殿巍峨壮丽，充满了中亚风情的典雅气息。 ";
	place[14].comefirst = 1;
	place[14].npc_index = 1;
	place[14].enemy_index = 0;
	place[14].connectnum = 2;
	place[14].connect_place[1] = 12;
	place[14].connect_place[2] = 13;
}



void game::select_talk(int num) {
	int choice = 0;
	if (num == 1 || num == 2 || num == 3)
		task_status(num);
	color(11);
	if (num == 1 && role[record.current_role].taskstatus[num] == 1) {
		color(11);
		cout << npc[num].name << ":大人，贫道乃此地的土地神，现特来告知此岭上的凶险。此地名为白虎岭，原本也算风平浪静，但自从那白骨精占据此地，这里便成了生灵的炼狱！" << endl;
		system("pause");
		cout << "那白骨精本是山中枯骨，因机缘巧合修炼成妖，已有千年道行。此妖心肠狠毒，最喜迷惑过路人，将其生吃，以求长生不老。她擅长变化，每次现身都以不同模样，诱骗无辜之人，残害性命，实在是罪大恶极！贫道多次劝阻，但她根本不听，反而更加肆无忌惮。望四位大人行事谨慎，切莫被她的伪装所迷惑。只要能除掉此妖，不仅可以为这片山岭除去灾祸，也能救下无数将要遭难的生灵！" << endl;
		system("pause");
		color(4);
		cout << "是否选择接受任务，帮助白虎岭恢复安宁？" << endl;
		cout << "1.接受任务\t2.拒绝任务" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "请输入正确选项。" << endl;
			cin >> choice;
		}
		if (choice == 1) {
			role[record.current_role].taskstatus[num] = 2;
		}

	}
	else if (num == 1 && role[record.current_role].taskstatus[num] == 2) {
		color(11);
		cout << place[record.current_role].Name << "希望大人尽快还白虎岭往日太平。" << endl;
		color(7);
	}
	else if (num == 1 && role[record.current_role].taskstatus[num] == 3) {
		color(11);
		cout << "多谢" << npc[num].name << "帮助白虎岭恢复太平。" << endl;
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 1) {
		color(11);
		cout << npc[num].name << ":道长，我的女儿小翠今天独自一人去了邻村，至今未归，恐怕是遇到了青毛狮子精，恳求道长帮忙去打败狮子精，救出我的女儿。" << endl;
		system("pause");
		color(4);
		cout << "是否选择接受任务，救出小翠？" << endl;
		cout << "1.接受任务\t2.拒绝任务" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "请输入正确选项。" << endl;
			cin >> choice;
		}
		if (choice == 1) {
			role[record.current_role].taskstatus[num] = 2;
		}
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 2) {
		cout << npc[num].name << "希望大人尽快救回我的女儿。" << endl;
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 3) {
		cout << "多谢" << role[record.current_role].Name << "帮助救回我的女儿。" << endl;
	}
	else if (num == 3 && role[record.current_role].taskstatus[num] == 1) {
		cout << npc[num].name << "认为你也是妖怪的同伙，对你一言不发。" << endl;
		system("pause");

		cout << "你向她解释了你的来意，她十分感动。" << endl;
		npc[num].taskstatus = 3;

	}
	else if (num == 3 && role[record.current_role].taskstatus[num] == 3) {
		cout << "多谢" << role[record.current_role].Name << "帮助救我脱离魔掌。" << endl;
	}
	else if (num == 4 && role[record.current_role].taskstatus[num] == 1) {
		cout << npc[num].name << "：盘丝洞错综复杂，普通人想要通过，简直痴心妄想，所以我特意设下考验，凡能够走入此迷宫者，我会带他走出盘丝洞。" << endl;
		system("pause");
		color(4);
		cout << "是否选择接受考验" << endl;
		cout << "1.接受任务\t2.拒绝任务" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "请输入正确选项。" << endl;
			cin >> choice;
		}

		while (choice == 1) {
			color(7);
			if (Labyrinth() == 1)
				role[record.current_role].taskstatus[num] = 3;
			else {
				cout << "是否重新挑战？" << endl;
				cout << "1.是\t2.否" << endl;
				cin >> choice;
				while (choice < 1 || choice>2) {
					cout << "请输入正确选项。" << endl;
					cin >> choice;
				}
			}
		}
	}
	else if (num == 4 && role[record.current_role].taskstatus[num] == 3) {
		cout << "你通过了考验，你在盘丝洞可以畅通无阻。" << endl;
	}


	else if (num == 5) {
		cout << "你迫不及待地登上雷音寺，面见如来佛祖。他们走进雷音寺大殿，见到佛祖端坐在金色莲花座上，佛光普照，显得无比庄严。" << endl;
		system("pause");
		if (role[record.current_role].taskstatus[num] == 1) {
			if (role[record.current_role].taskstatus[1] == 3 && role[record.current_role].taskstatus[2] == 3) {
				if (record.current_role == 1) {
					cout << "你说：弟子唐三藏历经艰辛，终于来到西天，恳请佛祖赐予真经。" << endl;
					system("pause");
					cout << "如来佛祖（微笑着点头）：善哉，善哉。你们师徒四人不畏艰险，心怀坚定，终于完成了取经之旅。此行的艰难困苦，都是对你们心性的考验，汝等皆通过此劫，实属不易。" << endl;
				}
				else if (record.current_role == 2) {
					cout << "你（上前一步，双手合十）：佛祖，俺老孙一路降妖除魔，可算尽心尽力。如今终于见到佛祖，请求赐予真经，让我们早日回到东土，造福众生。" << endl;
					system("pause");
					cout << "如来佛祖：悟空，你性情刚烈，虽然多有顽劣之处，但一路上护持唐僧，功不可没。你们所取的真经，乃是佛法精髓，需得用心领悟，才能普渡众生。" << endl;

				}
				else if (record.current_role == 3) {
					cout << "你（搓着手，谦虚地低头）：佛祖，我这一路上虽然懒惰了一些，但也没少出力。希望佛祖能宽恕我的过失，赐予真经，让我们早日回到东土，造福众生。" << endl;
					system("pause");
					cout << "如来佛祖（慈悲地看着八戒）：八戒，你虽然贪吃懒惰，但也能及时悔悟。你心中尚存善念，也当得福报。你们的功德，皆有定数。" << endl;
				}
				else if (record.current_role == 4) {
					cout << "你（恭敬地行礼）：佛祖，弟子沙悟净虽为末徒，但愿追随师父，一同将佛法传至东土，为众生造福。" << endl;
					system("pause");
					cout << "如来佛祖：沙僧，你心性忠厚，默默付出，虽少言语，但功德无量。今日，尔等完成大愿，皆为佛门有缘之人。" << endl;
				}
				cout << "如来挥手示意，众罗汉捧出几卷金光闪闪的佛经，交予你。然后目送你带着真经，心满意足地离开雷音寺，踏上了归途。" << endl;
				system("pause");
			}

			else if (role[record.current_role].taskstatus[1] == 2 || role[record.current_role].taskstatus[2] == 2) {
				cout << "如来佛祖：" << role[record.current_role].Name << "，其实取经途中也是有许多乐趣的，结果固然重要，但沿途的风景也很美丽，不妨主动帮助别人，这也是我佛存在的意义，希望你取回真经后，可以领悟其中的四圣谛和八正道。" << endl;
				system("pause");
				cout << "如来面露出一丝失望之色，对你说：佛只渡有缘人，这经与你无缘" << endl;
				system("pause");
			}


			else if (role[record.current_role].taskstatus[1] == 1 || role[record.current_role].taskstatus[2] == 1) {
				cout << "如来佛祖：" << role[record.current_role].Name << "，其实取经途中也是有许多乐趣的，结果固然重要，但沿途的风景也很美丽，不妨主动帮助别人，这也是我佛存在的意义，希望你取回真经后，可以领悟其中的四圣谛和八正道。" << endl;
				system("pause");
				cout << "如来挥手示意，众罗汉捧出几卷金光闪闪的佛经，交予你。然后目送你带着真经，离开雷音寺，踏上了归途。" << endl;
				system("pause");
			}
			role[record.current_role].taskstatus[num] == 3;
		}
		else if (role[record.current_role].taskstatus[num] == 3) {
			cout << "如来面说：你回去吧，佛只渡有缘人，这经与你无缘" << endl;
			system("pause");
		}

	}

	color(7);


}

void show_surface()
{
	color(6);
	cout << "        西西西西西西西西西西西　　游　　游　　　游　　　　　　　　释释　释释释释释　　　厄厄厄厄厄厄厄厄厄厄　　　　传　　　　传" << endl;
	cout << "	      西　　　西　　　　　　游游游游游　游游游游　　释释释　　　　释　释　　　　厄　　　　　　　　　　　　　传　传传传传传传传" << endl;
	cout << "	      西　　　西　　　　　　　　游　　游　　　　　　释　释　释　　　释　　　　　厄　　　　　　　　　　　　传　　　　传" << endl;
	cout << "	西西西西西西西西西西西　　游　　游　　　游游游游　　　释释释　　释释　释释　　　厄　　厄厄厄厄厄厄　　　　传　　　　传    " << endl;
	cout << "	西　　西　　　西　　西　　　游　游游游　　　　游　　释释释释释　　　释　　　　　厄　　厄　　　　厄　　　传传　传传传传传传传传" << endl;
	cout << "	西　　西　　　西　　西　　　　　游　游　　　游　　　　　释　　　释释释释释　　　厄　　厄　　　　厄　　　　传　　　传" << endl;
	cout << "	西　　西　　　西　　西　　　　　游　游　　　游　　　　释释释　　　　释　　　　　厄　　厄　　　　厄　　　　传　　传传传传传传传" << endl;
	cout << "	西　西　　　　西西西西　　　游　游　游　游游游游　　　释释释　　　　释　　　　　厄　　厄　　厄厄厄　　　　传　　　　　　　　传" << endl;
	cout << "	西西　　　　　　　　西　　　游　游　游　　　游　　　释　释　释　释释释释释　　　厄　　厄　　　　　　　　　传　　　　传　　传" << endl;
	cout << "	西　　　　　　　　　西　　　游　游　游　　　游　　　　　释　　　　　释　　　　厄　　　厄　　　　　厄　　　传　　　　　传传" << endl;
	cout << "	西西西西西西西西西西西　　游　游　游游　　游游　　　　　释　　　　　释　　　　厄　　　厄厄厄厄厄厄厄　　　传　　　　　　传" << endl;
	color(9);
	cout << '\t' << '\t' << '\t' << '\t';
	cout << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "       游戏制作信息" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2024夏季学期c++课程设计" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   李同学、两位梁同学、廉同学与刘同学" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t';
	color(7);
}

void game::task_status(int num)
{
	if (num == 1 && role[record.current_role].taskstatus[num] == 2) {
		if (true) {  //判断敌人血量是否为0
			role[record.current_role].taskstatus[num] == 3;
		}
	}
	else if ((num == 2 && role[record.current_role].taskstatus[num] == 2) || (num == 3 && role[record.current_role].taskstatus[num] == 2)) {
		if (true) {
			role[record.current_role].taskstatus[2] == 3;
			role[record.current_role].taskstatus[3] == 3;
		}
	}
}



