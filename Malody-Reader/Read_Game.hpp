#pragma once
#include <vector>
#include "Struct.hpp"
#include "Read_Base.hpp"

namespace Malody
{
	class ReaderGame : public _reader_base
	{
	public:
		/// <summary>
		/// ��ȡ��Ϸ״̬
		/// </summary>
		/// <param name="GameStatus">������Ϸ״̬</param>
		/// <returns></returns>
		bool GetGameStatus(Malody::GameStatus& GameStatus)
		{
			if (!IsInit())
				false;
			DWORD Address = Process.ModuleAddress + 0x1032DD4;
			DWORD _t_GameStatus = 0;
			if (Address == 0)
				return false;
			if (!Process.ReadMemory<DWORD>(Address, _t_GameStatus, 4))
				return false;
			GameStatus = static_cast<Malody::GameStatus>(_t_GameStatus);
			return true;
		}
		/// <summary>
		/// ��ȡ��Ϸ�ж�
		/// </summary>
		/// <param name="JudgeMent">������Ϸ�ж�</param>
		/// <returns></returns>
		bool GetJudgeMent(Malody::GameJudge& JudgeMent)
		{
			if (!IsInit())
				false;
			DWORD Address = Process.TraceAddress(Process.ModuleAddress + 0x8311C4,{0x9C});
			DWORD _t_JudgeMent = 0;
			if (Address == 0)
				return false;
			if (!Process.ReadMemory<DWORD>(Address, _t_JudgeMent, 4))
				return false;
			JudgeMent = static_cast<Malody::GameJudge>(_t_JudgeMent);
			return true;
		}
	};
}