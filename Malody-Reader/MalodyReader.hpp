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
		Malody::ProcessManager Process;				// ���̹���
		Malody::ReaderGame Game;					// ��Ϸ���ݻ�ȡ
		Malody::Reader_DataInGame DataInGame;		// ��Ϸ�����ݻ�ȡ
		Malody::Reader_DataInResult DataInResult;	// ����������ݻ�ȡ
		Malody::Reader_Map Map;						// ��ǰ�������ݻ�ȡ
		Malody::Reader_LocalPlayer Player;			// ����������ݻ�ȡ

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