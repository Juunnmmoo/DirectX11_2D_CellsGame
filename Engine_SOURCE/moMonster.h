#pragma once
#include "moGameObject.h"

namespace mo {
	using namespace math;
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};

}
