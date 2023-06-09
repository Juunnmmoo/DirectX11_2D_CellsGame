#include "moRenderer.h"

namespace mo::renderer {

	Vertex vertexes[4] = {};
	std::vector<UINT> indexes = {};

	mo::Shader* shader = nullptr;
	mo::graphics::ConstantBuffer* constantBuffer = nullptr;

	void SetUpState()
	{
	};

	void LoadBuffer()
	{
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		// ConstantBuffer
		/*constantBuffer = new mo::graphics::ConstantBuffer(eCBType::Transform);
		constantBuffer->Create(sizeof(Vector4));*/

		/*Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		constantBuffer->SetData(&pos);
		constantBuffer->Bind(eShaderStage::VS);*/
	};

	void LoadShader()
	{
		/*shader = new mo::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");*/
	};

	void Initialize()
	{
		// »ç°¢Çü
		vertexes[0].pos = Vector3(-0.05f, 0.1f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.05f, 0.1f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.05f, -0.1f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.05f, -0.1f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		LoadBuffer();
		LoadShader();
		SetUpState();
	}
	void Release()
	{
		delete shader;
		delete constantBuffer;
	}
}