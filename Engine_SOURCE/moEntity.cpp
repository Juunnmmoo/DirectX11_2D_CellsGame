#include "moEntity.h"

namespace mo {
	Entity::Entity()
		: mName(L"")
		, mID((UINT64)this)
	{

	}

	Entity::~Entity()
	{
	}
}