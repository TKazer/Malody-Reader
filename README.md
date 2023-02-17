- [介绍](#Malody-Reader)
- [1.类和函数](#ClassAndFunctions)
  * [(1) 游戏主数据](#ReaderGame)
  * [(2) 游戏中数据](#Reader_DataInGame)
  * [(3) 结算数据](#Reader_DataInResult)
  * [(4) 谱面数据](#Reader_Map)
  * [(5) 玩家数据](#Reader_LocalPlayer)
  * [(5) 数据算法](#Algorithm)
- [协议](#LICENSE)

# Malody-Reader

Using for reading data from malody.

# ClassAndFunctions

## ReaderGame

> 读取游戏主要数据。
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

> 读取游戏中数据。
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

> 读取结算数据
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

> 读取当前谱面数据
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

> 读取本地玩家信息。
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

## Algorithm

| Name         | Using      |                          |
| ------------ | ---------- | ------------------------ |
| CalcAccuracy | 计算准确度 | 游戏游玩中打击的总准确度 |
| CalcMM       | 计算MM值   | 计算单曲Malody metric值  |

# LICENSE

[MIT](https://github.com/TKazer/Malody-Reader/blob/master/LICENSE) 
![](https://img.shields.io/badge/license-MIT-blue)
