#include "moPlayer.h"
#include "moMesh.h"
#include "moRenderer.h"
#include "moConstantBuffer.h"
#include "moInput.h"
#include "moTime.h"

namespace mo {
	Player::Player()
		: mPos(Vector2::Zero)
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GetMesh()->CreateVertexBuffer(renderer::vertexes, 4);
		GetMesh()->CreateIndexBuffer(renderer::indexes.data(), renderer::indexes.size());

		mPos = GetPos();

		GameObject::Initialize();
	}
	void Player::Update()
	{
		mPos = GetPos();

		if (Input::GetKey(eKeyCode::UP))
		{
			mPos.y += 0.1 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			mPos.y -= 0.1 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::RIGHT))
		{
			mPos.x += 0.1 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			mPos.x -= 0.1 * Time::DeltaTime();
		}

		SetPos(mPos);

		GameObject::Update();
	}
	void Player::LateUpdate()
	{
	}
	void Player::Render()
	{
		Vector4 pos(GetPos().x, GetPos().y, 0.0f, 1.0f);
		GetConstantsBuffer()[UINT(eCBType::Transform)]->SetData(&pos);
		GetConstantsBuffer()[UINT(eCBType::Transform)]->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}