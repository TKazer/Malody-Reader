#include <iostream>
#include "MalodyReader.hpp" 

int main()
{
	Malody::ProcessManager PManager;
	if (PManager.Attach("malody.exe")== Malody::SUCCEED)
	{
		std::cout << "Attach succeed." << std::endl;
		std::cout << "is Active:" << PManager.IsActive() << std::endl;
		std::cout << "ModuleAddress:" << PManager.ModuleAddress << std::endl;
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

	Malody::GameStatus GameStatus = Malody::GameStatus::STATUS_NONE;
	Malody::MalodyReader::get().Game.GetGameStatus(GameStatus);

	std::cout << "--------" << std::endl;
	std::cout << "Current game status:" << GameStatus << std::endl;
	std::cout << "--------" << std::endl;

	Malody::MapData MapData;
	Malody::OnlinePlayer Player;

	Malody::MalodyReader::get().Player.GetData(Player);
	std::cout << "ID:" << Player.ID << std::endl;
	std::cout << "Name:" << Player.Name << std::endl;
	std::cout << "--------" << std::endl;

	Malody::MalodyReader::get().Map.GetData(MapData);
	std::cout << "Song:" << MapData.SongName << std::endl;
	std::cout << "Level:" << MapData.LevelName << std::endl;
	std::cout << "Artists:" << MapData.Artists << std::endl;
	std::cout << "Creator:" << MapData.Creator << std::endl;
	std::cout << "Mode:" << MapData.Mode << std::endl;
	std::cout << "BPM:" << MapData.BPM << std::endl;
	std::cout << "KeyCounts:" << MapData.KeyCount << std::endl;
	std::cout << "--------" << std::endl;

	Malody::ResultData PlayingData;
	if (GameStatus == Malody::STATUS_GAMING)
	{
		Malody::MalodyReader::get().DataInGame.GetData(PlayingData);
	}
	else if (GameStatus == Malody::STATUS_RESULT)
	{
		Malody::MalodyReader::get().DataInResult.GetData(PlayingData);
	}
	std::cout << "Score:" << PlayingData.Score << std::endl;
	std::cout << "Accuracy:" << PlayingData.Accuracy << std::endl;
	std::cout << "CurrentCombo:" << PlayingData.CurrentCombo << std::endl;
	std::cout << "MaxCombo:" << PlayingData.MaxCombo << std::endl;
	std::cout << "Best:" << PlayingData.Hit.Best << std::endl;
	std::cout << "Cool:" << PlayingData.Hit.Cool << std::endl;
	std::cout << "Great:" << PlayingData.Hit.Great << std::endl;
	std::cout << "Miss:" << PlayingData.Hit.Miss << std::endl;
	std::cout << "--------" << std::endl;

	if (GameStatus == Malody::STATUS_GAMING)
	{
		std::vector<Malody::Mods> Mods;
		Malody::MalodyReader::get().Mods.GetData(Mods);
		std::cout << "Mods:" << std::endl;
		for (auto ModKey : Mods)
		{
			std::cout << ModKey << std::endl;
		}
		std::cout << "--------" << std::endl;
	}

	if (GameStatus == Malody::STATUS_RESULT)
	{
		std::vector<Malody::MPData> MpDatas;
		Malody::MalodyReader::get().Mp.GetData(MpDatas);
		for (auto PlayerData : MpDatas)
		{
			//...
		}
	}

	system("pause");

	return 0;
}