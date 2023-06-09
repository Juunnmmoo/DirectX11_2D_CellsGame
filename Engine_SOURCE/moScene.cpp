#include "moScene.h"
#include "moPlayer.h"
#include "moMonster.h"

namespace mo {
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		Player* player = new Player();
		mGameObjects.push_back(player);

		Monster* monster = new Monster();
		mGameObjects.push_back(monster);

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Initialize();
		}
	}
	void Scene::Update()
	{

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}
	}
	void Scene::Release()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}
}