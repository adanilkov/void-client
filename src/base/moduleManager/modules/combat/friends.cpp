#include "friends.h"
#include "../../commonData.h"
#include "../../../sdk/sdk.h"
#include "../../../menu/menu.h"
#include "../../../util/logger.h"
#include "../../../sdk/net/minecraft/util/MovingObjectPosition.h"
#include "../../../sdk/net/minecraft/entity/Entity.h"
#include "../../../sdk/java/lang/String.h"
#include <chrono>
#include <algorithm>

long LastClickTime = 0;

void Friends::Update() 
{
	if (!Enabled) return;
	if (!CommonData::SanityCheck()) return;
	long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (LastClickTime == 0) LastClickTime = milli;
	if ((milli - LastClickTime) < (1000)) return;
	if (GetAsyncKeyState(VK_MBUTTON) && 1)
	{
		if (SDK::Minecraft->GetMouseOver().CMovingObjectPosition::isPlayer()) 
		{
			String str = String(Java::Env->CallObjectMethod(SDK::Minecraft->GetMouseOver().CMovingObjectPosition::getPlayer(), StrayCache::entity_getName));
			auto fName = CommonData::friendsList.begin();
			LastClickTime = milli;
			while (fName != CommonData::friendsList.end())
			{
				if (*fName == str.ToString()) {
					// Due to deletion in loop, iterator became
					// invalidated. So reset the iterator to next item.
					fName = CommonData::friendsList.erase(fName);
					return;
				}
				else
				{
					fName++;
				}
			}
			CommonData::friendsList.push_back(str.ToString());
		}
	}	
}

void Friends::RenderMenu()
{
	ImGui::BeginGroup();
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 20);

	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 0.5));
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 10);
	int len = CommonData::friendsList.size();
	if (ImGui::BeginChild("Friends", ImVec2(425, 381)))
	{
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 3);
		ImGui::Text("Friends:");
		for (const std::string& friendName : CommonData::friendsList) {
			ImGui::Text(friendName.c_str());
		}
		ImGui::EndChild();
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::EndGroup();
}