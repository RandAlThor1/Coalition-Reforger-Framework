[ComponentEditorProps(category: "Game Mode Component", description: "")]
class CRF_GunGameGameModeComponentClass: SCR_BaseGameModeComponentClass
{
	
};

class CRF_GunGameGameModeComponent: SCR_BaseGameModeComponent
{
	
	[Attribute("", UIWidgets.Object, desc: "Array of all guns in order of starting to final", category: "GunGame Zone Settings")]
	ref array<ref GunGameWeaponSelection> m_aGunsList;
	
	
	ref map<int, int> playerMap;
	
	
	string GetPlayerScoreMapString()
	{
		string returnString = "";
		foreach(int i, int j: playerMap)
		{
			returnString += "" + i + " - " + j + "\n";
		}
		return returnString;
	}
	
	override void OnPlayerConnected(int playerId)
	{
		super.OnPlayerConnected(playerId);
		playerMap.Set(playerId, 0);
		GetPlayerScoreMapString();
	}
	
	override void OnGameStateChanged(SCR_EGameModeState state)
	{
		super.onGameStateChanged(state);
		GetPlayerScoreMapString()
	}
};
