#pragma once
#include "moEntity.h"

namespace mo {

	using namespace enums;

	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
		const eComponentType mType;

	};
}

