#pragma once
#include <string>
#include <vector>
#include "game.h"

// オブジェクトプールの基本クラス
class ObjectPool {
public:
	// コンストラクタ
	ObjectPool(size_t size) : poolSize(size) {
		for (size_t i = 0; i < poolSize; ++i) {
			pool.push_back(Game(i, "PooledGame" + std::to_string(i)));
			available.push_back(true);
		}
	}
	// オブジェクトを取得するメソッド
	Game* acquire() {
		for (size_t i = 0; i < poolSize; ++i) {
			if (available[i]) {
				available[i] = false;
				return &pool[i];
			}
		}
		return nullptr; // プールが空の場合
	}
	// オブジェクトを解放するメソッド
	void release(Game* obj) {
		for (size_t i = 0; i < poolSize; ++i) {
			if (&pool[i] == obj) {
				available[i] = true;
				return;
			}
		}
	}
private:
	size_t poolSize;
	std::vector<Game> pool;
	std::vector<bool> available;
};

