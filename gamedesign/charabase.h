#pragma once
#include <iostream>
#include <string>


class CharaBase
{
public:
	int hp;
	int atk;
	std::string name;

	CharaBase(int arg_hp, int arg_atk, std::string arg_name) {
		hp = arg_hp;
		atk = arg_atk;
		name = arg_name;
	}

	void attack(int& hp)
	{
		hp -= atk;
	}

	void Heal()
	{
		hp = 10;
		std::cout << "hp‚ª" << hp << "‚É‚È‚Á‚½" << std::endl;
	}
};