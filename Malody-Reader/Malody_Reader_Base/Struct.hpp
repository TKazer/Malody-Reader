#pragma once
#include <iostream>
#include <Windows.h>

namespace Malody
{
	/// <summary>
	/// 游戏状态 Game status
	/// </summary>
	enum GameStatus : DWORD
	{
		STATUS_DEFAULTE = 0, // 大厅界面
		STATUS_GAMING   = 1, // 游戏中界面
		STATUS_ROOM     = 2, // 房间界面
		STATUS_RESULT   = 4, // 结算界面
		STATUS_STORE    = 5, // 商店界面
		STATUS_CREATE   = 6, // 编辑界面
		STATUS_NONE		= 7, // NONE
	};

	/// <summary>
	/// 游戏模式 Map mode
	/// </summary>
	enum GameMode : DWORD
	{
		MODE_KEY		= 0, // Key
		MODE_CATCH		= 3, // Catch
		MODE_JUBEAT		= 4, // Jubeat
		MODE_TAIKO		= 5, // Taiko
		MODE_RING		= 6, // Ring
		MODE_SLIDER		= 7, // Slieder
		MODE_NONE		= 8	 // None
	};

	/// <summary>
	/// 游戏判定 Judgement
	/// </summary>
	enum GameJudge : DWORD
	{
		JUDGE_A,
		JUDGE_B,
		JUDGE_C,
		JUDGE_D,
		JUDGE_E,
	};
	
	/// <summary>
	/// 游玩模式 Mods
	/// </summary>
	enum Mods : DWORD
	{
		MOD_AUTO = 0x1,		// 自动游玩
		MOD_LUCK = 0x2,		// 随机轨道
		MOD_FLIP = 0x4,		// 镜像
		MOD_CONST = 0x8,	// 下落速度不与BPM关联
		MOD_DASH = 0x10,	// 速度1.2x
		MOD_RUSH = 0x20,	// 速度1.5x
		MOD_HIDE = 0x40,	// 下隐
		MOD_ORIGIN = 0x80,	// 原始计分
		MOD_SLOW = 0x100,	// 速度0.8x
		MOD_DEATH = 0x200	// 死亡模式
	};
	const Malody::Mods ModValueList[]{ MOD_AUTO,MOD_LUCK,MOD_FLIP,MOD_CONST,MOD_DASH,MOD_RUSH,MOD_HIDE,MOD_ORIGIN,MOD_SLOW,MOD_DEATH };

	/// <summary>
	/// 玩家数据 Player's data
	/// </summary>
	class OnlinePlayer 
	{
	public:
		int ID = 0;
		std::string Name;
		OnlinePlayer(){}
		OnlinePlayer(int ID, std::string Name) :ID(ID), Name(Name) {}
	};

	/// <summary>
	/// 游戏数据 data
	/// </summary>
	class ResultData
	{
	public:
		int Score = 0;
		double Accuracy = 0;
		int MaxCombo = 0;
		int CurrentCombo = 0;

		struct _hitdata
		{
			int Best = 0;
			int Cool = 0;
			int Great = 0;
			int Miss = 0;
		}Hit;
	};

	/// <summary>
	/// 当前选中谱面数据 current map data
	/// </summary>
	class MapData
	{
	public:
		std::string SongName;
		std::string LevelName;
		std::string Artists;
		std::string Creator;
		float BPM = 0;
		GameMode Mode = MODE_NONE;
		int KeyCount = 0;	// Key模式下的Key数量
	};

	/// <summary>
	/// MP玩家结算数据 Multiplay player data
	/// </summary>
	class MPData
	{
	public:
		OnlinePlayer Player;
		ResultData Data;
	};

	/// <summary>
	/// MP玩家数量上限 Multiplay max player number
	/// </summary>
	const int MAX_MP_PLAYER_NUM = 8;
}