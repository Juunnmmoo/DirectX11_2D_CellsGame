#include "moRenderer.h"

namespace mo::renderer {

	Vertex vertexes[4] = {};
	mo::Mesh* mesh = nullptr;
	mo::Shader* shader = nullptr;
	std::vector<mo::graphics::ConstantBuffer*> constantBuffer = {};

	void SetUpState()
	{
		D3D11_INPUT_ELEMENT_DESC arrLayout[2] = {};

		arrLayout[0].AlignedByteOffset = 0;
		arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		arrLayout[0].InputSlot = 0;
		arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[0].SemanticName = "POSITION";
		arrLayout[0].SemanticIndex = 0;

		arrLayout[1].AlignedByteOffset = 12;
		arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		arrLayout[1].InputSlot = 0;
		arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[1].SemanticName = "COLOR";
		arrLayout[1].SemanticIndex = 0;


		mo::graphics::GetDevice()->CreateInputLayout(arrLayout, 2
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());
	};

	void LoadBuffer()
	{
		mesh = new mo::Mesh();
		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// ConstantBuffer
		constantBuffer.push_back(new mo::graphics::ConstantBuffer(eCBType::Transform));
		constantBuffer[UINT(eCBType::Transform)]->Create(sizeof(Vector4));

		constantBuffer.push_back(new mo::graphics::ConstantBuffer(eCBType::Color));
		constantBuffer[UINT(eCBType::Color)]->Create(sizeof(Vector4));

		constantBuffer.push_back(new mo::graphics::ConstantBuffer(eCBType::Scale));
		constantBuffer[UINT(eCBType::Scale)]->Create(sizeof(Vector4));
	};

	void LoadShader()
	{
		shader = new mo::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
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
		delete mesh;
		delete shader;

		for (ConstantBuffer* constants : constantBuffer)
			delete constants;
	}
}