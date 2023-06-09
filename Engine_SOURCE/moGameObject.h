#pragma once
#include "moEntity.h"
#include "moConstantBuffer.h"

namespace mo {

	using namespace graphics;
	using namespace math;

	class Mesh;
	class Shader;
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


		Mesh* GetMesh() { return mMesh; }
		std::vector<ConstantBuffer*> GetConstantsBuffer() { return mConstantBuffer; }

		Vector2 GetPos() { return mPos; }
		void SetPos(Vector2 pos) { mPos = pos; }

	private:
		eState mState;
		Mesh* mMesh;
		Shader* mShader;
		std::vector<ConstantBuffer*> mConstantBuffer;
		Vector2 mPos;

	};

}
