#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace mo::graphics {

	enum class eShaderStage
	{
		VS,
		HS,
		DS,
		GS,
		PS,
		CS,
		End,
	};
	
	enum class eCBType
	{
		Transform,
		End,
	};
	
	struct GpuBuffer
	{
		Microsoft::WRL::ComPtr<ID3D11Buffer> buffer;
		D3D11_BUFFER_DESC desc;
	
		GpuBuffer()
			: buffer(nullptr)
			, desc{}
		{
		}
		virtual ~GpuBuffer() = default;
	
	};
}