#pragma once
#include <iostream>
#include <Windows.h>

namespace Malody
{
	/// <summary>
	/// ��Ϸ״̬ Game status
	/// </summary>
	enum GameStatus : DWORD
	{
		STATUS_DEFAULTE = 0, // ��������
		STATUS_GAMING   = 1, // ��Ϸ�н���
		STATUS_ROOM     = 2, // �������
		STATUS_RESULT   = 4, // �������
		STATUS_STORE    = 5, // �̵����
		STATUS_CREATE   = 6, // �༭����
		STATUS_NONE		= 7, // NONE
	};

	/// <summary>
	/// ��Ϸģʽ Map mode
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
	/// ��Ϸ�ж� Judgement
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
	/// ����ģʽ Mods
	/// </summary>
	enum Mods : DWORD
	{
		MOD_AUTO = 0x1,		// �Զ�����
		MOD_LUCK = 0x2,		// ������
		MOD_FLIP = 0x4,		// ����
		MOD_CONST = 0x8,	// �����ٶȲ���BPM����
		MOD_DASH = 0x10,	// �ٶ�1.2x
		MOD_RUSH = 0x20,	// �ٶ�1.5x
		MOD_HIDE = 0x40,	// ����
		MOD_ORIGIN = 0x80,	// ԭʼ�Ʒ�
		MOD_SLOW = 0x100,	// �ٶ�0.8x
		MOD_DEATH = 0x200	// ����ģʽ
	};
	const Malody::Mods ModValueList[]{ MOD_AUTO,MOD_LUCK,MOD_FLIP,MOD_CONST,MOD_DASH,MOD_RUSH,MOD_HIDE,MOD_ORIGIN,MOD_SLOW,MOD_DEATH };

	/// <summary>
	/// ������� Player's data
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
	/// ��Ϸ���� data
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
	/// ��ǰѡ���������� current map data
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
		int KeyCount = 0;	// Keyģʽ�µ�Key����
	};

	/// <summary>
	/// MP��ҽ������� Multiplay player data
	/// </summary>
	class MPData
	{
	public:
		OnlinePlayer Player;
		ResultData Data;
	};

	/// <summary>
	/// MP����������� Multiplay max player number
	/// </summary>
	const int MAX_MP_PLAYER_NUM = 8;
}