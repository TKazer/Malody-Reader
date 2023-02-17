#include <Windows.h>
#include <cmath>
#include "Struct.hpp"
#define _is_invalid_int(v) if(v<0||v>999999) return 0
#define _is_invalid_float(v) if(v<0||isinf(v)||isnan(v)) return 0

namespace Malody
{
	namespace Algorithm
	{
		/// <summary>
		/// 计算准确度
		/// </summary>
		/// <param name="Data">打击数据</param>
		/// <returns>准确度</returns>
		double CalcAccuracy(const Malody::ResultData::_hitdata& Data)
		{
			_is_invalid_int(Data.Best);
			_is_invalid_int(Data.Cool);
			_is_invalid_int(Data.Great);
			_is_invalid_int(Data.Miss);
			int Nums = Data.Best + Data.Cool + Data.Great + Data.Miss;
			double Accuracy = 0;
			Accuracy = (Data.Best + Data.Cool * 0.75 + Data.Great * 0.4) / Nums;
			if (isnan(Accuracy) || isinf(Accuracy) || Accuracy < 0 || Accuracy>100)
				return 0;
			return Accuracy;
		}

		/// <summary>
		/// 计算MM值
		/// </summary>
		/// <param name="Data">结算数据</param>
		/// <param name="MapLevel">谱面等级</param>
		/// <returns>MM值</returns>
		float CalcMM(const Malody::ResultData& Data,const int& MapLevel)
		{
			float S = 0, A = 0, L = 1, MM = 0;

			S = static_cast<float> (Data.Score) / (2400 * (Data.Hit.Best + Data.Hit.Cool + Data.Hit.Great + Data.Hit.Miss));

			L *= powf(1.05, (MapLevel > 10) ? 9 : (MapLevel - 1));
			if (MapLevel >= 10)
				L *= powf(1.04, (MapLevel > 15) ? 5 : (MapLevel - 10));
			if (MapLevel >= 15)
				L *= powf(1.03, (MapLevel > 20) ? 5 : (MapLevel - 15));
			if (MapLevel >= 20)
				L *= powf(1.02, MapLevel - 20);

			if (Data.Accuracy > 99.6)
				A = (Data.Accuracy == 100) ? 0.05 : (Data.Accuracy - 99.6) / 10;
			MM = ((S + A) * L - 1) * 60;

			_is_invalid_float(MM);

			return MM;
		}
	}
}