#pragma once
#include <iostream>
#include <windows.h>
#include "Process.hpp"

namespace Malody
{
	class _reader_base
	{
	public:
		ProcessManager Process;
		DWORD BaseAddress = 0;

		void ReaderInit(const ProcessManager& _Process, DWORD _BaseAddress)
		{
			Process = _Process;
			BaseAddress = _BaseAddress;
		}

		bool IsInit()
		{
			if (BaseAddress == 0)
				return false;
			if (!Process.IsActive())
				return false;
			return true;
		}
	};
}