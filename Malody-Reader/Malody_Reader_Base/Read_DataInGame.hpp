#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"

namespace Malody
{
	class Reader_DataInGame : public _reader_base
	{
	public:
		bool GetData(Malody::ResultData& Data)
		{
			if (!this->IsInit())
				return false;
			DWORD ScoreAddress = Process.TraceAddress(BaseAddress, { 0x228,0x25C,0x23C,0x390 });
			DWORD AccuracyAddress = Process.TraceAddress(BaseAddress, { 0x228,0x25C,0x240,0x340 });
			DWORD ComboAddress = Process.TraceAddress(BaseAddress, { 0x228,0x25C,0x248 });
			DWORD HitAddress = Process.TraceAddress(BaseAddress, { 0x228,0x25C,0x304,0x20 });

			Malody::ResultData _t_Data;
			double _t_Score = 0;

			if (!Process.ReadMemory<double>(ScoreAddress, _t_Score))
				return false;
			if (!Process.ReadMemory<double>(AccuracyAddress, _t_Data.Accuracy))
				return false;
			if (!Process.ReadMemory<int>(ComboAddress, _t_Data.CurrentCombo))
				return false;
			if (!Process.ReadMemory<Malody::ResultData::_hitdata>(HitAddress, _t_Data.Hit))
				return false;
		
			_t_Data.Score = static_cast<int>(_t_Score);
			Data = _t_Data;

			return true;
		}
	};
}