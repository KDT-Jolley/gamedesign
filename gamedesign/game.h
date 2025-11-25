#pragma once
#include <string>
#include <vector>
#include "charabase.h"
#include <random>

// コンソールゲームの基本クラス
class Game
{
	CharaBase player = CharaBase(10, 2, "勇者");
	CharaBase enemy = CharaBase(4, 1, "スライム");
public:
	//　有限状態機械
	enum State {
		TITLE,
		GAME,
	};


	int currentState = State::TITLE;

	// コンストラクタ
	Game() : currentState(1) {}


	void showStatus(std::string name, int HP) {
		std::cout << name << "HP" << HP << std::endl;
	}

	void showDamage(int Damege) {
		std::cout << Damege << "のダメージ！" << std::endl;
	}

	void showMessage(std::string msg) {
		std::cout << msg << std::endl;
	}

	// ゲームステートに切り替え
	void changeState() {
		// キー入力を取得
		int a = 0;
		std::cin >> a;
		currentState = State::GAME;
		std::cout << "戦闘開始" << std::endl;
		std::cout << "スライムが現れた！" << std::endl;

	}

	void Update()
	{
		int inputNum = 0;
		while (true)
		{
			std::cout << player.name << ":" << player.hp << "/10\n";
			std::cout << "1で攻撃\n";
			std::cout << "2で回復\n";
			std::cin >> inputNum;
			enemy.atk = rand() % 10 + 1;

			switch (inputNum)
			{
			case 1:
				player.attack(enemy.hp);
				std::cout<<  player.name <<"が"<< enemy.name << "に" << player.atk << "のダメージを与えた" << std::endl;

				enemy.attack(player.hp);
				std::cout << enemy.name << "が" << player.name << "に" << enemy.atk << "のダメージを与えた" << std::endl;
				break;
			case 2:
				player.Heal();
				enemy.attack(player.hp);
				std::cout << enemy.name << "が" << player.name << "に" << enemy.atk << "のダメージを与えた" << std::endl;
				break;
			default:
				break;
			}

			if (enemy.hp <= 0 && player.hp <= 0)
			{
				std::cout << "相打ち\n";
				break;
			}
			else if (enemy.hp <= 0)
			{
				std::cout << "かった\n";
				break;
			}
			else if (player.hp <= 0)
			{
				std::cout << "負けた\n";
				break;
			}

		}
	}
};