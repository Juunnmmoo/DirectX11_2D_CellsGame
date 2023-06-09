#include "moGameObject.h"
#include "moRenderer.h"
#include "moGraphicDevice_Dx11.h"
#include "moMesh.h"
#include "moShader.h"
#include "moConstantBuffer.h"

namespace mo {
	GameObject::GameObject()
		: mState(eState::Active)
		, mMesh(nullptr)
		, mShader(nullptr)
		, mPos(Vector2::Zero)
	{ 
		mMesh = new Mesh();

		mShader = new Shader();
		mShader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		mShader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");

		mConstantBuffer.push_back(new ConstantBuffer(eCBType::Transform));
		mConstantBuffer[UINT(eCBType::Transform)]->Create(sizeof(Vector4));

	}
	GameObject::~GameObject()
	{
		delete mMesh;
		delete mShader;
		
		for (ConstantBuffer* constants : mConstantBuffer)
		{
			delete constants;
		}
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
		/*renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);*/

		mMesh->BindBuffer();
		mShader->Binds();
		graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}
	void GameObject::Release()
	{
	}
}