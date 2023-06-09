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

		Vector4 GetPos() { return mPos; }
		void SetPos(Vector4 pos) { mPos = pos; }

		Vector4 GetColor() { return mColor; }
		void SetColor(Vector4 color) { mColor = color; }

		Vector4 GetScale() { return mScale; }
		void SetScale(Vector4 scale) { mScale = scale; }

		Vector4* GetPosAdressOf() { return &mPos; }
		Vector4* GetColorAdressOf() { return &mColor; }
		Vector4* GetScaleAdressOf() { return &mScale; }

		void Destroyed() { mState = eState::Dead; }
		eState GetState() { return mState; }

	private:
		eState mState;
		Vector4 mPos;
		Vector4 mColor;
		Vector4 mScale;

	};

}
