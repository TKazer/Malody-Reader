#pragma once
#include "Malody_Reader_Base/Singleton.hpp"
#include "Malody_Reader_Base/Read_DataInGame.hpp"
#include "Malody_Reader_Base/Read_DataInResult.hpp"
#include "Malody_Reader_Base/Read_Game.hpp"
#include "Malody_Reader_Base/Read_Map.hpp"
#include "Malody_Reader_Base/Read_LocalPlayer.hpp"
#include "Malody_Reader_Base/Read_MpResultData.h"
#include "Malody_Reader_Base/Read_Mods.h"
#include "Malody_Reader_Base/Malody_Algorithm.hpp"

namespace Malody
{
	class MalodyReader : public Singleton<MalodyReader>
	{
	public:
		/// <summary>
		/// 进程管理 Process manager
		/// </summary>
		ProcessManager Process;
		/// <summary>
		/// 游戏数据获取 Get game's datas
		/// </summary>
		ReaderGame Game;
		/// <summary>
		/// 游玩中数据获取 Get data(only in gaming)
		/// </summary>
		Reader_DataInGame DataInGame;
		/// <summary>
		/// 结算中数据获取 Get data(only in result)
		/// </summary>
		Reader_DataInResult DataInResult;
		/// <summary>
		/// 当前屏幕数据获取 Get current map's data
		/// </summary>
		Reader_Map Map;
		/// <summary>
		/// 本地玩家数据获取 Get local player data
		/// </summary>
		Reader_LocalPlayer Player;
		/// <summary>
		/// Mp结算数据获取 Get Multiplay player's datas(only in Multiplay result)
		/// </summary>
		Reader_MpResultData Mp;
		/// <summary>
		/// 游玩mod获取(仅在游玩中获取) Get mods(only in gaming)
		/// </summary>
		Reader_Mods Mods;
	public:
		bool Init()
		{
			if (Process.Attach("malody.exe") != Malody::SUCCEED)
				return false;
			this->Game.ReaderInit(Process, 1);
			this->DataInGame.ReaderInit(Process, Process.ModuleAddress + 0x8311A8);
			this->DataInResult.ReaderInit(Process, Process.ModuleAddress + 0x8311A8);
			this->Map.ReaderInit(Process, Process.ModuleAddress + 0x8310C4);
			this->Player.ReaderInit(Process, Process.ModuleAddress + 0x8310BC);
			this->Mods.ReaderInit(Process, Process.ModuleAddress + 0x831210);
			return true;
		}
	};
}