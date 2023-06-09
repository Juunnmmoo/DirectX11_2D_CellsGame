#pragma once
#include "moGameObject.h"

namespace mo {
	using namespace math;
	class Player : public GameObject
	{
	public:
		Player();
		~Player() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};

}
