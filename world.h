#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

struct Enemy {
	int objectId;
	bool isDead = false;

	bool operator==(const Enemy& other) const {
		return objectId == other.objectId;
	}
};

class World {
	private:
		World() = delete;

		static std::vector<Enemy> enemies;
	public:
		static Enemy GetNextEnemy();
		static Enemy GetUpdatedEnemy(Enemy enemy);
		static void AddEnemy(Enemy enemy);
		static void RemoveEnemy(Enemy enemy);
};