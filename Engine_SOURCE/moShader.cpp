#include "moShader.h"

namespace mo {
	Shader::Shader()
		: mInputLayout(nullptr)
		, mTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
	{
	}
	Shader::~Shader()
	{
		mInputLayout->Release();
	}
	HRESULT Shader::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	bool Shader::Create(const eShaderStage stage, const std::wstring& fileName, const std::string& funcName)
	{
		std::filesystem::path shaderPath
			= std::filesystem::current_path().parent_path();
		shaderPath += L"\\Shader_SOURCE\\";

		std::filesystem::path fullPath(shaderPath.c_str());
		fullPath += fileName;

		if (stage == eShaderStage::VS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "vs_5_0", mVSBlob.GetAddressOf());
			GetDevice()->CreateVertexShader(mVSBlob->GetBufferPointer()
				, mVSBlob->GetBufferSize(), mVS.GetAddressOf());

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
				, GetVSCode()
				, GetInputLayoutAddressOf());

		}
		else if (stage == eShaderStage::PS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "ps_5_0", mPSBlob.GetAddressOf());
			GetDevice()->CreatePixelShader(mPSBlob->GetBufferPointer()
				, mPSBlob->GetBufferSize(), mPS.GetAddressOf());
		}

		return true;
	}
	void Shader::Binds()
	{
		GetDevice()->BindPrimitiveTopology(mTopology);
		GetDevice()->BindInputLayout(mInputLayout);

		GetDevice()->BindVertexShader(mVS.Get());
		GetDevice()->BindPixelShader(mPS.Get());
	}
}