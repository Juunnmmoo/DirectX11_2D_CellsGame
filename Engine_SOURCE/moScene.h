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

	private:
		std::vector<GameObject*> mGameObjects;

		GameObject* mGameObj;
	};
}

