#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"

namespace Malody
{
	class Reader_LocalPlayer : public _reader_base
	{
	public:
		bool GetData(Malody::OnlinePlayer& Data)
		{
			if (!this->IsInit())
				return false;
			DWORD IDAddress = Process.TraceAddress(BaseAddress, { 0x4 });
			DWORD NameAddress = Process.TraceAddress(BaseAddress, { 0x8});

			Malody::OnlinePlayer _t_Data;
			char _t_Name[256]{};

			if (!Process.ReadMemory<int>(IDAddress, _t_Data.ID))
				return false;
			if (!Process.ReadMemory(NameAddress, _t_Name, 256))
				return false;

			_t_Data.Name = _t_Name;
			Data = _t_Data;

			return true;
		}
	};
}
