#pragma once
#include <string>
#include <vector>
#include "game.h"

template<typename T>
// オブジェクトプールの基本クラス
class ObjectPool {
public:
	// コンストラクタ
	ObjectPool(size_t size) : poolSize(size) {
		for (size_t i = 0; i < poolSize; ++i) {
			available.push_back(true);
		}
	}
	// オブジェクトを取得するメソッド
	T* acquire() {
		for (size_t i = 0; i < poolSize; ++i) {
			if (available[i]) {
				available[i] = false;
				return &pool[i];
			}
		}
		return nullptr; // プールが空の場合
	}
	// オブジェクトを解放するメソッド
	void release(T* obj) {
		for (size_t i = 0; i < poolSize; ++i) {
			if (&pool[i] == obj) {
				available[i] = true;
				return;
			}
		}
	}
private:
	size_t poolSize;
	std::vector<T> pool;
	std::vector<bool> available;
};

