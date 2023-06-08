#pragma once
#include "momoEngine.h"
#include "moGraphicDevice_Dx11.h"
#include "moScene.h"

namespace mo {
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void SetWindow(HWND hwnd, UINT width, UINT height);

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HWND GetHwnd() { return mHwnd; }

	private:
		bool mbInitialize = false;

		// 오로지 한개의 객체만 만들수 있는 스마트 포인터
		std::unique_ptr<mo::graphics::GraphicDevice_Dx11> graphicDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;

		Scene* mScene;
	};
}

