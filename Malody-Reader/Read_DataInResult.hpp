#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"

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

			// Accuracyº∆À„
			int totalHit = _t_Data.Hit.Best + _t_Data.Hit.Cool + _t_Data.Hit.Great + _t_Data.Hit.Miss;
			double Accuracy = _t_Data.Hit.Best + _t_Data.Hit.Cool * 0.75 + _t_Data.Hit.Great * 0.4;
			Accuracy /= totalHit;

			_t_Data.Accuracy = Accuracy;
			_t_Data.Score = static_cast<int>(_t_Score);
			Data = _t_Data;

			return true;
		}
	};
}