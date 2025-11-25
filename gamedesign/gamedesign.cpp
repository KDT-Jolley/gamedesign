#include <iostream>
#include "game.h"
#include "ObjectPool.h"
#include <string>
#include <vector>


int main()
{
	//　シングルトンパターンを使用してゲームのインスタンスを取得
	Game game;

	// 有限状態機械の状態を変更
	game.currentState = Game::State::TITLE;
	// ゲームを始める
	std::cout << "タイトル" << std::endl;
	std::cout << "キーを入力してください" << std::endl;

	// ゲームの更新をシミュレート
	game.changeState();
	game.Update();
	// 更新後の状態を表示

	// プログラム終了
	return 0;

}

