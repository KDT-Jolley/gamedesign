#include <iostream>
#include "game.h"
#include "ObjectPool.h"
#include <string>
#include <vector>


int main()
{
	// ゲームのリストを作成
	std::vector<Game> games;
	games.emplace_back(1, "タイトル");
	games.emplace_back(2, "ゲーム");
	games.emplace_back(3, "デバック");
	// 各ゲームの情報を表示
	for (const auto& game : games) {
		game.displayInfo();
	}

	// ファクトリーパターンを使用してゲームを作成
	Game newGame = Game::createGame(4, "ファクトリーパターン");
	newGame.displayInfo();
	// データテーブルからゲームのリストを取得
	std::vector<Game> gameList = Game::gameTable();
	for (const auto& game : gameList) {
		game.displayInfo();
	}

	//　シングルトンパターンを使用してゲームのインスタンスを取得
	Game& singletonGame = Game::getInstance();
	singletonGame.displayInfo();

	// 有限状態機械の状態を変更
	singletonGame.currentState = Game::State::TITLE;
	// 現在の状態を表示
	switch (singletonGame.currentState) {
	case Game::State::TITLE:
		std::cout << "数字を選択してください" << std::endl;
		break;
	case Game::State::GAME:
		std::cout << "状態：GAME" << std::endl;

		break;
	case Game::State::DEBUG:
		std::cout << "状態：DEBUG" << std::endl;
		break;
	case Game::State::FACTORY:
		std::cout << "状態：FACTORY" << std::endl;
		break;
	case Game::State::NWE_TITLE:
		std::cout << "状態：NWE_TITLE" << std::endl;
		break;
	case Game::State::NWE_GAME:
		std::cout << "状態：NWE_GAME" << std::endl;
		break;
	case Game::State::NWE_DEBUG:
		std::cout << "状態：NWE_DEBUG" << std::endl;
		break;
	case Game::State::SINGLETON:
		std::cout << "状態：SINGLETON" << std::endl;
		break;
	}

	// ゲームの更新をシミュレート
	singletonGame.update();
	// 更新後の状態を表示
	switch (singletonGame.currentState) {
	case Game::State::TITLE:
		std::cout << "1ダメージ食らった" << std::endl;
		break;
	case Game::State::GAME:
		std::cout << "2ダメージ食らった" << std::endl;
		break;
	case Game::State::DEBUG:
		std::cout << "3ダメージ食らった" << std::endl;
		break;
	case Game::State::FACTORY:
		std::cout << "4ダメージ食らった" << std::endl;
		break;
	case Game::State::NWE_TITLE:
		std::cout << "5ダメージ食らった" << std::endl;
		break;
	case Game::State::NWE_GAME:
		std::cout << "6ダメージ食らった" << std::endl;
		break;
	case Game::State::NWE_DEBUG:
		std::cout << "7ダメージ食らった" << std::endl;
		break;
	case Game::State::SINGLETON:
		std::cout << "8ダメージ食らった" << std::endl;
		break;
	}

	// オブジェクトプールを作成
	ObjectPool pool(2);
	// オブジェクトプールからゲームオブジェクトを取得
	Game* pooledGame1 = pool.acquire();
	if (pooledGame1) {
		pooledGame1->displayInfo();
	}
	Game* pooledGame2 = pool.acquire();
	if (pooledGame2) {
		pooledGame2->displayInfo();
	}
	// オブジェクトプールからもう一つゲームオブジェクトを取得（プールが空の場合）
	Game* pooledGame3 = pool.acquire();
	if (!pooledGame3) {
		std::cout << "オブジェクトプールが空です。" << std::endl;
	}
	// ゲームオブジェクトを解放
	pool.release(pooledGame1);
	// 再度オブジェクトプールからゲームオブジェクトを取得
	pooledGame3 = pool.acquire();
	if (pooledGame3) {
		pooledGame3->displayInfo();
	}

	
	

	// プログラム終了
	return 0;

}

