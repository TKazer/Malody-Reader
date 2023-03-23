#pragma once
#include <iostream>
#include <Windows.h>

namespace Malody
{
	/// <summary>
	/// ��Ϸ״̬
	/// </summary>
	enum GameStatus : DWORD
	{
		STATUS_DEFAULTE = 0, // ��������
		STATUS_GAMING   = 1, // ��Ϸ�н���
		STATUS_ROOM     = 2, // �������
		STATUS_RESULT   = 4, // �������
		STATUS_STORE    = 5, // �̵����
		STATUS_CREATE   = 6, // �༭����
	};

	/// <summary>
	/// ��Ϸģʽ
	/// </summary>
	enum GameMode : DWORD
	{
		MODE_KEY		= 0, // Key
		MODE_CATCH		= 3, // Catch
		MODE_JUBEAT		= 4, // Jubeat
		MODE_TAIKO		= 5, // Taiko
		MODE_RING		= 6, // Ring
		MODE_SLIDER		= 7, // Slieder
		MODE_NONE		= 8, // 
	};

	/// <summary>
	/// ��Ϸ�ж�
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
	/// �������
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
	/// ��Ϸ����
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
	/// ��ǰѡ����������
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
	/// MP��ҽ�������
	/// </summary>
	class MPData
	{
	public:
		OnlinePlayer Player;
		ResultData Data;
	};

	/// <summary>
	/// MP�����������
	/// </summary>
	const int MAX_MP_PLAYER_NUM = 8;
}