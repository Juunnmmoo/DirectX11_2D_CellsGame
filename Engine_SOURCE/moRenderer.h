#pragma once
#include "momoEngine.h"
#include "moGraphicDevice_Dx11.h"
#include "moMesh.h"
#include "moShader.h"
#include "moConstantBuffer.h"

using namespace mo::math;
namespace mo::renderer {

	struct Vertex {
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern mo::Mesh* mesh;
	extern mo::Shader* shader;
	extern mo::graphics::ConstantBuffer* constantBuffer;

	void Initialize();
	void Release();
}

