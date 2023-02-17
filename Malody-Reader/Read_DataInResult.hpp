#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"
#include "Malody_Algorithm.hpp"

namespace Malody
{
	class Reader_DataInResult : public _reader_base
	{
	public:
		bool GetData(Malody::ResultData& Data)
		{
			if (!this->IsInit())
				return false;
			DWORD ScoreAddress = Process.TraceAddress(BaseAddress, { 0x228,0x250,0x6C });
			DWORD HitAddress = Process.TraceAddress(BaseAddress, { 0x228,0x250,0x74 });
			DWORD MaxComboAddress = Process.TraceAddress(BaseAddress, { 0x228,0x250,0x70 });

			Malody::ResultData _t_Data;
			double _t_Score = 0;

			if (!Process.ReadMemory<double>(ScoreAddress, _t_Score))
				return false;
			if (!Process.ReadMemory<int>(MaxComboAddress, _t_Data.MaxCombo))
				return false;
			if (!Process.ReadMemory<Malody::ResultData::_hitdata>(HitAddress, _t_Data.Hit))
				return false;

			_t_Data.Accuracy = Malody::Algorithm::CalcAccuracy(_t_Data.Hit);
			_t_Data.Score = static_cast<int>(_t_Score);
			Data = _t_Data;

			return true;
		}
	};
}