#include "moScene.h"
#include "moPlayer.h"
#include "moMonster.h"
#include "moTime.h"
#include "moPlayer.h"
#include "moRenderer.h"
#include <cmath>

namespace mo {
	Scene::Scene()
		: mTime(0.0f)
		, mPlayer(nullptr)
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		mPlayer = new Player();

		Monster* monster = new Monster();
		mMonsters.push_back(monster);

		mPlayer->Initialize();
		for (GameObject* gameObj : mMonsters)
		{
			gameObj->Initialize();
		}
	}
	void Scene::Update()
	{
		mTime += Time::DeltaTime();

		if (mTime > 3.0f)
		{
			mTime = 0.0f;
			Monster* monster = new Monster();
			monster->Initialize();
			mMonsters.push_back(monster);
		}

		mPlayer->Update();
		for (GameObject* gameObj : mMonsters)
		{
			gameObj->Update();
		}

		for (GameObject* gameObj : mMonsters)
		{
			
			if (gameObj->GetState() == GameObject::eState::Active)
			{
				if (CheckColider(gameObj)) 
				{
					gameObj->SetScale(Vector4(0.0f, 0.0f, 0.0f, 0.0f));
					gameObj->Destroyed();

					float x = mPlayer->GetScale().x;
					x = x + 0.1;
					mPlayer->SetScale(Vector4(x, 0.0f, 0.0f, 0.0f));
				}
			}
		}

	}

	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		mPlayer->Render();
		for (GameObject* gameObj : mMonsters)
		{
			gameObj->Render();
		}
	}
	void Scene::Release()
	{
		delete mPlayer;
		mPlayer = nullptr;

		for (GameObject* gameObj : mMonsters)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}
	bool Scene::CheckColider(GameObject* monster)
	{
		Vector2 origigLength = Vector2(mo::renderer::vertexes[1].pos.x, mo::renderer::vertexes[1].pos.y);

		Vector4 monsterPos = monster->GetPos();
		Vector4 playerPos = mPlayer->GetPos();

		Vector4 originMonsterScale = monster->GetScale();
		Vector4 originPlayerScale = mPlayer->GetScale();

		Vector2 monsterCollider = Vector2((origigLength.x * originMonsterScale.x), (origigLength.y * originMonsterScale.x));
		Vector2 playerCollider = Vector2((origigLength.x * originPlayerScale.x), (origigLength.y * originPlayerScale.x));

		if (fabs(playerCollider.x + monsterCollider.x) > fabs(playerPos.x - monsterPos.x)
			&& fabs(playerCollider.y + monsterCollider.y) > fabs(playerPos.y - monsterPos.y))
			return true;

		return false;
	}
}