#include "moPlayer.h"
#include "moRenderer.h"
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
		mPos = GetPos();

		GameObject::Initialize();
	}
	void Player::Update()
	{
		mPos = GetPos();

		if (Input::GetKey(eKeyCode::UP))
		{
			mPos.y += 0.5 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			mPos.y -= 0.5 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::RIGHT))
		{
			mPos.x += 0.5 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			mPos.x -= 0.5 * Time::DeltaTime();
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
		renderer::constantBuffer->SetData(&pos);
		renderer::constantBuffer->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}