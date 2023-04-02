- [介绍](#Malody-Reader)
- [示例](#Demo)
- [1.类和函数](#ClassAndFunctions)
  * [(1) 游戏主数据](#ReaderGame)
  * [(2) 游戏中数据](#Reader_DataInGame)
  * [(3) 结算数据](#Reader_DataInResult)
  * [(4) 谱面数据](#Reader_Map)
  * [(5) 玩家数据](#Reader_LocalPlayer)
  * [(6) MP数据](#Reader_MpPlayerData)
  * [(7) Mods](#Reader_Mods)
  * [(8) 数据算法](#Algorithm)
- [协议](#LICENSE)

# Malody-Reader

Using for reading data from malody.
It's easy to use this library to develop plugins.

# Demo

```c++
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

	std::vector<Malody::MPData> MpDatas;
	Malody::MalodyReader::get().Mp.GetData(MpDatas);
	for (auto PlayerData : MpDatas)
	{
		//...
	}

```

# ClassAndFunctions

## ReaderGame

> 读取游戏主要数据。Read game data
>
> ```c++
> 	/// <summary>
> 	/// 游戏状态
> 	/// </summary>
> 	enum GameStatus : DWORD
> 	{
> 		STATUS_DEFAULTE = 0, // 大厅界面
> 		STATUS_GAMING   = 1, // 游戏中界面
> 		STATUS_ROOM     = 2, // 房间界面
> 		STATUS_RESULT   = 4, // 结算界面
> 		STATUS_STORE    = 5, // 商店界面
> 		STATUS_CREATE   = 6, // 编辑界面
> 	};
> 
> 	/// <summary>
> 	/// 游戏判定
> 	/// </summary>
> 	enum GameJudge : DWORD
> 	{
> 		JUDGE_A,
> 		JUDGE_B,
> 		JUDGE_C,
> 		JUDGE_D,
> 		JUDGE_E,
> 	};
> ```
>
> 

## Reader_DataInGame

> 读取游戏中数据。Read data(only in gaming)
>
> ```c++
> 	/// <summary>
> 	/// 游戏数据
> 	/// </summary>
> 	class ResultData
> 	{
> 	public:
> 		int Score = 0;
> 		double Accuracy = 0;
> 		int MaxCombo = 0;
> 		int CurrentCombo = 0;
> 
> 		struct _hitdata
> 		{
> 			int Best = 0;
> 			int Cool = 0;
> 			int Great = 0;
> 			int Miss = 0;
> 		}Hit;
> 	};
> ```

## Reader_DataInResult

> 读取结算数据 Read data(only in result)
>
> ```c++
> 	/// <summary>
> 	/// 游戏数据
> 	/// </summary>
> 	class ResultData
> 	{
> 	public:
> 		int Score = 0;
> 		double Accuracy = 0;
> 		int MaxCombo = 0;
> 		int CurrentCombo = 0;
> 
> 		struct _hitdata
> 		{
> 			int Best = 0;
> 			int Cool = 0;
> 			int Great = 0;
> 			int Miss = 0;
> 		}Hit;
> 	};
> ```

## Reader_Map

> 读取当前谱面数据 Read current map data
>
> ```C++
> 	/// <summary>
> 	/// 当前选中谱面数据
> 	/// </summary>
> 	class MapData
> 	{
> 	public:
> 		std::string SongName;
> 		std::string LevelName;
> 		std::string Artists;
> 		std::string Creator;
> 		float BPM = 0;
> 		GameMode Mode = MODE_NONE;
> 		int KeyCount = 0;	// Key模式下的Key数量
> 	};
> 
> 	/// <summary>
> 	/// 游戏模式
> 	/// </summary>
> 	enum GameMode : DWORD
> 	{
> 		MODE_KEY		= 0, // Key
> 		MODE_CATCH		= 3, // Catch
> 		MODE_JUBEAT		= 4, // Jubeat
> 		MODE_TAIKO		= 5, // Taiko
> 		MODE_RING		= 6, // Ring
> 		MODE_SLIDER		= 7, // Slieder
> 		MODE_NONE		= 8, // None
> 	};
> ```

## Reader_LocalPlayer

> 读取本地玩家信息。Read local player's data
>
> ```c++
> 	/// <summary>
> 	/// 玩家数据
> 	/// </summary>
> 	class OnlinePlayer 
> 	{
> 	public:
> 		int ID = 0;
> 		std::string Name;
> 		OnlinePlayer(){}
> 		OnlinePlayer(int ID, std::string Name) :ID(ID), Name(Name) {}
> 	};
> ```

## Reader_MpPlayerData

> 读取Mp玩家数据。Read multiplay player's data
>
> ```c++
>	/// <summary>
>	/// MP玩家结算数据
>	/// </summary>
>	class MPData
>	{
>	public:
>		OnlinePlayer Player;
>		ResultData Data;
>	};
>	
>	std::vector<MPData> MPDatas;
> ```

## Reader_Mods

> 读取Mod数据 Read mods data
> 
> ```c++
>	/// <summary>
>	/// 游玩模式 Mods
>	/// </summary>
>	enum Mods : DWORD
>	{
>		MOD_AUTO = 0x1,		// 自动游玩
>		MOD_LUCK = 0x2,		// 随机轨道
>		MOD_FLIP = 0x4,		// 镜像
>		MOD_CONST = 0x8,	// 下落速度不与BPM关联
>		MOD_DASH = 0x10,	// 速度1.2x
>		MOD_RUSH = 0x20,	// 速度1.5x
>		MOD_HIDE = 0x40,	// 下隐
>		MOD_ORIGIN = 0x80,	// 原始计分
>		MOD_SLOW = 0x100,	// 速度0.8x
>		MOD_DEATH = 0x200	// 死亡模式
>	};
>```

## Algorithm

| Name         | Using      |                          |
| ------------ | ---------- | ------------------------ |
| CalcAccuracy | 计算准确度 | 游戏游玩中打击的总准确度 |
| CalcMM       | 计算MM值   | 计算单曲Malody metric值  |

> [Algorithm Code](https://github.com/TKazer/Malody-Reader/blob/master/Malody-Reader/Malody_Algorithm.hpp)

# LICENSE

[MIT](https://github.com/TKazer/Malody-Reader/blob/master/LICENSE) 
![](https://img.shields.io/badge/license-MIT-blue)
