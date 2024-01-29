#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	// choice validator variable i.e if user input a wrong choice
	bool choice_invalid = false;

	// player name and it's size
	char player_name[50]; int player_name_size;

	// stats variables
	int coins = 0;
	int gems = 0;
	int score = 0;
	int health = 100;
	int armor = 0;
	int max_health = 100;

	int level = 1;
	int xp = 0;
	int xp_to_level = 20;

	int damage_multiplier = 1;

	int dungeons_completed = 0;

	int melee_equipped_index = 0;
	int armor_equipped_index = 0;
	bool armor_is_equipped = false;

	float gym_points = 0;
	int gym_points_to_level = 25;
	int gym_level = 0;


	// --- WEAPONS ---

	// melee
	string melee[] = { "Stick", "Wooden Sword", "Dagger", "Iron sword", "Mace" };
	int melee_damage_start[] = { 1, 9, 40, 80, 145 };
	int melee_damage_end[] = { 4, 20, 65, 120, 185 };
	int melee_price[] = { 0, 50, 250, 700, 1500 }; // In Coins
	bool melee_purchased[] = { true, false, false, false, false };
	int melee_unlock_level[] = { 0, 0, 1, 1, 2 };
	int xp_at_melee_purchase[] = { 0, 5, 25, 50, 75 };

	int total_melee_weapons = sizeof(melee) / sizeof(melee[0]);


	// --- POTIONS ---

	// health
	string health_potions[] = { "Small Health Potion", "Medium Health Potion", "Large Health Potion", "EXTRA Large Health Potion"};
	int health_potion_price[] = { 20, 100, 350, 1000 }; // In Gems
	int health_potion_price_in_dungeon[] = { 50, 250, 700, 1800 }; // In coins in dungeon
	int health_potion_appears_at_dungeon_at_level[] = { 0, 1, 2, 3 };
	int health_potion_HP[] = { 25, 60, 120, 300 };
	int health_potion_unlock_level[] = { 1, 3, 5, 7 };
	int xp_at_health_potion_purchase[] = { 1, 3, 5, 15 };
	int health_potion_in_inventory[] = { 0, 0, 0, 0 };

	int total_health_potions = sizeof(health_potions) / sizeof(health_potions[0]);

	// --- ARMOR ---

	string armors[] = { "Leather Armor", "Wooden Armor", "Iron Armor", "Ring Armor", "Steel Armor" };
	int armor_price[] = { 100, 300, 650, 1200, 2000 };
	int armor_defence[] = { 5, 10, 20, 35, 50 };
	int armor_unlock_level[] = { 0, 0, 1, 1, 2 };
	int xp_at_armor_purchase[] = { 5, 15, 35, 60, 125 };
	bool armor_purchased[] = { false, false, false, false, false };
	bool armor_equipped[] = { false, false, false, false, false };

	int total_armors = sizeof(armors) / sizeof(armors[0]);

	// --- GYM ---

	string weights[] = { "weight 1", "weight 2", "weight 3", "weight 4", "weight 5" };
	int weight_gym_level_req[] = { 0, 10, 20, 30, 40 };
	int weight_point_award[] = { 1, 5, 25, 125, 625 };

	int total_weights = sizeof(weights) / sizeof(weights[0]);

	// --- DUNGEON ---

	string dungeons[] = { "DUNGEON - 1", "DUNGEON - 2", "DUNGEON - 3", "DUNGEON - 4", "DUNGEON - 5" };
	bool dungeon_cleared[] = { false, false, false, false, false };
	int dungeon_unlock_req[] = { 0, 1, 2, 3, 4 };
	int dungeon_waves[] = { 10, 10, 15, 15, 20 };
	int xp_at_dungeon_complete[] = { 150, 350, 750, 1450, 2250 };
	int coins_at_dungeon_complete[] = { 300, 700, 1500, 3500, 8000 };
	int gems_at_dungeon_complete[] = { 100, 250, 500, 1000, 2000 };
	int dungeon_enemy_index[] = { 0, 1, 2, 3, 4 };

	int total_dungeons = sizeof(dungeons) / sizeof(dungeons[0]);

	// --- ENEMIES ---

	string enemies[] = { "Slime", "Spider", "Skeleton", "Orc", "Bandit"};
	float enemy_health[] = { 10, 25, 50, 85, 120 };
	int enemy_damage_start[] = { 5, 10, 20, 50, 100 };
	int enemy_damage_end[] = { 10, 20, 50, 100, 200 };
	int enemy_defence[] = { 0, 5, 15, 35, 50 };
	int enemy_xp[] = { 15, 45, 100, 185, 260 };
	int enemy_coins[] = { 25, 75, 150, 225, 350 };
	int enemy_gems[] = { 5, 15, 35, 65, 100 };
	int enemy_score[] = { 50, 250, 550, 1200, 2060 };

	int total_enemies = sizeof(enemies) / sizeof(enemies[0]);

	// --- BOSSES ---

	string bosses[] = { "Slime Boss", "Spider Boss", "Skeleton Boss", "Orc Boss", "Bandit Boss" };
	float boss_health[] = { 100, 250, 500, 1000, 2300 };
	int boss_damgae_start[] = { 20, 50, 95, 130, 200 };
	int boss_damgae_end[] = { 50, 100, 150, 200, 250 };
	int boss_defence[] = { 20, 50, 95, 130, 200 };
	int boss_xp[] = { 300, 750, 1500, 3000, 5500 };
	int boss_coins[] = { 500, 1000, 2000, 4000, 8000 };
	int boss_gems[] = { 100, 250, 500, 1000, 2000 };
	int boss_score[] = { 5000, 10000, 20000, 40000, 80000 };

	int total_bosses = sizeof(bosses) / sizeof(bosses[0]);

	// --- GAME ---
	cout << "Enter your player name: "; cin.getline(player_name, 50);
	for (player_name_size = 0; player_name[player_name_size] != '\0'; player_name_size++);
	system("cls");

	while (true) {
		int choice_1;
		system("cls");

		// Dynamic Welcome Box sizing according to name length
		for (int i = 1; i <= 6; i++) {
			// initial spacing
			cout << "\t\t";
			if (i == 1 || i == 4 || i == 6) { // 1st, 4th and 6th line
				cout << "*********************";
				if (player_name_size > 13) {
					for (int j = player_name_size - 13; j >= 0; j--) {
						cout << "*";
					}
				}
				cout << endl;
			}
			else if (i == 2) { // second line "Welcome to"
				if (player_name_size > 13) {
					cout << "*    ";
					for (int j = player_name_size - 13; j >= 0; j -= 2)cout << " ";
					cout << "Welcome to";
					cout << "     ";
					for (int j = player_name_size - 13 - 1; j >= 0; j -= 2)cout << " "; cout << "*";
				}
				else {
					cout << "*    Welcome to     *";
				}
				cout << endl;
			}
			else if (i == 3) { // third line "Dungeon Quest"
				if (player_name_size > 13) {
					cout << "*   ";
					for (int j = player_name_size - 13; j >= 0; j -= 2)cout << " ";
					cout << "Dungeon Quest";
					cout << "   ";
					for (int j = player_name_size - 13 - 1; j >= 0; j -= 2)cout << " "; cout << "*";
				}
				else {
					cout << "*   Dungeon Quest   *";
				}
				cout << endl;
			}
			else { // 5th line player name
				int diff = 19 - player_name_size;
				bool even = (player_name_size % 2 == 0) ? true : false;
				if (player_name_size < 13) {
					cout << "*";
					for (int j = diff / 2 - 1; j >= 0; j -= 1)cout << " ";
					cout << player_name;
					if (even)cout << " ";
					for (int j = diff / 2 - 1; j >= 0; j -= 1)cout << " ";
					cout << "*";
				}
				else {
					cout << "*";
					if (even)cout << "    ";
					else cout << "   ";
					cout << player_name;
					cout << "   ";
					cout << "*";
				}
				cout << endl;
			}
		}

		// Main Menu
		cout << endl << endl;
		cout << " 1) Start" << endl;
		cout << " 0) Exit Game" << endl << endl;

		if (choice_invalid) {
			cout << "Choice not allowed" << endl;
			choice_invalid = false;
		}

		cout << "Enter the choice: "; cin >> choice_1;

		if (choice_1 == 1) { // Main Game Loop
			while (true) {
				int choice_2;
				system("cls");
				cout << player_name << endl << endl;
				cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
				cout << "Gems: " << gems << endl;
				cout << endl << endl;
				cout << "Health: " << health << "/" << max_health << endl;
				cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
				cout << endl << endl << endl << endl;

				cout << "1) Go to Town" << endl;
				cout << "2) Go to Dungeon" << endl;
				cout << "3) View Inventory" << endl;
				cout << "0) Leave" << endl;
				cout << endl;

				if (choice_invalid) {
					cout << "Choice not allowed" << endl;
					choice_invalid = false;
				}
				cout << "Enter the choice: "; cin >> choice_2;


				if (choice_2 == 1) { // Town
					while (true)
					{
						int choice_3;
						system("cls");
						cout << player_name << endl << endl;
						cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
						cout << "Gems: " << gems << endl;
						cout << endl << endl;
						cout << "Health: " << health << "/" << max_health << endl;
						cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
						cout << endl << endl << endl << endl;

						cout << "TOWN" << endl;
						cout << "1) Go to Weapon Store" << endl;
						cout << "2) Go to Potion Store" << endl;
						cout << "3) Go to Armor Store" << endl;
						cout << "4) Go to Gym" << endl;
						cout << "0) Leave" << endl;
						cout << endl;

						if (choice_invalid) {
							cout << "Choice not allowed" << endl;
							choice_invalid = false;
						}
						cout << "Enter the choice: "; cin >> choice_3;

						if (choice_3 == 1) { // Weapon Store
							while (true)
							{
								int choice_4;
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "TOWN - WEAPON STORE" << endl;
								cout << "1) Buy" << endl;
								cout << "0) Leave" << endl;
								cout << endl;

								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter the choice: "; cin >> choice_4;

								if (choice_4 == 1) { // Buy

									// Input validators
									bool insufficient_funds = false;
									bool weapon_locked = false;
									bool weapon_already_purchased = false;

									// other validators
									bool weapon_just_purchased = false; int just_purchased_index;

									// Buy loop
									while (true)
									{
										int choice_5;
										int i = 0;
										system("cls");
										cout << player_name << endl << endl;
										cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
										cout << "Gems: " << gems << endl;
										cout << endl << endl;
										cout << "Health: " << health << "/" << max_health << endl;
										cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
										cout << endl << endl << endl << endl;

										cout << "TOWN - WEAPON STORE - BUY" << endl;
										for (i = 0; i < total_melee_weapons; i++) {
											if (!melee_purchased[i] && melee_unlock_level[i] - dungeons_completed <= 0) {
												cout << i + 1 << ") " << melee[i] << "\t - " << melee_price[i] << " coins" << "\t - " << xp_at_melee_purchase[i] << " xp on purchase" << endl;
											}
											else if (!melee_purchased[i] && melee_unlock_level[i] - dungeons_completed > 0) {
												cout << i + 1 << ") " << "??????" << "\t - Locked (Requires " << melee_unlock_level[i] - dungeons_completed << " More Dungeons to be completed)" << endl;
											}
											else {
												cout << i + 1 << ") " << melee[i] << "\t - Purchased" << endl;
											}
										}
										cout << "0) Leave" << endl;
										cout << endl;

										// Input validators messages
										if (choice_invalid) {
											cout << "Choice not allowed" << endl;
											choice_invalid = false;
										}
										if (insufficient_funds) {
											cout << "Not enough coins" << endl;
											insufficient_funds = false;
										}
										if (weapon_locked) {
											cout << "Selected Weapon is locked" << endl;
											weapon_locked = false;
										}
										if (weapon_already_purchased) {
											cout << "Weapon Already purchased" << endl;
											weapon_already_purchased = false;
										}
										if (weapon_just_purchased) {
											cout << "You purchased " << melee[just_purchased_index] << " for " << melee_price[just_purchased_index] << " Coins!" << endl;
											weapon_just_purchased = false;
										}
										cout << "Enter the choice: "; cin >> choice_5;

										if (choice_5 == 0) {
											system("cls");
											break;
										}
										else if (choice_5 > 0 && choice_5 <= total_melee_weapons) {
											for (int i = 0; i < total_melee_weapons; i++) {
												if (choice_5 == i + 1) {
													if (!melee_purchased[i] && melee_unlock_level[i] - dungeons_completed <= 0) {
														if (melee_price[i] <= coins) {
															coins -= melee_price[i];
															melee_purchased[i] = true;
															weapon_just_purchased = true;
															just_purchased_index = i;
															xp += xp_at_melee_purchase[i];

															// check to increase level on xp
															if (xp >= xp_to_level) {
																xp -= xp_to_level;
																xp_to_level *= 3.5;
																level++;
															}
														}
														else {
															insufficient_funds = true;
														}
													}
													else {
														if (melee_purchased[i]) {
															weapon_already_purchased = true;
														}
														if (melee_unlock_level[i] - dungeons_completed > 0) {
															weapon_locked = true;
														}
													}
												}
											}
										}
										else {
											choice_invalid = true;
										}
									}
								}

								else if (choice_4 == 0) {
									break;
								}
								else {
									choice_invalid = true;
								}
							}
						}
						else if (choice_3 == 2) { // Potion Store
							while (true)
							{
								int choice_4;
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "TOWN - POTION STORE" << endl;
								cout << "1) Buy" << endl;
								cout << "0) Leave" << endl;
								cout << endl;

								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter the choice: "; cin >> choice_4;

								if (choice_4 == 1) { // Buy

									// Input validators
									bool insufficient_funds = false;
									bool potion_locked = false;

									// other checkers
									bool potion_just_purchased = false; int just_purchased_index;

									// Buy loop
									while (true)
									{
										int choice_5;
										int i = 0;
										system("cls");
										cout << player_name << endl << endl;
										cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
										cout << "Gems: " << gems << endl;
										cout << endl << endl;
										cout << "Health: " << health << "/" << max_health << endl;
										cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
										cout << endl << endl << endl << endl;

										cout << "TOWN - POTION STORE - BUY" << endl;
										for (i = 0; i < total_health_potions; i++) {
											if (health_potion_unlock_level[i] <= level) {
												cout << i + 1 << ") " << health_potions[i] << "\t - " << health_potion_price[i] << " Gems" << "\t - " << xp_at_health_potion_purchase[i] << " xp on purchase" << endl;
											}
											else {
												cout << i + 1 << ") " << "??????" << "\t - Locked (Requires " << health_potion_unlock_level[i] << " Level to be Acheived. You just need " << xp_to_level - xp << " more Xp for next level)" << endl;
											}
										}
										cout << "0) Leave" << endl;
										cout << endl;

										// Input validators messages
										if (choice_invalid) {
											cout << "Choice not allowed" << endl;
											choice_invalid = false;
										}
										if (insufficient_funds) {
											cout << "Not enough Gems" << endl;
											insufficient_funds = false;
										}
										if (potion_locked) {
											cout << "Selected Potion is locked" << endl;
											potion_locked = false;
										}
										if (potion_just_purchased) {
											cout << "You purchased " << health_potions[just_purchased_index] << " for " << health_potion_price[just_purchased_index] << " Gems!" << endl;
											potion_just_purchased = false;
										}
										cout << "Enter the choice: "; cin >> choice_5;

										if (choice_5 == 0) {
											system("cls");
											break;
										}
										else if (choice_5 > 0 && choice_5 <= total_health_potions) {
											for (int i = 0; i < total_health_potions; i++) {
												if (choice_5 == i + 1) {

													// purchase check
													if (health_potion_unlock_level[i] <= level) {
														if (health_potion_price[i] <= gems) {
															gems -= health_potion_price[i];
															potion_just_purchased = true;
															just_purchased_index = i;
															xp += xp_at_health_potion_purchase[i];
															health_potion_in_inventory[i]++;

															// check to increase level on xp
															if (xp >= xp_to_level) {
																xp -= xp_to_level;
																xp_to_level *= 3.5;
																level++;
															}
														}
														else {
															insufficient_funds = true;
														}
													}
													else {
														potion_locked = true;
													}
												}
											}
										}
										else {
											choice_invalid = true;
										}
									}
								}

								else if (choice_4 == 0) {
									break;
								}
								else {
									choice_invalid = true;
								}
							}
						}
						else if (choice_3 == 3) { // Armor Store
							while (true)
							{
								int choice_4;
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "TOWN - ARMOR STORE" << endl;
								cout << "1) Buy" << endl;
								cout << "0) Leave" << endl;
								cout << endl;

								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter the choice: "; cin >> choice_4;

								if (choice_4 == 1) { // Buy
									bool insufficient_funds = false;
									bool armor_locked = false;
									bool armor_just_purchased = false;
									int just_purchased_index = 0;

									while (true) {
										int choice_5;
										int i = 0;
										system("cls");
										cout << player_name << endl << endl;
										cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
										cout << "Gems: " << gems << endl;
										cout << endl << endl;
										cout << "Health: " << health << "/" << max_health << endl;
										cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
										cout << endl << endl << endl << endl;

										cout << "TOWN - ARMOR STORE" << endl;

										for (i = 0; i < total_armors; i++) {
											if (!(armor_unlock_level[i] <= dungeons_completed)) {
												cout << i + 1 << ") " << "??????" << "\t - You need to complete "<< armor_unlock_level[i] - dungeons_completed << " more dungeons to unlock" << endl;
											}
											else if (armor_purchased[i] == false) {
												cout << i + 1 << ") " << armors[i] << "\t - " << armor_price[i] << " Gems" << endl;
											}
											else {
												cout << i + 1 << ") " << armors[i] << "\t - Purchased" << endl;
											}
										}
										cout << "0) Exit" << endl;

										// Input validators messages
										if (choice_invalid) {
											cout << "Choice not allowed" << endl;
											choice_invalid = false;
										}
										if (insufficient_funds) {
											cout << "Not enough Gems" << endl;
											insufficient_funds = false;
										}
										if (armor_locked) {
											cout << "Armor is locked" << endl;
											armor_locked = false;
										}
										if (armor_just_purchased) {
											cout << "You just purchased " << armors[just_purchased_index] << " for " << armor_price[just_purchased_index] << endl;
											armor_just_purchased = false;
										}
										cout << "Enter the choice: "; cin >> choice_4;

										if (choice_4 == 0) {
											break;
										}
										else if (choice_4 > 0 && choice_4 <= total_armors) {
											for (int i = 0; i < total_armors; i++) {
												if (choice_4 == i + 1) {
													if (armor_unlock_level[i] <= dungeons_completed) {

														// purchase check
														if (armor_price[i] <= gems) {
															gems -= armor_price[i];
															armor_purchased[i] = true;
														}
														else {
															insufficient_funds = true;
														}
													}
													else {
														armor_locked = true;
													}
												}
											}
										}
									}
								}
								else if (choice_4 == 0) { // Exit
									break;
								}
								else {
									choice_invalid = true;
								}
							}
						}
						else if (choice_3 == 4) { // Gym
							bool weight_locked = false;

							while (true) {
								int choice_5;
								int i = 0;
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "TOWN - GYM" << endl << endl;

								cout << "Gym Level: " << gym_level << endl;

								for (int i = 0; i < total_weights; i++) {
									if (weight_gym_level_req[i] > gym_level) {
										cout << i + 1 << ") " << weights[i] << "\t - requires " << weight_gym_level_req[i] << " Gym Level" << endl;
									}
									else {
										cout << i + 1 << ") " << weights[i] << endl;
									}
								}
								cout << "0) Exit" << endl;

								// Input validators messages
								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								if (weight_locked) {
									cout << "Weight is locked" << endl;
									weight_locked = false;
								}

								cout << "Enter the choice: "; cin >> choice_5;

								if (choice_5 == 0) {
									break;
								}
								else if (choice_5 > 0 && choice_5 <= total_weights) {
									if (weight_gym_level_req[choice_5 - 1] <= gym_level) {
										int current_weight = choice_5 - 1;
										char ch;

										while (true) {
											int gym_per = (gym_points / gym_points_to_level) * 100;

											system("cls");
											cout << player_name << endl << endl;
											cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
											cout << "Gems: " << gems << endl;
											cout << endl << endl;
											cout << "Health: " << health << "/" << max_health << endl;
											cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
											cout << endl << endl << endl << endl;

											cout << "TOWN - GYM - " << weights[current_weight] << endl;
											cout << "Do Workout to increase HP" << endl;
											cout << "Press space to do the workout or press 'Q' to exit." << endl << endl;

											cout << "Current Gym Level: " << gym_level << endl;

											cout << "Current Gym Points: " << gym_points << endl;
											cout << "Points to next Gym Level: " << gym_points_to_level << endl;

											cout << endl << endl;
											cout << "Your Workout Progress: |";

											for (int i = 0; i <= gym_per / 2; i++) {
												cout << "=";
											}
											for (int i = 0; i < 50 - gym_per / 2; i++) {
												cout << " ";
											}
											cout << "|" << endl;

											ch = _getch();

											if (ch == ' ') {
												gym_points += weight_point_award[current_weight];
												if (gym_points >= gym_points_to_level) {
													gym_level++;
													gym_points = 0;
													gym_points_to_level *= 1.2;
													int current_max_health = max_health;
													max_health *= 1.05;
													health += max_health - current_max_health;
												}
											}
											else if (ch == 'q' || ch == 'Q') {
												break;
											}
										}
									}
									else {
										weight_locked = true;
									}
								}
								else {
									choice_invalid = true;
								}
							}
							}
						else if (choice_3 == 0) {
								break;
								}
						else {
									choice_invalid = true;
									}
					}
				}
				else if (choice_2 == 2) { // Dungeon
					bool dungeon_locked = false;
					while (true) {
						int choice_3;
						system("cls");
						cout << player_name << endl << endl;
						cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
						cout << "Gems: " << gems << endl;
						cout << endl << endl;
						cout << "Health: " << health << "/" << max_health << endl;
						cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
						cout << endl << endl << endl << endl;

						cout << "DUNGEON" << endl;
						for (int i = 0; i < total_dungeons; i++) {
							if (dungeon_unlock_req[i] - dungeons_completed <= 0) {
								cout << i + 1 << ") " << dungeons[i] << endl;
							}
							else {
								cout << i + 1 << ") " << dungeons[i] << " (Locked, Must Clear the previous one first.)" << endl;
							}
						}
						cout << "0) Exit" << endl;

						cout << endl;

						if (choice_invalid) {
							cout << "Choice not allowed" << endl;
							choice_invalid = false;
						}
						if (dungeon_locked) {
							cout << "Selected Dungeon is Locked. You must clear the previous dungeon first." << endl;
							dungeon_locked = false;
						}
						cout << "Enter your choice: "; cin >> choice_3;

						if (choice_3 == 0) {
							break;
						}
						else if (choice_3 > 0 && choice_3 <= total_dungeons) {
							if (dungeon_unlock_req[choice_3 - 1] - dungeons_completed <= 0) {
								while (true) {
									int choice_4;
									system("cls");
									cout << player_name << endl << endl;
									cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
									cout << "Gems: " << gems << endl;
									cout << endl << endl;
									cout << "Health: " << health << "/" << max_health << endl;
									cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
									cout << endl << endl << endl << endl;

									cout << dungeons[choice_3 - 1] << endl;

									cout << "1) Enter" << endl;
									cout << "0) Exit" << endl;

									cout << endl;

									if (choice_invalid) {
										cout << "Choice not allowed" << endl;
										choice_invalid = false;
									}
									cout << "Enter your choice: "; cin >> choice_4;

									if (choice_4 == 0) {
										break;
									}
									else if (choice_4 == 1) {
										int d_index = choice_3 - 1;
										bool player_turn = true;
										int wave = 1;
										float current_enemy_hp = enemy_health[d_index];
										float current_enemy_max_hp = current_enemy_hp;
										bool enemy_is_dead = false;
										bool player_is_dead = false;
										bool dungeon_complete = false;
										bool boss_wave = false;
										bool inventory_opened = false;
										int player_damage = 0;
										int enemy_damage = 0;
										bool merchant_wave = false;
										int enemy_hp_perc = 0;
										bool battle_in_progress = false;
										bool merchant_shop_opened = false;
										bool insufficient_funds = false;
										bool potion_purchased_in_dungeon = false;
										int potion_purchased_in_dungeon_index = 0;
										int inv_choice = 0;
										int potion_choice = 0;
										bool inventory_potion_selected = false;
										
										while (true) {
											enemy_hp_perc = (current_enemy_hp * 100) / current_enemy_max_hp;

											int choice_5;
											system("cls");
											cout << player_name << endl << endl;
											cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
											cout << "Gems: " << gems << endl;
											cout << endl << endl;
											cout << "Health: " << health << "/" << max_health << endl;
											cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
											cout << endl << endl << endl << endl;

											if (dungeon_complete) {
												cout << "YOU HAVE COMPLETED THE DUNGEON !!!" << endl << endl;
												cout << "Press any key to continue..."; _getch();
												dungeons_completed = 0;
												dungeon_cleared[d_index] = true;
												for (int i = 0; i < total_dungeons; i++) {
													if (dungeon_cleared[i]) {
														dungeons_completed++;
													}
												}
												health = max_health;
												break;
											}
											else {
												cout << dungeons[d_index] << "\t\t WAVE: " << wave << "/" << dungeon_waves[d_index] << "  ";

												if (boss_wave) {
													cout << "-= BOSS =-";
												}

												cout << endl << endl;

												if (merchant_wave) {
													cout << "MERCHANT HAS ARRIVED, Wanna Buy Something !!!" << endl << endl << endl << endl;
												}
												else {
													cout << "CURRENT ENEMY:\t" << enemies[d_index] << endl;
													cout << "ATK: " << enemy_damage_start[d_index] << " - " << enemy_damage_end[d_index] << endl << endl;
													cout << "\t\t\tHP: " << current_enemy_hp << "/" << current_enemy_max_hp << endl;
													cout << "|";
													for (int i = 0; i < enemy_hp_perc; i++) {
														cout << "=";
													}
													for (int i = 0; i < 100 - enemy_hp_perc; i++) {
														cout << " ";
													}
													cout << "|" << endl << endl << endl << endl;
												}
											}

											if (player_turn && battle_in_progress) {
												cout << "You inflicted " << player_damage << " damage!" << endl;
												if (!enemy_is_dead) {
													cout << "Now Enemy will Attack." << endl;
													cout << "Press any key to continue..."; _getch();
													player_turn = false;
												}
											}
											else if (battle_in_progress) {
												cout << "Enemy inflicted " << enemy_damage << " damage!" << endl;
												if (!player_is_dead) {
													cout << "Now you will Attack." << endl;
													cout << "Press any key to continue..."; _getch();
													cout << endl << endl;
													player_turn = true;
												}
											}

											if (!battle_in_progress && !merchant_wave && !merchant_shop_opened && !inventory_opened) {
												battle_in_progress = true;
											}
											if (enemy_is_dead) {
												cout << "ENEMY DEAD!" << endl;
												cout << "You Got " << enemy_coins[d_index] << " Coins, " << enemy_gems[d_index] << " Gems and score increased by " << enemy_score[d_index] << "!" << endl << endl;
												cout << "Press any key to continue..."; _getch();
												enemy_is_dead = false;
												battle_in_progress = false;
												player_turn = true;
												wave++;
												if (wave > dungeon_waves[d_index]) {
													dungeon_complete = true;
												}
												else if (wave == dungeon_waves[d_index]) {
													boss_wave = true;
													current_enemy_hp = boss_health[d_index];
													current_enemy_max_hp = current_enemy_hp;
												}
												else if (wave % 5 == 0) {
													merchant_wave = true;
												}
												else {
													current_enemy_hp = enemy_health[d_index] + (enemy_health[d_index] * (wave - 1)) * 0.1;
													current_enemy_max_hp = current_enemy_hp;
												}
											}
											else if (player_is_dead) {
												cout << "YOU DIED!" << endl;
												cout << "Press any key to continue..."; _getch();
												player_is_dead = false;
												health = max_health;
												break;
											}
											else if (inventory_opened) {
												cout << "|| INVENTORY ||" << endl << endl;
												for (int i = 0; i <= total_health_potions; i++) {
													if (health_potion_in_inventory[i] > 0) {
														cout << i + 1 << ") " << health_potions[i] << "\t x" << health_potion_in_inventory[i] << endl;
													}
												}
												cout << "0) Back" << endl;

												if (choice_invalid) {
													cout << "Choice not allowed" << endl;
													choice_invalid = false;
												}

												cout << "Enter your choice: "; cin >> inv_choice;

												if (inv_choice > 0 && inv_choice <= total_health_potions) {
													inventory_potion_selected = true;
													inventory_opened = false;
												}
												else if (inv_choice == 0) {
													inventory_opened = false;
												}
												else {
													choice_invalid = true;
												}
											}
											else if (inventory_potion_selected) {
												cout << "|| INVENTORY - " << health_potions[inv_choice] << " ||" << endl << endl;

												cout << "Heals " << health_potion_HP[inv_choice] << " HP on use." << endl;
												cout << "You have " << health_potion_in_inventory[inv_choice] << " of them" << endl << endl;

												cout << "1) Use" << endl;
												cout << "0) Exit" << endl << endl;

												if (choice_invalid) {
													cout << "Choice not Allowed" << endl;
													choice_invalid = false;
												}

												cout << "Enter the Choice: "; cin >> potion_choice;

											}
											else if (merchant_wave) {
												cout << "1) Yes" << endl;
												cout << "2) No thanks" << endl;

												if(choice_invalid) {
													cout << "Choice not allowed" << endl;
													choice_invalid = false;
												}
												cout << "Enter your choice: "; cin >> choice_5;
												if (choice_5 == 1) {
													merchant_shop_opened = true;
													merchant_wave = false;
												}
												else if (choice_5 == 2) {
													merchant_wave = false;
													wave++;
													current_enemy_hp = enemy_health[d_index] + (enemy_health[d_index] * (wave - 1)) * 0.1;
													current_enemy_max_hp = current_enemy_hp;
												}
											}
											else if (merchant_shop_opened) {
												int potion_choices = 0;
												for (int i = 0; i < total_health_potions; i++) {
													if (health_potion_appears_at_dungeon_at_level[i] > level) {
														potion_choices++;
													}
												}

												for (int i = 0; i < potion_choices; i++) {
													cout << i + 1 << ") " << health_potions[i] << " - " << health_potion_price_in_dungeon[i] << " coins" << endl;
												}
												cout << "0) Exit" << endl;
												cout << endl;

												if (choice_invalid) {
													cout << "Choice not allowed" << endl;
													choice_invalid = false;
												}
												if (insufficient_funds){
													cout << "Insufficient funds!" << endl;
													insufficient_funds = false;
												}
												if (potion_purchased_in_dungeon) {
													cout << "You Purchased" << health_potions[potion_purchased_in_dungeon_index] << " for " << health_potion_price_in_dungeon[potion_purchased_in_dungeon_index] << " coins!" << endl;
													potion_purchased_in_dungeon = false;
												}
												cout << "Enter your choice: "; cin >> choice_5;
												if (choice_5 > 0 && choice_5 <= potion_choices) {
													int choice = choice_5 - 1;
													if (coins >= health_potion_price_in_dungeon[choice]) {
														coins -= health_potion_price_in_dungeon[choice];
														health_potion_in_inventory[0]++;
														potion_purchased_in_dungeon = true;
														potion_purchased_in_dungeon_index = choice;
													}
													else {
														insufficient_funds = true;
													}
												}
												else if (choice_5 == 0) {
													merchant_shop_opened = false;
													merchant_wave = true;
												}
												else {
													choice_invalid = true;
												}
											}
											else if (player_turn) {
												cout << "1) Attack" << endl;
												cout << "2) Inventory" << endl;
												cout << "0) Exit" << endl;
												cout << endl;

												if (choice_invalid) {
													cout << "Choice not allowed" << endl;
													choice_invalid = false;
												}
												cout << "Enter your choice: "; cin >> choice_5;
												if (choice_5 == 0) { // exit
													char ch;

													cout << "Are you sure you want to exit?(press 'y' to confirm or any other key to cancel. )" << endl; ch = _getch();
													if (ch == 'y') {
														break;
													}
												}
												else if (choice_5 == 1) { // attack
													player_damage = (rand() % (melee_damage_end[melee_equipped_index] - melee_damage_start[melee_equipped_index] + 1)) + melee_damage_start[melee_equipped_index];
													current_enemy_hp -= player_damage;
													if (current_enemy_hp <= 0) {
														enemy_is_dead = true;
														battle_in_progress = false;
														coins += enemy_coins[d_index];
														gems += enemy_gems[d_index];
														xp += enemy_xp[d_index];
														score += enemy_score[d_index];

														if (xp >= xp_to_level) {
															int diff = xp - xp_to_level;
															xp = diff;
															xp_to_level *= 3.5;
															level++;
														}
													}
												}
												else if (choice_5 == 2) {
													inventory_opened = true;
												}
												else {
													choice_invalid = true;
												}
											}
											else {
												enemy_damage = boss_wave? (rand() % (boss_damgae_end[d_index] - boss_damgae_start[d_index] + 1)) + boss_damgae_start[d_index] : (rand() % (enemy_damage_end[d_index] - enemy_damage_start[d_index] + 1)) + enemy_damage_start[d_index];
												if (armor_is_equipped) {
													int new_damage = enemy_damage - armor_defence[armor_equipped_index];
													if (new_damage < 1) {
														new_damage = 1;
													}
													health -= new_damage;
												}
												else {
													health -= enemy_damage;
												}
												if (health <= 0) {
													health = 0;
													player_is_dead = true;
												}
											}
										}
									}
									else {
										choice_invalid = true;
									}
								}
							}
							else {
								dungeon_locked = true;
							}
						}
						else {
							choice_invalid = true;
						}
					}
				}
				else if (choice_2 == 3) { // Inventory
					while (true)
					{
						int choice_3;
						system("cls");
						cout << player_name << endl << endl;
						cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
						cout << "Gems: " << gems << endl;
						cout << endl << endl;
						cout << "Health: " << health << "/" << max_health << endl;
						cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
						cout << endl << endl << endl << endl;

						cout << "INVENTORY" << endl;
						cout << "1) Weapons" << endl;
						cout << "2) Potions" << endl;
						cout << "3) Armor" << endl;
						cout << "0) Exit" << endl;
						cout << endl;

						if (choice_invalid) {
							cout << "Choice not allowed" << endl;
							choice_invalid = false;
						}
						cout << "Enter the choice: "; cin >> choice_3;

						if (choice_3 == 1) { // Weapons Inventory
							while (true) {
								int choice_4;
								int melee_choices = 0;
								for (int i = 0; i < total_melee_weapons; i++) {
									if (melee_purchased[i]) {
										melee_choices++;
									}
								}
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "INVENTORY - WEAPONS" << endl;

								for (int i = 0; i < total_melee_weapons; i++) {
									if (melee_purchased[i]) {
										cout << i + 1 << ") " << melee[i] << endl;
									}
								}

								cout << "0) Exit" << endl;
								cout << endl;

								// input validator
								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter the choice: "; cin >> choice_4;

								if (choice_4 == 0) {
									break;
								}
								else if (choice_4 > 0 && choice_4 <= melee_choices) { // When a weapon is selected
									bool melee_just_equipped = false;
									bool already_equipped = false;
									while (true) {
										int choice_5;
										system("cls");
										cout << player_name << endl << endl;
										cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
										cout << "Gems: " << gems << endl;
										cout << endl << endl;
										cout << "Health: " << health << "/" << max_health << endl;
										cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
										cout << endl << endl << endl << endl;

										cout << "INVENTORY - WEAPONS - " << melee[choice_4 - 1] << endl;

										cout << "Damage: " << melee_damage_start[choice_4 - 1] << " - " << melee_damage_end[choice_4 - 1] << endl << endl;

										if (choice_4 - 1 == melee_equipped_index) {
											cout << "1) *Equipped*" << endl;
										}
										else {
											cout << "1) Equip" << endl;
										}
										cout << "0) Exit" << endl;
										cout << endl;

										// input validator
										if (choice_invalid) {
											cout << "Choice not allowed" << endl;
											choice_invalid = false;
										}
										if (already_equipped) {
											cout << "Weapon Already equipped." << endl;
											already_equipped = false;
										}
										if (melee_just_equipped) {
											cout << "Weapon equipped." << endl;
											melee_just_equipped = false;
										}
										cout << "Enter the choice: "; cin >> choice_5;

										if (choice_5 == 0) {
											break;
										}
										else if (choice_5 == 1) {
											if (choice_4 - 1 == melee_equipped_index) {
												already_equipped = true;
											}
											else {
												melee_equipped_index = choice_4 - 1;
												melee_just_equipped = true;
											}
										}
										else {
											choice_invalid = true;
										}
									}
								}
								else {
									choice_invalid = true;
								}
							}
						}
						else if (choice_3 == 2) { // Potions Inventory
							int choice_4;
							int potion_choices = 0;
							for (int i = 0; i < total_health_potions; i++) {
								if (health_potion_in_inventory[i] > 0) {
									potion_choices++;
								}
							}
							while (true) {
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "INVENTORY - POTIONS" << endl << endl;

								for (int i = 0; i < total_health_potions; i++) {
									if (health_potion_in_inventory[i] > 0) {
										cout << i + 1 << ") " << health_potions[i] << "\t\tx" << health_potion_in_inventory[i] << endl;
									}
								}
								if (potion_choices == 0) {
									cout << "No Potions in Inventory." << endl << endl;
								}
								cout << "0) Exit" << endl;
								cout << endl;

								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter Choice: "; cin >> choice_4;

								if (choice_4 == 0) { // Exit
									break;
								}
								else if (choice_4 > 0 && choice_4 <= potion_choices) { // When a potion is selected 
									bool potion_used = false, health_already_max = false; int used_potion_index = 0; int diff = 0;
									while (true) {
										int choice_5;
										system("cls");
										cout << player_name << endl << endl;
										cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
										cout << "Gems: " << gems << endl;
										cout << endl << endl;
										cout << "Health: " << health << "/" << max_health << endl;
										cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
										cout << endl << endl << endl << endl;

										cout << "INVENTORY - POTIONS - " << health_potions[choice_4 - 1] << endl << endl;

										cout << "Heals " << health_potion_HP[choice_4 - 1] << " HP on use.." << endl;
										cout << "You have currently " << health_potion_in_inventory[choice_4 - 1] << " of them in inventory" << endl << endl;

										cout << "1) Use" << endl;
										cout << "0) Exit" << endl;
										cout << endl;

										// input validator
										if (choice_invalid) {
											cout << "Choice not allowed";
											choice_invalid = false;
										}
										if (potion_used) {
											cout << "You just consumed " << health_potions[used_potion_index] << " And recovered " << health_potion_HP[used_potion_index] + diff << " health.";
											potion_used = false;
										}
										if (health_already_max) {
											cout << "Your Hp is Already Maxed.";
											health_already_max = false;
										}
										cout << endl;
										cout << "Enter the choice: "; cin >> choice_5;

										if (choice_5 == 0) {
											break;
										}
										if (choice_5 == 1) { // using the potion
											used_potion_index = choice_4 - 1;

											if (health < max_health) {
												potion_used = true;
												health += health_potion_HP[used_potion_index];

												if (health > max_health) {
													diff = max_health - health;
													health = max_health;
												}

												health_potion_in_inventory[used_potion_index]--;

												if (health_potion_in_inventory[used_potion_index] == 0) {
													break;
												}
											}
											else {
												health_already_max = true;
											}

										}
										else {
											choice_invalid = true;
										}
									}
								}
								else {
									choice_invalid = true;
								}

							}
						}
						else if (choice_3 == 3) { // Armor Inventory
							int choice_4;
							int armor_choices = 0;
							for (int i = 0; i < total_armors; i++) {
								if (armor_purchased[i]) {
									armor_choices++;
								}
							}
							while (true){
								system("cls");
								cout << player_name << endl << endl;
								cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
								cout << "Gems: " << gems << endl;
								cout << endl << endl;
								cout << "Health: " << health << "/" << max_health << endl;
								cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
								cout << endl << endl << endl << endl;

								cout << "INVENTORY - ARMOR" << endl << endl;
								
								for (int i = 0; i < total_armors; i++) {
									if (armor_purchased[i]) {
										if (armor_equipped[i]) {
											cout << i + 1 << ") " << armors[i] << " (Equipped)" << endl;
										}
										else {
											cout << i + 1 << ") " << armors[i] << endl;
										}
									}
								}

								cout << "0) Exit" << endl;
								cout << endl;

								// input validator
								if (choice_invalid) {
									cout << "Choice not allowed" << endl;
									choice_invalid = false;
								}
								cout << "Enter the choice: "; cin >> choice_4;
								if (choice_4 == 0) {
									break;
								}
								else if (choice_4 > 0 && choice_4 <= total_armors) {
									if (armor_purchased[choice_4 - 1]) {
										int current_armor = choice_4 - 1;
										int choice_5;
										while (true) {
											system("cls");
											cout << player_name << endl << endl;
											cout << "Coins: " << coins << "\t\t\t\tScore: " << score << endl;
											cout << "Gems: " << gems << endl;
											cout << endl << endl;
											cout << "Health: " << health << "/" << max_health << endl;
											cout << "Level: " << level << "\t\t\t\tXp:" << xp << "/" << xp_to_level << endl;
											cout << endl << endl << endl << endl;

											cout << "INVENTORY - ARMOR - " << armors[current_armor] << endl << endl;

											if (armor_equipped[current_armor]) {
												cout << "1) Unequip" << endl;
											}
											else {
												cout << "1) Equip" << endl;
											}
											cout << "0) Exit" << endl;

											// input validator
											if (choice_invalid) {
												cout << "Choice not allowed";
												choice_invalid = false;
											}
											cout << "Enter the choice: "; cin >> choice_5;
											if (choice_5 == 1) {
												if (armor_equipped[current_armor]) {
													armor_equipped[current_armor] = false;
													armor_is_equipped = false;
													armor_equipped_index = current_armor;
												}
												else {
													armor_equipped[current_armor] = true;
													armor_equipped_index = current_armor;
													armor_is_equipped = true;
													// unequip other armor
													for (int i = 0; i < total_armors; i++) {
														if (i != current_armor) {
															armor_equipped[i] = false;
														}
													}

												}
											}
											else if (choice_5 == 0) {
												break;
											}
											else {
												choice_invalid = true;
											}
										}
									}
									else {
										choice_invalid = true;
									}
								}
								else {
									choice_invalid = true;
								}
							}
						}
						else if (choice_3 == 0) { // Exit
							break;
						}
						else {
							system("cls");
							choice_invalid = true;
						}
					}
					system("cls");
					}
				else if (choice_2 == 0) { // Exit
						break;
						}
				else {
							choice_invalid = true;
							}
			}
		}
		else if (choice_1 == 0) { // Exit
			cout << "Thanks for Playing..." << endl;
			return 0;
		}
		else {
			choice_invalid = true;
		}
	}
}