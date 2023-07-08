#pragma once
#include "../../../../java/IClass.h"

struct CGameSettings : IClass
{
	CGameSettings();

	jclass GetClass();
	jobject GetInstance();
	jobject GetUseItem();

	int GetThirdPersonView();
	float GetFOV();
	void SetFullscreenKeyToNull();
	void RestoreFullscreenKey();
};

