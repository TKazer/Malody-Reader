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
		/// ����׼ȷ��
		/// </summary>
		/// <param name="Data">�������</param>
		/// <returns>׼ȷ��</returns>
		double CalcAccuracy(const Malody::ResultData::_hitdata& Data);

		/// <summary>
		/// ����MMֵ
		/// </summary>
		/// <param name="Data">��������</param>
		/// <param name="MapLevel">����ȼ�</param>
		/// <returns>MMֵ</returns>
		float CalcMM(const Malody::ResultData& Data, const int& MapLevel);
	}
}