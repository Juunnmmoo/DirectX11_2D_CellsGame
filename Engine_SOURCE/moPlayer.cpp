#include "moPlayer.h"
#include "moRenderer.h"
#include "moInput.h"
#include "moTime.h"
#include "moGraphics.h"

namespace mo {
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		SetScale(Vector4(1.0f, 0.0f, 0.0f, 0.0f));
		SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));

		GameObject::Initialize();
	}
	void Player::Update()
	{
		Vector4 mPos = GetPos();

		if (Input::GetKey(eKeyCode::UP))
		{
			mPos.y += 1.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			mPos.y -= 1.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::RIGHT))
		{
			mPos.x += 1.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			mPos.x -= 1.0f * Time::DeltaTime();
		}

		SetPos(mPos);

		GameObject::Update();
	}
	void Player::LateUpdate()
	{
	}
	void Player::Render()
	{
		
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Transform)]->SetData(GetPosAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Transform)]->Bind(eShaderStage::VS);

		renderer::constantBuffer[UINT(mo::graphics::eCBType::Color)]->SetData(GetColorAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Color)]->Bind(eShaderStage::VS);

		renderer::constantBuffer[UINT(mo::graphics::eCBType::Scale)]->SetData(GetScaleAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Scale)]->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}