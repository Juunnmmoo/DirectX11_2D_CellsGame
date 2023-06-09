#include "moGameObject.h"
#include "moRenderer.h"
#include "moGraphicDevice_Dx11.h"

namespace mo {
	GameObject::GameObject()
		: mState(eState::Active)
		, mPos(Vector2::Zero)
	{ 
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Update()
	{
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	void GameObject::Release()
	{
	}
}