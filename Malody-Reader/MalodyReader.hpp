#pragma once
#include "Singleton.hpp"
#include "Read_DataInGame.hpp"
#include "Read_DataInResult.hpp"
#include "Read_Game.hpp"
#include "Read_Map.hpp"
#include "Read_LocalPlayer.hpp"
#include "Read_MpResultData.h"
#include "Malody_Algorithm.hpp"

namespace Malody
{
	class MalodyReader : public Singleton<MalodyReader>
	{
	public:
		ProcessManager Process;				// ���̹���
		ReaderGame Game;					// ��Ϸ���ݻ�ȡ
		Reader_DataInGame DataInGame;		// ��Ϸ�����ݻ�ȡ
		Reader_DataInResult DataInResult;	// ����������ݻ�ȡ
		Reader_Map Map;						// ��ǰ�������ݻ�ȡ
		Reader_LocalPlayer Player;			// ����������ݻ�ȡ
		Reader_MpResultData Mp;				// Mp�������ݻ�ȡ
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