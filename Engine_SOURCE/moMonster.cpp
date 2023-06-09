#include "moMonster.h"
#include "moRenderer.h"
#include "moGraphics.h"
#include <random>

namespace mo {
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{

		float randomPos[2] = {};
		float randomColor[3] = {};

		for (int i = 0; i < 2; i++)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
			randomPos[i] = dis(gen);
		}

		for (int i = 0; i < 3; i++)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> dis(0.0f, 1.0f);
			randomColor[i] = dis(gen);
		}

		SetPos(Vector4(randomPos[0], randomPos[1], 0.0f, 1.0f));
		SetColor(Vector4(randomColor[0], randomColor[1], randomColor[2], 1.0f));
		SetScale(Vector4(0.5f, 0.0f, 0.0f, 0.0f));

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
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Transform)]->SetData(GetPosAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Transform)]->Bind(eShaderStage::VS);

		renderer::constantBuffer[UINT(mo::graphics::eCBType::Color)]->SetData(GetColorAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Color)]->Bind(eShaderStage::VS);

		renderer::constantBuffer[UINT(mo::graphics::eCBType::Scale)]->SetData(GetScaleAdressOf());
		renderer::constantBuffer[UINT(mo::graphics::eCBType::Scale)]->Bind(eShaderStage::VS);

		GameObject::Render();
	}
}