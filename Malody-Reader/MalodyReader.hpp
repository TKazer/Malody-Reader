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
		/// ���̹��� Process manager
		/// </summary>
		ProcessManager Process;
		/// <summary>
		/// ��Ϸ���ݻ�ȡ Get game's datas
		/// </summary>
		ReaderGame Game;
		/// <summary>
		/// ���������ݻ�ȡ Get data(only in gaming)
		/// </summary>
		Reader_DataInGame DataInGame;
		/// <summary>
		/// ���������ݻ�ȡ Get data(only in result)
		/// </summary>
		Reader_DataInResult DataInResult;
		/// <summary>
		/// ��ǰ��Ļ���ݻ�ȡ Get current map's data
		/// </summary>
		Reader_Map Map;
		/// <summary>
		/// ����������ݻ�ȡ Get local player data
		/// </summary>
		Reader_LocalPlayer Player;
		/// <summary>
		/// Mp�������ݻ�ȡ Get Multiplay player's datas(only in Multiplay result)
		/// </summary>
		Reader_MpResultData Mp;
		/// <summary>
		/// ����mod��ȡ(���������л�ȡ) Get mods(only in gaming)
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