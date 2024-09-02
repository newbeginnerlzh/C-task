#include"game.h"
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void color(const unsigned short textColor)      //�Զ��庯���ݲ����ı���ɫ 
{
	if (textColor >= 0 && textColor <= 15)     //������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //��һ���������ı�������ɫ
	else   //Ĭ�ϵ�������ɫ�ǰ�ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}





void game::game_init() {



	string background;
	color(2);
	cout << "���±���" << endl;
	color(6);
	background = "1";// "�������Դ�����������޳ִ�������̹ſ���ٵ�֮��������Ƿ����������ǳ������֣��������и�˾��ְ����ؼ�������������������ʱ������ƣ�ɽ�������Գ����ƣ���ľ����������������֮��������������֮�������������ݡ��滨�����������������и�չ���ܣ���ؼ��������޾�����������������������Ӵ�չ����";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");

	color(2);
	cout << "���±���" << endl;
	color(6);
	background = "1";// "�������������У��������飬�Կ�����������ߣ�����ؾ���֮����������컯֮��������ͨ��ɵ����޳ִ���������߻���ɽ���ӣ����������֣������¾�����������ط�����ó������ϡ�������ʥ֮����Ȼ��������֮·����ƽ̹�����ҵ��������ִ����Ӱ���Σ�Ψ�����Լᶨ�ߣ����ܳ�������������������а������ˣ������ڶ������ݻ�ƽ�⣬�������辭��ĥ�ѣ������������飬���ܵõ����ɡ�";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");

	color(2);
	cout << "���±���" << endl;
	color(6);
	background = "1";// "�����������������ﱾԴ������ϸ���������Ͷ򴫡����ھžŰ�ʮһ���У���ɮʦͽ���˵������޳�����׷Ѱ�����������֮������������������������塣������Ψ��������һ�����ܿ�������������������������������س��������������������ɵ�����ѭ������������֪�컯��Ԫ�����뿴�����Ͷ�";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	color(5);
	cout << "��ѡ������Ҫʹ�õĽ�ɫ��" << endl;

	color(9);
	cout << "1.��ɮ\t2.�����\t3.��˽�\t4.ɳ����" << endl;
	cin >> record.current_role;
	color(7);
	while (record.current_role < 1 || record.current_role>4) {
		cout << "û�д�ѡ���ѡ����ȷѡ�" << endl;
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
		case system_menu:		//�µĹ��£��ɵĻ��䣬�⽨����������
			show_surface();
			cout << endl << endl;
			cout << "1.��ʼ��Ϸ\t2.�˳���Ϸ" << endl;
			cin >> choice;
			while (choice < 1 || choice>2) {
				cout << "��������ȷѡ�" << endl;
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
			cout << "1.��̸	2.�۲�	3.����	4.ʰȡ	5.��·	6.״̬	7.�˳����浵	8.��ͼ  9.�̵�" << endl;
			cin >> choice;
			while (choice < 1 || choice>8) {
				cout << "��������ȷѡ�" << endl;
				cin >> choice;
			}
			if (choice == 1) {
				if (place[record.current_place].npc_index == 0) {
					color(4);
					cout << "����û���˿��Խ�̸��" << endl;
					color(7);
					system("pause");
					record.status = player_adven;
				}
				else {
					color(13);
					cout << "����Ժ�" << npc[place[record.current_place].npc_index].name << "��̸" << endl;
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
				cout << "                 �������� * ������������������������*��������������������                    --������*��������" << endl;
				cout << "               /    ������        ʨ����     \\                  /   ����ɽ    \\ " << endl;
				cout << "              /                               \\                /               \\ " << endl;
				cout << "             *                                  *��������������������������*                 * �յ㣺������" << endl;
				cout << "��ʼ��-----�׻���                           ����ɽ       ��˿��              /" << endl;
				cout << "              \\                              /                 \\              /" << endl;
				cout << "               \\                            /                   \\            /" << endl;
				cout << "                 *������������������������������������*��������������                     ��������������*������" << endl;
				cout << "              ��ɽ���ɽ�         ����ɽ                              ���ù�" << endl;
				system("pause");
				color(7);
			}
			else if (choice == 9) {
				record.status = trading;
			}

			break;
		case show_exits:
			cout << "��ǰλ��λ�ڣ�" << place[record.current_place].Name << endl;
			cout << "�����ȥ����" << endl;
			int i;
			for (i = 1; i <= place[record.current_place].connectnum; i++) {
				cout << i << "." << place[place[record.current_place].connect_place[i]].Name << endl;
			}
			cout << i << ".�˳�" << endl;
			cin >> choice;
			while (choice<1 || choice>i) {
				cout << "��������ȷ��ѡ�" << endl;
				cin >> choice;
			}
			if ((place[record.current_place].connect_place[choice] == 12 || place[record.current_place].connect_place[choice] == 13) && npc[4].taskstatus != 3) {
				cout << "���Ҳ���ȥ���˵ص�·" << endl;
				system("pause");

			}
			else if (place[record.current_place].connect_place[choice] == 10) {
				if (true) {  //��ӵ�аŽ���
					record.current_place = place[record.current_place].connect_place[choice];
				}
				else {
					cout << "�˴����������ʹ�����޷�ǰ������Ҫӵ�аŽ��Ȳſ���ͨ����" << endl;
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
			cout << "���Ƿ�ѡ����֮��̸��" << endl;
			cout << "1.��\t2.��" << endl;
			cin >> choice;
			while (choice < 1 || choice>2) {
				cout << "��������ȷѡ�" << endl;
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
				cout << "1.��������  2.������װ��  3.�˳�" << endl;
				cin >> i;
				if (i == 1) {
					show_state();
				}
				else if (i == 2) {
					while (true) {
						system("cls");
						show_bag();
						show_myeq();
						cout << "1.����װ��  2.����װ��  3.�˳�" << endl;
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
				cout << "1.�鿴��ϸ��Ϣ  2.�鿴����  3.����  4.����  5.�˳�" << endl;
				cin >> i;
				if (i == 1) {
					cout << "������Ҫ��ѯ��װ��" << endl;
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
				cout << "�������Ƿ�Ҫ������Ϸ����?" << endl;
				cin >> choice;
				while (choice < 1 || choice>8) {
					cout << "��������ȷѡ�" << endl;
					cin >> choice;
				}
				if (choice == 1) {
					string end = "���ڱ��沢�˳���Ϸ...";
					for (int i = 0; i < end.length(); i++) {
						Sleep(10);
						cout << end[i];
					}
					break;
				}
				else {
					string end = "�����˳���Ϸ...";
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
		cout << "��ӭ������" << place[record.current_place].Name << endl;
		for (int i = 0; i < place[record.current_place].Describe.length(); i++) {
			//Sleep(10);
			cout << place[record.current_place].Describe[i];
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	color(3);
	cout << "��ǰ��������\t������";
	color(9);
	cout << role[record.current_role].Name;
	color(3);
	cout << "\t�ȼ���" << role[record.current_role].Exp << endl;
	cout << "������" << role[record.current_role].HP << "/" << role[record.current_role].Max_Hp << "\t������" << role[record.current_role].MP << "/" << role[record.current_role].Max_Mp << endl;
	cout << "������" << role[record.current_role].Attack << "\t������" << role[record.current_role].Defence << "\t�ٶȣ�" << role[record.current_role].Speed << "\t��Ǯ��" << role[record.current_role].Money << endl;
	cout << "��ǰ���ڵص㣺";
	color(6);
	cout << place[record.current_place].Name << endl;
	color(7);
}

void game::init_role() {
	role = new Role[5];

	role[2].Name = "�����";
	role[2].Describe = "�����������������ʦ��������ʦ��ϰ����ͨ��ȴ���������ӣ�������ͥ���������������ܹ�����������������㻯��ǰ�������컯���ҡ�";
	role[2].Attack;//�չ�ֵ
	for (int i = 1, j = 4; i <= 3, j <= 6; i++, j++)
	{
		role[2].skill_index[i] = j;
	}
	role[2].Money;//��ң�������װ��
	for (int i = 0; i < 15; i++)
	{
		role[2].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[2].MyEquipment_index[i] = 0;
	}
	role[2].HP;//����ֵ
	role[2].Max_Hp;//��ǰHP��ֵ
	role[2].Defence;//����
	role[2].MP;//����
	role[2].Max_Mp;//��ǰMP��ֵ
	role[2].Speed;//�ٶ�
	role[2].Exp;//����ֵ
	role[2].Level;//�ȼ�
	for (int i = 1; i <= 14; i++) {
		role[2].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[2].taskstatus[i] = 1;
	}

	role[3].Name = "��˽�";
	role[3].Describe = "�㱾�����ϵ�����Ԫ˧���������ݣ���ò���á�ȴ����ƺ��Ϸ���϶𣬱����·������������ʾ�ˣ�Ϊ�ػ����ϣ��ֲ��Լ����µĹ�����̤����ǰ������ȡ���ĵ�·��";
	role[3].Attack;//�չ�ֵ
	for (int i = 1, j = 7; i <= 3, j <= 9; i++, j++)
	{
		role[3].skill_index[i] = j;
	}
	role[3].Money;//��ң�������װ��
	for (int i = 0; i < 15; i++)
	{
		role[3].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[3].MyEquipment_index[i] = 0;
	}
	role[3].HP;//����ֵ
	role[3].Max_Hp;//��ǰHP��ֵ
	role[3].Defence;//����
	role[3].MP;//����
	role[3].Max_Mp;//��ǰMP��ֵ
	role[3].Speed;//�ٶ�
	role[3].Exp;//����ֵ
	role[3].Level;//�ȼ�
	for (int i = 1; i <= 14; i++) {
		role[3].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[3].taskstatus[i] = 1;
	}

	role[4].Name = "ɳ����";
	role[4].Describe = "�������������ˣ��޵���ǧ����Բ����������׷�Ϊ�����󽫡�ȴ��Ϊ����һ���ʧ�ִ�������յ����������ɳ�ӣ�����Ϊʳ�������������㻯����������ţ�ǰ������ȡ����";
	for (int i = 1, j = 10; i <= 3, j <= 12; i++, j++)
	{
		role[4].skill_index[i] = j;
	}
	role[4].Money;//��ң�������װ��
	for (int i = 0; i < 15; i++)
	{
		role[4].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[4].MyEquipment_index[i] = 0;
	}
	role[4].HP;//����ֵ
	role[4].Max_Hp;//��ǰHP��ֵ
	role[4].Defence;//����
	role[4].MP;//����
	role[4].Max_Mp;//��ǰMP��ֵ
	role[4].Speed;//�ٶ�
	role[4].Exp;//����ֵ
	role[4].Level;//�ȼ�
	for (int i = 1; i <= 14; i++) {
		role[4].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[4].taskstatus[i] = 1;
	}

	role[1].Name = "��ɮ";
	role[1].Describe = "�������ڶ������ƣ�����������Ķ����ӽ����ת�����������ձ���ĥ�¿��ѣ�������������̫��֮��������Ϊʵ�����ҵ��ڽ�������ʹ����ҲΪ�˾����Լ�ǰ���Ĺ�������Ȼ��Ȼ��̤��ǰ������ȡ���ĵ�·�����ն�������";
	role[1].Attack = 10;//�չ�ֵ
	
	for (int i = 1, j = 1; i <= 3, j <= 3; i++, j++)
	{
		role[1].skill_index[i] = j;
	}
	role[1].Money = 100;//��ң�������װ��
	for (int i = 0; i < 15; i++)
	{
		role[1].Bag[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		role[1].MyEquipment_index[i] = 0;
	}
	role[1].HP = 100;//����ֵ
	role[1].Max_Hp = 100;//��ǰHP��ֵ
	role[1].Defence = 0.2;//����
	role[1].MP = 20;//����
	role[1].Max_Mp = 50;//��ǰMP��ֵ
	role[1].Speed = 10;//�ٶ�
	role[1].Exp = 0; //����ֵ
	role[1].Level = 1;//�ȼ�


	for (int i = 1; i <= 14; i++) {
		role[1].place_index[i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		role[1].taskstatus[i] = 1;
	}
}

void game::init_npc() {
	npc = new Npc[6];
	npc[1].name = "���ع�";
	npc[1].goodId = 20;
	npc[1].task = "�ð׻���ָ����";
	npc[1].tdescribe = "��ܰ׹Ǿ�";
	npc[1].tasknum = 1;
	npc[1].taskstatus = 1;

	npc[2].name = "С��ĸ���";
	npc[2].goodId = 20;
	npc[2].task = "���С��";
	npc[2].tdescribe = "�����ëʨ�Ӿ�����С�����ȳ�����";
	npc[2].tasknum = 2;
	npc[2].taskstatus = 1;

	npc[3].name = "С��";
	npc[3].goodId = 20;
	npc[3].tasknum = 0;

	npc[4].name = "֩�뾫";
	npc[4].goodId = 20;
	npc[4].task = "�߳��Թ�";
	npc[4].tdescribe = "�����ëʨ�Ӿ�����С�����ȳ�����";
	npc[4].tasknum = 3;
	npc[4].taskstatus = 1;

	npc[5].name = "��������";
	npc[5].goodId = 20;
	npc[5].task = "���Ϸ�̵���ʥ�кͰ�����";
	npc[5].tdescribe = "��";
	npc[5].tasknum = 4;
	npc[5].taskstatus = 1;
}

void game::init_place() {
	place = new Place[15];
	place[1].Name = "����";
	place[1].Describe = "���������ƻֺ꣬��ǽ�������࣬����ɭ�ϡ����ڽֵ��ݺύ�����з������̼��Ƽ���������֯�������۴��αȣ�����������Ŀ�����Է��ٲ�ʢ������¥��Ρ��׳������ǽ�������������������ԣ���ľ���裬��ˮ�峺������ɢ���Żʼ����������ϡ������ļ�������������ʵ�����������������Ϊ���Ƶ����Ρ����á��Ļ����ģ�����ǧ��ų�չ�ֳ������ױȵĸ�����Ի͡�";
	place[1].comefirst = 1;
	place[1].npc_index = 0;
	place[1].enemy_index = 0;
	place[1].connectnum = 1;
	place[1].connect_place[1] = 5;
	place[2].Name = "��ָɽ";
	place[2].Describe = "��ָɽΡ���վ�����������޴����ֱָָ��񷣬ɽ��⻬�����Եò��������ߡ�����ɽ��������������֮�£���Χ������ɭ�ֲ�����ջ谵�޹⣬ֻ�з��������غ�Х���·�����˵�ű���ѹ�ڴ˵�����յ������뱯�롣ɽ���»������̣��ž���������Ϣ����ָɽ������������Ȼ���ն񣬸�������������ѹ����յ��������ڣ���������������Ĳ���Υ����";
	place[2].comefirst = 1;
	place[2].npc_index = 0;
	place[2].enemy_index = 0;
	place[2].connectnum = 1;
	place[2].connect_place[1] = 5;
	place[3].Name = "����ׯ";
	place[3].Describe = "����ׯ������һƬ�������԰�У���Χ�����Ŵ��̵�ɽ��ͷ��ĵ���Ұ��������ѣ�������������������԰������������Ϣ�����з��ݴ������£�ũ����������׳������ţ�����е��ⲽ�������ǹ�����ʵ���������������ĸ߼Ҵ�Ժռ�ع�������ש���ߣ�Ժ�����࣬��ǰʯʨ���ϣ����������˵��Ժյ�λ�����۴����ﶬ������ׯ��չ�ֳ�һ��������͵���Ȼ��⡣";
	place[3].comefirst = 1;
	place[3].npc_index = 0;
	place[3].enemy_index = 0;
	place[3].connectnum = 1;
	place[3].connect_place[1] = 5;
	place[4].Name = "��ɳ��";
	place[4].Describe = "��ɳ��λ�ڻ��������򣬺�ˮ�ļ������ǣ�ˮ���ϳ���������һ�㱡�����������Ե���ɭ�ֲ����Ӱ����Ի��߼ž����Ӳݴ�������ʯ��ᾣ��·�ܾ�û���˼�̤�㡣��ˮ�в�ʱ�������Ĳ��ƣ�����͸��һ�����˲�����������Ϣ����ɳ��ˮ������ף�ˮ���̲�������Σ�գ�ɳ�����ڴ����ң�������֮ɫ�䡣��Ƭ������������أ��·�������������һ������������η�ĵط���";
	place[4].npc_index = 0;
	place[4].comefirst = 1;
	place[4].enemy_index = 0;
	place[4].connectnum = 1;
	place[4].connect_place[1] = 5;
	place[5].Name = "�׻���";
	place[5].Describe = "������������·�̣��������˰׻��룬��������վ���ɽ�����������������ϡ��Ĳ�ľ���Եû������¼š�ɽ�г��걻Ũ�ܵİ������֣��·���Զ����һ�����ʵ���Ӱ֮�У�ʹ���޷�����ǰ���ĵ�·��·�ԵĿ���Ť�����������ǹ��޵�צ�������˲�����������ʯ��ᾲ�ƽ��ɽ·������У�ÿһ����������Σ�ա�������������һ��ɭ��ĺ��⣬�·�����������Ǳ����Σ����ż�������������������������˸е���Ƭɽ�������δ֪�Ŀֲ������ܼž��ù��죬ֻ�з紩���������������·��ڵ�����˵����Ƭ�����ϵ�Σ�������ա�";
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

	place[6].Name = "һ�����ѵ�ɽ·";
	place[6].Describe = "����ƫƧ�ޱȣ�ֻ��һ���˼��ڴ˾�ס��";
	place[6].comefirst = 1;
	place[6].npc_index = 2;
	place[6].enemy_index = 0;
	place[6].connectnum = 2;
	place[6].connect_place[1] = 5;
	place[6].connect_place[2] = 7;

	place[7].Name = "ʨ��ɽ��";
	place[7].Describe = "����Ⱥɽ���ƣ�ɽʯ��ᾣ�ֲ��ϡ�裬͸�����ֻ�������š�ɽ���г���������һ�ɹ����������������������һ�ɳ�ʪ���������ζ�����˸е�ѹ�ֲ������ȵ׵Ķ�Ѩ�����İ������ڱ������Ӳ���ӳ��ɢ�����������Ϣ��������������Ұ�޵ĵͺ������ص��ڿտ���ɽ���У��Եø���ֲ��������ط�������Σ�������أ��·��Ǵ���Ȼ�����ص�����֮�ء�";
	place[7].comefirst = 1;
	place[7].npc_index = 3;
	place[7].enemy_index = 2;
	place[7].connectnum = 2;
	place[7].connect_place[1] = 6;
	place[7].connect_place[2] = 10;

	place[8].Name = "���ƶ�";
	place[8].Describe = "��ǰ������һ��ʯ�٣����԰˸����֣����ǡ���ɽ���ɽ����ƶ������Ǳ���һȺС������������ǹ�轣��������ˣ��";
	place[8].comefirst = 1;
	place[8].npc_index = 0;
	place[8].enemy_index = 3;
	place[8].connectnum = 2;
	place[8].connect_place[1] = 5;
	place[8].connect_place[2] = 9;

	place[9].Name = "�Ž���";
	place[9].Describe = "�Ž����⣬��ï�ܵİŽ������ƣ���Щ�Ž�����ͬ�ڷ����ֲ����Ǹߴ�ͦ�Σ�Ҷ�ӿ�����ȣ��·���������ա����ڻ�����������Ƭ�Ž���֮�У���Ϊ����������ֻ�еõ����˻���Ե�߲���Ѱ�����١�";
	place[9].comefirst = 1;
	place[9].npc_index = 0;
	place[9].enemy_index = 4;
	place[9].connectnum = 2;
	place[9].connect_place[1] = 8;
	place[9].connect_place[2] = 10;

	place[10].Name = "����ɽ";
	place[10].Describe = "���ܴ�ݲ�����һƬ����������ɽ�����һ���գ��������ƣ����˹�����ɽ�ϵ���ʯ���ֳ���ɫ����ɫ�ͺ�ɫ���·����Ҹ��ǡ�������������������ɽ��������ȼ�յĻ��棬����������η ";
	place[10].comefirst = 1;
	place[10].npc_index = 0;
	place[10].enemy_index = 0;
	place[10].connectnum = 3;
	place[10].connect_place[1] = 7;
	place[10].connect_place[2] = 9;
	place[10].connect_place[3] = 11;

	place[11].Name = "��˿��";
	place[11].Describe = "ֻ������ͷ���ʽ����̣�����ң��ͨ�������Ž�ʯ�ţ�����������ˮ�ˣ�԰�����ǧ��ǧ�Ŷ��v������޵������������֥����ɢ��ǧ����Զ�۶������������ɽ��ѹ̫������������Ѱ����������������ɼҡ�";
	place[11].comefirst = 1;
	place[11].npc_index = 4;
	place[11].enemy_index = 0;
	place[11].connectnum = 3;
	place[11].connect_place[1] = 10;
	place[11].connect_place[2] = 12;
	place[11].connect_place[3] = 13;

	place[12].Name = "����ɽ";
	place[12].Describe = "�˴�Ϊ����ɽ��ɽ���ɽ��ϸ��ɫ��ࡣ������Ʈ������ǰ��Ӱ���������������������硣������ǧ�ɣ���ͷ�񼸸͡�����ǲ��Ƕ�ʳ�������Ƕ������͡�ҰԳ��ХѰ�ʹ�����¹�ʻ��ϴ�ᰡ���������ˮ������ʱ���������ء���������ǣ�ֳ�����Ϫ���������������׹�ʯ���������ҡ����C��Ⱥ�ߣ���Գ�����硣�п�������վ����κιŵ����廹�� ";
	place[12].comefirst = 1;
	place[12].npc_index = 0;
	place[12].enemy_index = 5;
	place[12].connectnum = 2;
	place[12].connect_place[1] = 11;
	place[12].connect_place[2] = 14;

	place[13].Name = "���ù�";
	place[13].Describe = "���ù���������һ�����ٸ������������������ŷ𣬰��հ�����ҵ�����ﻷ��������ɽ��ˮ�㣬����Ρ��׳�������������Ƿ���ĵ�����Ϣ�� ";
	place[13].comefirst = 1;
	place[13].npc_index = 0;
	place[13].enemy_index = 6;
	place[13].connectnum = 1;
	place[13].connect_place[1] = 11;
	place[13].connect_place[2] = 14;

	place[14].Name = "������";
	place[14].Describe = "���ù���������һ�����ٸ������������������ŷ𣬰��հ�����ҵ�����ﻷ��������ɽ��ˮ�㣬����Ρ��׳�������������Ƿ���ĵ�����Ϣ�� ";
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
		cout << npc[num].name << ":���ˣ�ƶ���˴˵ص���������������֪�����ϵ����ա��˵���Ϊ�׻��룬ԭ��Ҳ���ƽ�˾������Դ��ǰ׹Ǿ�ռ�ݴ˵أ��������������������" << endl;
		system("pause");
		cout << "�ǰ׹Ǿ�����ɽ�пݹǣ����Ե�ɺ���������������ǧ����С������ĳ��ݶ�����ϲ�Ի��·�ˣ��������ԣ����������ϡ����ó��仯��ÿ�������Բ�ͬģ������ƭ�޹�֮�ˣ��к�������ʵ�������񼫣�ƶ�����Ȱ�裬�������������������������޼ɵ�������λ�������½�������Ī������αװ���Ի�ֻҪ�ܳ�����������������Ϊ��Ƭɽ���ȥ�ֻ���Ҳ�ܾ���������Ҫ���ѵ����飡" << endl;
		system("pause");
		color(4);
		cout << "�Ƿ�ѡ��������񣬰����׻���ָ�������" << endl;
		cout << "1.��������\t2.�ܾ�����" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "��������ȷѡ�" << endl;
			cin >> choice;
		}
		if (choice == 1) {
			role[record.current_role].taskstatus[num] = 2;
		}

	}
	else if (num == 1 && role[record.current_role].taskstatus[num] == 2) {
		color(11);
		cout << place[record.current_role].Name << "ϣ�����˾��컹�׻�������̫ƽ��" << endl;
		color(7);
	}
	else if (num == 1 && role[record.current_role].taskstatus[num] == 3) {
		color(11);
		cout << "��л" << npc[num].name << "�����׻���ָ�̫ƽ��" << endl;
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 1) {
		color(11);
		cout << npc[num].name << ":�������ҵ�Ů��С��������һ��ȥ���ڴ壬����δ�飬��������������ëʨ�Ӿ������������æȥ���ʨ�Ӿ����ȳ��ҵ�Ů����" << endl;
		system("pause");
		color(4);
		cout << "�Ƿ�ѡ��������񣬾ȳ�С�䣿" << endl;
		cout << "1.��������\t2.�ܾ�����" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "��������ȷѡ�" << endl;
			cin >> choice;
		}
		if (choice == 1) {
			role[record.current_role].taskstatus[num] = 2;
		}
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 2) {
		cout << npc[num].name << "ϣ�����˾���Ȼ��ҵ�Ů����" << endl;
	}
	else if (num == 2 && role[record.current_role].taskstatus[num] == 3) {
		cout << "��л" << role[record.current_role].Name << "�����Ȼ��ҵ�Ů����" << endl;
	}
	else if (num == 3 && role[record.current_role].taskstatus[num] == 1) {
		cout << npc[num].name << "��Ϊ��Ҳ�����ֵ�ͬ�����һ�Բ�����" << endl;
		system("pause");

		cout << "������������������⣬��ʮ�ָж���" << endl;
		npc[num].taskstatus = 3;

	}
	else if (num == 3 && role[record.current_role].taskstatus[num] == 3) {
		cout << "��л" << role[record.current_role].Name << "������������ħ�ơ�" << endl;
	}
	else if (num == 4 && role[record.current_role].taskstatus[num] == 1) {
		cout << npc[num].name << "����˿�����۸��ӣ���ͨ����Ҫͨ������ֱ�������룬�������������¿��飬���ܹ�������Թ��ߣ��һ�����߳���˿����" << endl;
		system("pause");
		color(4);
		cout << "�Ƿ�ѡ����ܿ���" << endl;
		cout << "1.��������\t2.�ܾ�����" << endl;
		cin >> choice;
		color(7);
		while (choice < 1 || choice>2) {
			cout << "��������ȷѡ�" << endl;
			cin >> choice;
		}

		while (choice == 1) {
			color(7);
			if (Labyrinth() == 1)
				role[record.current_role].taskstatus[num] = 3;
			else {
				cout << "�Ƿ�������ս��" << endl;
				cout << "1.��\t2.��" << endl;
				cin >> choice;
				while (choice < 1 || choice>2) {
					cout << "��������ȷѡ�" << endl;
					cin >> choice;
				}
			}
		}
	}
	else if (num == 4 && role[record.current_role].taskstatus[num] == 3) {
		cout << "��ͨ���˿��飬������˿�����Գ�ͨ���衣" << endl;
	}


	else if (num == 5) {
		cout << "���Ȳ������ص��������£�����������档�����߽������´�������������ڽ�ɫ�������ϣ�������գ��Ե��ޱ�ׯ�ϡ�" << endl;
		system("pause");
		if (role[record.current_role].taskstatus[num] == 1) {
			if (role[record.current_role].taskstatus[1] == 3 && role[record.current_role].taskstatus[2] == 3) {
				if (record.current_role == 1) {
					cout << "��˵���������������������������������죬�����������澭��" << endl;
					system("pause");
					cout << "�������棨΢Ц�ŵ�ͷ�������գ����ա�����ʦͽ���˲�η���գ��Ļ��ᶨ�����������ȡ��֮�á����еļ������࣬���Ƕ��������ԵĿ��飬��Ƚ�ͨ���˽٣�ʵ�����ס�" << endl;
				}
				else if (record.current_role == 2) {
					cout << "�㣨��ǰһ����˫�ֺ�ʮ�������棬������һ·������ħ�����㾡�ľ�����������ڼ������棬��������澭�����������ջص��������츣������" << endl;
					system("pause");
					cout << "�������棺��գ���������ң���Ȼ��������֮������һ·�ϻ�����ɮ��������û��������ȡ���澭�����Ƿ𷨾��裬����������򣬲����ն�������" << endl;

				}
				else if (record.current_role == 3) {
					cout << "�㣨�����֣�ǫ��ص�ͷ�������棬����һ·����Ȼ������һЩ����Ҳû�ٳ�����ϣ�������ܿ�ˡ�ҵĹ�ʧ�������澭�����������ջص��������츣������" << endl;
					system("pause");
					cout << "�������棨�ȱ��ؿ��Ű˽䣩���˽䣬����Ȼ̰�����裬��Ҳ�ܼ�ʱ�����������д����Ҳ���ø��������ǵĹ��£����ж�����" << endl;
				}
				else if (record.current_role == 4) {
					cout << "�㣨���������񣩣����棬����ɳ����Ϊĩͽ����Ը׷��ʦ����һͬ���𷨴���������Ϊ�����츣��" << endl;
					system("pause");
					cout << "�������棺ɳɮ���������Һ�ĬĬ����������������������������գ�������ɴ�Ը����Ϊ������Ե֮�ˡ�" << endl;
				}
				cout << "��������ʾ�⣬���޺����������������ķ𾭣������㡣Ȼ��Ŀ��������澭������������뿪�����£�̤���˹�;��" << endl;
				system("pause");
			}

			else if (role[record.current_role].taskstatus[1] == 2 || role[record.current_role].taskstatus[2] == 2) {
				cout << "�������棺" << role[record.current_role].Name << "����ʵȡ��;��Ҳ���������Ȥ�ģ������Ȼ��Ҫ������;�ķ羰Ҳ�����������������������ˣ���Ҳ���ҷ���ڵ����壬ϣ����ȡ���澭�󣬿����������е���ʥ�кͰ�������" << endl;
				system("pause");
				cout << "������¶��һ˿ʧ��֮ɫ������˵����ֻ����Ե�ˣ��⾭������Ե" << endl;
				system("pause");
			}


			else if (role[record.current_role].taskstatus[1] == 1 || role[record.current_role].taskstatus[2] == 1) {
				cout << "�������棺" << role[record.current_role].Name << "����ʵȡ��;��Ҳ���������Ȥ�ģ������Ȼ��Ҫ������;�ķ羰Ҳ�����������������������ˣ���Ҳ���ҷ���ڵ����壬ϣ����ȡ���澭�󣬿����������е���ʥ�кͰ�������" << endl;
				system("pause");
				cout << "��������ʾ�⣬���޺����������������ķ𾭣������㡣Ȼ��Ŀ��������澭���뿪�����£�̤���˹�;��" << endl;
				system("pause");
			}
			role[record.current_role].taskstatus[num] == 3;
		}
		else if (role[record.current_role].taskstatus[num] == 3) {
			cout << "������˵�����ȥ�ɣ���ֻ����Ե�ˣ��⾭������Ե" << endl;
			system("pause");
		}

	}

	color(7);


}

void show_surface()
{
	color(6);
	cout << "        ���������������������������Ρ����Ρ������Ρ������������������͡����������͡���������������򡡡�����������������" << endl;
	cout << "	      �������������������������������Ρ��������Ρ��������͡��������͡��͡��������򡡡�����������������������������������������" << endl;
	cout << "	      ���������������������������Ρ����Ρ������������͡��͡��͡������͡����������򡡡���������������������������������" << endl;
	cout << "	���������������������������Ρ����Ρ������������Ρ����������͡������͡����͡������򡡡�������򡡡�����������������    " << endl;
	cout << "	�����������������������������Ρ������Ρ��������Ρ������������͡������͡����������򡡡��򡡡������򡡡�������������������������" << endl;
	cout << "	���������������������������������Ρ��Ρ������Ρ����������͡��������������͡������򡡡��򡡡������򡡡���������������" << endl;
	cout << "	���������������������������������Ρ��Ρ������Ρ������������͡��������͡����������򡡡��򡡡������򡡡�������������������������" << endl;
	cout << "	�����������������������������Ρ��Ρ��Ρ��������Ρ����������͡��������͡����������򡡡��򡡡����򡡡�������������������������" << endl;
	cout << "	�����������������������������Ρ��Ρ��Ρ������Ρ������͡��͡��͡����������͡������򡡡��򡡡���������������������������������" << endl;
	cout << "	�����������������������������Ρ��Ρ��Ρ������Ρ����������͡����������͡��������򡡡����򡡡��������򡡡�������������������" << endl;
	cout << "	���������������������������Ρ��Ρ����Ρ������Ρ����������͡����������͡��������򡡡����������򡡡�������������������" << endl;
	color(9);
	cout << '\t' << '\t' << '\t' << '\t';
	cout << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "       ��Ϸ������Ϣ" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   �����ˣ��й������ѧ2024�ļ�ѧ��c++�γ����" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   ��ͬѧ����λ��ͬѧ����ͬѧ����ͬѧ" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t';
	color(7);
}

void game::task_status(int num)
{
	if (num == 1 && role[record.current_role].taskstatus[num] == 2) {
		if (true) {  //�жϵ���Ѫ���Ƿ�Ϊ0
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



