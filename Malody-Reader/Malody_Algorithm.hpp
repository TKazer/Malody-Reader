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
		double CalcAccuracy(const Malody::ResultData::_hitdata& Data);

		/// <summary>
		/// 计算MM值
		/// </summary>
		/// <param name="Data">结算数据</param>
		/// <param name="MapLevel">谱面等级</param>
		/// <returns>MM值</returns>
		float CalcMM(const Malody::ResultData& Data, const int& MapLevel);
	}
}