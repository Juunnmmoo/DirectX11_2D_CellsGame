#include "moMonster.h"
#include "moMesh.h"
#include "moRenderer.h"
#include "moConstantBuffer.h"


namespace mo {
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		GetMesh()->CreateVertexBuffer(renderer::vertexes, 4);
		GetMesh()->CreateIndexBuffer(renderer::indexes.data(), renderer::indexes.size());

		

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
		GetConstantsBuffer()[UINT(eCBType::Transform)]->SetData(&pos);
		GetConstantsBuffer()[UINT(eCBType::Transform)]->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}