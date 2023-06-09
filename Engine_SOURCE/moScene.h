#pragma once
#include "moEntity.h"
#include "moGameObject.h"

namespace mo {
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Release();

		bool CheckColider(GameObject* monster);

	private:
		float mTime;

		std::vector<GameObject*> mMonsters;
		class Player* mPlayer;
	};
}

