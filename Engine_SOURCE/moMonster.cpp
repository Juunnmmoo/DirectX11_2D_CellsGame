#include "moMonster.h"
#include "moRenderer.h"


namespace mo {
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();

	}
	void Monster::LateUpdate()
	{
	}
	void Monster::Render()
	{
		Vector4 pos(0.5f, 0.3f, 0.0f, 1.0f);
		renderer::constantBuffer->SetData(&pos);
		renderer::constantBuffer->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}