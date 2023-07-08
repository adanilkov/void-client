#include "Throwpot.h"
#include "../../commonData.h"
#include "../../../sdk/sdk.h"
#include "../../../menu/menu.h"
#include "../../../util/logger.h"
#include "../../../sdk/strayCache.h"
#include "../../../sdk/net/minecraft/client/settings/GameSettings.h"
#include "../../../sdk/net/minecraft/entity/player/InventoryPlayer.h"
#include "../../../sdk/net/minecraft/item/ItemStack.h"
#include "../../../sdk/java/lang/String.h"
#include <chrono>


bool running = false;
long LastThrowTime = 0;
int initialIndex;

void Throwpot::Update()
{
	if (!Enabled) return;
	if (!CommonData::SanityCheck()) return;
	if (SDK::Minecraft->IsInGuiState()) return;
	long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (LastThrowTime == 0) LastThrowTime = milli;
	if ((milli - LastThrowTime) < (50)) return;
	jobject useItemObj = SDK::Minecraft->gameSettings->GetUseItem();
	jobject inventoryInstance = SDK::Minecraft->thePlayer->GetInventory().GetInstance();
	if (GetAsyncKeyState(0x43) && 1 && !SDK::Minecraft->IsInGuiState()) //(0x43) - C key ---- double checking gui in state to prevent flickering of item bar after leaving gui/chat
	{
		if (!running)
		{
			initialIndex = Java::Env->GetIntField(inventoryInstance, StrayCache::inventoryPlayer_currentItem);
			Java::Env->CallVoidMethod(useItemObj, StrayCache::keyBinding_setKeyBindState, true);
		}
		for (int i = 8; i >= 0; i--) 
		{
			jobject item = Java::Env->CallObjectMethod(inventoryInstance, StrayCache::inventoryPlayer_getStackInSlot, i);
			if (item == NULL) continue;
			CItemStack itemAtIndex = CItemStack(item);
			String str = String(itemAtIndex.GetName());
			if (str.ToString() != "Splash Potion of Healing") continue;
			Java::Env->SetIntField(inventoryInstance, StrayCache::inventoryPlayer_currentItem, i);
			running = true;
			//if (running) Java::Env->CallVoidMethod(useItemObj, StrayCache::keyBinding_setKeyBindState, false);
		}
	}
	else if (running)
	{
		Java::Env->CallVoidMethod(useItemObj, StrayCache::keyBinding_setKeyBindState, false);
		Java::Env->SetIntField(inventoryInstance, StrayCache::inventoryPlayer_currentItem, initialIndex);
		LastThrowTime = 0;
		running = false;
	}
}