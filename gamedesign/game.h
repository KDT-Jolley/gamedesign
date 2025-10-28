#pragma once
#include <string>
#include <vector>


// コンソールゲームの基本クラス
class Game {
public:
	// コンストラクタ
	Game(int n, const std::string& t) : num(n), HP(t) {}
	
	
	void showStatus(std::string name, int HP) {
		std::cout << name << "HP" << HP << std::endl;
	}

	void showDamage(int Damege) {
		std::cout << Damege << "のダメージ！" << std::endl;
	}

	void showMessage(std::string msg) {
		std::cout << msg << std::endl;
	}
	// ゲームの情報を表示するメソッド
	void displayInfo() const {
		std::cout << "HP " << num << "のダメージ！" << HP << std::endl;
	}

	//　ファクトリーパターン
	static Game createGame(int n, const std::string& t) {
		return Game(n, t);
	}
	//　データテーブル
	static std::vector<Game> gameTable() {
		return {
			Game(5, "プレイヤー"),
			Game(6, "スライム"),
			Game(7, "攻撃")
		};
	}

	//　シングルトン
	static Game& getInstance() {
		static Game instance(8, "シングルトン");
		return instance;
	}

	//　有限状態機械
	enum class State {
		TITLE,
		GAME,
		DEBUG,
		FACTORY,
		NWE_TITLE,
		NWE_GAME,
		NWE_DEBUG,
		SINGLETON,
	};
	State currentState = State::TITLE;

	// ゲームの更新メソッド
	void update() {
		// キー入力を取得
		std::cin >> inputKey;
		// 入力に応じて状態を変更
		switch (inputKey) {
		case '1':
			currentState = State::TITLE;
			break;
		case '2':
			currentState = State::GAME;
			break;
		case '3':
			currentState = State::DEBUG;
			break;
		case '4':
			currentState = State::FACTORY;
			break;
		case '5':
			currentState = State::NWE_TITLE;
			break;
		case '6':
			currentState = State::NWE_GAME;
			break;
		case '7':
			currentState = State::NWE_DEBUG;
			break;
		case '8':
			currentState = State::SINGLETON;
			break;
		default:
			break;
		}

	}


	


	
private:
	// ゲームの番号
	int num;
	// ゲームのタイトル
	std::string HP;
	// キー入力
	char inputKey;



	


};