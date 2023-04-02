#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"

namespace Malody
{
	class Reader_Mods : public _reader_base
	{
	public:
		bool GetData(std::vector<Mods>& ModsList)
		{
			if (!this->IsInit())
				return false;
			DWORD ModAddress = Process.TraceAddress(BaseAddress, { 0x8,0xF0});

			DWORD ModStatus = 0;
			if (!Process.ReadMemory<>(ModAddress, ModStatus))
				return false;

			std::vector<Mods> _t_ModsList;
			for (auto ModKey : ModValueList)
			{
				if ((ModKey & ModStatus) == ModKey)
				{
					_t_ModsList.push_back(ModKey);
				}
			}
			ModsList = _t_ModsList;

			return true;
		}
	};
}