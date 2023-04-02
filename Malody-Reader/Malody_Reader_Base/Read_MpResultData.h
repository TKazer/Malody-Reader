#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"
#include "Malody_Algorithm.hpp"

namespace Malody
{
	class Reader_MpResultData : public _reader_base
	{
	public:
		bool GetData(std::vector<MPData>& Data)
		{
			if (!this->IsInit())
				return false;
			DWORD DataAddress = Process.TraceAddress(BaseAddress, { 0x228, 0x2A8 });

			std::vector<MPData> _t_Data;
			char _t_Name[256]{};

			for (DWORD i = 0; i < MAX_MP_PLAYER_NUM; i++)
			{
				DWORD PlayerDataAddress = Process.TraceAddress(BaseAddress, {  i * 0x4, 0x14 });
				DWORD PlayerNameAddress = Process.TraceAddress(PlayerDataAddress + 0x24, { 0 });

				MPData _t_MpData;

				if (!Process.ReadMemory(PlayerDataAddress, _t_MpData.Data.Score))
					goto END;
				if (!Process.ReadMemory(PlayerDataAddress + 0x4, _t_MpData.Data.MaxCombo))
					goto END;
				if (!Process.ReadMemory(PlayerDataAddress + 0x14, _t_MpData.Data.Hit))
					goto END;
				if (!Process.ReadMemory(PlayerNameAddress, _t_Name, 256))
					goto END;

				_t_MpData.Data.Accuracy = Algorithm::CalcAccuracy(_t_MpData.Data.Hit);
				_t_MpData.Player.Name = _t_Name;

				_t_Data.push_back(_t_MpData);
			}

		END:
			Data = _t_Data;

			return Data.size() > 0;
		}
	};
}