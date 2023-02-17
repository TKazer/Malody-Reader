#pragma once
#include "Singleton.hpp"
#include "Read_DataInGame.hpp"
#include "Read_DataInResult.hpp"
#include "Read_Game.hpp"
#include "Read_Map.hpp"
#include "Read_LocalPlayer.hpp"
#include "Malody_Algorithm.hpp"

namespace Malody
{
	class MalodyReader : public Singleton<MalodyReader>
	{
	public:
		Malody::ProcessManager Process;				// 进程管理
		Malody::ReaderGame Game;					// 游戏数据获取
		Malody::Reader_DataInGame DataInGame;		// 游戏中数据获取
		Malody::Reader_DataInResult DataInResult;	// 结算界面数据获取
		Malody::Reader_Map Map;						// 当前谱面数据获取
		Malody::Reader_LocalPlayer Player;			// 本地玩家数据获取

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
			return true;
		}
	};
}