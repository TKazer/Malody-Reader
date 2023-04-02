#pragma once
#include "Struct.hpp"
#include "Read_Base.hpp"

namespace Malody
{
	class Reader_Map : public _reader_base
	{
	public:
		bool GetData(Malody::MapData& Data)
		{
			if (!this->IsInit())
				return false;
			DWORD BPMAddress = Process.TraceAddress(BaseAddress, { 0xC,0x6C });
			DWORD KeyCountsAddress = Process.TraceAddress(BaseAddress, { 0x8,0x114 });
			DWORD ModeAddress = Process.TraceAddress(BaseAddress, { 0x18 });
			DWORD LevelNameAddress = Process.TraceAddress(BaseAddress, { 0xC,0x4 });
			DWORD SongNameAddress = Process.TraceAddress(BaseAddress, { 0xC,0x58,0x0 });
			DWORD ArtistsAddress = Process.TraceAddress(BaseAddress, { 0xC,0x5C,0 });
			DWORD CreatorAddress = Process.TraceAddress(BaseAddress, { 0x8,0xE0,0 });

			Malody::MapData _t_Data;

			if (!Process.ReadMemory<float>(BPMAddress, _t_Data.BPM))
				return false;
			if (!Process.ReadMemory(ModeAddress, _t_Data.Mode, 4))
				return false;
			if (_t_Data.Mode == Malody::GameMode::MODE_KEY)
			{
				if (!Process.ReadMemory<int>(KeyCountsAddress, _t_Data.KeyCount))
					return false;
			}

			_t_Data.LevelName = ReadName(LevelNameAddress);
			_t_Data.SongName = ReadName(SongNameAddress);
			_t_Data.Artists = ReadName(ArtistsAddress);
			_t_Data.Creator = ReadName(CreatorAddress);

			Data = _t_Data;

			return true;
		}
	private:
		std::string ReadName(DWORD Address)
		{
			char _t_Name[256]{};
			DWORD ScAddress = 0;
			if (Process.ReadMemory(Address, ScAddress))
			{
				if (Process.ReadMemory(ScAddress, _t_Name, 256))
				{
					if (!std::string(_t_Name).empty())
						return _t_Name;
				}
			}
			ZeroMemory(_t_Name, 256);
			if (!Process.ReadMemory(Address, _t_Name, 256))
				return "";
			return _t_Name;
		}
	};
}
