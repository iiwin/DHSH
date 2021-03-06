#ifndef __DHSH_GAMEDLL_GAME_OBJECT_GAMEUI_GAMEUIEXTEND_H__
#define __DHSH_GAMEDLL_GAME_OBJECT_GAMEUI_GAMEUIEXTEND_H__

#include "GameBase.h"

class CGameUi;
class CGameUiExtend : public MyTools::CRelfexBaseClass
{
public:
	CGameUiExtend() = default;
	~CGameUiExtend() = default;
	
	UINT GetVecGameUi(_Out_ std::vector<CGameUi>& Vec) CONST;
	
	BOOL FindGameUi_By_Name(_In_ CONST std::wstring& wsUiName, _Out_ CGameUi& GameUi) CONST;

	BOOL IsShowNpcDlg() CONST;

	VOID CloseNpcDlg() CONST;

	BOOL FindText_In_NpcDlg(_In_ CONST std::wstring& wsText) CONST;

	std::wstring GetNpcDlgText() CONST;

	BOOL IsShowDlg(_In_ CONST std::wstring& wsDlgName) CONST;

	BOOL CloseDlg(_In_ CONST std::wstring& wsDlgName) CONST;

	VOID PrintGameUi() CONST;

	BOOL Action_By_DlgName_When_ShowDlg(_In_ CONST std::wstring& wsDlgName, std::function<VOID(CONST CGameUi&)> ActionPtr) CONST;
private:
	UINT TraverseGameUi(_Out_ std::vector<CGameUi>& Vec, _In_ std::function<BOOL(CONST CGameUi&)> fnExprPtr) CONST;
public:
	static CGameUiExtend* CreateInstance()
	{
		return new CGameUiExtend;
	}
	
	virtual VOID ReleaseInstance(_In_ LPVOID lpObjectAddr) CONST
	{
		delete reinterpret_cast<CGameUiExtend*>(lpObjectAddr);
	}
};

#endif // !__DHSH_GAMEDLL_GAME_OBJECT_GAMEUI_GAMEUIEXTEND_H__
