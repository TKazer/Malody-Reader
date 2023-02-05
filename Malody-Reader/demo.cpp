#include <iostream>
#include "Process.hpp"
#include "MalodyReader.hpp" 

int main()
{
	Malody::ProcessManager PManager;
	if (PManager.Attach("malody.exe")== Malody::SUCCEED)
	{
		std::cout << "Attach succeed." << std::endl;
		std::cout << "is Active:" << PManager.IsActive() << std::endl;
		std::cout <<"ModuleAddress:" << PManager.ModuleAddress << std::endl;
	}
	else
	{
		std::cout << "Attach failed." << std::endl;
		system("pause");
		return 0;
	}
	
	if (Malody::MalodyReader::get().Init())
	{
		std::cout << "Reader init succeed." << std::endl;
	}
	else
	{
		std::cout << "Reader init failed." << std::endl;
		system("pause");
		return 0;
	}

	std::cout << "--------" << std::endl;

	Malody::MapData Data;
	Malody::OnlinePlayer Player;

	Malody::MalodyReader::get().Player.GetData(Player);
	std::cout << "ID:" << Player.ID << std::endl;
	std::cout << "Name:" << Player.Name << std::endl;
	std::cout << "--------" << std::endl;

	Malody::MalodyReader::get().Map.GetData(Data);
	std::cout << "Song:" << Data.SongName << std::endl;
	std::cout << "Level:" << Data.LevelName << std::endl;
	std::cout << "Artists:" << Data.Artists << std::endl;
	std::cout << "Creator:" << Data.Creator << std::endl;
	std::cout << "Mode:" << Data.Mode << std::endl;
	std::cout << "BPM:" << Data.BPM << std::endl;
	std::cout << "KeyCounts:" << Data.KeyCount << std::endl;
	std::cout << "--------" << std::endl;

	return 0;
}