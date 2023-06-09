#pragma once
#include "moEntity.h"

namespace mo {

	using namespace math;
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Release();

		Vector2 GetPos() { return mPos; }
		void SetPos(Vector2 pos) { mPos = pos; }

	private:
		eState mState;
		Vector2 mPos;

	};

}
