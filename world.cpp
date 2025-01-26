#include "world.h"

/* Ugly ass file but me = tired */

std::vector<Enemy> World::enemies = {};

Enemy World::GetNextEnemy() {
	return enemies[0];
}

Enemy World::GetUpdatedEnemy(Enemy enemy) {
	std::vector<Enemy>::iterator it = std::find(enemies.begin(), enemies.end(), enemy);
	return *it;
}

void World::AddEnemy(Enemy newEnemy) {
	for (Enemy& enemy : enemies) {
		if (enemy.objectId == newEnemy.objectId) {
			enemy.isDead = newEnemy.isDead;

			return;
		}
	}

	if (newEnemy.isDead) {
		return;
	}

	enemies.push_back(newEnemy);
}

void World::RemoveEnemy(Enemy enemy) {
	enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}